#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <windows.h>

int main(int argc, char *argv[]) {
    DIR *dir;
    struct dirent *_dir;
    struct stat _stat;
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

    dir = opendir(".");
    if(dir == NULL)
    {
        perror("Something went wrong");
        exit(EXIT_FAILURE);
    }

    while ((_dir = readdir(dir)) != NULL) {
        stat(_dir->d_name,&_stat);
        if (S_ISDIR(_stat.st_mode)) {
            if (strcmp(_dir->d_name,".") == 0 || strcmp(_dir->d_name,"..") == 0) {
                continue;
            }
            SetConsoleTextAttribute(console, 6);
            printf("%s ", _dir->d_name);
            continue;
        }
        SetConsoleTextAttribute(console, FOREGROUND_GREEN);
        printf("%s ", _dir->d_name);
    }
    SetConsoleTextAttribute(console,7);
    closedir(dir);
}