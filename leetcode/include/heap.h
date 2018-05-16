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

private:
    Heap(bool is_min);

    bool is_min;
    vector<int> data;
    int parent(int i);
    int left(int i);
    int right(int i);
};
