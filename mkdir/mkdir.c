#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

    if (argc < 2) {
        printf("no directory specified");
        exit(EXIT_FAILURE);
    }

    for (int i = 1; i < argc; i++) {
        int dir = mkdir(argv[i]);
        if (dir != 0) {
            perror("Something went wrong");
            exit(EXIT_FAILURE);
        }
    }
    return 0;
}