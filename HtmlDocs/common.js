var		majlnks_w = 160;
var	vstr='visible';
var	dly=220;
var     metrix=new Array(1);
metrix[0] = {'dn':'MTCS2', 'sl':'LMTCS2', 'toid':0 };
function showMorepopup( f, mid, srcl,div_id,file )
{
	var		rtw = window.top.sgv_CC_rframe;
	if ( rtw != null )
	{
		var		pop_div,Tab1,Tab2,W1,W2,Tab3;
		var		rtw_doc = rtw.document;
		if ( rtw_doc != null )
		{
			pop_div = getele(rtw_doc, mid);
			Tab1 = getele(rtw_doc, 'MORE_TAB');
 			 Tab2 = getele(rtw_doc, 'MORE_TAB0');
			 Tab3 = getele(rtw_doc, 'MoreArea1');
			if ( pop_div != null && pop_div.style!=null)
			{
				pop_div.style.visibility = f;
				if( Tab1!=null )
				W1 = Tab1.width - 0 
				if(div_id==3 )
				pop_div.style.left = 4* majlnks_w+55+ rtw_doc.body.scrollLeft;
				else if(div_id==2 && Tab2!=null)
{ 
				W2 = Tab2.width - 0 
				if( Tab3!=null)
				pop_div.style.left = W1 + W2 +2* majlnks_w-100+ rtw_doc.body.scrollLeft;
				else
				pop_div.style.left = W1 + W2 +2* majlnks_w+10+ rtw_doc.body.scrollLeft;
} 
else 
{ 
				if( Tab3!=null && file==0)
				pop_div.style.left = W1+2* majlnks_w-100+ rtw_doc.body.scrollLeft;
				else
				pop_div.style.left = W1+2* majlnks_w+10+ rtw_doc.body.scrollLeft;
} 
			    pop_div.style.top = rtw_doc.body.scrollTop;
			}
		}
		}
		}
function showvisiblediv(idx)
{
	var		rtw = window.top.sgv_CC_rframe;
	if ( rtw != null )
	{
		var		pop_div;
		var		rtw_doc = rtw.document;
		if ( rtw_doc != null )
		{
			pop_div = getele(rtw_doc, 'SCUT');			
			if ( pop_div != null && pop_div.style!=null)
				pop_div.style.visibility = 'visible';
			pop_div = getele(rtw_doc, 'MoreArea0');			
			if ( pop_div != null && pop_div.style!=null)
				pop_div.style.visibility = 'visible';
			pop_div = getele(rtw_doc, 'MoreArea1');			
			if ( pop_div != null && pop_div.style!=null && idx==1)
				pop_div.style.visibility = 'visible';
		}
	}
	}
function getele( doc, eid )
{
	if ( doc.all )
		return doc.all(eid);
	if ( doc.getElementById )
		return doc.getElementById(eid);
	return null;
}
function showpopup( f, mid, srcl, idx )
{
	hideall();
	var		rtw = window.top.sgv_CC_rframe;
	if ( rtw != null )
	{
		var		pop_div,Tr_Tab;
		var		rtw_doc = rtw.document;
		if ( rtw_doc != null )
		{
			pop_div = getele(rtw_doc, mid);
			if ( pop_div != null && pop_div.style!=null)
			{
				pop_div.style.visibility = f;
			Tr_Tab = getele(rtw_doc, 'MoreArea1');
			if ( Tr_Tab!=null  && mid=='SCUT')
				pop_div.style.left = (idx) * majlnks_w - 100 + rtw_doc.body.scrollLeft;
			else 
				pop_div.style.left = (idx) * majlnks_w + 10 + rtw_doc.body.scrollLeft;
			    pop_div.style.top = rtw_doc.body.scrollTop;
			}
		}
		}
		}
function hideall()
{
	var		rtw = window.top.sgv_CC_rframe;
	if ( rtw != null )
	{
		var		pop_div;
		var		rtw_doc = rtw.document;
		if ( rtw_doc != null )
		{
			pop_div = getele(rtw_doc, 'IDCS');			
			if ( pop_div != null && pop_div.style!=null)
				pop_div.style.visibility = 'hidden';
			pop_div = getele(rtw_doc, 'OVVW');			
			if ( pop_div != null && pop_div.style!=null)
				pop_div.style.visibility = 'hidden';
			pop_div = getele(rtw_doc, 'DOCS');			
			if ( pop_div != null && pop_div.style!=null)
				pop_div.style.visibility = 'hidden';
			pop_div = getele(rtw_doc, 'MTCS');			
			if ( pop_div != null && pop_div.style!=null)
				pop_div.style.visibility = 'hidden';
			pop_div = getele(rtw_doc, 'XREF');			
			if ( pop_div != null&& pop_div.style!=null )
				pop_div.style.visibility = 'hidden';
			pop_div = getele(rtw_doc, 'SCUT');			
			if ( pop_div != null && pop_div.style!=null)
				pop_div.style.visibility = 'hidden';
			pop_div = getele(rtw_doc, 'MoreArea0');			
			if ( pop_div != null && pop_div.style!=null)
				pop_div.style.visibility = 'hidden';
			pop_div = getele(rtw_doc, 'MoreArea1');			
			if ( pop_div != null && pop_div.style!=null)
				pop_div.style.visibility = 'hidden';
			pop_div = getele(rtw_doc, 'MTCS2');			
			if ( pop_div != null && pop_div.style!=null)
				pop_div.style.visibility = 'hidden';
		}
	}
	}
function shwlcnhlpln( str )
{
	var		hlo;
	var		tw = window.top.sgv_CC_tframe;
	if ( tw != null )
	{
		hlo = getele( tw.document, "HELPLINE" );
		if ( hlo != null )
		{
			hlo.style.visibility = 'visible';
			if (hlo.innerHTML!=null)
		       	hlo.innerHTML=str;
		}
	}
	}
function file_doc_starter( flg )
{
	var		rtw = window.top.sgv_CC_tframe;
	if ( rtw != null )
	{
		var		lnk, nrml;
		var		rtw_doc = rtw.document;
		if ( rtw_doc != null )
		{
			lnk  = getele( rtw_doc, "LSCUT" );
			nrml = getele( rtw_doc, "GOTOA" );
			if( flg == false)
			{
				if ( lnk != null )
					lnk.style.display="none";
				if ( nrml != null )
					nrml.style.display="inline";
			}
			else
			{
				if ( lnk != null )
					lnk.style.display="inline";
				if ( nrml != null )
					nrml.style.display="none";
			}
		}
	}
	}
function tovr()
{
	event.srcElement.style.cursor = "hand";
}
function tclk( img_o, ol_o )
{
	var		imo, olo;
	imo = getele( document, img_o );
	olo = getele( document, ol_o );
	if ( olo != null )
	{
		if ( olo.xpd == 1 )
		{
			olo.xpd = 0;
			olo.style.display = "none";
			if( imo != null )
				imo.src = "../tvwnonlfc.gif";
		}
		else
		{
			olo.xpd = 1;
			olo.style.display = "list-item";
			if( imo != null )
				imo.src = "../tvwnonlfo.gif";
		}
	}
}
function tclkds( img_o, ol_o )
{
	var		imo, olo;
	imo = getele( document, img_o );
	olo = getele( document, ol_o );
	if ( olo != null )
	{
		if ( olo.xpd == 1 )
		{
			olo.xpd = 0;
			olo.style.display = "none";
			if( imo != null )
				imo.src = "tvwnonlfc.gif";
		}
		else
		{
			olo.xpd = 1;
			olo.style.display = "list-item";
			if( imo != null )
				imo.src = "tvwnonlfo.gif";
		}
	}
}
var		lnkstyl='POPM_LNK1TXT';
var		dfltstyl='POPM_DFLTTXT';
var		target_frm = '_sgv_cc_brws_tree';
var		target_frm = '_sgv_cc_brws_tree';
var		i11='overview.html';
var		i12='graphs/prj_rpt.html';
var		i13='(null).html';
var		i21='allfilestv.html';
var		i22='allgftv.html';
var		i23='allgvtv.html';
var		i212='allmacstv.html';
var		i31='mt_prj.html';
var		i33='vmt_lns.html';
var		i34='vmt_cflw.html';
var		i35='vmt_dcln.html';
var		i36='vmt_idfr.html';
var		i37='cmthlstd.html';
var		i38='cmtmcabe.html';
var		i39='fnmt_lns_0.html';
var		i310='fnmt_cflw_0.html';
var		i311='fnmt_dcln_0.html';
var		i312='fnmt_idfr_0.html';
var		i313='fnmt_mccbs_0.html';
var		i314='fw_mccbs_oc.html';
var		i315='fw_mccbs_od.html';
var		i316='fw_mccbs_oe.html';
var		i41='allgf_0.html';
var		i42='allgv_0.html';
var		i410='allmacs_0.html';
function put_pdmenus( rootpth )
{
	var		d = document;
	d.write("<div id='OVVW' name='NOVVW' style='visibility:hidden;position:absolute'>");	d.write("<table border=1 cellspacing=0 cellpadding=0><tr><td>");
	d.write("<table border=0");	d.write(" bgcolor='#F0F0F0'");	d.write(" cellspacing=0 cellpadding=5 width=130>");	d.write("<tr><td width=5 height=1><td>");
	d.write("<tr><td><td><a class='"+lnkstyl+"' href='"+rootpth+i11+"' onclick='hideall();return true;'>Summary</a><br>");
	d.write("<tr><td><td nowrap><a class='"+lnkstyl+"' href='"+rootpth+i12+"' target='_sgv_cc_brws_tree'>Project Report Tree</a><br>");
	d.write("</table></table></div>");
	d.write("<div id='DOCS' name='NDOCS' style='visibility:hidden;position:absolute'>");	d.write("<table border=1 cellspacing=0 cellpadding=0><tr><td>");
	d.write("<table border=0");	d.write(" bgcolor='#F0F0F0'");	d.write(" cellspacing=0 cellpadding=5 width=150><tr><td width=5><td>");
	d.write("<tr><td colspan=2 height=5>");
	d.write("<tr><td><td><a class='"+lnkstyl+"' target='"+target_frm+"' href='"+rootpth+i21+"'>All Files</a><br>");
	d.write("<tr><td><td><a class='"+lnkstyl+"' target='"+target_frm+"' href='"+rootpth+i22+"'>Functions</a><br>");
	d.write("<tr><td><td><a class='"+lnkstyl+"' target='"+target_frm+"' href='"+rootpth+i23+"'>Variables</a><br>");
	d.write("<tr><td><td><a class='"+lnkstyl+"' target='"+target_frm+"' href='"+rootpth+i212+"'>Macros</a><br>");
	d.write("<tr><td colspan=2 height=10>");
	d.write("</table></table></div>");
	d.write("<div id='MTCS' name='NMTCS' style='visibility:hidden;position:absolute'>");	d.write("<table border=1 cellspacing=0 cellpadding=0><tr><td>");
	d.write("<table border=0 cellspacing=0");	d.write(" bgcolor='#F0F0F0'");	d.write(" cellpadding=5 width=200 class='"+dfltstyl+"'><tr><td width=1 height=1><td height=1 width=1><td>");
	d.write("<tr><td colspan=3 height=5>");
	d.write("<tr><td><td colspan=2><a class='"+lnkstyl+"' href='"+rootpth+i31+"'>Whole Project</a>");
	d.write("<tr><td colspan=3 height=5>");
	d.write("<tr><td><td colspan=2>Filewise - by Volume");
	d.write("<tr><td><td><td><a class='"+lnkstyl+"' href='"+rootpth+i33+"'>Lines</a><br>");
	d.write("<tr><td><td><td><a class='"+lnkstyl+"' href='"+rootpth+i34+"'>Control-Flow</a><br>");
	d.write("<tr><td><td><td><a class='"+lnkstyl+"' href='"+rootpth+i35+"'>Declarations</a><br>");
	d.write("<tr><td><td><td><a class='"+lnkstyl+"' href='"+rootpth+i36+"'>Identifiers</a><br>");
	d.write("<tr><td colspan=3 height=5>");
	d.write("<tr><td><td colspan=2>Filewise - by Complexity");
	d.write("<tr><td><td><td><a class='"+lnkstyl+"' href='"+rootpth+i37+"'>Halstead's</a><br>");
	d.write("<tr><td><td><td><a class='"+lnkstyl+"' href='"+rootpth+i38+"'>McCabe's</a><br>");
	d.write("<tr><td colspan=3 height=5>");
d.write("<tr><td><td  colspan=2 align='right' > &nbsp; <a class='POPM_LNK1TXT' id='LMTCS2' alt='Summary of the Document being viewed' href='#'  onmouseover='metrix[0].toid=setTimeout(\"showMorepopup(vstr, metrix[0].dn, metrix[0].sl,3,0)\", dly)'>More &nbsp  &nbsp>>></a>");	
	d.write("<tr><td colspan=2 height=10>");
	d.write("</table></table></div>");
	d.write("<div id='MTCS2' name='NMTCS2' style='visibility:hidden;position:absolute'>");	d.write("<table border=1 cellspacing=0 cellpadding=0><tr><td>");
	d.write("<table border=0 cellspacing=0");	d.write(" bgcolor='#F0F0F0'");	d.write(" cellpadding=5 width=200 class='"+dfltstyl+"'><tr><td width=1 height=1><td height=1 width=1><td>");
	d.write("<tr><td colspan=3 height=5>");
	d.write("<tr><td><td colspan=2>Functionwise - by Volume");
	d.write("<tr><td><td><td><a class='"+lnkstyl+"' href='"+rootpth+i39+"'>Lines</a><br>");
	d.write("<tr><td><td><td><a class='"+lnkstyl+"' href='"+rootpth+i310+"'>Control-Flow</a><br>");
	d.write("<tr><td><td><td><a class='"+lnkstyl+"' href='"+rootpth+i311+"'>Declarations</a><br>");
	d.write("<tr><td><td><td><a class='"+lnkstyl+"' href='"+rootpth+i312+"'>Identifiers</a><br>");
	d.write("<tr><td colspan=4 height=5>");
	d.write("<tr><td><td colspan=2 nowrap>Functionwise - by McCabes Complexity ");
	d.write("<tr><td><td><td><a class='"+lnkstyl+"' href='"+rootpth+i313+"'>Default</a><br>");
	d.write("<tr><td><td><td><a class='"+lnkstyl+"' href='"+rootpth+i314+"'>Cyclomatic</a><br>");
	d.write("<tr><td><td><td><a class='"+lnkstyl+"' href='"+rootpth+i315+"'>Design</a><br>");
	d.write("<tr><td><td><td><a class='"+lnkstyl+"' href='"+rootpth+i316+"'>Essential</a><br>");
	d.write("<tr><td colspan=3 height=5>");
	d.write("</table></table></div>");
	d.write("<div id='XREF' name='NXREF' style='visibility:hidden;position:absolute'>");	d.write("<table border=1 cellspacing=0 cellpadding=0><tr><td>");
	d.write("<table border=0");	d.write(" bgcolor='#F0F0F0'");	d.write(" cellspacing=0 cellpadding=5 width=150>");
	d.write("<tr><td colspan=2 height=5>");
	d.write("<tr><td width=5><td><a class='"+lnkstyl+"' href='"+rootpth+i41+"'>Functions</a><br>");
	d.write("<tr><td><td><a class='"+lnkstyl+"' href='"+rootpth+i42+"'>Variables</a><br>");
	d.write("<tr><td><td><a class='"+lnkstyl+"' href='"+rootpth+i410+"'>Macros</a><br>");
	d.write("<tr><td colspan=2 height=10>");
	d.write("</table></table></div>");
}
function ExpandAll(tot_tbl)
{
  var	olo,imo, tbl_id = 1;

    while(tbl_id < tot_tbl)
    {
     var tbl_str,img_str;

     tbl_str = "N_" + tbl_id;
     img_str = "I_" + tbl_id;

     olo = getele( document, tbl_str );
     imo = getele( document, img_str );

    if(olo != null)
    {
     olo.xpd = 1;
     olo.style.display = "list-item";
     if( imo != null )
     imo.src = "../tvwnonlfo.gif";
    }
   tbl_id = tbl_id + 1;
}
}
function CollapseAll(tot_tbl)
{
  var	olo,imo, tbl_id = 1;

  while(tbl_id < tot_tbl)
  {
    var tbl_str,img_str;

    tbl_str = "N_" + tbl_id;
    img_str = "I_" + tbl_id;

    olo = getele( document, tbl_str );
    imo = getele( document, img_str );

    if(olo != null)
    {
     olo.xpd = 0;
     olo.style.display = "none";
     if( imo != null )
     imo.src = "../tvwnonlfc.gif";
     }
  tbl_id = tbl_id + 1;
 }
}
