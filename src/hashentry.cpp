#include "hashentry.hpp"

template <typename K, typename V>
HashEntry<K,V>::HashEntry(const K& key, const V& value) {
    this->key = key;
    this->value = value;
    this->next = NULL;
}

template <typename K, typename V>
K HashEntry<K,V>::getKey() const {
    return this->key;
}

template <typename K, typename V>
V HashEntry<K,V>::getValue() const {
    return this->value;
}

template <typename K, typename V>
void HashEntry<K,V>::setValue(const V& value) {
    this->value = value;
}

template <typename K, typename V>
HashEntry<K,V>* HashEntry<K,V>::getNext() const {
    return this->next;
}

template <typename K, typename V>
void HashEntry<K,V>::setNext(HashEntry* next) {
    this->next = next;
}

template <typename K, typename V>
std::ostream& operator<< (std::ostream& stream, IHashEntry<K,V>* e) {
    HashEntry<K, V>* entry = dynamic_cast<HashEntry<K, V>*>(e);

    while (entry != NULL) {
        stream << entry->getKey();
        stream << " - ";
        stream << entry->getValue();
        stream << std::endl;

        entry = entry->getNext();
    }

    return stream;
}

template <typename K, typename V>
void HashEntry<K,V>::insert(const K& key, const V& value) {
    HashEntry<K, V>* entry = this;
    HashEntry<K,V>* new_entry = new HashEntry<K,V>(key,value);

    while(entry && entry->getKey() != key) {
        if(entry->getKey() == key && entry->getValue() == value) return;
        if(entry->getNext())
            entry = entry->getNext();
        else
            break;
    }

    if(entry->getKey() == key) {
        entry->setValue(value);
    } else {
        entry->setNext(new_entry);
    }
}

template <typename K, typename V>
void HashEntry<K,V>::remove(const K& key, const V& value) {
    if(this->getKey() == key && this->getValue() == value) return;

    HashEntry<K, V>* curr = this;
    HashEntry<K,V>* prev;

    while(curr) {
        if(curr->getKey() == key && curr->getValue() == value) {
            if(prev) {
                prev->setNext(curr->getNext());
            }
            delete curr;
            curr = nullptr;
            break;
        }
        prev = curr;
        curr = curr->getNext();
    }
}

template <typename K, typename V>
IHashEntry<K, V>* HashEntry<K,V>::search(const K& key, const V& value) {
    HashEntry<K,V>* entry = this;
    while(entry) {
        if(entry->getKey() == key && entry->getValue() == value)
            return entry;
        entry = entry->getNext();
    }

    return nullptr;
}