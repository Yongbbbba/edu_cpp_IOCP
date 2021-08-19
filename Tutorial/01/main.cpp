#include "EchoServer.h"
#include <iostream>
#include <string>

const UINT16 SERVER_PORT = 11021;
const UINT16 MAX_CLIENT = 100;		//총 접속할수 있는 클라이언트 수

int main()
{
	EchoServer echoserver;

	//소켓을 초기화
	echoserver.InitSocket();

	//소켓과 서버 주소를 연결하고 등록 시킨다.
	echoserver.BindandListen(SERVER_PORT);

	echoserver.StartServer(MAX_CLIENT);

	printf("아무 키나 누를 때까지 대기합니다\n");
	while (true)
	{
		std::string inputCmd;
		std::getline(std::cin, inputCmd);

		if (inputCmd == "quit")
			break;
	}

	echoserver.DestroyThread();
	return 0;
}

