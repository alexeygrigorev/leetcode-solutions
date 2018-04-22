#include <string>
#include <vector>
#include <iostream>

#include "debug.h"

using namespace std;

void print(vector<int>& v) {
    int len = v.size();

    for (int i = 0; i < len; i++) {
        cout << v[i] << " ";
    }

    cout << endl;
}

void print(int* v, int len) {
    for (int i = 0; i < len; i++) {
        cout << v[i] << " ";
    }

    cout << endl;
}

void print_no_endl(int* array, int start, int end) {
    for (int i = start; i < end; i++) {
        cout << array[i] << " ";
    }
}