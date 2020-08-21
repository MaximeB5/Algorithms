#ifndef DEMO_H
#define DEMO_H

/**
 * @brief The Demo class
 * This class allows users to have a demo on the std::cout stream of what can do the namespace Algorithms and the namespaces included within it.
 */
class Demo
{
public:
    // Rule of three : add copy constructor and copy assignment in addition to the destructor.
    Demo() {};
    ~Demo() {};
    Demo(const Demo &) = delete;                // copy constructor
    Demo & operator=(const Demo &) = delete;    // copy assignment operator

    /* Rule of five : add move constructor and move assignment.
     * Cf. C++11 12.8/9 :
     * If the definition of a class X does not explicitly declare a move constructor,
     * one will be implicitly declared as defaulted if and only if :
     *      - X does not have a user-declared copy constructor, [...]
     *
     * -> Being given we declared a copy constructor, even if it is delete in the class declaration,
     * there won't be neither a move constructor nor a move operator at all.
     * So, we don't need to declare them even as delete.
     */

    //Algorithms
    void what(void) const noexcept;

    // Algorithms::Searching
    void searching(void) const;
    void contains(void) const noexcept;
    void linear_search(void) const;
    void binary_search(void) const;

    // Algorithms::Sorting
        // TODO

    // Algorithms::Graph
        // TODO
};

#endif // DEMO_H
