#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int lines_count(char *file_name) {
    FILE *file;
    file = fopen(file_name, "r");
    if (file == NULL) {
        return errno;
    }
    int lines_count = 0;
    int ch;

    while ((ch = fgetc(file)) != EOF)
    {
        if (ch == '\n') lines_count++;
    }
    fclose(file);

    return lines_count;
}

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

    int lines = lines_count(argv[1]);
    if (lines == errno) {
        printf("Something went wrong: %s", strerror(lines));
        exit(EXIT_FAILURE);
    }

    stat(argv[1], &f_stat);
    char content[f_stat.st_size];
    int count = 0;

    while(fgets(content, f_stat.st_size, file) != NULL)
    {
        int length = lines - count;
        count += 1;
        if (length >= 10) {
            continue;
        }
        printf("%s", content);
    }
    fclose(file);
    return 0;
}