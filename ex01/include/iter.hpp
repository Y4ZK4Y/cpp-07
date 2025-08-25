/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   iter.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ykarimi <ykarimi@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/08/13 15:13:57 by ykarimi       #+#    #+#                 */
/*   Updated: 2025/08/25 13:58:07 by ykarimi       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstddef>

// non-const array
template <typename T, typename F> 
void iter(T* array, std::size_t len, F func) {
    if (!array)
        return ;
    for (std::size_t i = 0; i < len; i++)
        func(array[i]);
}

// const array
template <typename T, typename F> 
void iter(T const* array, std::size_t len, F func) {
    if (!array)
        return ;
    for (std::size_t i = 0; i < len; i++)
        func(array[i]);
}

// can also use std::forward