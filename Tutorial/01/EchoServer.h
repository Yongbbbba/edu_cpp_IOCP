// Logic�� ���� ��
#pragma once

#include "IOCPServer.h"

class EchoServer : public IOCPServer
{
public:
	virtual void OnClose() override
	{
		std::cout << "[OnClose] Client ���� ����" << std::endl;
	}

	virtual void OnConnect() override 
	{
		std::cout << "[OnConnect] Ŭ���̾�Ʈ ����" << std::endl;
	}

	virtual void OnReceive(stClientInfo* pClientInfo, const UINT32 size_, char* pData_) override
	{
		std::cout << "[OnReceive] bytes : " << size_ << " msg : " << pData_ << std::endl;
		
		// Ŭ���̾�Ʈ���� ���� �޼����� �����Ѵ�.
		SendMsg(pClientInfo, pClientInfo->m_recvBuf, size_);
		BindRecv(pClientInfo);  //�ٽ� ���ô븦 ������. 
	}
};
