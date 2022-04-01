//
// Created by belov on 30.03.2022.
//
#include "hashfunc.h"
#include <stdio.h>
/**
 * hash function
 *
 * @param key ...
 * @return hash code
 */
int hashCode(const char* key) {
    int i = 0;
    for (int j=0; key[j]; j++)
        i += key[j];
    int hash = i % CAPACITY;
    return hash;
}