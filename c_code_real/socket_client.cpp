#include "socket_client.h"

int a ;

int createSocket() {
    int sock;
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        std::cerr << "Socket creation error" << std::endl;
        exit(EXIT_FAILURE);
    }
    return sock;
}

int connectToServer(int sock, const char *server_ip) {
    struct sockaddr_in serv_addr;
    if (inet_pton(AF_INET, server_ip, &serv_addr.sin_addr) <= 0) {
        std::cerr << "Invalid address/ Address not supported" << std::endl;
        exit(EXIT_FAILURE);
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        std::cerr << "Connection Failed" << std::endl;
        exit(EXIT_FAILURE);
    }

    return sock;
}

void sendMessage(int sock, const char *message) {
    send(sock, message, strlen(message), 0);
    std::cout << "Message sent to server: " << message << std::endl;
}

std::string receiveMessage(int sock) {
    char buffer[BUFFER_SIZE] = {0};
    int valread = read(sock, buffer, BUFFER_SIZE);
    return std::string(buffer);
}
