// Write a program that opens the text.txt file (with the `fopen()` library call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    // Your code here 
    FILE * openfile = fopen("text.txt", "r+");
    int pid = fork();

    if (pid < 0) {
        perror("failed");
    }
    else if (pid == 0) {
        fprintf(openfile, "%s %s\n", "Child", "Here!");
    }
    else {
        wait(NULL);
        fprintf(openfile, "%s %s\n", "Parent", "Here!");
    }

    fclose(openfile);

    return 0;
}
