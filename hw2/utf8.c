#include "utf8.h"

const int utf8Bom = 15711167;

int getOctetsNumber(int ch) {
    if (0 <= ch && ch <= 0x0000007F) {
        return 1;
    } else if (0x00000080 <= ch && ch <= 0x000007FF) {
        return 2;
    } else if (0x00000800 <= ch && ch <= 0x0000FFFF) {
        return 3;
    } else if (0x00010000 <= ch && ch <= 0x0010FFFF) {
        return 4;
    }
    return -1;
}

int convertUnicodeToUtf8(int unicodeChar) {
    int octets = getOctetsNumber(unicodeChar);
    if (octets == -1) {
        return -1;
    }
    int result = 0;
    if (octets > 1) {
        int highestBits = (unicodeChar >> ((octets - 1) * 6));
        result = highestBits;
        for (int i = 1; i <= octets; ++i) {
            result |= (1 << (8 - i));
        }

        unicodeChar ^= (highestBits << ((octets - 1) * 6));

        for (int i = 1; i < octets; ++i) {
            highestBits = (unicodeChar >> ((octets - i - 1) * 6));
            unicodeChar ^= (highestBits << ((octets - i - 1) * 6));
            int curByte = highestBits | (1 << 7);
            result <<= 8;
            result |= curByte;
        }
    } else {
        result = unicodeChar;
    }

    return result;
}