#pragma  once

#include "Common.h"

class LoginWnd : public WindowImplBase{

public:
	Mysql *p_mysql;
	virtual void Notify(TNotifyUI& msg);
	void Login();						//ע�ᰴ������֮����Ӧ���¼�

protected:
	virtual CDuiString GetSkinFolder();			//xml�ļ���Ӧ��Ŀ¼
	virtual CDuiString GetSkinFile();           //xml�ļ������� 
	virtual LPCTSTR GetWindowClassName(void) const; //�����������

};
