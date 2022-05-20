#pragma once
#include <iostream>
using namespace std;
template <typename T>
void SQ(T* arr, int size) {
    if (size == 0) { cout << "Array is empty" << endl; return; }
    for (int i = 0; i < size; i++) {
        arr[i] *= arr[i];
    }
}