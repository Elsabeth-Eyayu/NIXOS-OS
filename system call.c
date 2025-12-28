//#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

int main() {
    int ftr = open("file1.txt", O_RDWR);
    if (ftr < 0) {
        perror("Failed to open file");
        return 1;
    }

    if (ftruncate(ftr, 30) == -1) {
        perror("ftruncate failed");
        close(ftr);
        return 1;
    }
    printf("File truncated to 30 bytes successfully.\n");
    close(ftr);
    return 0;
}

