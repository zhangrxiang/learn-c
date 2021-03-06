//
// Created by zhangrongxiang on 2017/9/18 16:02
//

/* fread example: read an entire file */
#include <stdio.h>
#include <stdlib.h>

//http://www.cplusplus.com/reference/cstdio/fread/
int main() {
    FILE *pFile;
    long lSize;
    char *buffer;
    size_t result;

    pFile = fopen("test.txt", "rb");
    if (pFile == NULL) {
        fputs("File error", stderr);
        exit(1);
    }

    // obtain file size:
    fseek(pFile, 0, SEEK_END);
    lSize = ftell(pFile);
    rewind(pFile);

    // allocate memory to contain the whole file:
    buffer = (char *) malloc(sizeof(char) * lSize);
    if (buffer == NULL) {
        fputs("Memory error", stderr);
        exit(2);
    }

    // copy the file into the buffer:
    result = fread(buffer, 1, lSize, pFile);
    if (result != lSize) {
        fputs("Reading error", stderr);
        exit(3);
    }

    /* the whole file is now loaded in the memory buffer. */

    // terminate
    fclose(pFile);
    printf("%s\n", buffer);
    free(buffer);
    return 0;
}