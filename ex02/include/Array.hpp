/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Array.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ykarimi <ykarimi@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/08/25 11:35:12 by ykarimi       #+#    #+#                 */
/*   Updated: 2025/08/25 13:23:06 by ykarimi       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstddef>     // std::size_t
#include <stdexcept>   // std::out_of_range
#include <utility>     // std::swap

template <typename T>
class Array {

private:
    std::size_t _size; // num of elements
    T* _data; // 

public:
    Array() noexcept; // default constructor
    explicit Array(unsigned int n); // constructor
    Array(Array const& other); // copy constrcutor
    Array& operator=(Array const& other); // copy assignment
    Array(Array&& other) noexcept; // move constructor 
    Array& operator=(Array&& other) noexcept; // move assignment
    ~Array(); // destrcutor

    T& operator[](std::size_t i);
    T const& operator[](std::size_t i);

    std::size_t size() const noexcept; // returns num of elements
    
    void swap(Array& other) noexcept;
};

#include "Array.tpp"