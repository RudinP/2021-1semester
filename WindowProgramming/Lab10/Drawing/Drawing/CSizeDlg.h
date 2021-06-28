#pragma once


// CSizeDlg dialog

class CSizeDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CSizeDlg)

public:
	CSizeDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CSizeDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	int m_nSize;
};
