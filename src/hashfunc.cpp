#include "hashfunc.hpp"
#include <iostream>

#define MAX_BUCKET 10

template<typename K, typename H>
HashFunc<K,H>::HashFunc() {
}

template<typename K, typename H>
H HashFunc<K,H>::operator()(const K& key) {
    return key%MAX_BUCKET;
}
