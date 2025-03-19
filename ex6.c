// Amogh Bantwal
// amoghb07@uw.edu

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

int main(int argc, char* argv[]) {
    // open directoryu
    DIR* dir = opendir(argv[1]);

    // struct for getting contents in directory
    struct dirent* entry;

    // check if directory passed is existing
    if (dir == NULL) {
        perror("Directory not found");
        return 1;
    }

    // read all contents from directory until entry pointer is null
    while ((entry = readdir(dir)) != NULL) {
        // check if name of content ends in a . extension. get the pointer to this character
        char* fileextension = strrchr(entry->d_name, '.');
        // make sure pointer not null in case fileext was not found, and also verify that extension is a .txt
        if (fileextension && strcmp(fileextension, ".txt") == 0) {

            /*
                Read the file contents using POSIX and print to standard out
            */
            int fd = open(strcat(strcat(argv[1], "/"), entry->d_name), O_RDONLY);

            if (fd == -1) {
                perror("File not found");
                return 1;
            }
            
            int size = lseek(fd, 0, SEEK_END);
            lseek(fd, 0, SEEK_SET);
            if (size == -1) {
                perror("lseek failed");
                close(fd);
                return 1;
            }

            char* buffer = (char*) malloc(size + 1);
            int result = read(fd, buffer, size);

            if (result == -1) {
                perror("Error occured");
                free(buffer);
                close(fd);
                return 1;
            }

            printf("%s\n", buffer);

            free(buffer);
            close(fd);
        }
    }

    closedir(dir);
    return 0;
}