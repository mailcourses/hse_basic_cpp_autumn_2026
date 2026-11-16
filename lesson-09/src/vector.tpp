#include "vector.hpp"

namespace my
{

template<class T>
void vector<T>::push_back(const T& value)
{
    data_[0] = value;
}

} // namespace my
