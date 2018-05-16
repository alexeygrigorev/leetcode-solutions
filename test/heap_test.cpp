#include "heap.h"
#include "gtest/gtest.h"

using namespace std;

TEST(HeapTest, Test_Min_Heap_1) {
    Heap *heap = Heap::max_heap();
    heap->push(10);
    EXPECT_EQ(10, heap->peek());
    EXPECT_EQ(10, heap->pop());
}

TEST(HeapTest, Test_Min_Heap_2) {
    Heap *heap = Heap::max_heap();
    heap->push(10);
    EXPECT_EQ(10, heap->peek());

    heap->push(2);
    EXPECT_EQ(2, heap->peek());

    heap->push(20);
    EXPECT_EQ(2, heap->peek());

    EXPECT_EQ(2, heap->pop());
    EXPECT_EQ(10, heap->pop());
    EXPECT_EQ(20, heap->pop());
}
