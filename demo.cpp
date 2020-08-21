// Include header
#include "demo.h"

// My includes
#include "exceptions.h"
#include "searching.h"
#include "sorting.h"

// Includes (streams)
#include <iostream>

// Includes (data structures)
#include <vector>
#include <array>
#include <deque>
#include <list>
#include <stack>
#include <queue>
#include <set>
#include <map>

//////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////

void Demo::what() const noexcept {
    Algorithms::Searching::what();
    Algorithms::Sorting::what();
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////

void Demo::searching() const {
    this->contains();
    this->linear_search();
    this->binary_search();
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////

void Demo::contains(void) const noexcept {
    std::cout << "Demo for containers applied to the template method " << __FUNCTION__ << "\n";
    std::cout << "Results expected for each containers :\n\t1\n\t0" << "\n";

    // Demo Sequence Containers
    std::cout << "Vector\n";
    std::vector<int> v {1, 2, 3, 8};
    std::cout << Algorithms::Searching::contains(v, 3) << "\n"; // true
    std::cout << Algorithms::Searching::contains(v, 4) << "\n"; // false
    std::cout << "\n";


    std::cout << "Array\n";
    std::array<int, 8> a;
    for(int i(0); i < 8; ++i)
    { a[i] = i; }
    std::cout << Algorithms::Searching::contains(a, 3) << "\n"; // true
    std::cout << Algorithms::Searching::contains(a, 9) << "\n"; // false
    std::cout << "\n";


    std::cout << "Deque\n";
    std::deque<int> d(4, 5);
    std::cout << Algorithms::Searching::contains(d, 5) << "\n"; // true
    std::cout << Algorithms::Searching::contains(d, 6) << "\n"; // false
    std::cout << "\n";


    std::cout << "List\n";
    std::list<int> l(4, 5);
    std::cout << Algorithms::Searching::contains(l, 5) << "\n"; // true
    std::cout << Algorithms::Searching::contains(l, 6) << "\n"; // false
    std::cout << "\n";


    // Demo Container Adaptors
    std::cout << "Stack\n";
    std::stack<int> st;
    st.push(3); st.push(4); st.push(5);
    std::cout << Algorithms::Searching::contains(st, 5) << "\n"; // true
    std::cout << Algorithms::Searching::contains(st, 6) << "\n"; // false
    std::cout << "\n";


    std::cout << "Queue\n";
    std::stack<int> q;
    q.push(3); q.push(4); q.push(5);
    std::cout << Algorithms::Searching::contains(q, 5) << "\n"; // true
    std::cout << Algorithms::Searching::contains(q, 6) << "\n"; // false
    std::cout << "\n";


    // Demo Associative Containers
    std::cout << "Set\n";
    std::set<int> se{1, 2, 3};
    std::cout << Algorithms::Searching::contains(se, 3) << "\n"; // true
    std::cout << Algorithms::Searching::contains(se, 5) << "\n"; // false
    std::cout << "\n";


    std::cout << "Multiset\n";
    std::multiset<int> ms{1, 2, 3};
    std::cout << Algorithms::Searching::contains(ms, 3) << "\n"; // true
    std::cout << Algorithms::Searching::contains(ms, 5) << "\n"; // false
    std::cout << "\n";


    std::cout << "Map\n";
    std::map<char,int> m{{'a', 1}, {'b', 2}, {'c', 3}};
    std::cout << Algorithms::Searching::contains(m, 'a') << "\n"; // true
    std::cout << Algorithms::Searching::contains(m, 'd') << "\n"; // false
    std::cout << "\n";


    std::cout << "Multimap\n";
    std::multimap<char, int> mm{{'a', 1}, {'b', 2}, {'c', 3}};
    std::cout << Algorithms::Searching::contains(mm, 'a') << "\n"; // true
    std::cout << Algorithms::Searching::contains(mm, 'd') << "\n"; // false
    std::cout << "\n";
} // end contains

void Demo::linear_search() const {
    throw new Algorithms::NotImplementedMethodException(__FUNCTION__);
    std::cout << "Demo for containers applied to the template method " << __FUNCTION__ << "\n";
    std::cout << "Results expected for each containers :\n\t1\n\t0" << "\n";
} // end linear search

void Demo::binary_search() const {
    throw new Algorithms::NotImplementedMethodException(__FUNCTION__);
    std::cout << "Demo for containers applied to the template method " << __FUNCTION__ << "\n";
    std::cout << "Results expected for each containers :\n\t1\n\t0" << "\n";
} // end linear search

