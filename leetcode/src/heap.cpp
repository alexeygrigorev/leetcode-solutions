#include <vector>
#include "heap.h"

using namespace std;

int Heap::peek() {
    return data.front();
}

int Heap::pop() {
    int result = peek();
    data[0] = data.back();
    data.pop_back();

    int p = 0;

    while (true) {
        bool with_left = has_left(p);
        bool with_right = has_right(p);
        if (!with_left && !with_right) {
            break;
        }

        int l = left(p);
        int r = right(p);

        if (with_left && !with_right) {
            if (compare(p, l)) {
                int tmp = data[l];
                data[l] = data[p];
                data[p] = tmp;
            }
            break;
        }

        if (compare(p, l) || compare(p, r)) {
            if (compare(l, r)) {
                int tmp = data[l];
                data[l] = data[p];
                data[p] = tmp;
                p = l;
            } else {
                int tmp = data[l];
                data[l] = data[p];
                data[p] = tmp;
                p = r;
            }
        }
    }

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
