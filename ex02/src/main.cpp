/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ykarimi <ykarimi@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/08/25 11:35:20 by ykarimi       #+#    #+#                 */
/*   Updated: 2025/08/25 13:09:06 by ykarimi       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Array.hpp"

struct Point {
    int x{0}, y{0};
};
std::ostream& operator<<(std::ostream& os, Point const& p) {
    return os << '(' << p.x << ',' << p.y << ')';
}

int main() {
    try {
        // 1) default construction
        Array<int> empty;
        std::cout << "empty.size() = " << empty.size() << '\n';
        try {
            // should throw
            (void)empty[0];
        } catch (std::exception const& e) {
            std::cout << "access empty[0] threw: " << e.what() << '\n';
        }

        // 2) sized construction: value-initialized (ints -> 0)
        Array<int> a(5);
        std::cout << "a.size() = " << a.size() << '\n';
        for (std::size_t i = 0; i < a.size(); ++i) {
            std::cout << "a[" << i << "] = " << a[i] << '\n';
            a[i] = static_cast<int>(i * 10);
        }

        // 3) copy semantics: deep copy
        Array<int> b = a;         // copy-ctor
        b[0] = 999;
        std::cout << "a[0] (should be 0) = " << a[0] << '\n';
        std::cout << "b[0] (should be 999) = " << b[0] << '\n';

        // 4) assignment
        Array<int> c(2);
        c = a;                    // copy-assign
        std::cout << "c.size() = " << c.size() << '\n';
        std::cout << "c[1] = " << c[1] << '\n';

        // 5) const correctness
        Array<std::string> s(3);
        s[0] = "alpha"; s[1] = "beta"; s[2] = "gamma";
        Array<std::string> s2 = s;
        Array<std::string> const sc = s2;
        std::cout << "sc[2] = " << sc[2] << '\n';
        try {
            std::cout << sc[99] << '\n';
        } catch (std::exception const& e) {
            std::cout << "out-of-bounds on const array: " << e.what() << '\n';
        }

        // 6) custom type + default init via new T[n]()
        Array<Point> pts(3);
        for (std::size_t i = 0; i < pts.size(); ++i) {
            pts[i].x = static_cast<int>(i);
            pts[i].y = static_cast<int>(i * i);
        }
        for (std::size_t i = 0; i < pts.size(); ++i) {
            std::cout << "pts[" << i << "] = " << pts[i] << '\n';
        }

        // 7) move semantics (optional)
        Array<int> moved = std::move(a);
        std::cout << "moved.size() = " << moved.size() << '\n';
        std::cout << "a.size() after move = " << a.size() << '\n';
    }
    catch (std::exception const& e) {
        std::cerr << "Unhandled exception: " << e.what() << '\n';
        return 1;
    }
    return 0;
}



/*
a small vector like templatte with deep cpy + bounds check

*/

/*
Learning objectivs:
    class templates
    rule of three
    const correctness
    move semantics
    RAI manual memory
    
*/


/*
class template
build one class that works for any T
templates are compiled when you use them -> definitions must be vidible in header 

*/

/*

*/