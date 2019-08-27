#include"Mainwindow.h"
#include "Cashier.h"
#include "Common.h"

CDuiString MainWnd::GetSkinFolder(){
	return _T("skin\\");
}
CDuiString MainWnd::GetSkinFile(){
	//return _T("Cashier.xml");
	return _T("MainWnd.xml");
}
LPCTSTR MainWnd::GetWindowClassName() const{
	return _T("DUIMainFrame");
}

void MainWnd:: Notify(TNotifyUI& msg) {
	//CDuiString strName = msg.pSender->GetName();
	if (msg.sType == _T("click")){
		if (msg.pSender->GetName() == _T("BTN_CLOSE"))					//�رհ���
			PostQuitMessage(0);
		else if (msg.pSender->GetName() == _T("BTN_MIN")){				//��С��
			::SendMessage(m_hWnd, WM_SYSCOMMAND, SC_MINIMIZE, 0);
		}
		else if (msg.pSender->GetName() == _T("Button_SELECT")) {		//��ѯ
			Button_SELECT();
		}
		else if (msg.pSender->GetName() == _T("Button_INSERT")) {
			Button_INSERT();
		}
		else if (msg.pSender->GetName() == _T("Button_DROP")) {
			Button_Delete();
		}
	}
	else if (msg.sType == _T("selectchanged")) {
		//������ؼ�,������TABLAYOUT
		//���ص�ָ����,�����пؼ��Ļ���CControlUI						ucode��ʽ
		CTabLayoutUI *pTab = (CTabLayoutUI*)m_PaintManager.FindControl(_T("TABLAYOUT"));
		if (msg.pSender->GetName() == _T("BTN_EMP")) {
			//m_hwnd			��������
			//MessageBox(m_hWnd, _T("EMP"), _T("MAINWND"), NULL);
			//���ز�ͬ��ҳ��,����ѡ����
			//Ա���Ĳ�����0
			pTab->SelectItem(0);
		}
		else {
			//��Ʒ�������
			DestroyWindow(m_hWnd);
			Cashier cashier;
			cashier.Create(NULL, _T("Cashier"), UI_WNDSTYLE_EX_FRAME, WS_EX_WINDOWEDGE);
			cashier.CenterWindow();
			cashier.ShowModal();
		}
	}
}

//��ѯ����----ʵ�ֵ���ѡ��Ĳ�ѯ
void MainWnd::Button_SELECT() {
	
	string strSql("select *from employee");
	CDuiString combo_name = ((CComboBoxUI*)m_PaintManager.FindControl(_T("Combo_SELECT")))->GetText();
	//�����Ļ�����ȫ����ѯ
	//�����Ļ����ǰ���������н�ʷֱ��ѯ
	// select *from employee where name='����';

	if (combo_name == _T(""))
		strSql += ";";

	else if (combo_name == _T("����")) {
		CDuiString strName = ((CEditUI*)m_PaintManager.FindControl(_T("username")))->GetText();
		if (strName == _T("")) {
			MessageBox(m_hWnd,_T("�������û���"), _T("cashier"), IDOK);
			return;
		}
		strSql += " where name='";
		strSql += UnicodeToANSI(strName);
		strSql += "';";
	}
	else if (combo_name == _T("�Ա�")) {

	}
	else if (combo_name == _T("н��")) {

	}

	vector<vector<string>> vret = p_mysql->SelectDB(strSql);
	if (vret.empty())
		return;

	//��������˵��������,��Ҫ���뵽ҳ������
	CListUI* pList = (CListUI*)m_PaintManager.FindControl(_T("List_Employee"));
	if (pList != NULL) {
		pList->RemoveAll();
	}
	for (size_t i = 0; i < vret.size(); ++i) {
		vector<string>& strItem = vret[i];
		CListTextElementUI* pData = new CListTextElementUI;
		pData->SetAttribute(_T("align"), _T("center"));

		pList->Add(pData);

		pData->SetText(0, ANSIToUnicode(strItem[0]));
		pData->SetText(1, ANSIToUnicode(strItem[1]));
		pData->SetText(2, ANSIToUnicode(strItem[2]));
		pData->SetText(3, ANSIToUnicode(strItem[3]));
		pData->SetText(4, ANSIToUnicode(strItem[5]));
		pData->SetText(5, ANSIToUnicode(strItem[6]));
		pData->SetText(6, ANSIToUnicode(strItem[7]));
	}

}

//
void MainWnd::Button_INSERT() {
	CDuiString strName = ((CEditUI*)m_PaintManager.FindControl(_T("username")))->GetText();
	CDuiString strGender = ((CComboBoxUI*)m_PaintManager.FindControl(_T("Combo_sex")))->GetText();
	CDuiString strBirthday = ((CEditUI*)m_PaintManager.FindControl(_T("birthday")))->GetText();
	CDuiString strPosition = ((CComboBoxUI*)m_PaintManager.FindControl(_T("Combo_Position")))->GetText();
	CDuiString strNumber = ((CEditUI*)m_PaintManager.FindControl(_T("phone_number")))->GetText();
	CDuiString strSalary = ((CEditUI*)m_PaintManager.FindControl(_T("slary")))->GetText();

	//�����ʱ���ѯһ��,�ж�����Ȼ����뵽���һ��
	CListUI* pListUI = (CListUI*)m_PaintManager.FindControl(_T("List_Employee"));
	char szcount[32] = { 0 };
	//�������ݱ��ַ���
	//		���ε�����			���յ�����  �����Ƶ����� 
	_itoa(pListUI->GetCount() + 1, szcount, 10);
	string strSql("insert into employee values(");
	//Ա����ID����
	strSql += szcount;
	strSql += ",'";
	strSql += UnicodeToANSI(strName);
	strSql += "','";
	strSql += UnicodeToANSI(strGender);
	strSql += "','";
	strSql += UnicodeToANSI(strBirthday);
	strSql += "','0','";
	strSql += UnicodeToANSI(strPosition);
	strSql += "','";
	strSql += UnicodeToANSI(strNumber);
	strSql += "','";
	strSql += UnicodeToANSI(strSalary);
	strSql += "');";

	//�������ݿ���
	p_mysql->Insert(strSql);

	//Ա����Ϣ���뵽List��
	CListTextElementUI* pItem = new CListTextElementUI;
	pListUI->Add(pItem);
	pItem->SetText(0, strName);
	pItem->SetText(1, strGender);
	pItem->SetText(2, strBirthday);
	pItem->SetText(3, strPosition);
	pItem->SetText(4, strNumber);
	pItem->SetText(5, strSalary);

}

void MainWnd::Button_Delete() {

	//����ҳ��ɾ����һ��
	//���ݿ���ȥɾ��
	//��ȡ��ǰѡ��
	string mySql("delete ");
	CListUI* pList = (CListUI*)m_PaintManager.FindControl(_T("List_Employee"));
	int line = pList->GetCurSel();	//��ȡ��ǰѡ��,���ص����к�

	//��ȡ����ĳһ�е���һ������
	CListTextElementUI* pItem = (CListTextElementUI*)pList->GetItemAt(line);
	
	//�����ݿ��н���Ա����Ϣɾ����
	//������ֺ����к�
	//��Ӧ�������
	//p_mysql->Delete(mySql);


	//�õ�ĳһ�е�����
	CDuiString strName = pItem->GetText(0);

	//ɾ����ĳһ��
	pList->RemoveAt(line);
}