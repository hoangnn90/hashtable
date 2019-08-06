#ifndef __IHASH_FUNC__
#define __IHASH_FUNC__

template<typename K, typename H>
class IHashFunc
{
public:
    virtual H operator()(const K& key) = 0;
    virtual ~IHashFunc() {}
};

template<typename K, typename H>
class HashFunc : public IHashFunc<K,H> {
public:
    HashFunc();
    virtual H operator()(const K& key);
    virtual ~HashFunc() {}
};

#endif