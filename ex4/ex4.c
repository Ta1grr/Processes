// Write a program that calls `fork()` and then calls some form of `exec()`
// to run the program `/bin/ls`. Try a few variants of `exec()`, such as 
// `execl()`, `execle()`, `execv()`, and others. Why do you think there 
// are so many variants of the same basic call?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(void)
{
    // Your code here
    int ret;    
    int pid = fork();

    if (pid < 0) {
        perror("fork");
    }
    else if (pid == 0) {
        // using execl
        ret = execl("/bin/ls", "ls", "-1", '\0');
        printf("%d", ret);
    }
    else{
        wait(NULL);
    }

    return 0;
}
