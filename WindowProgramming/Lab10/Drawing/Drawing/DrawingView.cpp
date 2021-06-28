
// DrawingView.cpp : implementation of the CDrawingView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Drawing.h"
#endif

#include "DrawingDoc.h"
#include "DrawingView.h"

#include "CSizeDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDrawingView

IMPLEMENT_DYNCREATE(CDrawingView, CView)

BEGIN_MESSAGE_MAP(CDrawingView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_MOUSEMOVE()
	ON_COMMAND(O_OPTION_SIZE, &CDrawingView::OnOptionSize)
END_MESSAGE_MAP()

// CDrawingView construction/destruction

CDrawingView::CDrawingView() noexcept
{
	// TODO: add construction code here
	w = 5;

}

CDrawingView::~CDrawingView()
{
}

BOOL CDrawingView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CDrawingView drawing

void CDrawingView::OnDraw(CDC* pDC)
{
	CDrawingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	for (int i = 0; i < pDoc->Size(); i++) {
		CPoint p = pDoc->GetPoint(i);
		pDC->Rectangle(p.x, p.y, p.x + w, p.y + w);
	}
}



// CDrawingView printing

BOOL CDrawingView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CDrawingView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CDrawingView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CDrawingView diagnostics

#ifdef _DEBUG
void CDrawingView::AssertValid() const
{
	CView::AssertValid();
}

void CDrawingView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDrawingDoc* CDrawingView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDrawingDoc)));
	return (CDrawingDoc*)m_pDocument;
}
#endif //_DEBUG


// CDrawingView message handlers


void CDrawingView::OnMouseMove(UINT nFlags, CPoint point)
{
	CDrawingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	if (nFlags == MK_LBUTTON) { // 마우스 왼쪽 버튼이 눌려져 있으면
		CClientDC dc(this);
		dc.Rectangle(point.x, point.y, point.x + w, point.y + w);
		pDoc->Add(point);
		pDoc->SetModifiedFlag();
		pDoc->UpdateAllViews(this, 0, 0);
	}
	CView::OnMouseMove(nFlags, point);
}



void CDrawingView::OnOptionSize()
{
	// TODO: Add your command handler code here
	CSizeDlg dlg;
	dlg.m_nSize = w;
	if(dlg.DoModal() == IDOK)
		w = dlg.m_nSize;
}


void CDrawingView::OnUpdate(CView* pSender, LPARAM lHint,CObject* pHint)
{
	CDrawingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	int n = pDoc->Size();
	if (n > 0) {
		CPoint p = pDoc->GetPoint(n - 1);
		CClientDC dc(this);
		dc.Rectangle(p.x, p.y, p.x + w, p.y + w);
	}
}

