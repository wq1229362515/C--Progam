

#include "Cashier.h"


CDuiString Cashier::GetSkinFolder(){
	return _T("skin\\");
}
CDuiString Cashier::GetSkinFile(){

	return _T("Cashier.xml");
}
LPCTSTR Cashier::GetWindowClassName() const{
	return _T("DUIMainFrame");
}

void Cashier:: Notify(TNotifyUI& msg){
	//psender 在哪一个控件上所做的单机,获取一下他的名字

	CDuiString strName = msg.pSender->GetName();
	//msg.pSender->GetText()			获取到的是文本
	//sType 消息的类型
	//自己所封装的string类,自己已经重载过了比较的方式

	if (msg.sType ==_T("click")) {
		if (strName == _T("BTN_CLOSE")) {
			PostQuitMessage(0);
		}
		else if (strName == _T("BTN_MIN")) {
			//win32 系统命令的消息
			::SendMessage(m_hWnd, WM_SYSCOMMAND, SC_MINIMIZE, 0);
		}
		else if (strName == _T("Button_ADD")) {
			MessageBox(m_hWnd, _T("ADD"), _T("cashier"), IDOK);
		}
		else if (strName == _T("Button_SUB")) {
			MessageBox(m_hWnd, _T("ADD"), _T("cashier"), IDOK);
		}
		else if (strName == _T("Button_ENQUIRY")) {
			MessageBox(m_hWnd, _T("ADD"), _T("cashier"), IDOK);
		}
		else if (strName == _T("Button_CANCEL")) {
			MessageBox(m_hWnd, _T("ADD"), _T("cashier"), IDOK);
		}
		else if (strName == _T("Button_SELL")) {
			MessageBox(m_hWnd, _T("ADD"), _T("cashier"), IDOK);
		}
	}
}
void Cashier::Button_SELECT() {
	//1.获取商品名称	//强制的转换,基类转换成子类的方式
	CDuiString Good_Name = ((CEditUI*)m_PaintManager.FindControl(_T("EDIT_GOODSNAME")))->GetText();

	//2.构造sql语句
	//3.将商品剩余的个数显示到界面编辑框中
}