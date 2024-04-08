#ifndef SOCKET_CLIENT_H
#define SOCKET_CLIENT_H

#include <iostream>
#include <cstring>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

const int PORT = 8888;
const int BUFFER_SIZE = 1024;

int createSocket();
int connectToServer(int sock, const char *server_ip);
void sendMessage(int sock, const char *message);
std::string receiveMessage(int sock);

#endif /* SOCKET_CLIENT_H */
