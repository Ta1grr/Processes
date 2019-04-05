// Write a program that forks a child and creates a shared pipe
// between the parent and child processes. Have the child write 
// the three messages to the parent and have the parent print out 
// the messages. 

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

#define MSGSIZE 16

char* msg1 = "hello world #1";
char* msg2 = "hello world #2";
char* msg3 = "hello world #3";

int main(void)
{
    // Your code here
    char inbuf[MSGSIZE]; // a buffer that will hold the incoming data that is being written

    int p[2]; // a two-element array to hold the read and write file descriptors that are used by the pipe

    int pid = fork();

    if (pid < 0) {
        perror("fork");
        exit(1);
    }
    else if(pid == 0) {
        write(p[1], msg1, MSGSIZE);
        write(p[1], msg2, MSGSIZE);
        write(p[1], msg3, MSGSIZE);
    }
    else {
        wait(NULL);
        read(p[0], inbuf, MSGSIZE);
        puts(inbuf);
    }

    return 0;
}
