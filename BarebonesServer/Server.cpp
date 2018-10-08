#include "Server.h"
#include <WS2tcpip.h>
#define _WINSOCK_DEPRECATED_NO_WARINGS
void main()
{
	long SUCCESSFUL;
	WSAData WinSockData;
	WORD DLLVERSION;

	DLLVERSION = MAKEWORD(2, 2);

	SUCCESSFUL = WSAStartup(DLLVERSION, &WinSockData);

	SOCKADDR_IN ADDRESS;
	int AddressSize = sizeof(ADDRESS);

	SOCKET sock_LISTEN;
	SOCKET sock_CONNECTION;
	sock_CONNECTION = socket(AF_INET, SOCK_STREAM, NULL);
	inet_pton(AF_INET, "192.168.1.65", &(ADDRESS.sin_addr));
	ADDRESS.sin_family = AF_INET;
	ADDRESS.sin_port = htons(444);

	sock_LISTEN = socket(AF_INET, SOCK_STREAM, NULL);
	bind(sock_LISTEN, (SOCKADDR*)&ADDRESS, sizeof(ADDRESS));
	listen(sock_LISTEN, SOMAXCONN);

	for(;;) {
		std::cout << "\\n\tServer: waiting for incoming connection...";
		if (sock_CONNECTION = accept(sock_LISTEN, (SOCKADDR*)&ADDRESS, &AddressSize))
		{
			std::cout << "\n\tA connection was found!" << std::endl;
			SUCCESSFUL = send(sock_CONNECTION, "Wlecome! You have connected to the Server", 46, NULL);
		}
	}
}