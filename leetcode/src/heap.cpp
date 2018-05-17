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

    while (has_parent(i)) {
        int p = parent(i);
        if (!compare(i, p)) {
            break;
        }

        int tmp = data[i];
        data[i] = data[p];
        data[p] = tmp;
        i = p;
    }
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

bool Heap::has_parent(int i) {
    return i != 0;
}

bool Heap::has_left(int i) {
    return left(i) < data.size();
}

bool Heap::has_right(int i) {
    return right(i) < data.size();
}

bool Heap::compare(int i1, int i2) {
    if (is_min) {
        return data[i1] < data[i2];
    } else {
        return data[i1] > data[i2];
    }
}
