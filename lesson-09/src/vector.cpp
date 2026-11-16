#include "vector.hpp"

namespace my
{

template<class T>
void vector<T>::push_back(const T& value)
{
    data_[0] = value;
}

template class vector<int>;
template class vector<double>;
template class vector<std::string>;

} // namespace my
