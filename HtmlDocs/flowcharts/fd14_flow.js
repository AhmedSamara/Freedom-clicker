function goflowtodoc(idx,funname,clkidx){
  var html_file ; 
 var fc_file ;	
 html_file  = null; 
 fc_file    = null;
 switch ( idx ) { 
case 85 : 
fc_file ='fn3_0_103_fc.html';
 html_file ='../Files/fd_14.html#OD0_3_103'; 
break; 
case 93 : 
fc_file ='fn3_0_100_fc.html';
 html_file ='../Files/fd_14.html#OD0_3_100'; 
break; 
case 36 : 
fc_file ='fn3_0_98_fc.html';
 html_file ='../Files/fd_14.html#OD0_3_98'; 
break; 
case 99 : 
fc_file ='fn3_0_109_fc.html';
 html_file ='../Files/fd_19.html#OD0_3_109'; 
break; 
case 100 : 
fc_file ='fn3_0_97_fc.html';
 html_file ='../Files/fd_19.html#OD0_3_97'; 
break; 
case 72 : 
fc_file ='fn3_0_51_fc.html';
 html_file ='../Files/fd_14.html#OD0_3_51'; 
break; 
case 133 : 
fc_file ='fn3_0_5_fc.html';
 html_file ='../Files/fd_2.html#OD0_3_5'; 
break; 
case 143 : 
fc_file ='fn3_0_92_fc.html';
 html_file ='../Files/fd_14.html#OD0_3_92'; 
break; 
case 135 : 
fc_file ='fn3_0_106_fc.html';
 html_file ='../Files/fd_14.html#OD0_3_106'; 
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
