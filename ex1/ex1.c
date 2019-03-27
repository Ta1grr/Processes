// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    // Your code here
    int pid = fork();


    if (pid == 0){
        for(int i = 0; i < 5; i++){
            printf("I am a child");
        }
    }
    else 
    {
        while(1);
        printf("I am a parent");
    }

    return 0;
}
