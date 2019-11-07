#include <stdio.h>

int main() {
    FILE* rnd;
    FILE* output = fopen("ex1.txt", "w");
    char str[20];


    rnd = fopen("/dev/random", "r");
    fgets(str, 20, rnd);

    fprintf(output, str);
    printf("%s\n", str);
    fclose(rnd);
    fclose(output);
    return 0;
}