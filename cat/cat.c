#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {

    if (argc < 2) {
        printf("no file specified");
        exit(EXIT_FAILURE);
    }

    FILE *file;
    struct stat f_stat;

    file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Something went wrong: No such file");
        exit(EXIT_FAILURE);
    }

    stat(argv[1], &f_stat);
    char content[f_stat.st_size];

    while(fgets(content, f_stat.st_size, file) != NULL)
    {
        printf("%s", content);
    }
    fclose(file);
    return 0;
}