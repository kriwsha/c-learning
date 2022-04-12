#ifndef HW2_UTF8_H
#define HW2_UTF8_H

extern const int utf8Bom;

int getOctetsNumber(int ch);

int convertUnicodeToUtf8(int unicodeChar);

#endif
