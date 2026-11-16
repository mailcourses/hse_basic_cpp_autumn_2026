#pragma once

#include <iostream>

namespace my
{

template<class T>
class vector
{
public:
    vector(size_t size) : size_(size), data_(new T[size_]) {}
    void push_back(const T& value);
private:
    size_t size_;
    T* data_;
};

/*
template<class T>
void vector<T>::push_back(const T& value)
{
    data_[0] = value;
}
*/
} // namespace my

#include "vector.tpp"
