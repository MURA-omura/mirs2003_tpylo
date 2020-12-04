#include <stdio.h>
#include <WinSock2.h>// WinSocketを使用するためのInclude
#include <WS2tcpip.h>// WinSocketを使用するためのInclude

// WinSocketを使用するためのlibファイル
#pragma comment(lib, "ws2_32.lib")

int main()
{
	WSADATA wsaData;
	SOCKET sockListen;

	// Winsockの初期化
	WSAStartup(WINSOCK_VERSION, &wsaData);

	struct sockaddr_in addr;
	// AF_INETを渡すことによりIPv4で通信する事を指定
	addr.sin_family = AF_INET;
	// ポート番号を指定好きなポートを指定してください。
	addr.sin_port = htons(12345);
	// INADDR_ANYを指定する事によりどのIPからでも通信を受け取る状態にする。
	addr.sin_addr.S_un.S_addr = INADDR_ANY;

	// ソケットを作成
	sockListen = socket(addr.sin_family, SOCK_STREAM, 0);

	// ソケットの作成に失敗していないかどうか
	if (sockListen == INVALID_SOCKET)
	{
		printf("socket failed\n");
		return -1;
	}

	// ソケットにアドレスを割り当てる
	if (bind(sockListen, (struct sockaddr*)&addr, sizeof(addr)) == SOCKET_ERROR)
	{
		printf("bind:エラー");
		return -1;
	}

	// ソケットを接続待ち状態にする
	if (listen(sockListen, 5) == SOCKET_ERROR)
	{
		printf("listen:エラー");
		return -1;
	}

	SOCKET sock;
	struct sockaddr_in client;
	int clientlen = sizeof(client);
	char buf[256];
	memset(buf, 0, sizeof(buf));

	// クライアントからの接続を待つ
	sock = accept(sockListen, (struct sockaddr*)&client, &clientlen);
	printf("接続完了\n");
	// クライアントからデータを受け取る
	recv(sock, buf, sizeof(buf), 0);
	// 受け取った文字を表示
	printf("%s\n", buf);

	// ソケット通信を終了
	closesocket(sock);
	// Winsockを終了
	WSACleanup();

	return 0;
}