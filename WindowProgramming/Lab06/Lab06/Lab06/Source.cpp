#include <afxwin.h>
#define IDB_BUTTON0 100
#define IDB_BUTTON1 101
#define IDB_BUTTON2 102
#define IDB_BUTTON3 103
#define IDB_BUTTON4 104
#define IDB_BUTTON5 105
#define IDB_BUTTON6 106
#define IDB_BUTTON7 107
#define IDB_BUTTON8 108 //����ؾ� �� ��ư���� ID�� ���ϴµ� 9���� ��ư�̹Ƿ�, 100~108�� ���� �ǹ��ϵ��� ��ũ�θ� �����Ѵ�.
enum { OFF, ON };

// Declare the application class
class CToggleApp : public CWinApp {
public:
	virtual BOOL InitInstance();
};

// Create an instance of the application class
CToggleApp ToggleApp;

// Declare the main window class
class CToggleWindow : public CFrameWnd {
	CButton* button[9]; //��ư�� 9���̹Ƿ� ������ �迭 ũ�Ⱑ 8�̸� �� ������, ũ��� 9�� �����Ѵ�. 
	int status[9]; //��ư �����͹迭 ���� ���� ��ư�� ���ȴ���, �ƴ����� ���¸� ��Ÿ���� ���� �迭 status �� �����Ѵ�.
	void init();
public:
	CToggleWindow();
	afx_msg void HandleButton0();
	afx_msg void HandleButton1();
	afx_msg void HandleButton2();
	afx_msg void HandleButton3();
	afx_msg void HandleButton4();
	afx_msg void HandleButton5();
	afx_msg void HandleButton6();
	afx_msg void HandleButton7();
	afx_msg void HandleButton8(); //�� ��ư���� ������ �� ����Ǵ� �Լ��� �����Ѵ�.
	void HandleButton(int _iK);
	DECLARE_MESSAGE_MAP();
};

// the InitInstance function is called once
// when the application first executes
	BOOL CToggleApp::InitInstance()
	{
		m_pMainWnd = new CToggleWindow();
		m_pMainWnd->ShowWindow(m_nCmdShow);
		m_pMainWnd->UpdateWindow();
		return TRUE;
	}

	// the message map
	BEGIN_MESSAGE_MAP(CToggleWindow, CFrameWnd)
		ON_BN_CLICKED(IDB_BUTTON0, HandleButton0)
		ON_BN_CLICKED(IDB_BUTTON1, HandleButton1)
		ON_BN_CLICKED(IDB_BUTTON2, HandleButton2)
		ON_BN_CLICKED(IDB_BUTTON3, HandleButton3)
		ON_BN_CLICKED(IDB_BUTTON4, HandleButton4)
		ON_BN_CLICKED(IDB_BUTTON5, HandleButton5)
		ON_BN_CLICKED(IDB_BUTTON6, HandleButton6)
		ON_BN_CLICKED(IDB_BUTTON7, HandleButton7)
		ON_BN_CLICKED(IDB_BUTTON8, HandleButton8) //�� ��ư�� Ŭ���Ǿ�����, � �Լ��� ����� ������ ON_BN_CLIKED ��ũ�� �Լ��� �ִ´�.
	END_MESSAGE_MAP()
	void CToggleWindow::init()
	{	for(int i=0;i<9;i++) //ó�� ��ư�� ���¸� �� -1�� �����Ͽ� , ǥ�ð� ���ٴ� ������ status�� �̴ϼȶ��������ش�.
			status[i] = -1; 
	}

	// the contructor for the window class
	CToggleWindow::CToggleWindow()
	{
		//Create the window itself
			Create(NULL, _T("Tic-Tac-Toe"),//��ܹ��� �۾��� Tic-Tac_Toe�� �����Ѵ�.
				WS_OVERLAPPEDWINDOW,
				CRect(0, 0, 300, 200));
			init();
			int k = 0;// button�� index�� �����ϱ� ���� ������ ���� k. �ʱⰪ 0
			for (int i = 0; i <3; i++)//CRect(a,b,c,d)�� �Ѵٸ�, a,c�� ��ġ���� �����ϱ� ���� loop
			{
				for (int j = 0; j < 3; j++)//b,d���� �����ϱ� ���� innerloop
				{
					// Create button
					button[k] = new CButton();
					button[k]->Create(_T(""), //button�� �ʱ� �ؽ�Ʈ ���¸� �� ���·� �����.
						WS_CHILD | WS_VISIBLE |
						BS_PUSHBUTTON,
						CRect(6 + i * 30, 6 + j * 30, 34 + i * 30, 34 + j * 30),
						this,
						100+k); //button�� id�� 100,101..�� �����Ͽ����Ƿ� 100+k�� �Է��Ͽ� ��ư�� �����Ѵ�.
					k++;
				}

		}
	}

	void  CToggleWindow::HandleButton(int _iK)
	{
		if (status[_iK] == ON) { //��ư�� X ���¶�� 
			button[_iK]->SetWindowText(_T("O")); //O�� �ؽ�Ʈ�� �ٲ۴�
			status[_iK] = OFF;
			MessageBeep(-1); //����� �߻�(��ư�� �̹� �ؽ�Ʈ�� �־����ִ� �����̱� ����
		}
		else if(status[_iK]==OFF) //��ư�� O ���¶��
		{
			button[_iK]->SetWindowText(_T("X")); //X�� �ؽ�Ʈ�� �ٲ۴�.
			status[_iK] = ON;
			MessageBeep(-1); 
		}
		else //��ư�� �ƹ� text�� �Էµ����� �ʴ� ���¶��
		{
			button[_iK]->SetWindowText(_T("X")); 
			status[_iK] = ON;
		}
	}

	// message handler function for number buttons
	void CToggleWindow::HandleButton0() //�� ��ư���� ������ �� ����Ǵ� �Լ�
	{	
		HandleButton(0); 
	}
	void CToggleWindow::HandleButton1()
	{
		HandleButton(1); 
	}
	void CToggleWindow::HandleButton2()
	{
		HandleButton(2);
	}
	void CToggleWindow::HandleButton3()
	{
		HandleButton(3);
	}
	void CToggleWindow::HandleButton4()
	{
		HandleButton(4);
	}
	void CToggleWindow::HandleButton5()
	{
		HandleButton(5);
	}
	void CToggleWindow::HandleButton6()
	{
		HandleButton(6);
	}
	void CToggleWindow::HandleButton7()
	{
		HandleButton(7);
	}
	void CToggleWindow::HandleButton8()
	{
		HandleButton(8);
	}
