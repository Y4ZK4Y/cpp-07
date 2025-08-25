/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   template.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ykarimi <ykarimi@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/08/13 12:07:03 by ykarimi       #+#    #+#                 */
/*   Updated: 2025/08/25 13:50:31 by ykarimi       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <utility>

template <typename T>
void swap(T& a, T& b) {
    if (&a == &b)
        return;
    T temp = std::move(a);
    a = std::move(b);
    b = std::move(temp);
}

template <typename T>
T const& max(const T& a, const T& b) {
    return (a > b) ? a : b;
}
// if T is non-copyable (std::unique_ptr) , return by value (T) wont even compile

template <typename T>
T const& min(const T& a, const T& b) {
    return (a >= b) ? b : a;
}

/*
Notes:

Learning checklist:
    templates
    rvalue lvalue
    move semantics
    std::move and std::forward
*/

/*
Templates:

in java or c# templates are similar to "generics"
allows you to define a template that will be compiled based on your usage
to have the compiler write you code based on a set of rules - creating a blueprint

you might wanna define a template for a function that stays the same but takes different types
to prevent defining manual different overloads

evaluated at compile time
template parameter ==>  template <typename T> typename as the template parameter
and T as the name

some people ban using templates - they could be handy in logging, for example

modern cpp templates
std::move - a cast that turns an expression into an rvalue - 
doesnt move anything by itself, it enables move constructors to be chosen -
use when youre done with an object and want to transfer its resources

std::forward 
a conditional cast used with forwarding references
*/


/*
lvalues and rvalues:
int i = 10;
i is lvalue - a variable with a location in memory
10 is rvalue -  a value - no location no storage UNlESS it's assigned to an lvalue
rvalue could also be the result of a function - bc it's gonna be a tmeporary value
cannot assign someting to an rvalue

lvalue: an object that occupies some identifiable location in memory
rvalue: any object that is not lvalue

another example:
int i;
int& r = i;
r is lvalue reference

c++11 introduced rvalue reference
*/

/*
std::invoke
a unified call utility introduced in c++17

*/


/*
std::forward
a conditional cast
used with forwarding references (T&& in templates)
Guarantees “perfect forwarding”: the function you call sees
the parameter in the exact form the caller provided.

this F&& is not a normal rvalue reference (like int&&).
Inside a template, it’s called a forwarding reference
(used to be called “universal reference” by Scott Meyers)
*/