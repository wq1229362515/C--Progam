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
		else if (msg.pSender->GetName() == _T("Button_UPDATE")) {
			Button_Update();
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
	else if (msg.sType == _T("itemclick")) {

		//MessageBox(m_hWnd, _T("ADD"), _T("domain"), IDOK);
		//ѡ���б��е�ĳһ��,������Դ�ӡ�������ѡ����ȥ
		//Iltemselect();
		//CListUI* pList = (CListUI*)m_PaintManager.FindControl(_T("List_Employee"));
		//int line = pList->GetCurSel();	//��ȡ��ǰѡ��,���ص����к�
		//CListTextElementUI* pItem = (CListTextElementUI*)pList->GetItemAt(line);			//ѡ�е��кŵ�����
		//CDuiString* strName = (CDuiString*)m_PaintManager.FindControl(pItem->GetText(0));
		
	}
}
void MainWnd::Iltemselect() {

	
	CListUI* pList = (CListUI*)m_PaintManager.FindControl(_T("List_Employee"));
	int line = pList->GetCurSel();	//��ȡ��ǰѡ��,���ص����к�
	CListTextElementUI* pItem = (CListTextElementUI*)pList->GetItemAt(line);			//ѡ�е��кŵ�����
	CDuiString* strName = (CDuiString*)m_PaintManager.FindControl(pItem->GetText(0));

	m_PaintManager.FindControl(_T("username"))->SetText(pItem->GetText(1));				//����
	//m_PaintManager.FindControl(_T(""))->SetText(pItem->GetText(2));					//�Ա�	
	m_PaintManager.FindControl(_T("birthday"))->SetText(pItem->GetText(3));				//����
	//m_PaintManager.FindControl(_T(""))->SetText(pItem->GetText(4));					//��λ
	m_PaintManager.FindControl(_T("phone_number"))->SetText(pItem->GetText(5));			//�绰
	m_PaintManager.FindControl(_T("slary"))->SetText(pItem->GetText(6));				//нˮ



	

}


//��ѯ����----ʵ�ֵ���ѡ��Ĳ�ѯ
void MainWnd::Button_SELECT() {
	
	string strSql("select *from employee");
	CDuiString combo_name = ((CComboBoxUI*)m_PaintManager.FindControl(_T("Combo_SELECT")))->GetText();
	//�����Ļ�����ȫ����ѯ
	//�����Ļ����ǰ���������н�ʷֱ��ѯ
	// select *from employee where name='����';

	if (combo_name == _T("�����ѯ"))
		strSql += ";";

	else if (combo_name == _T("����")) {
		CDuiString strName = ((CEditUI*)m_PaintManager.FindControl(_T("username")))->GetText();
		if (strName == _T("")) {
			MessageBox(m_hWnd,_T("������Ա������"), _T("Ա����ѯ"), IDOK);
			return;
		}
		strSql += " where name='";
		strSql += UnicodeToANSI(strName);
		strSql += "';";
	}
	else if (combo_name == _T("�Ա�")) {
		CDuiString strGender = ((CComboBoxUI*)m_PaintManager.FindControl(_T("Combo_sex")))->GetText();
		strSql += " where Gender='";
		strSql += UnicodeToANSI(strGender);
		strSql += "';";
	}
	else if (combo_name == _T("н��")) {
		CDuiString strGender = ((CComboBoxUI*)m_PaintManager.FindControl(_T("slary")))->GetText();
		strSql += " where Salary='";
		strSql += UnicodeToANSI(strGender);
		strSql += "';";
	}

	vector<vector<string>> vret = p_mysql->SelectDB(strSql);
	if (vret.empty()) {
		MessageBox(m_hWnd, _T("�޲�ѯ���!"), _T("�û���ѯ"), IDOK);
		CListUI* pList = (CListUI*)m_PaintManager.FindControl(_T("List_Employee"));
		pList->RemoveAll();
		return;
	}
		

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
	//ÿ�β�ѯ��Ͼ����������
	vret.clear();
}

//
void MainWnd::Button_INSERT() {

	//CDuiString strId = ((CEditUI*)m_PaintManager.FindControl(_T("")))->GetText();
	CDuiString strName = ((CEditUI*)m_PaintManager.FindControl(_T("username")))->GetText();
	CDuiString strGender = ((CComboBoxUI*)m_PaintManager.FindControl(_T("Combo_sex")))->GetText();
	CDuiString strBirthday = ((CEditUI*)m_PaintManager.FindControl(_T("birthday")))->GetText();
	CDuiString strPosition = ((CComboBoxUI*)m_PaintManager.FindControl(_T("Combo_Position")))->GetText();
	CDuiString strNumber = ((CEditUI*)m_PaintManager.FindControl(_T("phone_number")))->GetText();
	CDuiString strSalary = ((CEditUI*)m_PaintManager.FindControl(_T("slary")))->GetText();
	
	if (strName.IsEmpty() || strGender.IsEmpty() || strBirthday.IsEmpty() ||
		strPosition.IsEmpty() || strNumber.IsEmpty() || strSalary.IsEmpty()) {
		MessageBox(m_hWnd, _T("�뽫Ҫ����Ա��������������"), _T("����Ա��"), IDOK);
		return;
	}

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

	//Ա����Ϣ���뵽List��,�´���һ���б�����޸Ĳ���
	CListTextElementUI* pItem = new CListTextElementUI;
	pListUI->Add(pItem);
	pItem->SetText(1, strName);
	pItem->SetText(2, strGender);
	pItem->SetText(3, strBirthday);
	pItem->SetText(4, strPosition);
	pItem->SetText(5, strNumber);
	pItem->SetText(6, strSalary);

	m_PaintManager.FindControl(_T("username"))->SetText(_T(""));
}

void MainWnd::Button_Delete() {

	//����ҳ��ɾ����һ��
	//���ݿ���ȥɾ��
	//��ȡ��ǰѡ��
	// delete from employee where name='����'and id='6';
	
	CListUI* pList = (CListUI*)m_PaintManager.FindControl(_T("List_Employee"));
	int line = pList->GetCurSel();	//��ȡ��ǰѡ��,���ص����к�
	//��ȡ����ĳһ�е���һ����Ϣ
	CListTextElementUI* pItem = (CListTextElementUI*)pList->GetItemAt(line);
	if (pItem == NULL) {
		MessageBox(m_hWnd, _T("��ѡ��Ҫ�޸ĵ���Ա"), _T("�û�ɾ��"), IDOK);
		return;
	}
	if (pItem->GetText(0) == NULL) {
		MessageBox(m_hWnd, _T("��ѡ��Ҫ�޸ĵ���Ա"), _T("�û�ɾ��"), IDOK);
		return;
	}
	if (pItem->GetText(0) != NULL) {
		if (IDCANCEL == MessageBox(m_hWnd,_T("ȷ��ɾ��?"),_T("�û�ɾ��"),IDOK))
			return;
	}
	//�����ݿ��н���Ա����Ϣɾ����
	string mySql("delete from employee where name='");
	mySql += UnicodeToANSI(pItem->GetText(1));
	mySql += "'and id='";
	mySql += UnicodeToANSI(pItem->GetText(0));
	mySql += "';";
	p_mysql->Delete(mySql);

	//�õ�ĳһ�е�����
	//CDuiString strName = pItem->GetText(0);

	//ɾ����ĳһ��
	pList->RemoveAt(line);
}
void MainWnd::Button_Update() {
	CListUI* pList = (CListUI*)m_PaintManager.FindControl(_T("List_Employee"));
	int line = pList->GetCurSel();	//��ȡ��ǰѡ��,���ص����к�
	CListTextElementUI* pItem = (CListTextElementUI*)pList->GetItemAt(line);			//ѡ�е��кŵ�����
	if (line == -1	&& pItem != NULL) {
		MessageBox(m_hWnd, _T("��ѡ��Ҫ�޸ĵ���Ա"), _T("�û�����"), IDOK);
		return;
	}
	if (pItem->GetText(line) == NULL)  {
		MessageBox(m_hWnd, _T("��ѡ��Ҫ�޸ĵ���Ա"), _T("�û�����"), IDOK);
		return;
	}
	//����Ҫ�޸ĵĲ���,�������޸�,���޸ĵ�ҳ���ϵ���Ϣ,�ٶ����ݿ��е���Ϣ�����޸�
	//��List��ѡ��Ҫ�޸ĵ���,�ٽ�edit�б仯�Ĳ���,����List�ؼ��Ĳ�����,�����޸�
		//��ȡ����ĳһ�е���һ����Ϣ

	CDuiString strId = pItem->GetText(0);
	CDuiString strName = ((CEditUI*)m_PaintManager.FindControl(_T("username")))->GetText();
	CDuiString strGender = ((CComboBoxUI*)m_PaintManager.FindControl(_T("Combo_sex")))->GetText();
	CDuiString strBirthday = ((CEditUI*)m_PaintManager.FindControl(_T("birthday")))->GetText();
	CDuiString strPosition = ((CComboBoxUI*)m_PaintManager.FindControl(_T("Combo_Position")))->GetText();
	CDuiString strNumber = ((CEditUI*)m_PaintManager.FindControl(_T("phone_number")))->GetText();
	CDuiString strSalary = ((CEditUI*)m_PaintManager.FindControl(_T("slary")))->GetText();

	if (strName.IsEmpty() || strGender.IsEmpty() || strBirthday.IsEmpty() ||
		strPosition.IsEmpty() || strNumber.IsEmpty() || strSalary.IsEmpty()) {
		MessageBox(m_hWnd, _T("�뽫Ҫ���µ�������������"), _T("�û�����"), IDOK);
		return;
	}


	pItem->SetText(1, strName);
	pItem->SetText(2, strGender);
	pItem->SetText(3, strBirthday);
	pItem->SetText(4, strPosition);
	pItem->SetText(5, strNumber);
	pItem->SetText(6, strSalary);

	//UPDATE exam_result SET shuxue = 60, yuwen = 70 WHERE name = '���ϵ�'; 
	//id   | name   | gender | birthday   | password | position     | telphone    | salary  |
	string mySql("update employee set name='");
	mySql += UnicodeToANSI(strName);
	mySql += "',gender='";
	mySql += UnicodeToANSI(strGender);
	mySql += "',birthday='";
	mySql += UnicodeToANSI(strBirthday);
	mySql += "',position='";
	mySql += UnicodeToANSI(strPosition);
	mySql += "',telphone='";
	mySql += UnicodeToANSI(strNumber);
	mySql += "',salary='";
	mySql += UnicodeToANSI(strSalary);
	mySql += "' where id='";
	mySql += UnicodeToANSI(strId);
	mySql += "';";
	p_mysql->Update(mySql);

	m_PaintManager.FindControl(_T("username"))->SetText(_T(""));
}


