// Logic에 관한 것
#pragma once

#include "IOCPServer.h"

class EchoServer : public IOCPServer
{
	virtual void OnClose() override
	{
		std::cout << "[OnClose] Client 연결 종료" << std::endl;
	}

	virtual void OnConnect() override 
	{
		std::cout << "[OnConnect] 클라이언트 접속" << std::endl;
	}

	virtual void OnReceive(const UINT32 size_, char* pData_) override 
	{
		std::cout << "[OnReceive] bytes : " << size_ << " msg : " << pData_ << std::endl;
	}
};
