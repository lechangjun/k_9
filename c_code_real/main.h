#ifndef MAIN_H
#define MAIN_H



// 기본
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <iostream>
#include <string>
#include <cerrno>
#include <cstring>
#include <unistd.h>

// 시리얼
#include <termios.h>

typedef struct
{
    int fd;
} SerialPort;

int serial_open(const char *device);
void serial_close(int fd);
int serial_read(int fd, char *buffer, size_t size);


// class 




static char buffer2[256];


void run();

#endif // MAIN_H
