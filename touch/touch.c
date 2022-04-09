#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    if (argc < 2) {
        printf("missing file name");
        exit(EXIT_FAILURE);
    }

    for (int i = 1; i != argc; i++) {
        FILE *file;
        file = fopen(argv[i], "a");
        if (file == NULL) {
            perror("Something went wring");
            exit(EXIT_FAILURE);
        }
        fclose(file);
    }
    return 0;
}