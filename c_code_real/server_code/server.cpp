#include "server.h"

int createSocket() {
    int server_socket;
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        std::cerr << "Socket creation error" << std::endl;
        exit(EXIT_FAILURE);
    }
    return server_socket;
}

void setAddress(struct sockaddr_in &server_address) {
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);
}

void bindSocket(int server_socket, struct sockaddr_in &server_address) {
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        std::cerr << "Bind failed" << std::endl;
        exit(EXIT_FAILURE);
    }
}

void listenSocket(int server_socket) {
    if (listen(server_socket, 3) < 0) {
        std::cerr << "Listen failed" << std::endl;
        exit(EXIT_FAILURE);
    }
}

int acceptClient(int server_socket, struct sockaddr_in &server_address, int &addrlen) {
    int client_socket;
    if ((client_socket = accept(server_socket, (struct sockaddr *)&server_address, (socklen_t *)&addrlen)) < 0) {
        std::cerr << "Accept failed" << std::endl;
        exit(EXIT_FAILURE);
    }
    return client_socket;
}

int readMessage(int client_socket, char *buffer, int buffer_size) {
    int valread;
    valread = read(client_socket, buffer, buffer_size);
    return valread;
}

void sendMessage(int client_socket, const char *message) {
    send(client_socket, message, strlen(message), 0);
    std::cout << "Hello message sent" << std::endl;
}
