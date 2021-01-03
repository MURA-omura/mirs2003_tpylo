#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
#include <pthread.h>
#include "sock.h"


void convertNum(char *buf, int *power, int *dist){
    signed short a, b;
    a = (int)buf[0] * 256 + (int)buf[1];
    b = (int)buf[2] * 256 + (int)buf[3];
    *power = a - 128;
    *dist = b;
}


void connectPython(Move mover) {
    int sockfd;
    int client_sockfd;
    struct sockaddr_in addr;

    socklen_t len = sizeof( struct sockaddr_in );
    struct sockaddr_in from_addr;

    char buf[4];
    // 受信バッファ初期化
    memset( buf, 0, sizeof( buf ) );

    // ソケット生成
    if( ( sockfd = socket( AF_INET, SOCK_STREAM, 0 ) ) < 0 ) {
        perror( "socket" );
    }

    // 待ち受け用IP・ポート番号設定
    addr.sin_family = AF_INET;
    addr.sin_port = htons( 51000 );
    // ローカルホストを指定
    addr.sin_addr.s_addr = inet_addr( "127.0.0.1" );
    //addr.sin_addr.s_addr = INADDR_ANY;

    // バインド
    if( bind( sockfd, (struct sockaddr *)&addr, sizeof( addr ) ) < 0 ) {
        perror( "bind" );
    }

    // 受信待ち
    if( listen( sockfd, SOMAXCONN ) < 0 ) {
        perror( "listen" );
    }

    // クライアントからのコネクト要求待ち
    if( ( client_sockfd = accept( sockfd, (struct sockaddr *)&from_addr, &len ) ) < 0 ) {
        perror( "accept" );
    }

    // 受信
    int rsize;
    while(1) {
        int power, dist;
        rsize = recv( client_sockfd, buf, sizeof( buf ), 0 );
        //printf( "rsize = %d\n", rsize );
        if ( rsize > 0 ) {
            convertNum(buf, &power, &dist);
            if(dist > 0) G_power = power;
            printf("power: %d,  dist: %d\n", power, dist);
            char send_str[4];
            send_str[0] = 0;
            send_str[1] = G_state;
            send_str[2] = 0;
            send_str[3] = G_audio;
            //printf("%x %x\n", send_str[0], send_str[1]);
            send( client_sockfd, send_str, 4, MSG_NOSIGNAL );
        }
    }

    // ソケットクローズ
    close( client_sockfd );
    close( sockfd );
    pthread_exit(0);
}
