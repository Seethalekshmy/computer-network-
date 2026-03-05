/*to implement client side of tcp 
algorithm
* create socket
*request connection 
* send message 
* receive reply
* close connection*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<string.h>
void main()
{
    int n, sockfd,client_sock,server_sock;
    char port = "5000";
    char ip = "127.0.0.100"
    struct sockaddr_in addr;
    sockfd = socket(AF_INET,SOCK_STREAM,0);
    if(sockfd<0)
    {
        perror("[-]socket error");
        exit(1);
    }
    
}