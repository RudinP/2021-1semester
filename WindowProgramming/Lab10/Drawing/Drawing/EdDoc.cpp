// EdDoc.cpp : implementation file
//

#include "pch.h"
#include "Drawing.h"
#include "EdDoc.h"


// CEdDoc

IMPLEMENT_DYNCREATE(CEdDoc, CDocument)

CEdDoc::CEdDoc()
{
}

BOOL CEdDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;
	return TRUE;
}

CEdDoc::~CEdDoc()
{
}


BEGIN_MESSAGE_MAP(CEdDoc, CDocument)
END_MESSAGE_MAP()


// CEdDoc diagnostics

#ifdef _DEBUG
void CEdDoc::AssertValid() const
{
	CDocument::AssertValid();
}

#ifndef _WIN32_WCE
void CEdDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif
#endif //_DEBUG

#ifndef _WIN32_WCE
// CEdDoc serialization

void CEdDoc::Serialize(CArchive& ar)
{
	((CEditView*)m_viewList.GetHead()) -> SerializeRaw(ar);
}

#endif


// CEdDoc commands
