

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
	//psender ����һ���ؼ��������ĵ���,��ȡһ����������

	CDuiString strName = msg.pSender->GetName();
	//msg.pSender->GetText()			��ȡ�������ı�
	//sType ��Ϣ������
	//�Լ�����װ��string��,�Լ��Ѿ����ع��˱Ƚϵķ�ʽ

	if (msg.sType ==_T("click")) {
		if (strName == _T("BTN_CLOSE")) {
			PostQuitMessage(0);
		}
		else if (strName == _T("BTN_MIN")) {
			//win32 ϵͳ�������Ϣ
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
	//1.��ȡ��Ʒ����	//ǿ�Ƶ�ת��,����ת��������ķ�ʽ
	CDuiString Good_Name = ((CEditUI*)m_PaintManager.FindControl(_T("EDIT_GOODSNAME")))->GetText();

	//2.����sql���
	//3.����Ʒʣ��ĸ�����ʾ������༭����
}