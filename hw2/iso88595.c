#include "iso88595.h"
#include <stdio.h>

int iso88595toUnicode[128];

void initIso88595Encoding() {
    int last_pos = 0;
    for (int i = 0x80; i <= 0xA0; ++i) {
        iso88595toUnicode[last_pos++] = i;
    }
    for (int i = 0x401; i <= 0x44f; ++i) {
        iso88595toUnicode[last_pos++] = i;
    }
    iso88595toUnicode[last_pos++] = 0x2116;
    for (int i = 0x451; i <= 0x45c; ++i) {
        iso88595toUnicode[last_pos++] = i;
    }
    iso88595toUnicode[last_pos++] = 0xA7;
    iso88595toUnicode[last_pos++] = 0x45E;
    iso88595toUnicode[last_pos] = 0x45F;
}

int convertIso8859ToUnicode(int ch) {
    return (ch < 128) ? ch : iso88595toUnicode[ch - 128];
}