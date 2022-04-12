#ifndef HW2_CP1251_H
#define HW2_CP1251_H

extern int cp1251toUnicode[128];

void initCp1251Encoding();

int convertCp1251ToUnicode(int ch);

#endif
