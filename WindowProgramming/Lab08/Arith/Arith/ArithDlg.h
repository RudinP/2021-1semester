#pragma once
#include "resource.h"
// CArithDlg dialog
class CArithDlg : public CDialogEx
{
	// Construction
public:
	CArithDlg(CWnd* pParent = NULL); // standard constructor
	// Dialog Data
	enum { IDD = IDD_ARITH_DIALOG };
protected:
	virtual void DoDataExchange(CDataExchange* pDX); // DDX/DDV support
	// Implementation
protected:
	HICON m_hIcon;
	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	int m_nRadio;
	int m_nAnswer;
	CString m_strName;
	int m_nNum1;
	int m_nNum2;
	int m_nLimit;
	afx_msg void OnExecRenew();
	afx_msg void OnExecChangelevel();
	afx_msg void OnExecCheck();
	afx_msg void OnExitQuit();
	afx_msg void OnExitSaveandquit();
	afx_msg void OnBnClickedAddRadio();
};