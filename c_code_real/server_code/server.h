#ifndef SERVER_H
#define SERVER_H

#include <iostream>
#include <cstring>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

const int PORT = 8888;
const int BUFFER_SIZE = 1024;

int createSocket();
void setAddress(struct sockaddr_in &server_address);
void bindSocket(int server_socket, struct sockaddr_in &server_address);
void listenSocket(int server_socket);
int acceptClient(int server_socket, struct sockaddr_in &server_address, int &addrlen);
int readMessage(int client_socket, char *buffer, int buffer_size);
void sendMessage(int client_socket, const char *message);

#endif /* SERVER_H */
