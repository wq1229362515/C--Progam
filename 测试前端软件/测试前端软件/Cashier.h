

#pragma once


#include "Common.h"

class Cashier : public WindowImplBase{

public:
	Mysql* p_mysql;
	void Button_SELECT();						//��ȡ��Ʒ���Ƶ����ݿ��в�ѯ
	void Button_ADDGOODS();						//�����Ʒ���ۻ��б���
	virtual void Notify(TNotifyUI& msg);

protected:
	virtual CDuiString GetSkinFolder();			//xml�ļ���Ӧ��Ŀ¼
	virtual CDuiString GetSkinFile();           //xml�ļ������� 
	virtual LPCTSTR GetWindowClassName(void) const; //�����������

};
