#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    if (argc < 2) {
        printf("missing file name");
        exit(EXIT_FAILURE);
    }

    for (int i = 1; i != argc; i++) {
        if (remove(argv[i]) != 0) {
            perror("Something went wring");
            exit(EXIT_FAILURE);
        }
    }
    return 0;
}