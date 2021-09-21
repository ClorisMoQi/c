#include <WinSock2.h>
#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int main(){

    // load socket lib
    WORD wVersionRequested;
    WSADATA wsaData;
    int err;

    wVersionRequested = MAKEWORD(2,2);

    err = WSAStartup(wVersionRequested, &wsaData);
    if (err != 0){
        return 0;
    }
    if (LOBYTE(wsaData.wVersion) != 2 || HIBYTE(wsaData.wVersion) != 2){
        
    }
}