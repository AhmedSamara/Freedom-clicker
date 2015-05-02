function goflowtodoc(idx,funname,clkidx){
  var html_file ; 
 var fc_file ;	
 html_file  = null; 
 fc_file    = null;
 switch ( idx ) { 
case 54 : 
fc_file ='fn3_0_91_fc.html';
 html_file ='../Files/fd_16.html#OD0_3_91'; 
break; 
case 31 : 
fc_file ='fn3_0_19_fc.html';
 html_file ='../Files/fd_5.html#OD0_3_19'; 
break; 
case 55 : 
fc_file ='fn3_0_93_fc.html';
 html_file ='../Files/fd_14.html#OD0_3_93'; 
break; 
case 56 : 
fc_file ='fn3_0_3_fc.html';
 html_file ='../Files/fd_1.html#OD0_3_3'; 
break; 
case 34 : 
fc_file ='fn3_0_25_fc.html';
 html_file ='../Files/fd_17.html#OD0_3_25'; 
break; 
case 35 : 
fc_file ='fn3_0_26_fc.html';
 html_file ='../Files/fd_18.html#OD0_3_26'; 
break; 
case 37 : 
fc_file ='fn3_0_24_fc.html';
 html_file ='../Files/fd_18.html#OD0_3_24'; 
break; 
case 38 : 
fc_file ='fn3_0_27_fc.html';
 html_file ='../Files/fd_18.html#OD0_3_27'; 
break; 
case 42 : 
fc_file ='fn3_0_11_fc.html';
 html_file ='../Files/fd_4.html#OD0_3_11'; 
break; 
case 43 : 
fc_file ='fn3_0_31_fc.html';
 html_file ='../Files/fd_10.html#OD0_3_31'; 
break; 
case 44 : 
fc_file ='fn3_0_18_fc.html';
 html_file ='../Files/fd_5.html#OD0_3_18'; 
break; 
case 57 : 
fc_file ='fn3_0_92_fc.html';
 html_file ='../Files/fd_14.html#OD0_3_92'; 
break; 
case 48 : 
fc_file ='fn3_0_5_fc.html';
 html_file ='../Files/fd_2.html#OD0_3_5'; 
break; 
case 58 : 
fc_file ='fn3_0_28_fc.html';
 html_file ='../Files/fd_16.html#OD0_3_28'; 
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
