function goflowtodoc(idx,funname,clkidx){
  var html_file ; 
 var fc_file ;	
 html_file  = null; 
 fc_file    = null;
 switch ( idx ) { 
case 102 : 
fc_file ='fn3_0_67_fc.html';
 html_file ='../Files/fd_19.html#OD0_3_67'; 
break; 
case 109 : 
fc_file ='fn3_0_115_fc.html';
 html_file ='../Files/fd_19.html#OD0_3_115'; 
break; 
case 47 : 
fc_file ='fn3_0_73_fc.html';
 html_file ='../Files/fd_17.html#OD0_3_73'; 
break; 
case 140 : 
fc_file ='fn3_0_79_fc.html';
 html_file ='../Files/fd_17.html#OD0_3_79'; 
break; 
case 104 : 
fc_file ='fn3_0_74_fc.html';
 html_file ='../Files/fd_17.html#OD0_3_74'; 
break; 
case 29 : 
fc_file ='fn3_0_5_fc.html';
 html_file ='../Files/fd_2.html#OD0_3_5'; 
break; 
case 119 : 
fc_file ='fn3_0_69_fc.html';
 html_file ='../Files/fd_17.html#OD0_3_69'; 
break; 
case 132 : 
fc_file ='fn3_0_70_fc.html';
 html_file ='../Files/fd_17.html#OD0_3_70'; 
break; 
case 271 : 
fc_file ='fn3_0_66_fc.html';
 html_file ='../Files/fd_17.html#OD0_3_66'; 
break; 
case 361 : 
fc_file ='fn3_0_24_fc.html';
 html_file ='../Files/fd_18.html#OD0_3_24'; 
break; 
case 289 : 
fc_file ='fn3_0_54_fc.html';
 html_file ='../Files/fd_17.html#OD0_3_54'; 
break; 
case 369 : 
fc_file ='fn3_0_43_fc.html';
 html_file ='../Files/fd_18.html#OD0_3_43'; 
break; 
default :
 break; 
 } 
if(clkidx == 1)
 { 
 if(html_file != null)
 window.open(html_file,'sgv_CC_rframe','scrollbars=yes,resizable=1')
  } 
 else  {	
 	document.write("<tr><td align='left' valign='center'>" );
 if(html_file != null )
 { 
 if( fc_file != null) 
 document.write("<a class='POPM_LNK1TXT' href='"+fc_file+"'title ='go to flowchart' target='sgv_CC_rframe' ><image src='../flow.gif' border=1></a><td align='left'><a href='"+html_file+"' Title='go to Defination' target='sgv_CC_rframe' class='POPM_LNK1TXT'>" + funname + "</a>" );
else 
 document.write("<td align='left'><a href='"+html_file+"' Title='go to Defination' target='sgv_CC_rframe' class='POPM_LNK1TXT'>" + funname + "</a>" );
 	} 
 else 
 document.write("<td align='left' class='POPM_LNK2TXT'>"+ funname);
  } } 
