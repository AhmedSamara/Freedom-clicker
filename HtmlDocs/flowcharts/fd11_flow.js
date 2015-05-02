function goflowtodoc(idx,funname,clkidx){
  var html_file ; 
 var fc_file ;	
 html_file  = null; 
 fc_file    = null;
 switch ( idx ) { 
case 37 : 
fc_file ='fn3_0_94_fc.html';
 html_file ='../Files/fd_19.html#OD0_3_94'; 
break; 
case 39 : 
fc_file ='fn3_0_95_fc.html';
 html_file ='../Files/fd_19.html#OD0_3_95'; 
break; 
case 78 : 
fc_file ='fn3_0_43_fc.html';
 html_file ='../Files/fd_18.html#OD0_3_43'; 
break; 
case 80 : 
fc_file ='fn3_0_24_fc.html';
 html_file ='../Files/fd_18.html#OD0_3_24'; 
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
