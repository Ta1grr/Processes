/*
Write a program that will find the average time it takes for your computer
to make a system call an empty write to stdout. Your program should use the 
`clock_gettime` procedure to time how long a single system call takes. It'll 
do this for one million iterations, and then find the average of all of those 
iterations in nanoseconds.
For some helpful documentation and examples of using time-related system calls,
visit this site: https://www.cs.rutgers.edu/~pxk/416/notes/c-tutorials/gettime.html
While the linked site does say that `clock_gettime()` does not work on OSX, this 
turns out to only be the case for OSX versions < 10.12. Anything later than that 
and `clock_gettime()` should work just fine. 
*/

#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <sys/wait.h>

#define number_iter 1000000
#define BILLION 1000000000L

int main()
{
    // Your code here
    uint64_t diff;
	struct timespec start, end;
	int i;

    // char inbuf[number_iter];
    // int p[2];

    // int pid = fork();

    // if (pid < 0) {
    //     perror("fork");
    //     exit(1);
    // }
    // else if (pid == 0) {
    //     /* measure monotonic time */
    //     clock_gettime(CLOCK_MONOTONIC, &start);	/* mark start time */
    //     for (i = 0; i < number_iter; i++) {
    //     write(p[1], &inbuf, number_iter);
    //     }	/* do stuff */
    //     clock_gettime(CLOCK_MONOTONIC, &end);	/* mark the end time */
    // }
    // else {
    //     diff = BILLION * (end.tv_sec - start.tv_sec) + end.tv_nsec - start.tv_nsec;
    //     printf("elapsed time = %llu nanoseconds\n", (long long unsigned int) diff);
    //     // wait(NULL);
    // }

    int sums = 0;

	// /* now re-do this and measure CPU time */
	// /* the time spent sleeping will not count (but there is a bit of overhead */
	// clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start);	/* mark start time */
	// sleep(1);	/* do stuff */
	// clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end);		/* mark the end time */

	// diff = BILLION * (end.tv_sec - start.tv_sec) + end.tv_nsec - start.tv_nsec;
	// printf("elapsed process CPU time = %llu nanoseconds\n", (long long unsigned int) diff);

    for (int i = 0; i < number_iter; i++) {
        clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start);	/* mark start time */
        sleep(1);	/* do stuff */
        clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end);		/* mark the end time */

        diff = BILLION * (end.tv_sec - start.tv_sec) + end.tv_nsec - start.tv_nsec;
        sums = sums + diff;
    }
    int average = sums / number_iter;
    printf("Average time: %d", average);

    // close(p[0]); 
    // close(p[1]); 
    
    return 0;
}
