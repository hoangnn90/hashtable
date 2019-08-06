#include "hashfunc.cpp"
#include <gtest/gtest.h>
#include <gmock/gmock.h>

TEST(HashFunc, constructor) {
    HashFunc<int, int>* func = new HashFunc<int, int>();
    delete func;
}

TEST(HashFunc, hash_func) {
    HashFunc<int, int> func;

    int key = 1;
    EXPECT_EQ(func(key), key%MAX_BUCKET);

    key = 11;
    EXPECT_EQ(func(key), key % MAX_BUCKET);
}