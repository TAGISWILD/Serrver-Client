#include <iostream>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>
using namespace std;
 int main()
{
    
    int listening_socket, client_socket;
    listening_socket = socket(AF_INET, SOCK_STREAM, 0);
    if(listening_socket == -1)
    {
        cerr<<"cant connect";
        return 0;
    }
    sockaddr_in server, client;
    server.sin_family= AF_INET;
    server.sin_port = htons(54000);
    server.sin_addr.s_addr = INADDR_ANY;
    memset(server.sin_zero,0,8);
    
    unsigned len = sizeof(sockaddr_in);
    if((bind(listening_socket,(sockaddr*)&server,len)==-1))
    {
        cerr<<"Can't listen";
        return 0;
    }
    
    if(listen(listening_socket,5) == -1)
    {
        cerr<<"Can't connect 3";
        return 0;
    }
    
    if((client_socket = accept(listening_socket,(sockaddr*)&client,&len)) == -1)
    {
        cerr<<"can't connect 4";
        return 0;
    }
    close(listening_socket);
    
    char buf[4096];
    string msg;
    while(1)
    {
        memset(buf,4096,0);
        int bytesrecieved = recv(client_socket,buf,bytesrecieved+1,0);
        cout<<"sent "<<send<<" bytes to client"<<inet_ntoa(client.sin_addr)<<endl;
    }
    close(client_socket);
    return 0;
}
