#include <vector>
#include "heap.h"

using namespace std;

int Heap::peek() {
    return data.front();
}

int Heap::pop() {
    int result = peek();
    return result;
}

void Heap::push(int k) {
    int i = data.size();
    data.push_back(k);

}

Heap *Heap::min_heap() {
    return new Heap(true);
}

Heap *Heap::max_heap() {
    return new Heap(false);
}

Heap::Heap(bool is_min) {
    this->is_min = is_min;
}

int Heap::parent(int i) {
    return i / 2;
}

int Heap::left(int i) {
    return 2 * i;
}

int Heap::right(int i) {
    return 2 * i + 1;
}