#include<stdio.h>
#include <fcntl.h>
#include <zconf.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    int input = fileno(stdin);
    int *outputs = (int *) calloc(argc - 2, sizeof(int));
    int status = 0;
    if (strcmp(argv[1], "-a") != 0 && argc > 1) {
        for (int i = 0; i < argc - 1; ++i) {
            outputs[i] = open(argv[i + 1], O_RDWR | O_CREAT | O_TRUNC, 0777);
        }
        status = 0;
    } else if (strcmp(argv[1], "-a") == 0 && argc > 3) {
        for (int i = 0; i < argc - 2; ++i) {
            outputs[i] = open(argv[i + 2], O_RDWR | O_APPEND | O_CREAT, 0777);
        }
        status = 1;
    } else {
        printf("Error");
        return 0;
    }

    char byte;
    int is_end = read(input, &byte, 1);

    while (is_end != 0) {
        if (status == 1) {
            for (int i = 0; i < argc - 2; ++i) {
                write(outputs[i], &byte, 1);
            }
        } else {
            for (int i = 0; i < argc - 1; ++i) {
                write(outputs[i], &byte, 1);
            }
        }
        is_end = read(input, &byte, 1);
    }

    close(input);
    for (
            int i = 0;
            i < argc - 2; ++i) {
        close(outputs[i]);
    }

    return 0;
}