#pragma  once 


#include "Common.h"



class MainWnd : public WindowImplBase{

public:
	Mysql* p_mysql;
	virtual void Notify(TNotifyUI& msg);
	void Button_SELECT();
	void Button_INSERT();
	void Button_Delete();
protected:
	virtual CDuiString GetSkinFolder();
	virtual CDuiString GetSkinFile();
	virtual LPCTSTR GetWindowClassName(void) const;

};