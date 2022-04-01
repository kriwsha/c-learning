#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <malloc.h>
#include "hashmap.h"

#define BUFFER_LENGTH 256

char* readWord(FILE* inputFile);

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Incorrect number of input arguments: the path to the input file missing.\n");
        return 1;
    }

    const char* const inputPath = argv[1];
    printf("Path to the input file: %s\n", inputPath);

    FILE* inputFile;
    inputFile = fopen(inputPath, "r");
    if (!inputFile) {
        perror("Can't open the input file");
        return errno;
    }

    HashMap* hashMap = createHashMap();

    while (1) {
        char* nextWord = readWord(inputFile);
        if (nextWord == NULL) {
            break;
        }
        int value = getFromHmOrDefault(hashMap, nextWord, 0);
        printf("word = %s; count = %d\n", nextWord, value);
        value = value + 1;
        putToHm(hashMap, nextWord, value);
        printf("===========\n");
    }
    hashMapToString(hashMap);
    return 0;
}

char* readWord(FILE* inputFile) {
    static char buffer[BUFFER_LENGTH];
    if (fscanf(inputFile, "%s", buffer) != 1) {
        return NULL;
    }
    size_t len = strlen(buffer);
    char* result = (char*)malloc(len + 1);
    return strcpy(result, buffer);
}