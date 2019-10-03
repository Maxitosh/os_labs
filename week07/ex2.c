#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Enter N!\n");
    int N = 0;
    scanf("%d", &N);

    int * arr = (int *)malloc(sizeof(int) * N);

    for (int i = 0; i < N; ++i) {
        arr[i] = i;
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);

    return 0;
}