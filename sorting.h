#ifndef SORTING_H
#define SORTING_H

// My includes
#include "exceptions.h"

// Includes
#include <iostream>
#include <vector>
#include <algorithm>    // std::iter_swap
#include <thread>

namespace Algorithms {
namespace Sorting {

// What
/**
 * @brief what
 * Print on std::cout the templates contained in the namespace Sorting which is part of the namespace Algorithms.
 */
void what(void) noexcept {
    std::cout << "\nNamespace Algorithms -> Namespace Sorting :\n"
              << "1. Bubble Sort\t\t\t\t\tTime Complexity O(n2)\t\tSpace Complexity O(1)\n"
              << "2. Bubble Sort Optimized\t\t\tTime Complexity O(n2)\t\tSpace Complexity O(1)\n"
              << "3. Insertion Sort\t\t\t\tTime Complexity O(n2)\t\tSpace Complexity O(1)\n"
              << "4. Selection Sort\t\t\t\tTime Complexity O(n2)\t\tSpace Complexity O(1)\n"
              << "5. Quick Sort\t\t\t\t\tTime Complexity O(n*log(n))\tSpace Complexity O(n*log(n))\n"
              << "6. Merge Sort\t\t\t\t\tTime Complexity O(n*log(n))\tSpace Complexity O(n)\n"
              << "7. Heap Sort\t\t\t\t\tTime Complexity O(n*log(n))\tSpace Complexity O(1)\n"
              << "\t\t\t\t\t\t(loop iterates n times, count array uses k iterations)\n"
              << "\n";
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief bubbleSort
 * @param std::vector<Type> & data
 * Worst Case Time Complexity [ Big-O ] : O(n2)
 * Best Case Time Complexity [Big-omega] : O(n)
 * Average Time Complexity [Big-theta] : O(n2)
 * Space Complexity : O(1)
 */
template<class Type>
static void bubbleSort(std::vector<Type> & data) noexcept {
    for(int i(0); i < data.size(); ++i) {
        for(int j(0); j < data.size() - 1; ++j) {
            if(data[i] > data[j+1]) {
                std::iter_swap(data[i], data[j+1]);
            }
        }
    }
}

/**
 * @brief bubbleSortOptimized
 * @param std::vector<Type> & data
 * Worst Case Time Complexity [ Big-O ] : O(n2)
 * Best Case Time Complexity [Big-omega] : O(n)
 * Average Time Complexity [Big-theta] : O(n2)
 * Space Complexity : O(1)
 */
template<class Type>
static void bubbleSortOptimized(std::vector<Type> & data) noexcept {
    bool flag{false};

    for(int i(0); i < data.size(); ++i) {
        for(int j(0); j < data.size() - 1; ++j) {
            if(data[i] > data[j+1]) {
                std::iter_swap(data[i], data[j+1]);
                flag = true;
            }
        }

        if(flag == false) {
            break;
        }
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief insertionSort
 * @param std::vector<Type> & data
 * Worst Case Time Complexity [ Big-O ] : O(n2)
 * Best Case Time Complexity [Big-omega] : O(n)
 * Average Time Complexity [Big-theta] : O(n2)
 * Space Complexity : O(1)
 */
template<class Type>
static void insertionSort(std::vector<Type> & data) noexcept {
    int j;

    for(int i(1); i < data.size(); ++i) {
        j = i;

        while(j > 0 && data[j-1] > data[j]) {
            std::iter_swap(data[j], data[j-1]);
            --j;
        }
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief selectionSort
 * @param std::vector<Type> & data
 * Worst Case Time Complexity [ Big-O ] : O(n2)
 * Best Case Time Complexity [Big-omega] : O(n2)
 * Average Time Complexity [Big-theta] : O(n2)
 * Space Complexity : O(1)
 */
template<class Type>
static void selectionSort(std::vector<Type> & data) noexcept {
    for(int i(0); i < data.size(); ++i) {
        std::iter_swap(data[i], std::min_element(data.begin(), data.end()));
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief The QuickSort class
 * This class has been created in order not to make visible from the user side the method partition.
 */
class QuickSort {
private:
/**
 * @brief partition
 * @param std::vector<Type> &
 * @param unsigned int begin
 * @param unsigned int end
 * @return unsigned int pivot required for quickSort
 * After selecting an element as pivot, which is the last index of the array in our case, we divide the array for the first time.
 * In quick sort, we call this partitioning. It is not simple breaking down of array into 2 subarrays, but in case of partitioning,
 * the array elements are so positioned that all the elements smaller than the pivot will be on the left side of the pivot
 * and all the elements greater than the pivot will be on the right side of it.
 */
template<class Type>
static unsigned int partition(std::vector<Type> & data, unsigned int begin, unsigned int end) {
    unsigned int pivot{begin}, left{begin}, right{end};
    bool flag{false};

    while(!flag) {
        while((data[pivot] <= data[right]) && (pivot != right)) {
            --right;
        }

        if(pivot == right) {
            flag = true;
        }
        else if(data[pivot] > data[right]) {
            std::iter_swap(data[pivot], data[right]);
            pivot = right;
        }

        if(!flag) {
            while((data[pivot] >= data[left]) && (pivot != left)) {
                ++left;
            }

            if(pivot == left) {
                flag = true;
            }
            else if(data[pivot] < data[left]) {
                std::iter_swap(data[pivot], data[left]);
                pivot = left;
            }
        }
    }

    return pivot;
}

public:
/**
 * @brief quickSortSequential
 * @param std::vector<Type> & data
 * @param unsigned int begin
 * @param unsigned int end
 * Worst Case Time Complexity [ Big-O ] : O(n2)
 * Best Case Time Complexity [Big-omega] : O(n*log n)
 * Average Time Complexity [Big-theta] : O(n*log n)
 * Space Complexity : O(n*log n)
 */
template<class Type>
static void quickSortSequential(std::vector<Type> & data, unsigned int begin, unsigned int end) noexcept {
    if(begin < end) {
        int pivot = QuickSort::partition(data, begin, end);
        quickSort(data, begin, pivot-1);
        quickSort(data, pivot+1, end);
    }
}

/**
 * @brief quickSortParallelized
 * @param std::vector<Type> & data
 * @param unsigned int begin
 * @param unsigned int end
 * Worst Case Time Complexity [ Big-O ] : O(n2)
 * Best Case Time Complexity [Big-omega] : O(n*log n)
 * Average Time Complexity [Big-theta] : O(n*log n)
 * Space Complexity : O(n*log n)
 */
template<class Type>
static void quickSortParallelized(std::vector<Type> & data, unsigned int begin, unsigned int end) noexcept {
    if(begin < end) {
        unsigned int pivot = QuickSort::partition(data, begin, end);
        std::thread subVec1(quickSortParallelized, data, begin, pivot-1);
        std::thread subVec2(quickSortParallelized, data, pivot+1, end);
        subVec1.join();
        subVec2.join();
    }
}

}; // end class QuickSort

//////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief The MergeSort class
 * This class has been created in order not to make visible from the user side the method merge.
 */
class MergeSort {
private:
/**
 * @brief merge
 * @param std::vector<Type> & data
 * @param unsigned int begin
 * @param unsigned int middleIndex
 * @param unsigned int end
 * This method is used by mergeSort in order to merge all sub vectors created by the Divide and Conquer algorithm.
 * Indeed, this algorithm split the whole vector (the problem to be solved) into sub vectors, and will do it until
 * we have only vectors with a single data within. Then, it merges them sorted.
 */
template<class Type>
static void merge(std::vector<Type> & data, unsigned int begin, unsigned int middleIndex, unsigned int end) {
    std::vector<Type> tmpVec;
    tmpVec.reserve(data.size());

    unsigned int i{begin}, j{middleIndex + 1}, k{0};

    while(i <= middleIndex && j <= end) {
        if(data[i] < data[j])
            tmpVec[k++] = data[i++];    // same as tmpVec[k] = data[i]; ++k; ++i;
        else
            tmpVec[k++] = data[j++];
    }

    while(i <= middleIndex)
        tmpVec[k++] = data[i++];

    while(j <= end)
        tmpVec[k++] = data[j++];

    for(i = end; i >= begin; --i)
        data[i] = tmpVec[--k];          // copying back the sorted list to data

}

public:
/**
 * @brief mergeSort
 * @param std::vector<Type> & data
 * @param unsigned int begin
 * @param unsigned int end
 * Worst Case Time Complexity [ Big-O ] : O(n*log n)
 * Best Case Time Complexity [Big-omega] : O(n*log n)
 * Average Time Complexity [Big-theta] : O(n*log n)
 * Space Complexity : O(n)
 * Divide and Conquer algorithm :
 * If we can break a single big problem into smaller sub-problems,
 * solve the smaller sub-problems and combine their solutions
 * to find the solution for the original big problem,
 * it becomes easier to solve the whole problem.
 * This algorithm is the best sorting technique used for sorting linked lists.
 */
template<class Type>
static void mergeSort(std::vector<Type> & data, unsigned int begin, unsigned int end) noexcept {
    if(begin < end) {
        unsigned int middleIndex = (begin + end) / 2;
        mergeSort(data, begin, middleIndex);
        mergeSort(data, middleIndex + 1, end);
        MergeSort::merge(data, begin, middleIndex, end);
    }
}

}; // end class MergeSort

//////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief The HeapSort class
 * This class has been created in order not to make visible from the user side the method heapify.
 */
class HeapSort {
private:
    /**
     * @brief heapify
     * @param std::vector<Type> & data
     * @param unsigned int n
     * @param unsigned int largestElement
     * Initially on receiving an unsorted list, the first step in heap sort is to create
     * a Heap data structure(Max-Heap or Min-Heap).
     * Once heap is built, the first element of the Heap is either largest or smallest
     * (depending upon Max-Heap or Min-Heap), so we put the first element of the heap in our array.
     * Then we again make heap using the remaining elements,
     * to again pick the first element of the heap and put it into the array.
     * We keep on doing the same repeatedly untill we have the complete sorted list in our array.
     *
     * The method heapSort calls this private method, heapify, whose the job is to build the heap.
     */
    template<class Type>
    static void heapify(std::vector<Type> & data, unsigned int n, unsigned int largestElement) {
        unsigned int largest = largestElement;
        unsigned int left    = (2 * largestElement) + 1;
        unsigned int right   = (2 * largestElement) + 2;

        if(left < n && data[left] > data[largest]) // if the left child is larger than the root
            largest = left;

        if(right < n && data[right] > data[largest]) // if the right child is larger than the root
            largest = right;

        if(largest != largestElement) // if largest isn't the root
        {
            std::iter_swap(data[largestElement], data[largest]);
            HeapSort::heapify(data, n, largest); // recursively heapify the sub-tree
        }

    }

public:
    /**
     * @brief heapSort
     * @param std::vector<Type> & data
     * Worst Case Time Complexity : O(n*log n)
     * Best Case Time Complexity : O(n*log n)
     * Average Time Complexity : O(n*log n)
     * Space Complexity : O(1)
     * Heap sort is not a Stable sort, and requires a constant space for sorting a list.
     * Heap Sort is very fast and is widely used for sorting.
     * Heap Sort is one of the best sorting methods being in-place and with no quadratic worst-case running time.
     * Heap sort involves building a Heap data structure from the given array and then utilizing the Heap to sort the array
     */
    template<class Type>
    static void heapSort(std::vector<Type> & data) {
        for(unsigned int i = data.size()/2 - 1; i >= 0; --i) // build the heap (rearrange the array)
            HeapSort::heapify(data, data.size(), i);

        for(unsigned int i = data.size() - 1; i >= 0; --i) // extract one by one the elements from the heap
        {
            std::iter_swap(data[0], data[i]);
            HeapSort::heapify(data, i, 0); // call max heapify on the reduced heap
        }
    }

}; // end class HeapSort

} // end namespace Sorting
} // end namespace Algorithms



#endif // SORTING_H
