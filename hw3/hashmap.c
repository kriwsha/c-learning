//
// Created by belov on 30.03.2022.
//
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "hashfunc.h"
#include "hashmap.h"

HashMap* createHashMap() {
    HashMap* hashMap = (HashMap*) malloc(sizeof(HashMap));
    hashMap->buckets = malloc(CAPACITY * sizeof(NodeEntry*));
    for(int i = 0; i < CAPACITY; i++) {
        hashMap->buckets[i] = malloc(sizeof(NodeEntry*));
    }
    return hashMap;
}

void putToHm(HashMap* map, char* key, int value) {
    int hash = hashCode(key);
    printf("for key = %s hash = %d\n", key, hash);
    NodeEntry* entry = map->buckets[hash];

    int i = 0;
    while (entry != NULL) {
        printf("entry #%d; key = %s; entry->key = %s; entry->value = %d\n", i++, key, entry->key, entry->value);
        if (entry->key == NULL) {
            entry->key = key;
            entry->value = value;
            printf("fill entry: entry->key: %s ; entry->value = %d\n", entry->key, entry->value);
            break;
        }
        if (strcmp(entry->key, key) == 0) {
            printf("adding to existing; new value = %d\n", value);
            entry->value = value;
            break;
        }
        if (entry->nextEntry == NULL) {
            entry->nextEntry = malloc(sizeof(NodeEntry*));
            printf("create entry: %p\n", entry);
        }
        entry = (NodeEntry *) entry->nextEntry;
    }
    printBucket(map->buckets[hash], hash);
}

int getFromHm(HashMap* map, char* key) {
    int hash = hashCode(key);
    NodeEntry* entry = map->buckets[hash];
    while (entry != NULL) {
        if (entry->key == NULL) {
            return null;
        }
        if (strcmp(entry->key, key) == 0) {
            return entry->value;
        }
        entry = (NodeEntry *) entry->nextEntry;
    }
    return null;
}

int getFromHmOrDefault(HashMap* map, char* key, int defaultValue) {
    int value = getFromHm(map, key);
    return value == null ? defaultValue : value;
}

void removeFromHm(HashMap* map, char* key) {
    int hash = hashCode(key);
    NodeEntry* entry = map->buckets[hash];

    if (strcmp(entry->key, key) == 0) {
        NodeEntry* toBeFirst = (NodeEntry *) entry->nextEntry;
        if (toBeFirst == NULL) {
            toBeFirst = malloc(sizeof(NodeEntry*));
        }
        map->buckets[hash] = toBeFirst;
        free(entry);
        return;
    }

    NodeEntry* previous = entry;
    NodeEntry* next;
    NodeEntry* toRemove;

    while (1) {
        entry = (NodeEntry *) entry->nextEntry;
        if (strcmp(entry->key, key) == 0) {
            toRemove = entry;
            next = (NodeEntry *) entry->nextEntry;
            break;
        }
        previous = entry;
    }
    previous->nextEntry = (struct NodeEntry *) next;
    free(toRemove);
}

void hashMapToString(HashMap* map) {
    for (int i = 0; i < CAPACITY; i++) {
        NodeEntry* entry = map->buckets[i];
        do {
            if (entry == NULL) {
                break;
            }
            if (entry->key == NULL) {
                break;
            }
//            printf("[%s => %d; address => %p]\n", entry->key, entry->value, entry);
            printf("[%s => %d]\n", entry->key, entry->value);
            entry = (NodeEntry *) entry->nextEntry;
        } while (1);
    }
}

void printBucket(NodeEntry* entry, int bucketHash) {
    while (entry != NULL) {
        printf("Bucket%d :: [%s => %d]\n", bucketHash, entry->key, entry->value);
        entry = (NodeEntry *) entry->nextEntry;
        printf("NextEntry = %p\n", entry);
    }
}
