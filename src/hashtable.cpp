#include "hashtable.hpp"

template<typename K, typename V, typename H>
HashTable<K,V,H>::HashTable(std::unique_ptr<IHashFunc<K,H>>& func) : func(std::move(func)), table() {
}

template<typename K, typename V, typename H>
HashTable<K,V,H>::~HashTable() {
    for(int i=0; i<MAX_ENTRY; ++i) {
        delete table[i];
        table[i] = NULL;
    }
}

template<typename K, typename V, typename H>
void HashTable<K,V,H>::insert(const K& key, const V& value) {
    H hash = (*func)(key);

    IHashEntry<K,V>* entry = table[hash];

    if (entry) {
        entry->insert(key, value);
    } else {
        table[hash] = dynamic_cast<IHashEntry<K,V>*>(new HashEntry<K,V>(key,value));
    }
}

template<typename K, typename V, typename H>
IHashEntry<K,V>* HashTable<K,V,H>::search(const K& key, const V& value) {
    H h = (*this->func)(key);
    if(table[h]) {
        std::cout << "===> Table h" << std::endl;
        return table[h]->search(key, value);
    }

    return nullptr;
}

template<typename K, typename V, typename H>
void HashTable<K,V,H>::remove(const K& key, const V& value) {
    H hash = (*this->func)(key);
    if(table[hash])
        table[hash]->remove(key, value);
}

template<typename K, typename V, typename H>
void HashTable<K,V,H>::print() {
    for(int i=0; i<MAX_ENTRY; ++i) {
        IHashEntry<K, V>* entry = table[i];
        if(entry) {
            std::cout << entry;
        }
    }
}