#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

int main(){

    struct stat bufstat;
    int f = open("ex1.txt", O_RDWR);
    void* m;
    int st = fstat(f, &bufstat);
    m = mmap(0,bufstat.st_size,PROT_READ | PROT_WRITE ,MAP_SHARED, f , 0);
    sprintf((char *)m,"%s\n","This is a nice day!\n");
    return 0;
}