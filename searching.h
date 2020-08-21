#ifndef SEARCHING_H
#define SEARCHING_H

// My includes
#include "exceptions.h"

// Includes
#include <iostream>
#include <stack>
#include <map>
#include <vector>
#include <list>
#include <cmath>        // sqrt
#include <stdexcept>    // std::out_of_range for map partial specialization

namespace Algorithms {
namespace Searching {

// What
/**
 * @brief what
 * Print on std::cout the templates contained in the namespace Searching which is part of the namespace Algorithms.
 */
void what(void) noexcept {
    std::cout << "\nNamespace Algorithms -> Namespace Searching :\n"
              << "1. Contains (all data structures)\n"
              << "2. Linear Search (Vector)\t\t\tTime Complexity O(n)\t\t\t\t\tLow Speed\n"
              << "3. Binary Search (sorted Vector or List)\tTime Complexity O(log2(n))\t\t\t\tFast Speed\n"
              << "4. Jump Search (sorted Vector or List)\t\tTime Complexity O(square(n))\tSpace Complexity O(1)\tMedium Speed\n"
              << "\n";
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////

// Contains for all data structures
/**
 * @brief contains
 * @param DataStructure const& data
 * @param TargetedValue const& target
 * @return true if the data contained the target, else false
 * All data structures are supported thanks to a partial specialisation of the main template for std::stack, std::map and std::multimap.
 */
template<class DataStructure, class TargetedValue>
static bool contains(DataStructure const& data, TargetedValue const& target) noexcept {
    for(auto iterator = data.begin(); iterator != data.end(); ++iterator) {
        if(*iterator == target)
        { return true; }
    }

    return false;
}

// Partial specialization for the stack data structure
/**
 * @brief contains
 * @param std::stack<TargetedValue> const& data
 * @param TargetedValue const& target
 * @return true if the data contained the target, else false
 * All data structures are supported thanks to a partial specialisation of the main template for std::stack, std::map and std::multimap.
 * This is the partial specialisation for std::stack.
 */
template<class TargetedValue>
static bool contains(std::stack<TargetedValue> const& data, TargetedValue const& target) noexcept {
    std::stack<TargetedValue> s{data};
    for(unsigned int i(0); i < s.size(); ++i) {
       if(s.top() == target)
       { return true; }
       else s.pop();
    }

    return false;
}

// Partial specialization for the map data structure
/**
 * @brief contains
 * @param std::map<Key, Value> const& data
 * @param Key const& key
 * @return true if the data contained the target, else false
 * All data structures are supported thanks to a partial specialisation of the main template for std::stack, std::map and std::multimap.
 * This is the partial specialisation for std::map.
 */
template<class Key, class Value>
static bool contains(std::map<Key, Value> const& data, Key const& key) noexcept {
    if(data.find(key) != data.end()) return true;
    return false;
    /*
    // The following code works, but checking with an execption isn't a good practice. If used, then remove noexcept from the signature.
    try {
        data.at(key); // it throws an out_of_range exception if the key doesn't exist in the map
        return true;

    } catch (const std::out_of_range& oor) {
        return false;
    }
    */
}

// Partial specialization for the multimap data structure
/**
 * @brief contains
 * @param std::multimap<Key, Value> const& data
 * @param Key const& key
 * @return true if the data contained the target, else false
 * All data structures are supported thanks to a partial specialisation of the main template for std::stack, std::map and std::multimap.
 * This is the partial specialisation for std::multimap.
 */
template<class Key, class Value>
static bool contains(std::multimap<Key, Value> const& data, Key const& key) noexcept {
    if(data.find(key) != data.end()) return true;
    return false;
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////

// Linear Search for the Vector class - index
/**
 * @brief linearSearch
 * @param std::vector<Type> const& data
 * @param Type const& target
 * @return the index of the target in the data if found, else -1
 */
template<class Type>
static int linearSearch(std::vector<Type> const& data, Type const& target) noexcept {
    for(unsigned int i(0); i != i < data.size(); ++i) {
        if(data[i] == target)
        { return i; }
    }

    return -1;
}

// Linear Search for the Vector class - pointer
/**
 * @brief linearSearch
 * @param std::vector<Type> const& data
 * @param Type const& target
 * @return an iterator pointing on the target in the data if found, else nullptr
 */
template<class Type>
static int* linearSearch(std::vector<Type> const& data, Type const& target) noexcept {
    for(auto iterator = data.begin(); iterator != data.end(); ++iterator) {
        if(*iterator == target)
        { return iterator; }
    }

    return nullptr;
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////

// Binary Search for sorted Vector and List
/**
 * @brief binarySearch
 * @param std::vector<Type> const& data
 * @param Type const& target
 * @return the index of the target in the data if found, else -1
 * The condition to use this template is to have a sorted data structure (i.e. for vector).
 * This template works for a sorted std::vector.
 */
template<class Type>
static int binarySearch(std::vector<Type> const& data, Type const& target) noexcept {
    int maximum = data.size() - 1;
    int minimum = 0;

    int indexOfMiddleElement;

    while(maximum >= minimum) {
        indexOfMiddleElement = (maximum + minimum) / 2;

        if(data[indexOfMiddleElement] == target)
            return indexOfMiddleElement;
        else if(data[indexOfMiddleElement] > target)
            maximum = indexOfMiddleElement - 1; // target is in the first half of the data structure
        else
            minimum = indexOfMiddleElement + 1; // target is in the second half of the data structure
    } // while

    return -1;
}

/**
 * @brief binarySearch
 * @param std::list<Type> const& data
 * @param Type const& target
 * @return the index of the target in the data if found, else -1
 * The condition to use this template is to have a sorted data structure (i.e. for vector).
 * This template works for a std::list.
 */
template<class Type>
static int binarySearch(std::list<Type> const& data, Type const& target) noexcept {
    int maximum = data.size() - 1;
    int minimum = 0;

    int indexOfMiddleElement;

    while(maximum >= minimum) {
        indexOfMiddleElement = (maximum + minimum) / 2;

        if(data[indexOfMiddleElement] == target)
            return indexOfMiddleElement;
        else if(data[indexOfMiddleElement] > target)
            maximum = indexOfMiddleElement - 1; // target is in the first half of the data structure
        else
            minimum = indexOfMiddleElement + 1; // target is in the second half of the data structure
    } // while

    return -1;
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////

// Jump Search for sorted Vector and List
/**
 * @brief jumpSearch
 * @param std::vector<Type> const& data
 * @param Type const& target
 * @return the index of the target in the data if found, else -1
 * The condition to use this template is to have a sorted data structure (i.e. for vector).
 * This template works for a sorted std::vector.
 */
template<class Type>
static int jumpSearch(std::vector<Type> const& data, Type const& target) noexcept {
    int i = 0;
    int index = sqrt(data.size());

    while(data[index] <= target && index < data.size()) {
        i = index;
        index += sqrt(data.size());

        if(index > data.size() - 1) // out of data structure size
            return -1;
    }

    for(int j(i); j < index; ++j) {
        if(data[j] == target)
            return j;
    }

    return -1;
}

/**
 * @brief jumpSearch
 * @param std::list<Type> const& data
 * @param Type const& target
 * @return the index of the target in the data if found, else -1
 * The condition to use this template is to have a sorted data structure (i.e. for vector).
 * This template works for a std::list.
 */
template<class Type>
static int jumpSearch(std::list<Type> const& data, Type const& target) noexcept {
    int i = 0;
    int index = sqrt(data.size());

    while(data[index] <= target && index < data.size()) {
        i = index;
        index += sqrt(data.size());

        if(index > data.size() - 1) // out of data structure size
            return -1;
    }

    for(int j(i); j < index; ++j) {
        if(data[j] == target)
            return j;
    }

    return -1;
}

} // end namespace Searching
} // end namespace Algorithms

#endif // SEARCHING_H
