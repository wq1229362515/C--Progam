

#include "Cashier.h"

#include <vector>

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
			Button_SELECT();
		}
		else if (strName == _T("Button_CANCEL")) {
			MessageBox(m_hWnd, _T("ADD"), _T("cashier"), IDOK);
		}
		else if (strName == _T("Button_SELL")) {
			MessageBox(m_hWnd, _T("ADD"), _T("cashier"), IDOK);
		}
		else if (strName == _T("Button_ADDGOODS")) {
			Button_ADDGOODS();
		}
	}
}
void Cashier::Button_SELECT() {
	//1.��ȡ��Ʒ����	//ǿ�Ƶ�ת��,����ת��������ķ�ʽ
	CDuiString str_GoodsName = ((CEditUI*)m_PaintManager.FindControl(_T("EDIT_GoodsName")))->GetText();
	//select* from Goods where GoodsName='ơ��';
	//2.����sql���
	string strSql("select *from Goods where GoodsName='");
	strSql += UnicodeToANSI(str_GoodsName);
	strSql += "';";
	
	//����Ʒ����Ϣ��ʾ������༭����
	vector<vector<string>> vret = p_mysql->SelectDB(strSql);
	if (vret.empty()) {
		MessageBox(m_hWnd, _T("�޲�ѯ���!"), _T("�û���ѯ"), IDOK);
		CListUI* pList = (CListUI*)m_PaintManager.FindControl(_T("List_Goods"));
		pList->RemoveAll();
		return;
	}

	////3.����Ʒʣ��ĸ�����ʾ������༭����
	////����һ�������������ָ���
	//CListUI* pList = (CListUI*)m_PaintManager.FindControl(_T("List_Goods"));
	////ѭ�����ÿһ�е�����


	//vector<string>& strItem = vret[0];
	//CListTextElementUI* pData = new CListTextElementUI;
	//pData->SetAttribute(_T("align"), _T("center"));

	//pList->Add(pData);
	// 0		1			2				3			4				5    6		7			8
	//ID	    ����		����		��������		��������	�۸�    ��λ	�����		����ֵ
	// GoodsID | GoodsName | GoodsType | ProductDate | DeadDate   | Price | Unit | Inventory | AlarmValye
	//pData->SetText(0, ANSIToUnicode(strItem[0]));		//���
	//pData->SetText(1, ANSIToUnicode(strItem[1]));		//����
	//pData->SetText(2, ANSIToUnicode(strItem[5]));		//�۸�
	//pData->SetText(3, ANSIToUnicode(strItem[7]));		//����
	//pData->SetText(4, ANSIToUnicode(strItem[6]));		//��λ
	//pData->SetText(5, ANSIToUnicode(strItem[6]));		//�ܼ�
	m_PaintManager.FindControl(_T("EDIT_Inventory"))->SetText(ANSIToUnicode(vret[0][7]));

	//���ʣ����µ�
}
void Cashier::Button_ADDGOODS() {
	//1.��ȡ��Ʒ����	//ǿ�Ƶ�ת��,����ת��������ķ�ʽ
	CDuiString str_GoodsName = ((CEditUI*)m_PaintManager.FindControl(_T("EDIT_GoodsName")))->GetText();
	//select* from Goods where GoodsName='ơ��';
	//2.����sql���
	string strSql("select *from Goods where GoodsName='");
	strSql += UnicodeToANSI(str_GoodsName);
	strSql += "';";

	//����Ʒ����Ϣ��ʾ������༭����
	vector<vector<string>> vret = p_mysql->SelectDB(strSql);
	if (vret.empty()) {
		MessageBox(m_hWnd, _T("�޲�ѯ���!"), _T("�û���ѯ"), IDOK);
		CListUI* pList = (CListUI*)m_PaintManager.FindControl(_T("List_Goods"));
		pList->RemoveAll();
		return;
	}

	//3.����Ʒʣ��ĸ�����ʾ������༭����
	//����һ�������������ָ���
	CListUI* pList = (CListUI*)m_PaintManager.FindControl(_T("List_Goods"));
	//����б��������ݾ����
	//ѭ�����ÿһ�е�����

	for (size_t i = 0; i < vret.size(); ++i) {
		vector<string>& strItem = vret[i];
		CListTextElementUI* pData = new CListTextElementUI;
		pData->SetAttribute(_T("align"), _T("center"));

		pList->Add(pData);
		// 0		1			2				3			4				5    6		7			8
		//ID	    ����		����		��������		��������	�۸�    ��λ	�����		����ֵ
		// GoodsID | GoodsName | GoodsType | ProductDate | DeadDate   | Price | Unit | Inventory | AlarmValye
		pData->SetText(0, ANSIToUnicode(strItem[0]));		//���
		pData->SetText(1, ANSIToUnicode(strItem[1]));		//����
		pData->SetText(2, ANSIToUnicode(strItem[5]));		//�۸�
		pData->SetText(3, ANSIToUnicode(strItem[7]));		//����
		pData->SetText(4, ANSIToUnicode(strItem[6]));		//��λ
		//pData->SetText(5, ANSIToUnicode(strItem[6]));		//�ܼ�
		m_PaintManager.FindControl(_T("EDIT_Inventory"))->SetText(ANSIToUnicode(strItem[7]));
	}
	//���ʣ����µ�;

}