#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {

    if (argc < 2) {
        printf("no in_file specified");
        exit(EXIT_FAILURE);
    }

    if (argc < 3) {
        printf("no out_file specified");
        exit(EXIT_FAILURE);
    }

    FILE *in_file;
    FILE *out_file;
    struct stat f_stat;

    in_file = fopen(argv[1], "r");
    if (in_file == NULL) {
        printf("Something went wrong: No such file");
        exit(EXIT_FAILURE);
    }

    out_file = fopen(argv[2], "a");
    if (out_file == NULL) {
        printf("Something went wrong: No such file");
        exit(EXIT_FAILURE);
    }

    stat(argv[1], &f_stat);
    char content[f_stat.st_size];

    while(fgets(content, f_stat.st_size, in_file) != NULL)
    {
        fprintf(out_file, "%s", content);
    }
    fclose(in_file);
    fclose(out_file);
    return 0;
}