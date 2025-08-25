/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ykarimi <ykarimi@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/08/13 12:13:16 by ykarimi       #+#    #+#                 */
/*   Updated: 2025/08/25 13:43:58 by ykarimi       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "template.hpp"
#include <iostream>


int main() {
    int a = 2;
    int b = 2;

    ::swap(a, b);
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
    std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
    std::string c = "chaine1";
    std::string d = "chaine2";
    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
    std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

    // same object passed twice
    int x = 42;
    ::swap(x, x);
    std::cout << "Min: " << ::min(x, x) << std::endl;
    std::cout << "Max: " << ::max(x, x) << std::endl;
    
    int e = 5, f = 5;
    const int& r1 = ::min(e, f);  // must be f
    const int& r2 = ::max(e, f);  // must be f
    std::cout << (&r1 == &f) << " " << (&r2 == &f) << "\n"; // expect 1 1

    // c string
    const char* s1 = "abc";
    const char* s2 = "abd";
    std::cout << ::min(s1, s2) << "\n"; // compares addresses not contents
    std::string S1 = "abc", S2 = "abd";
    std::cout << ::min(S1, S2) << "\n";

    return 0;
}
