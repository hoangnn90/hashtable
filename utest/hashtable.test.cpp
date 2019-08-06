#include "hashtable.cpp"
#include <gtest/gtest.h>
#include <gmock/gmock.h>

TEST(HashTable, contructor) {
    std::unique_ptr<IHashFunc<int, int>> func = std::make_unique<HashFunc<int, int>>();
    HashTable<int, int, int>* table = new HashTable<int, int, int>(func);
    delete table;
}

TEST(HashTable, insert) {
    std::unique_ptr<IHashFunc<int, int>> func = std::make_unique<HashFunc<int, int>>();
    HashTable<int, int, int> table(func);
    table.insert(1, 2);
    table.insert(2, 3);

    EXPECT_FALSE(table.search(2, 3) == nullptr);
    table.print();
}

TEST(HashTable, insert_same_hash) {
    std::unique_ptr<IHashFunc<int, int>> func = std::make_unique<HashFunc<int, int>>();
    HashTable<int, int, int> table(func);
    table.insert(1, 2);
    table.insert(11, 2);

    EXPECT_FALSE(table.search(11, 2) == nullptr);
    table.print();
}

TEST(HashTable, insert_duplicate) {
    std::unique_ptr<IHashFunc<int, int>> func = std::make_unique<HashFunc<int, int>>();
    HashTable<int, int, int> table(func);
    table.insert(1, 2);
    table.insert(1, 2);

    table.print();
}

TEST(HashTable, insert_and_remove) {
    std::unique_ptr<IHashFunc<int, int>> func = std::make_unique<HashFunc<int, int>>();
    HashTable<int, int, int> table(func);
    table.insert(1, 2);
    table.remove(1, 2);

    EXPECT_TRUE(table.search(1, 2) == nullptr);

    table.print();
}