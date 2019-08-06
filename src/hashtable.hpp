#ifndef __HASH_TABLE___
#define __HASH_TABLE___

#include "hashentry.hpp"
#include "hashfunc.hpp"
#include <iostream>
#include <memory>

#define MAX_ENTRY 100

template<typename K, typename V, typename H>
class HashTable {
private:
    IHashEntry<K,V> *table[MAX_ENTRY];
    std::unique_ptr<IHashFunc<K, H>> func;

public:
    HashTable(std::unique_ptr<IHashFunc<K,H>>&);
    ~HashTable();

    void insert(const K& key, const V& value);
    IHashEntry<K,V>* search(const K& key, const V& value);
    void remove(const K& key, const V& value);

    void print();
};

#endif