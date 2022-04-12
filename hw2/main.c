#include <stdio.h>
#include <string.h>
#include <errno.h>

#include "cp1251.h"
#include "iso88595.h"
#include "koi8.h"

#include "utf8.h"

int getBitsNumber(int ch) {
    int res = 0;
    while (ch) {
        ch >>= 1;
        res++;
    }
    return res ? res : 1;
}

void printToFile(FILE *outputFile, int utf8) {
    const int len = getBitsNumber(utf8);
    const int bytesNumber = (len + 7) / 8;

    for (int i = bytesNumber - 1; i >= 0; --i) {
        int curByte = (utf8 >> (i * 8));
        fputc((char) curByte, outputFile);
        utf8 ^= (curByte << (i * 8));
    }
}

int convertCp1251(FILE *inputFile, FILE *outputFile) {
    initCp1251Encoding();
    printToFile(outputFile, utf8Bom);
    int ch;
    while ((ch = getc(inputFile)) != EOF) {
        int unicodeCh = convertCp1251ToUnicode(ch);
        int utf8Char = convertUnicodeToUtf8(unicodeCh);
        if (utf8Char == -1) {
            return -1;
        }
        printToFile(outputFile, utf8Char);
    }
    return 0;
}

int convertKoi8(FILE *inputFile, FILE *outputFile) {
    initIso88595Encoding();
    printToFile(outputFile, utf8Bom);
    int ch;
    while ((ch = getc(inputFile)) != EOF) {
        int unicodeCh = convertKoi8ToUnicode(ch);
        int utf8Char = convertUnicodeToUtf8(unicodeCh);
        if (utf8Char == -1) {
            return -1;
        }
        printToFile(outputFile, utf8Char);
    }
    return 0;
}

int convertIso88595(FILE *inputFile, FILE *outputFile) {
    printToFile(outputFile, utf8Bom);
    initIso88595Encoding();
    int ch;
    while ((ch = getc(inputFile)) != EOF) {
        int unicodeCh = convertIso8859ToUnicode(ch);
        int utf8Char = convertUnicodeToUtf8(unicodeCh);
        if (utf8Char == -1) {
            return -1;
        }
        printToFile(outputFile, utf8Char);
    }
    return 0;
}

int encode(char *encoding, FILE *inputFile, FILE *outputFile) {
    if (strcmp(encoding, "cp1251") == 0) {
        convertCp1251(inputFile, outputFile);
        return 0;
    }
    if (strcmp(encoding, "koi8") == 0) {
        convertKoi8(inputFile, outputFile);
        return 0;
    }
    if (strcmp(encoding, "iso88595") == 0) {
        convertIso88595(inputFile, outputFile);
        return 0;
    }
    printf("Incorrect encoding. Available encodings: cp1251, koi8, iso88595\n");
    return 1;
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Incorrect number of arguments. "
               "3 arguments are required: input file path; the input encoding; output file path;\n");
        return 1;
    }

    char *inputPath = argv[1];
    printf("The input file path: %s\n", inputPath);

    FILE *inputFile;
    inputFile = fopen(inputPath, "rb");
    if (inputFile == NULL) {
        perror("Can't open the input file");
        return errno;
    }

    char *encoding = argv[2];
    printf("The input file encoding: %s\n", encoding);

    char *outputPath = argv[3];
    printf("The output file path: %s\n", outputPath);

    FILE *outputFile;
    outputFile = fopen(outputPath, "wb");
    if (outputFile == NULL) {
        perror("Can't create or open the output file");
        fclose(inputFile);
        return errno;
    }

    int successRes = 1 - encode(encoding, inputFile, outputFile);

    fclose(outputFile);
    fclose(inputFile);

    if (successRes) {
        printf("Converting succeeded: %s -> utf8; file path: %s\n", encoding, outputPath);
    } else {
        printf("Failed to convert the file.\n");
        return 1;
    }

    return 0;
}