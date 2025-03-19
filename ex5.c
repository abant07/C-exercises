// Amogh Bantwal
// amoghb07@uw.edu

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    FILE* ptr;

    ptr = fopen("foo.txt", "rb");

    if (ptr == NULL) {
        printf("error opening");
        return 1;
    }

    if(fseek(ptr, 0, SEEK_END) == 0) { // move 0 bytes from end of file to see what the value of ptr is which will tell us the size of file
        char buffer[1];

        long pos = ftell(ptr);

        while(pos > 0) { 
            fseek(ptr, --pos, SEEK_SET); // moves --pos bytes from the start of the file
            fread(buffer, sizeof(char), 1, ptr); // reads the --pos's byte and stores in the buffer
            printf("%c", buffer[0]);
        }
    }

    fclose(ptr);

    return 0;
}