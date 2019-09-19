#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void thread_f(void *arg) {
    printf("Thread with id %d has been terminated\n", *(int*)arg);
    pthread_exit(0);
}

int main() {
    int N = 5;
    pthread_t *a = (pthread_t *)malloc(N * sizeof(pthread_t));
    for (int i = 0; i < N; i++) {
        pthread_create(&a[i], NULL, thread_f, &i);
        printf("New thread has been created\n");
        //pthread_join(a[i], NULL);
        pthread_join(a[i], NULL);
    }
    printf("Main thread terminated\n");
    return 0;
}
/*
 * Output of the program if we don't wait until created thread terminates!
 * to prevent it - lets add pthread_join() function - that blocks main thread until created thread is not terminated
New thread has been created
Thread with id 1 has been terminated
Thread with id 1 has been terminated
New thread has been created
New thread has been created
Thread with id 3 has been terminated
New thread has been created
New thread has been created
Main thread terminated
Thread with id 32767 has been terminated
Thread with id 4 has been terminated

-----------------------------------------------------------------------------------------------------------------------
*Fixed output
 New thread has been created
Thread with id 0 has been terminated
New thread has been created
Thread with id 1 has been terminated
New thread has been created
Thread with id 2 has been terminated
New thread has been created
Thread with id 3 has been terminated
New thread has been created
Thread with id 4 has been terminated
Main thread terminated
 */