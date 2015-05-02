/*
* Print the names of ELF sections.
*
* $Id: prog4.txt 2133 2011 -11 -10 08:28:22 Z jkoshy $
*/
#include <err.h>
#include <fcntl.h>
#include <gelf.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int debug=0, gen_c_code=0, gen_sizes=0, gen_sort_support=0;

int
main ( int argc , char ** argv )
{
  int fd;
  FILE * ofp;
  Elf *e;
  char *name , *p, *ofname=NULL;
  Elf_Scn *scn, *symtab_scn, *strtab_scn=NULL;
  Elf_Data * data, * strings;
  char * str;
  Elf32_Sym *sym;
  GElf_Shdr shdr;
  size_t n, shstrndx, sz;
  int reg_num=0, i;

  if ( argc < 2) {
    printf(" usage : %s file-name [options]\n", argv [0]);
    printf("  -c Generate C code with region information for time profiling\n");
    printf("  -s Generate C code with data structure to support sorting regions by time\n");
    printf("  -z Generate text with region size information\n");
    printf("  -o Output file name\n");
    printf("  -d Print debug information\n");  
    exit (EXIT_FAILURE);
  }

  for (i=2; i < argc; i++) {
    if (argv[i][0] == '-') {
      switch (argv[i][1]) {
      case 'c': 
	gen_c_code = 1;
	break;
      case 'z': 
	gen_sizes = 1;
	break;
      case 's': 
	gen_sort_support = 1;
	break;
      case 'd':
 	debug = 1;
	break;
      case 'o':
	ofname = &(argv[i][2]);
	if (strlen(ofname) < 1) {
	  printf("Output file name must be concatenated with -o\n");
	  exit(EXIT_FAILURE);
	}
	break;
      default:
	printf("Unknown option %s\n", argv[i]);
	break;
      }
    }
  }
  
  if (gen_c_code & gen_sizes) {
    errx ( EXIT_FAILURE , "Error: -c and -s are mutually exclusive options.");
  }

  if ( elf_version ( EV_CURRENT ) == EV_NONE )
    errx ( EXIT_FAILURE , " ELF library initialization  "
	   " failed : %s", elf_errmsg ( -1));
  if (( fd = open ( argv [1] , O_RDONLY , 0)) < 0)
    err ( EXIT_FAILURE , " open  \%s\"  failed ", argv [1]);
  if ((e = elf_begin (fd , ELF_C_READ , NULL )) == NULL )
    errx ( EXIT_FAILURE , " elf_begin ()  failed : %s.",
	   elf_errmsg ( -1));
  if ( elf_kind (e) != ELF_K_ELF )
    errx ( EXIT_FAILURE , "%s is  not an  ELF  object.",
	   argv [1]);
  if ( elf_getshdrstrndx (e, & shstrndx ) != 0)
    errx ( EXIT_FAILURE , " elf_getshdrstrndx ()  failed : %s.",
	   elf_errmsg ( -1));


  if ((ofname != NULL) && (strlen(ofname) > 0)) {
    // open file for output
    ofp = fopen (ofname, "w");
    if (ofp == NULL) {
      err ( EXIT_FAILURE , " fopen %s  failed ", ofname);
    }
  } else {
    errx ( EXIT_FAILURE , " Must specify output file name with -o");
  }

  scn = NULL ;
  while (( scn = elf_nextscn (e, scn )) != NULL ) {
    if ( gelf_getshdr (scn , & shdr ) != & shdr )
      errx ( EXIT_FAILURE , " getshdr ()  failed : %s.", elf_errmsg ( -1));
    if (shdr.sh_type == SHT_SYMTAB){
      if (debug)
	printf("Found symbol table\n");
      symtab_scn = scn;
    }
    if ((strtab_scn == NULL) && (shdr.sh_type == SHT_STRTAB)){
      if (debug)
	printf("Found string table\n");
      strtab_scn = scn;
    }
    
    if (( name = elf_strptr (e, shstrndx , shdr.sh_name )) == NULL )
      errx ( EXIT_FAILURE , " elf_strptr ()  failed : %s.", elf_errmsg ( -1));
   
    if (debug)
      ( void ) printf (" Section  % -4.4 jd %s\n", ( uintmax_t ) elf_ndxscn (scn), name );
  }

  // get section header for symbol table
  if ( gelf_getshdr (symtab_scn , & shdr ) != & shdr )
    errx ( EXIT_FAILURE , " getshdr (  )  failed : %s.", elf_errmsg ( -1));
  

  if (debug)
    printf (".symtab:  size =% jd, (%d entries)\n", (uintmax_t) shdr.sh_size, shdr.sh_size/sizeof(Elf32_Sym));

  data = NULL ;  n = 0;
  data = elf_getdata (symtab_scn , data );
  if (data == NULL) {
    errx(EXIT_FAILURE, "Couldn't get elf data\n");
  }
  sym = ( Elf32_Sym *) data->d_buf ;

  strings = NULL;
  strings = elf_getdata (strtab_scn, strings );
  if (strings == NULL) {
    errx(EXIT_FAILURE, "Couldn't get elf strings\n");
  }
  str = ( char * ) strings->d_buf;

  if (gen_c_code) {
    fprintf(ofp, "// Automatically generated file. Do not edit if you plan to regenerate it.\n"
	    "#include \"region.h\"\n"
	    "const REGION_T RegionTable[] = {\n");
  }
  
  for (n = 0, reg_num = 0; n < shdr.sh_size/sizeof(Elf32_Sym); n++ ) {
    if ((ELF32_ST_TYPE(sym[n].st_info) == STT_FUNC) && (sym[n].st_size != 0)) {
      if (gen_c_code) {
	fprintf(ofp, "\t{0x%08x, 0x%08x, \"%.24s\"}, // %d\n",
		sym[n].st_value, sym[n].st_value+sym[n].st_size-1, &(str[sym[n].st_name]), reg_num);
      } 
      if (gen_sizes) {
	fprintf(ofp, "%08d %s\n", sym[n].st_size, &(str[sym[n].st_name]), reg_num);
      }
      if (debug) {
	printf("Code symbol %d: %d, %s, value 0x%08x and size 0x%08x\n",
	       n, sym[n].st_name, &(str[sym[n].st_name]), sym[n].st_value, sym[n].st_size);
      }
      reg_num++;
    }
  }

  if (gen_c_code) {
    fprintf(ofp, "}; \n");
    fprintf(ofp, "const unsigned NumProfileRegions=%d;\n", reg_num);
    fprintf(ofp, "volatile unsigned RegionCount[%d];\n", reg_num);
    if (gen_sort_support) {
      fprintf(ofp, "unsigned SortedRegions[%d];\n", reg_num);
    }
  }

  ( void ) elf_end (e);
  ( void ) close (fd );
  fclose(ofp);
  exit ( EXIT_SUCCESS );
}
