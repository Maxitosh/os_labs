#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void printLeftTriangle(int n){
    int stars = 1;
    for (int i = 1; i < n + 1; ++i) {
        //stars
        for (int j = 0; j < 2*i - 1; ++j) {
            printf("%c", '*');
        }
        stars+=2;
        printf("\n");
    }
}

void printNormalTriangle(int n){
    int stars = 1;
    for (int i = 1; i < n + 1; ++i) {
        //spaces
        for (int k = 0; k < (2*n-stars-1)/2; ++k) {
            printf("%c", ' ');
        }
        //stars
        for (int j = 0; j < 2*i - 1; ++j) {
            printf("%c", '*');
        }
        stars+=2;
        printf("\n");
    }
}

void printRectangle(int n){
    for (int i = 0; i < n; ++i) {
        for (int q = 0; q < n; ++q) {
            printf("%c", '*');
        }
        printf("\n");
    }
}

void printArrow(int n){
    if(n % 2 == 0){
        printf("%s", "Height is not odd - arrow cannot be constructed!");
        return;
    }

    for (int i = 0; i < n/2; ++i) {
        for (int j = 0; j < i + 1; ++j) {
            printf("%c", '*');
        }
        printf("\n");
    }

    for (int k = 0; k < ceil((double)n/2); ++k) {
        printf("%c", '*');
    }
    printf("\n");

    for (int i = n/2; i > 0; --i) {
        for (int j = 0; j < i; ++j) {
            printf("%c", '*');
        }
        printf("\n");
    }
}

int main(int argc, char* argv[]) {
    int n = 0;
    n = atoi(argv[1]);

    printNormalTriangle(n);
    //printLeftTriangle(n);
    //printArrow(n);
    //printRectangle(n);

    return 0;
}