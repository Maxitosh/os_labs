#include  <stdio.h>
#include <unistd.h>

int  main(void)
{

    int n = 29;
    int pid = fork();

    if (pid == 0)
        printf("Hello from child [%d - %d]\n", getpid(), n);
    else
        printf("Hello from parent [%d - %d]\n", getpid(), n);
    return 0;
}

/*
 * Each process has it's own PID
 * Variable n remains the same - because fork() duplicates program
 * fork() returns 0 in child process
 *                PID of child in parent process
 * Output from program
Hello from parent [2207 - 29]
Hello from child [2208 - 29]
Hello from parent [2209 - 29]
Hello from child [2210 - 29]
Hello from parent [2211 - 29]
Hello from child [2212 - 29]
Hello from parent [2213 - 29]
Hello from child [2214 - 29]
Hello from parent [2215 - 29]
Hello from child [2216 - 29]
Hello from parent [2217 - 29]
Hello from child [2218 - 29]
Hello from parent [2219 - 29]
Hello from child [2220 - 29]
Hello from parent [2221 - 29]
Hello from child [2222 - 29]
Hello from parent [2223 - 29]
Hello from child [2224 - 29]
Hello from parent [2225 - 29]
Hello from child [2226 - 29]
 */