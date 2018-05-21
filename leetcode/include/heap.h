#include <vector>

using namespace std;

class Heap {
public:
    int peek();
    int pop();
    void push(int k);

    static Heap* min_heap();
    static Heap* max_heap();
    ~Heap();

    int size();
    void print_content();

private:
    Heap(bool is_min);

    bool is_min;
    vector<int> data;
    int parent(int i);
    bool has_parent(int i);
    int left(int i);
    bool has_left(int i);
    int right(int i);
    bool has_right(int i);

    void bubble_up(int i);
    void bubble_down(int p);

    void swap(int i, int j);

    bool compare(int i1, int i2);

    void assert_heap_property();
};
