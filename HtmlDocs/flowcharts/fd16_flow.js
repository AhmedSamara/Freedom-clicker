function goflowtodoc(idx,funname,clkidx){
  var html_file ; 
 var fc_file ;	
 html_file  = null; 
 fc_file    = null;
 switch ( idx ) { 
case 90 : 
fc_file ='fn3_0_56_fc.html';
 html_file ='../Files/fd_16.html#OD0_3_56'; 
break; 
case 94 : 
fc_file ='fn3_0_55_fc.html';
 html_file ='../Files/fd_16.html#OD0_3_55'; 
break; 
case 97 : 
fc_file ='fn3_0_122_fc.html';
 html_file ='../Files/fd_14.html#OD0_3_122'; 
break; 
case 99 : 
fc_file ='fn3_0_112_fc.html';
 html_file ='../Files/fd_16.html#OD0_3_112'; 
break; 
case 101 : 
fc_file ='fn3_0_121_fc.html';
 html_file ='../Files/fd_14.html#OD0_3_121'; 
break; 
case 125 : 
fc_file ='fn3_0_27_fc.html';
 html_file ='../Files/fd_18.html#OD0_3_27'; 
break; 
case 135 : 
fc_file ='fn3_0_54_fc.html';
 html_file ='../Files/fd_17.html#OD0_3_54'; 
break; 
case 140 : 
fc_file ='fn3_0_104_fc.html';
 html_file ='../Files/fd_14.html#OD0_3_104'; 
break; 
case 141 : 
fc_file ='fn3_0_105_fc.html';
 html_file ='../Files/fd_14.html#OD0_3_105'; 
break; 
case 153 : 
fc_file ='fn3_0_34_fc.html';
 html_file ='../Files/fd_10.html#OD0_3_34'; 
break; 
case 154 : 
fc_file ='fn3_0_30_fc.html';
 html_file ='../Files/fd_10.html#OD0_3_30'; 
break; 
case 177 : 
fc_file ='fn3_0_72_fc.html';
 html_file ='../Files/fd_17.html#OD0_3_72'; 
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
