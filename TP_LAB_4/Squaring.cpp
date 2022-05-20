#include "Squaring.h"
template Squaring<int>;
template Squaring<float>;
template <typename T>
Squaring<T>::Squaring() {
    m_size = 0;
    m_capacity = 0;
    m_data = NULL;
}
template <typename T>
Squaring<T>::Squaring(const Squaring<T>& a) {
    m_size = a.m_size;
    m_capacity = m_size;
    m_data = NULL;
    if (m_size != 0)
        m_data = new T[m_size];
    else
        m_data = 0;
    for (int i = 0; i < m_size; ++i)
        m_data[i] = a.m_data[i];
}
template <typename T>
Squaring<T>::Squaring(int size) {
    m_size = size;
    m_capacity = size;
    if (size != 0)
        m_data = new T[size];
    else
        m_data = 0;
}
template <typename T>
Squaring<T>::~Squaring() {
    if (m_data)
        delete[] m_data;
}
template <typename T>
void Squaring<T>::resize(int size)
{
    if (size > m_capacity)
    {
        int new_capacity = max(size, m_size * 2);
        T* new_data = new T[new_capacity];
        for (int i = 0; i < m_size; ++i)
            new_data[i] = m_data[i];
        delete[] m_data;
        m_data = new_data;
        m_capacity = new_capacity;
    }
    m_size = size;
}
template <typename T>
void Squaring<T>::push_back(T val)
{
    resize(m_size + 1);
    m_data[m_size - 1] = val;
}
template <typename T>
int Squaring<T>::size() const
{
    return m_size;
}

template <typename T>
T Squaring<T>::Summ() {
    if (m_size == 0) { cout << "Array is empty" << endl; return 0; }
    T sum = 0;
    for (int i = 0; i < m_size; i++) {
        sum += m_data[i];
    }
    return sum;
}
template <typename T>
T Squaring<T>::Aver() {
    if (m_size == 0) { cout << "Array is empty" << endl; return 0; }
    T sum = 0;
    for (int i = 0; i < m_size; i++) {
        sum += m_data[i];
    }
    sum /= m_size;
    return sum;
}
template<typename T>
void Squaring<T>::operator+(Squaring<T> arr)
{
    if (this->m_size < arr.m_size) {
        for (int i = this->m_size; i < arr.m_size; i++) {
            this->push_back(arr.m_data[i]);
        }
    }
    for (int i = 0; i < this->m_size; i++) {
        this->m_data[i] += arr.m_data[i];
    }
}
template<typename T>
void Squaring<T>::operator-(Squaring<T> arr)
{
    if (this->m_size < arr.m_size) {
        for (int i = this->m_size; i < arr.m_size; i++) {
            this->push_back(0);
        }
    }
    for (int i = 0; i < arr.m_size; i++) {
        this->m_data[i] -= arr.m_data[i];
    }
}
template<typename T>
bool Squaring<T>::operator!=(Squaring<T> arr)
{
    if (this->m_size != arr.m_size) return 1;
    bool flag = 1;
    for (int i = 0; i < arr.m_size; i++) if (this->m_data[i] != arr.m_data[i]) return 1;
    return 0;
}
template<typename T>
bool Squaring<T>::operator<(Squaring<T> arr)
{
    if (this->Summ() < arr.Summ()) return 1;
    return 0;
}



