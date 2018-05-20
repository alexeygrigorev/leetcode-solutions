#include "heap.h"
#include "gtest/gtest.h"

using namespace std;

TEST(HeapTest, Test_Min_Heap_1) {
    Heap *heap = Heap::min_heap();
    heap->push(10);
    EXPECT_EQ(10, heap->peek());
    EXPECT_EQ(10, heap->pop());
}

TEST(HeapTest, Test_Min_Heap_2) {
    Heap *heap = Heap::min_heap();
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


TEST(HeapTest, Test_Min_Heap_3) {
    Heap *heap = Heap::min_heap();
    vector<int> sorted = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    for (int el : sorted) {
        heap->push(el);
    }

    for (int el : sorted) {
        EXPECT_EQ(el, heap->pop());
    }
}

TEST(HeapTest, Test_Min_Heap_4) {
    Heap *heap = Heap::min_heap();
    vector<int> elements = {5, 6, 12, 3, 7, 80, 1, 40, 2, 5, 7, 3, 10};
    vector<int> sorted(elements);
    sort(sorted.begin(), sorted.end());

    for (int el : elements) {
        printf("push %d\n", el);
        heap->push(el);
    }


    for (int el : sorted) {
        printf("pop %d\n", el);
        EXPECT_EQ(el, heap->pop());
    }
}

TEST(HeapTest, Test_Max_Heap_3) {
    Heap *heap = Heap::max_heap();
    vector<int> sorted = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    for (int el : sorted) {
        heap->push(el);
    }

    reverse(sorted.begin(), sorted.end());

    for (int el : sorted) {
        EXPECT_EQ(el, heap->pop());
    }
}

TEST(HeapTest, Test_Max_Heap_4) {
    Heap *heap = Heap::max_heap();
    vector<int> elements = {5, 6, 12, 3, 7, 80, 1, 40, 2, 5, 7, 3, 10};
    vector<int> sorted(elements);
    sort(sorted.rbegin(), sorted.rend());

    for (int el : elements) {
        printf("push %d\n", el);
        heap->push(el);
    }

    for (int el : sorted) {
        printf("pop %d\n", el);
        EXPECT_EQ(el, heap->pop());
    }
}
