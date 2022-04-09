#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    char path[PATH_MAX];
    if (getcwd(path, sizeof(path)) == NULL) {
        perror("Something went wrong");
        exit(EXIT_FAILURE);
    }
    printf("%s", path);
    return 0;
}