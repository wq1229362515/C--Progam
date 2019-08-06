#if 0

#include <Windows.h>
#include <tchar.h>


//消息回调函数,消息触发了就会走到函数里面
LRESULT CALLBACK WinProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message) //捕获消息
	{
	case WM_CLOSE:
		//	窗口的句柄  NULL        _T  win32 默认采用uleecode编码方式   
		if (IDOK == MessageBox(hWnd, _T("你确定退出？"), _T("退出"), MB_OKCANCEL))
		{
			DestroyWindow(hWnd);
			return 0;
		}
	case WM_LBUTTONDOWN:
	{
						 //内容           对话框标题
	   MessageBox(NULL, _T("Test"), _T("hello"), IDOK);
	   return 0;
						   
	}
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	default:


		//没有拦截的消息,走的都是default
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
}



/*

	win32 程序从winmain开始
	Windows程序的运行是依靠外部的事件来驱动。换句话说，程序不断等待，等待任何可能的输入，然后做出 判断，再做适当的处理。
	如果没有外部事件来触动,就是一个阻塞的行为
	
	上述的“输入”是由操作系统捕获到后，以消息的形式发送给应用程序。消息，其实 就是系统内设的一种数据结构:
	typedef struct MSG {     
		HWND hwnd;//hwnd 是窗口的句柄，这个参数将决定由哪个窗口过程函数对消息进行处理      
		UINT message;      //message是一个消息常量，用来表示消息的类型      
		WPARAM wParam;     //32 位的附加信息，具体表示什么内容，要视消息的类型而定      
		LPARAM lParam;     //32 位的附加信息，具体表示什么内容，要视消息的类型而定   比如说按键,就会把按键的字母给表示出来      
		DWORD time;       //time 是消息发送的时间      
		POINT pt;         //消息发送时鼠标所在的位置 
	}

*/
int APIENTRY _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
	//Step1:注册一个窗口类   
	HWND hwnd;
	//窗口的句柄  
	WNDCLASSEX wc;
	//窗口类结构    
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.style = CS_VREDRAW | CS_HREDRAW;
	wc.lpszMenuName = 0;
		//注册的窗口的名字
	wc.lpszClassName = _T("Win32");
	wc.lpfnWndProc = WinProc;
	//消息回调函数    
	wc.hInstance = hInstance;
	wc.hIcon = NULL;
	wc.hCursor = NULL;
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wc.cbWndExtra = 0;
	wc.cbClsExtra = 0;
	wc.hIconSm = NULL;
	RegisterClassEx(&wc);
	//注册窗口        
	//Step2:创建一个窗口    通过注册的函数才可以创建 
	hwnd = CreateWindow(_T("Win32"),
		//窗口的类名，也就是上面我们自定义的窗口类的名字        
		_T("hello win32"),
		//窗口的标题,窗口风格        
		WS_OVERLAPPEDWINDOW, //窗口style 
		/*基于屏幕的左上角 窗口的左上角位置
		
			矩形的区域
			width,higth
		*/
		400, //窗口位置x坐标   
		150, //窗口位置y坐标    
		800, //窗口宽度     
		600, //窗口高度    
		NULL, //父窗口句柄      
		NULL, //菜单句柄      
		hInstance, //实例句柄     
		NULL //创建数据     
		);
	if (!hwnd)    {
		return FALSE;
	}
	ShowWindow(hwnd, SW_SHOW); //显示窗口    
	UpdateWindow(hwnd); //刷新


	//Step3:消息循环 
	MSG msg;
	/*
	  
		固定的方法,当前的消息派发给
		msg派发给这些函数


		1.注册窗口类    ---> 系统知道有这个窗口
		2.创建窗口	
		3.显示窗口& 更新
		4.消息循环    重要的一步 ,但是是固定的


	*/

	/*
		不断的从消息队列里面取获取消息,没有的话就阻塞了
	
	*/
	while (GetMessage(&msg, NULL, 0, 0))
	{
		//处理消息
		TranslateMessage(&msg);
		//发送消息,发送给了我们的消息回调函数
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

	自己写的类 ,继承自CWindowWnd,
	showMedal 封装了消息循环


*/
//												通知
class CDuiFrameWnd : public CWindowWnd, public INotifyUI
{
public:
	//重载,重写 设置窗口类的名称,
	virtual LPCTSTR GetWindowClassName() const { return _T("DUIMainFrame"); }
	//捕获一些消息:duilib 自己在里面封装的消息
	virtual void  Notify(TNotifyUI& msg){
		if (msg.sType == _T("click")){
			if (msg.pSender->GetName() == _T("btnHello")){
				::MessageBox(NULL,_T("来给出你的答案"),_T("今日青年"),NULL);
			}
		}
	}

	//虚函数,基类一定有一个方法
	virtual LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam)
	{
		LRESULT lRes = 0;

		if (uMsg == WM_CREATE)
		{
			m_PaintManager.Init(m_hWnd);

			CDialogBuilder builder;
			CControlUI* pRoot = builder.Create(_T("duilib.xml"), (UINT)0, NULL, &m_PaintManager);   // duilib.xml需要放到exe目录下
			ASSERT(pRoot && "Failed to parse XML");

			m_PaintManager.AttachDialog(pRoot);
			m_PaintManager.AddNotifier(this);   // 添加控件等消息响应，这样消息就会传达到duilib的消息循环，我们可以在Notify函数里做消息处理

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