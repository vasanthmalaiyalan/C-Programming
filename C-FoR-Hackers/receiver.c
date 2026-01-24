#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>

#define FIFO_FILE "/tmp/myfifo"

int main(){
    char buffer[100];

    //create FIFO (kernal object)
    mkfifo(FIFO_FILE, 0666);

    int fd = open(FIFO_FILE, O_RDONLY);

    read(fd, buffer, sizeof(buffer));
    printf("Receive got: %s\n",buffer);

    close(fd);
    return 0;

}
