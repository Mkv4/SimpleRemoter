// Manager.cpp: implementation of the CManager class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Manager.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CManager::CManager(IOCPClient* ClientObject)
{
	m_ClientObject = ClientObject;
	m_ClientObject->setManagerCallBack(this);  

	m_hEventDlgOpen = CreateEvent(NULL,TRUE,FALSE,NULL);
}

CManager::~CManager()
{
	if (m_hEventDlgOpen!=NULL)
	{
		CloseHandle(m_hEventDlgOpen);
		m_hEventDlgOpen = NULL;
	}
}

VOID CManager::WaitForDialogOpen()
{
	WaitForSingleObject(m_hEventDlgOpen, INFINITE);
	//�����Sleep,��ΪԶ�̴��ڴ�InitDialog�з���COMMAND_NEXT����ʾ��Ҫһ��ʱ��
	Sleep(150);
}

VOID CManager::NotifyDialogIsOpen()
{
	SetEvent(m_hEventDlgOpen);
}