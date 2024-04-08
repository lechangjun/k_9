//#include "main.h"
#include "socket_client.h"
#include "actually_works.h"


int main() {
    const char* server_ip = "127.0.0.1"; // 예시 IP
    const char* argv[] = {"program_name", server_ip}; // 프로그램 이름과 서버 IP를 전달하는 배열 생성
    client_socket_run(2, argv); // client_socket_run 함수 호출
    run(); // run 함수 호출
    return 0;
}

