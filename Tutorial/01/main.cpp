#include "EchoServer.h"
#include <iostream>
#include <string>

const UINT16 SERVER_PORT = 11021;
const UINT16 MAX_CLIENT = 100;		//�� �����Ҽ� �ִ� Ŭ���̾�Ʈ ��

int main()
{
	EchoServer echoserver;

	//������ �ʱ�ȭ
	echoserver.InitSocket();

	//���ϰ� ���� �ּҸ� �����ϰ� ��� ��Ų��.
	echoserver.BindandListen(SERVER_PORT);

	echoserver.StartServer(MAX_CLIENT);

	printf("�ƹ� Ű�� ���� ������ ����մϴ�\n");
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

