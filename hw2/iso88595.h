#ifndef HW2_ISO88595_H
#define HW2_ISO88595_H

extern int iso88595toUnicode[128];

void initIso88595Encoding();

int convertIso8859ToUnicode(int ch);

#endif
