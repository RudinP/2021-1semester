#pragma once

// CEdDoc document

class CEdDoc : public CDocument
{
	DECLARE_DYNCREATE(CEdDoc)

public:
	CEdDoc();
	virtual ~CEdDoc();
#ifndef _WIN32_WCE
	virtual void Serialize(CArchive& ar);   // overridden for document i/o
#endif
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual BOOL OnNewDocument();

	DECLARE_MESSAGE_MAP()
};
