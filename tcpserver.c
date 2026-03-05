/*to implement a TCP server in C, we can use the socket programming API provided by the operating system.
 Below is an example of a simple TCP server that listens for incoming connections and echoes back any messages
 received from clients.
 
 algorithm
 * create socket
 * establish connection
 * listen 
 * close connection */


#include<stdio.h>
#include<stdlib.h>
#include<arpa/inet.h>
#include<string.h>
#include<unistd.h>

void main(){
    int sockfd,server_sock,client_sock,n,addr_size;//n is the binding variable 
    char buffer[1024];
    char ip = "127.0.0.100";
    char port ="5000";
    struct sockaddr_in client_addr,server_addr;//client_addr & server_addr of type structure
    server_sock = socket(AF_INET,SOCK_STREAM,0);
    if(server_sock <0)//if negative socket not created
    {
        perror("[+]socket error");
        exit(1);
        
    }
    printf("TCP connection created\n");
    memset(&server_addr,'\0',sizeof(server_addr));// to clear garbage value
    sever_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);//assigning port number 
    server_addr.sin_addr.s_addr = inet_addr(ip);//convert char ip into binary
    n = bind(server_sock,(struct sockaddr*)&server_addr,sizeof(server_addr));
    if(n<0)//negative n value = bind error 
    {
        perror("[-]bind error");
        exit(1);
    }
    printf("bind to the port %d ",port);
    listen(server_sock,10);//listening to the client
    printf("listening....\n");
    while(1)
    {
        addr_size = sizeof(client_addr);
        client_sock = accept(server_sock,(struct sockaddr*)&client_addr,sizeof(client_addr));
        printf("client connected\n");
        bzero(buffer,1024);
        recv(client_sock,buffer,sizeof(buffer),0);
        printf("client: %s\n",buffer);
        strcpy("HELLO FROM SERVER");
        printf("%s\n",buffer);
        send(client_sock,buffer,strlen(buffer),0);
        close(client_sock);
    }

    printf("client disconnected\n");

}