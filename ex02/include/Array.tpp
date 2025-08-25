/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Array.tpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ykarimi <ykarimi@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/08/25 13:06:44 by ykarimi       #+#    #+#                 */
/*   Updated: 2025/08/25 13:31:48 by ykarimi       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// default constructor - builds an empty array
template <typename T>
Array<T>::Array() noexcept : _size(0), _data(nullptr) {   
}

// constructor - allocates n elements
template <typename T>
Array<T>::Array(unsigned int n): _size(n), _data(n ? new T[n]() : nullptr) {
}

// copy ctor - allocates its own buffer, and copies each element(deep copy)
template <typename T>
Array<T>::Array(Array const& other): _size(other._size), _data(_size ? new T[_size] : nullptr) {
    for (std::size_t i = 0; i < _size; ++i)
        _data[i] = other._data[i];
}

template <typename T>
Array<T>& Array<T>::operator=(Array const& other) {
    if (this == &other) return *this;
    Array tmp(other);   // copy-construct
    swap(tmp);          // strong exception safety
    return *this;
}

template <typename T>
Array<T>::Array(Array&& other) noexcept
    : _size(other._size), _data(other._data) {
    other._size = 0;
    other._data = nullptr;
}

template <typename T>
Array<T>& Array<T>::operator=(Array&& other) noexcept {
    if (this == &other) return *this;
    delete[] _data;
    _size = other._size;
    _data = other._data;
    other._size = 0;
    other._data = nullptr;
    return *this;
}

template <typename T>
Array<T>::~Array() {
    delete[] _data;
}

template <typename T>
T& Array<T>::operator[](std::size_t i) {
    if (i >= _size) throw std::out_of_range("Array index out of bounds");
    return _data[i];
}

template <typename T>
T const& Array<T>::operator[](std::size_t i) const {
    if (i >= _size) throw std::out_of_range("Array index out of bounds");
    return _data[i];
}

template <typename T>
std::size_t Array<T>::size() const noexcept {
    return _size;
}

template <typename T>
void Array<T>::swap(Array& other) noexcept {
    std::swap(_size, other._size);
    std::swap(_data, other._data);
}
