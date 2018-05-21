#include <vector>
#include "heap.h"
#include "debug.h"

using namespace std;


void Heap::assert_heap_property() {
    if (data.size() <= 1) {
        return;
    }

    for (int i = 1; i < data.size(); i++) {
        int p = parent(i);
        if (!compare(p, i) && (data[p] != data[i])) {
            printf("heap property violated: data[%d]=%d & data[%d]=%d\n", p, data[p], i, data[i]);
            throw exception();
        }
    }
}

int Heap::peek() {
    int result = data.front();
    return result;
}

int Heap::pop() {
    int result = data.front();

    if (data.size() == 1) {
        data.pop_back();
        return result;
    }

    data[0] = data.back();
    data.pop_back();

    bubble_down(0);

    assert_heap_property();
    return result;
}

void Heap::push(int k) {
    int i = data.size();
    data.push_back(k);
    bubble_up(i);
    assert_heap_property();
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
    return (i - 1) / 2;
}

int Heap::left(int i) {
    return 2 * i + 1;
}

int Heap::right(int i) {
    return 2 * i + 2;
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

void Heap::bubble_up(int i) {
    if (!has_parent(i)) {
        return;
    }

    int p = parent(i);
    if (compare(i, p)) {
        swap(i, p);
        bubble_up(p);
    }
}

void Heap::bubble_down(int p) {
    if (!has_left(p)) {
        return;
    }

    if (!has_right(p)) {
        // here we compare it with only left child
        int l = left(p);
        if (compare(l, p)) {
            swap(l, p);
        }
        // no need to continue since l if a leaf anyway
        return;
    }

    int l = left(p);
    int r = right(p);

    if (compare(p, l) && compare(p, r)) {
        return;
    }

    if (compare(l, r)) {
        swap(p, l);
        bubble_down(l);
    } else {
        swap(p, r);
        bubble_down(r);
    }
}

void Heap::swap(int i, int j) {
    int tmp = data[i];
    data[i] = data[j];
    data[j] = tmp;
}

void Heap::print_content() {
    print(data);
}

int Heap::size() {
    return data.size();
}
