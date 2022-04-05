#ifndef HW1_RAR_JPEG_H
#define HW1_RAR_JPEG_H

#include <stdint.h>

const uint32_t ecdrSign = 0x06054b50;
const uint32_t fileHeaderSignature = 0x02014b50;

#pragma pack(push, 1)
struct CentralDirectoryFileHeader {
    uint32_t signature;
    uint16_t versionMadeBy;
    uint16_t versionToExtract;
    uint16_t generalPurposeBitFlag;
    uint16_t compressionMethod;
    uint16_t modificationTime;
    uint16_t modificationDate;
    uint32_t crc32;
    uint32_t compressedSize;
    uint32_t uncompressedSize;
    uint16_t filenameLength;
    uint16_t extraFieldLength;
    uint16_t fileCommentLength;
    uint16_t diskNumber;
    uint16_t internalFileAttributes;
    uint32_t externalFileAttributes;
    uint32_t localFileHeaderOffset;
};

struct EndOfCentralDirectoryRecord {
    uint32_t signature;
    uint16_t diskNumber;
    uint16_t startDiskNumber;
    uint16_t numberCentralDirectoryRecord;
    uint16_t totalCentralDirectoryRecord;
    uint32_t sizeOfCentralDirectory;
    uint32_t centralDirectoryOffset;
    uint16_t commentLength;
};

#pragma pack(pop)
#endif