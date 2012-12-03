/*
 * Client - main.c
 *
 *  Created on: Nov 24, 2012
 *      Author: huy
 */

#include <sys/socket.h>
#include <stdlib.h>
#include "Utilities.h"

int main(int argc, char **argv){
    int clientfd, port;
    char *host, buf[MAXLINE];
    rio_t rio;

    /*
    if (argc != 3) {
		fprintf(stderr, "usage: %s <host> <port>\n", argv[0]);
		exit(0);
    }
    host = argv[1];
    port = atoi(argv[2]);
	*/

    //statically assign host and port
    host = "127.0.0.1";
    port = 49000;

    clientfd = Open_clientfd(host, port);
    Rio_readinitb(&rio, clientfd);

    while (Fgets(buf, MAXLINE, stdin) != NULL) {
		Rio_writen(clientfd, buf, strlen(buf));
		Rio_readlineb(&rio, buf, MAXLINE);
		Fputs(buf, stdout);
    }
    Close(clientfd); //line:netp:echoclient:close
    exit(0);
}
