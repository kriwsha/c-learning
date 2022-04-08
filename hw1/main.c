#include <stdio.h>
#include <errno.h>
#include <sys/stat.h>

#include "pkzip.h"

int main(int argc, char** argv) {
    if (argc != 2) {
        printf("the program requires input file path parameter\n");
        return 1;
    }

    char* filePath = argv[1];
    printf("input file path: %s\n", filePath);

    FILE* inputFile;
    inputFile = fopen(filePath, "rb");
    if (inputFile == NULL) {
        perror("cannot open file");
        return errno;
    }

    struct stat fileStats;
    if (stat(filePath, &fileStats) != 0) {
        fclose(inputFile);
        return errno;
    }
    long fileSize = (long) fileStats.st_size;
    long ecdrStart = -1;
    for (long i = 0; i <= UINT16_MAX; ++i) {
        if (fseek(inputFile, fileSize - i - (long)sizeof(struct EndOfCentralDirectoryRecord), SEEK_SET) != 0) {
            continue;
        }

        struct EndOfCentralDirectoryRecord ecdr;
        if (fread(&ecdr, sizeof(ecdr), 1, inputFile) != 1) {
            continue;
        }

        if (ecdr.signature == ecdrSign) {
            ecdrStart = fileSize - (long)sizeof(struct EndOfCentralDirectoryRecord) - i;
            break;
        }
    }

    if (ecdrStart == -1) {
        printf("this is non-zipjpeg.\n");
        fclose(inputFile);
        return 0;
    }

    for (long i = 0; i < fileSize; ++i) {
        fseek(inputFile, i, SEEK_SET);
        struct CentralDirectoryFileHeader fileHeader;

        if (fread(&fileHeader, sizeof(fileHeader), 1, inputFile) != 1) {
            continue;
        }

        if (fileHeader.signature == fileHeaderSignature) {
            char buffer[fileHeader.filenameLength + 1];
            fseek(inputFile, i + (long)sizeof(struct CentralDirectoryFileHeader), SEEK_SET);
            fread(buffer, fileHeader.filenameLength, 1, inputFile);
            buffer[fileHeader.filenameLength] = '\0';
            printf("file name: %s\n", buffer);
        }
    }
    printf("this is zipjpeg\n");
    fclose(inputFile);
    return 0;
}