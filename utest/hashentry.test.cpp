#include "hashentry.cpp"
#include <gtest/gtest.h>
#include <gmock/gmock.h>

TEST(HashEntry, constructor) {
    HashEntry<int, int>* entry = new HashEntry<int, int>(1, 2);
    delete entry;
}

TEST(HashEntry, get_key_and_value) {
    int key = 1;
    int value = 2;

    HashEntry<int, int> entry(key, value);
    EXPECT_EQ(entry.getKey(), key);
    EXPECT_EQ(entry.getValue(), value);

    std::string svalue = "Test";
    HashEntry<int, std::string> sentry(key, svalue);
    EXPECT_EQ(sentry.getKey(), key);
    EXPECT_STREQ(sentry.getValue().c_str(), svalue.c_str());
}

TEST(HashEntry, operator) {
    int key = 1;
    int value = 2;

    HashEntry<int, int> entry(key, value);

    std::cout << &entry;
}

TEST(HashEntry, insert_normal) {
    int key = 1;
    int value = 2;

    HashEntry<int, int> entry(key, value);

    entry.insert(2, 3);

    EXPECT_TRUE(entry.search(2, 3) != nullptr);
}

TEST(HashEntry, insert_remove) {
    int key = 1;
    int value = 2;

    HashEntry<int, int> entry(key, value);

    entry.insert(2, 3);

    entry.remove(2, 3);

    EXPECT_TRUE(entry.search(2, 3) == nullptr);

    // entry.remove(1, 2);
}

TEST(HashEntry, insert_duplicate) {
    int key = 1;
    int value = 2;

    HashEntry<int, int> entry(key, value);

    entry.insert(1, 2);

    std::cout << &entry;
}

TEST(HashEntry, insert_same_key) {
    int key = 1;
    int value = 2;

    HashEntry<int, int> entry(key, value);

    entry.insert(1, 3);

    entry.insert(1, 4);

    std::cout << &entry;
}

TEST(HashEntry, insert_multiple_key) {
    int key = 1;
    int value = 2;

    HashEntry<int, int> entry(key, value);

    entry.insert(3, 4);

    entry.insert(5, 6);

    std::cout << &entry;
}

TEST(HashEntry, remove_twice) {
    int key = 1;
    int value = 2;

    HashEntry<int, int> entry(key, value);

    entry.insert(2, 3);

    entry.remove(2, 3);

    entry.remove(2, 3);
}
