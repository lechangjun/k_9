#include "socket_client.h"



int client_socket_run(int argc, char const *argv[])
{
    if (argc != 2)
    {
        std::cerr << "Usage: " << argv[0] << " <server_ip>" << std::endl;
        return 1;
    }

    const char *server_ip = argv[1];
    int sock = createSocket();
    sock = connectToServer(sock, server_ip);

    const char *message = "Hello from client";
    sendMessage(sock, message);

    std::string receivedMessage = receiveMessage(sock);
    std::cout << "Received message: " << receivedMessage << std::endl;

    close(sock);
    return 0;
}

void run() 
{
    const char* server_ip = "127.0.0.1"; // 예시 IP
    int sock = createSocket();
    sock = connectToServer(sock, server_ip);

    const char* message = "Hello from client";
    sendMessage(sock, message);

    std::string receivedMessage = receiveMessage(sock);
    std::cout << "Received message from server: " << receivedMessage << std::endl;

    close(sock);
}
