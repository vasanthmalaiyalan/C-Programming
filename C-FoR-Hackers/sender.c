#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

#define FIFO_FILE "/tmp/myfifo"

int main(){
    int fd;
    char message[] = "Hello from Sender (kernal FIFO IPC)";

    fd = open(FIFO_FILE,O_WRONLY);

    write(fd,message, sizeof(message));
    printf("Sender sent: %s\n",message);

    close(fd);
    return 0;
}