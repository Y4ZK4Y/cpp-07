/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ykarimi <ykarimi@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/08/13 14:53:02 by ykarimi       #+#    #+#                 */
/*   Updated: 2025/08/25 13:56:54 by ykarimi       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "iter.hpp"

// A print function template (takes const ref)
template <typename T>
void print(T const& v) {
    std::cout << v << '\n';
}

// A modifier function template (takes non-const ref)
template <typename T>
void increment(T& v) { ++v; }


int main() {
    // ints: mutate, then print
    int a[] = {1, 2, 3, 4};
    ::iter(a, 4, increment<int>);   // OK: non-const array -> T&
    ::iter(a, 4, print<int>);       // OK: const-ref also fine

    std::cout << "----\n";

    // strings (const array): only const ops allowed
    std::string s1[] = {"chaine1", "chaine2"};
    ::iter(s1, 2, print<std::string>);

    std::cout << "----\n";

    // const array
    const std::string s2[] = {"alpha", "beta", "gamma"};
    ::iter(s2, 3, print<std::string>); // OK
    // ::iter(s2, 3, increment<std::string>); // would fail to compile, as intended

    return 0;
}


/*
a baby version of std::for_each for raw arrays
about writing a generic iter that preserves const-ness so it can call a
function that takes either T& or T const&.

/*
Learning objectives:
    function templates with type parameters
    arrays decay to pointers - ?
    const correctness
    wtf is a functor
    instantiated function template
    generic callable
*/


/*
separate traversal from work - one loop, many possible actions
must accept any element type T - int[] std::string[] Box[]
the third parameter could be :
    function pointer : void f(T&) - void f(const T&)
    function template imstantiation - &print<int>
    functor - object with operator()
    a lambda

when you pass arr , it becomes T* - that's why you must pass the len separately
*/



/*
generic algorithm:
function you wite once and works for many types and operations - with zero runtime cost
how to make it generic:
    type parameterizing - template
    behavior parameterizing - you pass in what to do with each element;
    function, funcor or lambda
*/
