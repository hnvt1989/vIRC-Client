/*
 * net_helper.h
 *
 *  Created on: Nov 24, 2012
 *      Author: huy
 */

#ifndef NET_HELPER_H_
#define NET_HELPER_H_

#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netdb.h>
#include <sys/types.h>
#include <ctype.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>


/**include <unistd.h>

#include <setjmp.h>
#include <signal.h>
#include <sys/time.h>

#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <errno.h>
#include <math.h>
#include <pthread.h>
#include <semaphore.h>
**/

#define LISTENQ  1024  /* second argument to listen(), maximum number (size) of pending connections queue*/
/* Simplifies calls to bind(), connect(), and accept() */
typedef struct sockaddr SA;


/* Sockets interface wrappers */
int Socket(int domain, int type, int protocol);
void Setsockopt(int s, int level, int optname, const void *optval, int optlen);
void Bind(int sockfd, struct sockaddr *my_addr, int addrlen);
void Listen(int s, int backlog);
int Accept(int s, struct sockaddr *addr, socklen_t *addrlen);
void Connect(int sockfd, struct sockaddr *serv_addr, int addrlen);

/* DNS wrappers */
struct hostent *Gethostbyname(const char *name);
struct hostent *Gethostbyaddr(const char *addr, int len, int type);


#endif /* NET_HELPER_H_ */
