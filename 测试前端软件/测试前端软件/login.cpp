#include"login.h"
#include "Mainwindow.h"
#include "Common.h"
#include "Cashier.h"

CDuiString LoginWnd::GetSkinFolder(){
	return _T("skin\\");
}
CDuiString LoginWnd::GetSkinFile(){
	return _T("login.xml");
}
LPCTSTR LoginWnd::GetWindowClassName() const{
	return _T("LogInWnd");
}

void LoginWnd::Notify(TNotifyUI& msg){

		
	if (msg.sType == _T("click")){
		if (msg.pSender->GetName() == _T("Button_CLOSE")){					//�رհ���
			PostQuitMessage(0);												//��������
		}																
		else if (msg.pSender->GetName() == _T("Button_MIN")){				//��С��
			::SendMessage(m_hWnd, WM_SYSCOMMAND, SC_MINIMIZE, 0);
			}
		else if (msg.pSender->GetName() == _T("Button_LOGIN")){
			Login();														//��¼
		}
	}
}
void LoginWnd::Login(){
	CEditUI* pEdituserName = (CEditUI*)m_PaintManager.FindControl(_T("Edit_Uer"));
	CDuiString strUserName = pEdituserName->GetText();

	CEditUI* pEdituserPassword = (CEditUI*)m_PaintManager.FindControl(_T("Edit_MI"));
	CDuiString strUserPassword = pEdituserPassword->GetText();


	if (strUserName.IsEmpty()){
		MessageBox(m_hWnd, _T("�������û���"), _T("Cashier"), IDOK);
		return;
	}
	if (strUserPassword.IsEmpty()){
		MessageBox(m_hWnd, _T("����������"), _T("Cashier"), IDOK);
		return;
	}

	//��ѯ���ݿ�,����û��Ƿ����
	string strSQL("select *from Employee where name='");
	strSQL += UnicodeToANSI(strUserName);
	strSQL += "';";

	vector <vector<string >> vRet = p_mysql->SelectDB(strSQL);

	if (vRet.empty()) {
		MessageBox(m_hWnd, _T("�û�������"), _T("Cashier"), IDOK);
		return;
	}
	string userpassword = UnicodeToANSI(strUserPassword);
	if (userpassword != vRet[0][4]) {
		MessageBox(m_hWnd, _T("�û����������"), _T("Cashier"), IDOK);
		return;
	}
	if (vRet[0][5] == "�ۻ�Ա") {					//�ۻ�Ա����
		DestroyWindow(m_hWnd);//����֮��͹رս���
		Cashier cashier;
		cashier.p_mysql = p_mysql;
		cashier.Create(NULL, _T("Cashier"), UI_WNDSTYLE_EX_FRAME, WS_EX_WINDOWEDGE);
		cashier.CenterWindow();
		cashier.ShowModal();
		
	}
	else{											//����Ա����
		DestroyWindow(m_hWnd);
		MainWnd mainwnd;
		mainwnd.p_mysql = p_mysql;
		mainwnd.Create(NULL, _T("MainWnd"), UI_WNDSTYLE_EX_FRAME, WS_EX_WINDOWEDGE);
		mainwnd.CenterWindow();
		mainwnd.ShowModal();
	}
}




