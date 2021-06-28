
// SDIView.h : interface of the CSDIView class
//

#pragma once


class CSDIView : public CView
{
protected: // create from serialization only
	CSDIView();
	DECLARE_DYNCREATE(CSDIView)

private:
	int m_nPos;
	int m_nVuSz;

// Attributes
public:
	CSDIDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CSDIView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	virtual void OnInitialUpdate();
	afx_msg void OnEditAppend();
	afx_msg void OnArrowUp();
	afx_msg void OnArrowDown();
};

#ifndef _DEBUG  // debug version in SDIView.cpp
inline CSDIDoc* CSDIView::GetDocument() const
   { return reinterpret_cast<CSDIDoc*>(m_pDocument); }
#endif

