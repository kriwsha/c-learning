#include "hashfunc.h"

static const int null = -1;

/**
 * null pointer
 */
//struct NodeEntry* dummyEntry;

typedef struct  {
    char* key;
    int value;
} NodeEntry;

typedef struct {
    NodeEntry** buckets;
} HashMap;

/**
 * Creating hash map
 *
 * @return ...
 */
HashMap* createHashMap();

/**
 * Put value into hash map
 *
 * @param key ...
 * @param value ...
 */
void putToHm(HashMap* map, char* key, int value);

/**
 * Get value by key
 *
 * @param key ...
 * @return ...
 */
int getFromHm(HashMap* map, char* key);

/**
 * Get value by key or default value if no value found
 *
 * @param key ...
 * @param defaultValue ...
 * @return ...
 */
int getFromHmOrDefault(HashMap* map, char* key, int defaultValue);

/**
 * Remove entry by key
 *
 * @param key ...
 */
void removeFromHm(HashMap* map, char* key);

/**
 * Display data
 *
 * @param map ...
 */
void hashMapToString(HashMap* map);

void printBucket(NodeEntry* entry, int bucketHash);