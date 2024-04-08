#include "server.h"

void processClient(int client_socket) {
    char buffer[BUFFER_SIZE] = {0};
    int valread = readMessage(client_socket, buffer, BUFFER_SIZE);
    std::cout << "Message from client: " << buffer << std::endl;

    const char *response_message = "Message received from server";
    sendMessage(client_socket, response_message);

    // 클라이언트 소켓을 닫지 않고 계속 수신 대기
    // close(client_socket);
}

int main() {
    int server_socket = createSocket();

    struct sockaddr_in server_address;
    setAddress(server_address);

    bindSocket(server_socket, server_address);

    listenSocket(server_socket);

    while (true) {
        int addrlen = sizeof(server_address);
        int client_socket = acceptClient(server_socket, server_address, addrlen);

        // 클라이언트의 메시지를 처리하는 함수 호출
        processClient(client_socket);
    }

    close(server_socket);
    return 0;
}
