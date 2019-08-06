#if 0

#include <Windows.h>
#include <tchar.h>


//��Ϣ�ص�����,��Ϣ�����˾ͻ��ߵ���������
LRESULT CALLBACK WinProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message) //������Ϣ
	{
	case WM_CLOSE:
		//	���ڵľ��  NULL        _T  win32 Ĭ�ϲ���uleecode���뷽ʽ   
		if (IDOK == MessageBox(hWnd, _T("��ȷ���˳���"), _T("�˳�"), MB_OKCANCEL))
		{
			DestroyWindow(hWnd);
			return 0;
		}
	case WM_LBUTTONDOWN:
	{
						 //����           �Ի������
	   MessageBox(NULL, _T("Test"), _T("hello"), IDOK);
	   return 0;
						   
	}
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	default:


		//û�����ص���Ϣ,�ߵĶ���default
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
}



/*

	win32 �����winmain��ʼ
	Windows����������������ⲿ���¼������������仰˵�����򲻶ϵȴ����ȴ��κο��ܵ����룬Ȼ������ �жϣ������ʵ��Ĵ���
	���û���ⲿ�¼�������,����һ����������Ϊ
	
	�����ġ����롱���ɲ���ϵͳ���񵽺�����Ϣ����ʽ���͸�Ӧ�ó�����Ϣ����ʵ ����ϵͳ�����һ�����ݽṹ:
	typedef struct MSG {     
		HWND hwnd;//hwnd �Ǵ��ڵľ��������������������ĸ����ڹ��̺�������Ϣ���д���      
		UINT message;      //message��һ����Ϣ������������ʾ��Ϣ������      
		WPARAM wParam;     //32 λ�ĸ�����Ϣ�������ʾʲô���ݣ�Ҫ����Ϣ�����Ͷ���      
		LPARAM lParam;     //32 λ�ĸ�����Ϣ�������ʾʲô���ݣ�Ҫ����Ϣ�����Ͷ���   ����˵����,�ͻ�Ѱ�������ĸ����ʾ����      
		DWORD time;       //time ����Ϣ���͵�ʱ��      
		POINT pt;         //��Ϣ����ʱ������ڵ�λ�� 
	}

*/
int APIENTRY _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
	//Step1:ע��һ��������   
	HWND hwnd;
	//���ڵľ��  
	WNDCLASSEX wc;
	//������ṹ    
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.style = CS_VREDRAW | CS_HREDRAW;
	wc.lpszMenuName = 0;
		//ע��Ĵ��ڵ�����
	wc.lpszClassName = _T("Win32");
	wc.lpfnWndProc = WinProc;
	//��Ϣ�ص�����    
	wc.hInstance = hInstance;
	wc.hIcon = NULL;
	wc.hCursor = NULL;
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wc.cbWndExtra = 0;
	wc.cbClsExtra = 0;
	wc.hIconSm = NULL;
	RegisterClassEx(&wc);
	//ע�ᴰ��        
	//Step2:����һ������    ͨ��ע��ĺ����ſ��Դ��� 
	hwnd = CreateWindow(_T("Win32"),
		//���ڵ�������Ҳ�������������Զ���Ĵ����������        
		_T("hello win32"),
		//���ڵı���,���ڷ��        
		WS_OVERLAPPEDWINDOW, //����style 
		/*������Ļ�����Ͻ� ���ڵ����Ͻ�λ��
		
			���ε�����
			width,higth
		*/
		400, //����λ��x����   
		150, //����λ��y����    
		800, //���ڿ��     
		600, //���ڸ߶�    
		NULL, //�����ھ��      
		NULL, //�˵����      
		hInstance, //ʵ�����     
		NULL //��������     
		);
	if (!hwnd)    {
		return FALSE;
	}
	ShowWindow(hwnd, SW_SHOW); //��ʾ����    
	UpdateWindow(hwnd); //ˢ��


	//Step3:��Ϣѭ�� 
	MSG msg;
	/*
	  
		�̶��ķ���,��ǰ����Ϣ�ɷ���
		msg�ɷ�����Щ����


		1.ע�ᴰ����    ---> ϵͳ֪�����������
		2.��������	
		3.��ʾ����& ����
		4.��Ϣѭ��    ��Ҫ��һ�� ,�����ǹ̶���


	*/

	/*
		���ϵĴ���Ϣ��������ȡ��ȡ��Ϣ,û�еĻ���������
	
	*/
	while (GetMessage(&msg, NULL, 0, 0))
	{
		//������Ϣ
		TranslateMessage(&msg);
		//������Ϣ,���͸������ǵ���Ϣ�ص�����
		DispatchMessage(&msg);
	}


	return 0;
}
#endif


#pragma once
#include <UIlib.h>
using namespace DuiLib;

#ifdef _DEBUG
#   ifdef _UNICODE
#       pragma comment(lib, "DuiLib_ud.lib")
#   else
#       pragma comment(lib, "DuiLib_d.lib")
#   endif
#else
#   ifdef _UNICODE
#       pragma comment(lib, "DuiLib_u.lib")
#   else
#       pragma comment(lib, "DuiLib.lib")
#   endif
#endif

/*

	�Լ�д���� ,�̳���CWindowWnd,
	showMedal ��װ����Ϣѭ��


*/
//												֪ͨ
class CDuiFrameWnd : public CWindowWnd, public INotifyUI
{
public:
	//����,��д ���ô����������,
	virtual LPCTSTR GetWindowClassName() const { return _T("DUIMainFrame"); }
	//����һЩ��Ϣ:duilib �Լ��������װ����Ϣ
	virtual void  Notify(TNotifyUI& msg){
		if (msg.sType == _T("click")){
			if (msg.pSender->GetName() == _T("btnHello")){
				::MessageBox(NULL,_T("��������Ĵ�"),_T("��������"),NULL);
			}
		}
	}

	//�麯��,����һ����һ������
	virtual LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam)
	{
		LRESULT lRes = 0;

		if (uMsg == WM_CREATE)
		{
			m_PaintManager.Init(m_hWnd);

			CDialogBuilder builder;
			CControlUI* pRoot = builder.Create(_T("duilib.xml"), (UINT)0, NULL, &m_PaintManager);   // duilib.xml��Ҫ�ŵ�exeĿ¼��
			ASSERT(pRoot && "Failed to parse XML");

			m_PaintManager.AttachDialog(pRoot);
			m_PaintManager.AddNotifier(this);   // ��ӿؼ�����Ϣ��Ӧ��������Ϣ�ͻᴫ�ﵽduilib����Ϣѭ�������ǿ�����Notify����������Ϣ����

		}
		
		else if (uMsg == WM_NCACTIVATE){
			if (!::IsIconic(m_hWnd))
				return (wParam == 0) ? TRUE : FALSE;
		}
		else if (uMsg == WM_NCCALCSIZE){
			return 0;
		}
		else if (uMsg == WM_NCPAINT){
			return 0;
		}



		if (m_PaintManager.MessageHandler(uMsg, wParam, lParam, lRes))
		{
			return lRes;
		}

		return __super::HandleMessage(uMsg, wParam, lParam);
	}

protected:
	CPaintManagerUI m_PaintManager;
};

int APIENTRY _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
	CPaintManagerUI::SetInstance(hInstance);
	CPaintManagerUI::SetResourcePath(CPaintManagerUI::GetInstancePath());

	CDuiFrameWnd duiFrame;
	duiFrame.Create(NULL, _T("DUIWnd"), UI_WNDSTYLE_FRAME, WS_EX_WINDOWEDGE);
	duiFrame.CenterWindow();
	duiFrame.ShowModal();
	return 0;
}