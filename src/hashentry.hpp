#ifndef __IHASH_ENTRY__
#define __IHASH_ENTRY__

#include <iostream>

template <typename K, typename V>
class IHashEntry;

template <typename K, typename V>
class IHashEntry {
public:
    virtual K getKey() const = 0;
    virtual V getValue() const = 0;
    virtual void insert(const K& key, const V& value) = 0;
    virtual void remove(const K& key, const V& value) = 0;
    virtual IHashEntry<K, V>* search(const K& key, const V& value) = 0;
};

template <typename K, typename V>
class HashEntry;
template <typename K, typename V>
std::ostream& operator<<(std::ostream& stream, IHashEntry<K, V>*);

template <typename K, typename V>
class HashEntry : public IHashEntry<K, V> {
private:
    K key;
    V value;
    HashEntry* next;

    void setValue(const V& value);

    HashEntry* getNext() const;
    void setNext(HashEntry* next);
public:
    HashEntry(const K& key, const V& value);
    K getKey() const;
    V getValue() const;

    friend std::ostream& operator<<<K, V>(std::ostream& stream, IHashEntry<K, V>* e);

    void insert(const K& key, const V& value);
    void remove(const K& key, const V& value);
    IHashEntry<K, V>* search(const K& key, const V& value);
};

#endif