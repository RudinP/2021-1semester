#include "pch.h"
#include "Arith.h"
#include "ArithDlg.h"
#include "afxdialogex.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif
// CAboutDlg dialog used for App About
class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();
	// Dialog Data
	enum { IDD = IDD_ABOUTBOX };
protected:
	virtual void DoDataExchange(CDataExchange* pDX); // DDX/DDV support
	// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};
CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}
void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}
BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()
// CArithDlg dialog
CArithDlg::CArithDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_ARITH_DIALOG, pParent)
	, m_nRadio(0)
	, m_nAnswer(0)
	, m_strName(_T(""))
	, m_nNum1(0)
	, m_nNum2(0)
	, m_nLimit(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}
void CArithDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Radio(pDX, IDC_ADD_RADIO, m_nRadio);
	DDX_Text(pDX, IDC_ANSWER_EDIT, m_nAnswer);
	DDV_MinMaxInt(pDX, m_nAnswer, 1, 9999);
	DDX_Text(pDX, IDC_NAME_EDIT, m_strName);
	DDV_MaxChars(pDX, m_strName, 10);
	DDX_Text(pDX, IDC_NUM1_EDIT, m_nNum1);
	DDX_Text(pDX, IDC_NUM2_EDIT, m_nNum2);
}
BEGIN_MESSAGE_MAP(CArithDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_COMMAND(ID_EXEC_RENEW, &CArithDlg::OnExecRenew)
	ON_COMMAND(ID_EXEC_CHANGELEVEL, &CArithDlg::OnExecChangelevel)
	ON_COMMAND(ID_EXEC_CHECK, &CArithDlg::OnExecCheck)
	ON_COMMAND(ID_EXIT_QUIT, &CArithDlg::OnExitQuit)
	ON_COMMAND(ID_EXIT_SAVEANDQUIT, &CArithDlg::OnExitSaveandquit)
	ON_BN_CLICKED(IDC_ADD_RADIO, &CArithDlg::OnBnClickedAddRadio)
END_MESSAGE_MAP()
BOOL CArithDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	// Add "About..." menu item to system menu.
	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);
	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}
	// Set the icon for this dialog. The framework does this automatically
	// when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE); // Set big icon
	SetIcon(m_hIcon, FALSE); // Set small icon
	// TODO: Add extra initialization here
	m_nLimit = 9; // 편집 - 추가
	m_nRadio = 0; // 편집 - 추가
	srand((int)time(NULL)); // 편집 - 추가
	m_nNum1 = 1 + rand() % m_nLimit; // 편집 - 추가
	m_nNum2 = 1 + rand() % m_nLimit; // 편집 - 추가
	UpdateData(FALSE); // 편집 - 추가
	return TRUE; // return TRUE unless you set the focus to a control
}
void CArithDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}
// If you add a minimize button to your dialog, you will need the code below
// to draw the icon. For MFC applications using the document/view model,
// this is automatically done for you by the framework.
void CArithDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting
		SendMessage(WM_ICONERASEBKGND,
			reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);
		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;
		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}
// The system calls this function to obtain the cursor to display while the user drags
// the minimized window.
HCURSOR CArithDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}
void CArithDlg::OnExecRenew()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다. 
	m_nNum1 = 1 + rand()%m_nLimit; // 편집 - 추가
	m_nNum2 = 1 + rand() % m_nLimit; // 편집 - 추가
	UpdateData(FALSE); // 편집 - 추가
}
void CArithDlg::OnExecChangelevel()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다. 
	m_nLimit = (9 + 99) - m_nLimit; // 편집 - 추가
}
void CArithDlg::OnExecCheck()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	int correct_answer; // 편집 - 추가
   // 편집 - 추가
	UpdateData(); // 편집 - 추가
	if (m_nRadio == 0) // 편집 - 추가
		correct_answer = m_nNum1 + m_nNum2; // 편집 - 추가
	else // 편집 - 추가
		correct_answer = m_nNum1 * m_nNum2; // 편집 - 추가
	   // 편집 - 추가
	if (m_nAnswer == correct_answer) // 편집 - 추가
		MessageBox(_T("Correct. Congratulations, ") + m_strName); // 편집 - 추가
	else // 편집 - 추가
		MessageBox(_T("Wrong. Try again, ") + m_strName); // 편집 - 추가
}
void CArithDlg::OnExitQuit()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다. 
	OnOK(); // 편집 - 추가
}
void CArithDlg::OnExitSaveandquit()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다. 
	OnOK(); // 편집 - 추가
}

void CArithDlg::OnBnClickedAddRadio()
{
	// TODO: Add your control notification handler code here
}
