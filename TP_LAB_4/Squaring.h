#pragma once
#include <iostream>
#include "safe_input.h"
using namespace std;
template <typename T>
class Squaring {
public:
    int m_size;
    int m_capacity;
    T* m_data;
    Squaring();
    Squaring(const Squaring<T>&a);
    Squaring(int);
    ~Squaring();
    void resize(int);
    void push_back(T);
    int size() const;
    T Summ();
    T Aver();
    void operator + (Squaring<T>);
    void operator - (Squaring<T>);
    bool operator != (Squaring<T>);
    bool operator < (Squaring<T>);
};
template<typename T>
ostream& operator << (ostream& out, Squaring<T> a)
{
    for (int i = 0; i < a.size(); ++i)
        out << a.m_data[i] << " ";
    return out;
}
template<typename T>
istream& operator >> (istream& in, Squaring<T>& a)
{
    T val;
    while(1) {
        in >> val;
        if (cin.good())
           a.push_back(val);
        else {
            cin.clear();
            cin.ignore(100, '\n');
            system("cls");
            break;
        }
        cin.clear();
        cin.ignore(100, '\n');
    }
    return in;
}



