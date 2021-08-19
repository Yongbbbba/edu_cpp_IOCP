// Logic에 관한 것
#pragma once

#include "IOCPServer.h"

class EchoServer : public IOCPServer
{
public:
	virtual void OnClose() override
	{
		std::cout << "[OnClose] Client 연결 종료" << std::endl;
	}

	virtual void OnConnect() override 
	{
		std::cout << "[OnConnect] 클라이언트 접속" << std::endl;
	}

	virtual void OnReceive(stClientInfo* pClientInfo, const UINT32 size_, char* pData_) override
	{
		std::cout << "[OnReceive] bytes : " << size_ << " msg : " << pData_ << std::endl;
		
		// 클라이언트에게 받은 메세지를 에코한다.
		SendMsg(pClientInfo, pClientInfo->m_recvBuf, size_);
		BindRecv(pClientInfo);  //다시 낚시대를 던진다. 
	}
};
