
// SDIView.cpp : implementation of the CSDIView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "SDI.h"
#endif

#include "SDIDoc.h"
#include "SDIView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#include "CInputDialog.h"


// CSDIView

IMPLEMENT_DYNCREATE(CSDIView, CView)

BEGIN_MESSAGE_MAP(CSDIView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_EDIT_APPEND, &CSDIView::OnEditAppend)
	ON_COMMAND(ID_ARROW_UP, &CSDIView::OnArrowUp)
	ON_COMMAND(ID_ARROW_DOWN, &CSDIView::OnArrowDown)
END_MESSAGE_MAP()

// CSDIView construction/destruction

CSDIView::CSDIView() 
	: m_nPos(0)
{
	// TODO: add construction code here
	m_nVuSz = 5;
}

CSDIView::~CSDIView()
{
}

BOOL CSDIView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CSDIView drawing

void CSDIView::OnDraw(CDC* pDC)
{
	CSDIDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
	for (int i = m_nPos; i < m_nPos + m_nVuSz && i < pDoc->m_nLines; i++) {
		CString str;
		str.Format(_T("%d: "), i);
		pDC->TextOutW(10, 10 + 20 * (i - m_nPos), str + pDoc->m_strLines[i]);
	}

}


// CSDIView printing

BOOL CSDIView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CSDIView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CSDIView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CSDIView diagnostics

#ifdef _DEBUG
void CSDIView::AssertValid() const
{
	CView::AssertValid();
}

void CSDIView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSDIDoc* CSDIView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSDIDoc)));
	return (CSDIDoc*)m_pDocument;
}
#endif //_DEBUG


// CSDIView message handlers


void CSDIView::OnInitialUpdate()
{
	CView::OnInitialUpdate();

	// TODO: Add your specialized code here and/or call the base class
	m_nPos = 0;
}


void CSDIView::OnEditAppend()
{
	// TODO: Add your command handler code here
	CInputDialog iDlg;
	if (iDlg.DoModal() == IDOK) {
		CSDIDoc* pDoc = GetDocument();
		ASSERT_VALID(pDoc);
		if (!pDoc)
			return;
		pDoc-> m_strLines[pDoc-> m_nLines] = iDlg.m_strLine;
		pDoc-> m_nLines++;
		pDoc-> SetModifiedFlag(TRUE);
		m_nPos = pDoc-> m_nLines- m_nVuSz;
		if (m_nPos < 0)
			m_nPos = 0;
		Invalidate();
	}
}


void CSDIView::OnArrowUp()
{
	// TODO: Add your command handler code here
	(m_nPos > 0) ? m_nPos-- : 0;
	Invalidate();

}


void CSDIView::OnArrowDown()
{
	// TODO: Add your command handler code here
	CSDIDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	(m_nPos < pDoc->m_nLines - 1) ? m_nPos++ : 0;
	Invalidate();

}
