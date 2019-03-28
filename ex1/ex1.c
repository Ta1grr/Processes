// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    // Your code here
    int x = 3;
    int pid = fork();

    printf("x is current %d\n", x); // Print 3
    
    if (pid < 0){
        fprintf(stderr, "fork failed\n" );
        exit(1);
    }
    else if (pid == 0){
        x = 5;
        printf("I am a child and x is currently: %d\n", x); // Will print 5
    }
    else
    {
        int ppid = waitpid(pid, NULL, 0);
        // x = 10;  // If I uncomment, this it'll print 10 for parent.
        printf("I am a parent and x is currently: %d\n", x); // This will print out 3, since child is in a seperate instance.
    }

    return 0;
}
