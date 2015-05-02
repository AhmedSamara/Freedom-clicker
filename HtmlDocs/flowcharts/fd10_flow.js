function goflowtodoc(idx,funname,clkidx){
  var html_file ; 
 var fc_file ;	
 html_file  = null; 
 fc_file    = null;
 switch ( idx ) { 
case 45 : 
fc_file ='fn3_0_12_fc.html';
 html_file ='../Files/fd_4.html#OD0_3_12'; 
break; 
case 50 : 
fc_file ='fn3_0_5_fc.html';
 html_file ='../Files/fd_2.html#OD0_3_5'; 
break; 
case 52 : 
fc_file ='fn3_0_17_fc.html';
 html_file ='../Files/fd_4.html#OD0_3_17'; 
break; 
case 61 : 
fc_file ='fn3_0_15_fc.html';
 html_file ='../Files/fd_4.html#OD0_3_15'; 
break; 
case 62 : 
fc_file ='fn3_0_13_fc.html';
 html_file ='../Files/fd_4.html#OD0_3_13'; 
break; 
case 65 : 
fc_file ='fn3_0_14_fc.html';
 html_file ='../Files/fd_4.html#OD0_3_14'; 
break; 
case 85 : 
fc_file ='fn3_0_35_fc.html';
 html_file ='../Files/fd_10.html#OD0_3_35'; 
break; 
case 76 : 
fc_file ='fn3_0_36_fc.html';
 html_file ='../Files/fd_10.html#OD0_3_36'; 
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
