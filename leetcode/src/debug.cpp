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