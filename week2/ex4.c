#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(int argc, char *argv[]) {
    printf("Enter 2 integers: ");
    int a, b;
    scanf("%d %d", &a, &b);
    swap(&a, &b);
    printf("Swapped values: a=%d, b=%d\n", a,b);
    return 0;
}