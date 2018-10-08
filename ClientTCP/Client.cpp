#include "Client.h"
#include <WS2tcpip.h>
void main()
{
	long SUCCESSFUL;
	WSAData WinSockData;
	WORD DLLVERSION;

	DLLVERSION = MAKEWORD(2, 2);

	SUCCESSFUL = WSAStartup(DLLVERSION, &WinSockData);

	std::string RESPONSE;
	std::string CONVERTER;
	char MESSAGE[200];
	SOCKADDR_IN ADDRESS;
	
	SOCKET sock;
	sock = socket(AF_INET, SOCK_STREAM, NULL);
	inet_pton(AF_INET, "192.168.1.65", &(ADDRESS.sin_addr));
	ADDRESS.sin_family = AF_INET;
	ADDRESS.sin_port = htons(444);

	std::cout << "\n\tClient: Do you want to connect to this Server? (Y/N)" << std::endl;
	std::cin >> RESPONSE;

	RESPONSE[0] = tolower(RESPONSE[0]);

	if (RESPONSE == "n")
	{
		std::cout << "\n\tOK. quitting instead"<< std::endl;
	}
	else if (RESPONSE == "y")
	{
		connect(sock, (SOCKADDR*)&ADDRESS, sizeof(ADDRESS));
		SUCCESSFUL = recv(sock, MESSAGE, sizeof(MESSAGE), NULL);
		CONVERTER = MESSAGE;
		std::cout << "\n\tMEssage from Server:\n\n\t" << CONVERTER << std::endl;
	}
	else
	{
		std::cout << "\n\tThat was an inappropriate RESPONSE";
	}

	std::cout << "\n\n\t";
	system("PAUSE");
	exit(1);
}