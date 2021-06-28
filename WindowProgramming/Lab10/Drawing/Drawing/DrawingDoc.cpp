
// DrawingDoc.cpp : implementation of the CDrawingDoc class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Drawing.h"
#endif

#include "DrawingDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CDrawingDoc

IMPLEMENT_DYNCREATE(CDrawingDoc, CDocument)

BEGIN_MESSAGE_MAP(CDrawingDoc, CDocument)
END_MESSAGE_MAP()


// CDrawingDoc construction/destruction

CDrawingDoc::CDrawingDoc() noexcept
{
	// TODO: add one-time construction code here

}

CDrawingDoc::~CDrawingDoc()
{
}

BOOL CDrawingDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}




// CDrawingDoc serialization

void CDrawingDoc::Serialize(CArchive& ar)
{
	x.Serialize(ar);
	y.Serialize(ar);
}

void CDrawingDoc::Add(CPoint point)
{
	x.Add(point.x);
	y.Add(point.y);
}

int CDrawingDoc::Size()
{
	return x.GetSize();
}

CPoint CDrawingDoc::GetPoint(int i)
{
	return CPoint(x[i], y[i]);
}

#ifdef SHARED_HANDLERS

// Support for thumbnails
void CDrawingDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// Modify this code to draw the document's data
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// Support for Search Handlers
void CDrawingDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// Set search contents from document's data.
	// The content parts should be separated by ";"

	// For example:  strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CDrawingDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = nullptr;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != nullptr)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CDrawingDoc diagnostics

#ifdef _DEBUG
void CDrawingDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDrawingDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CDrawingDoc commands
