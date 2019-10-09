#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <zconf.h>
#include <sys/resource.h>

int main() {
    struct rusage data;

    for (int i = 0; i < 10; ++i) {
        void *p = malloc(10 * 1024 * 1024);
        memset(p, 0, 10 * 1024 * 1024);
        getrusage(RUSAGE_SELF, &data);
        printf("Used: %ld\n", data.ru_maxrss);
        sleep(1);
    }


    return 0;
}

//while we have free space si and so are 0