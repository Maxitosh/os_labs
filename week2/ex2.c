#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    printf("%s", "Enter string: ");
    char *s = (char *)malloc(100* sizeof(char));
    scanf("%s", s);

    for (int i = 0; i < strlen(s); ++i) {
        printf("%c", s[strlen(s)-i-1]);
    }
    printf("\n");

    return 0;
}