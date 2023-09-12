#ifndef MINHEAP_H
#define MINHEAP_H

#include <vector>
#include <stdexcept>

class MinHeap {
private:
    std::vector<std::pair<int, int>> heap;

    // Helper function to maintain the heap property by moving an element down the heap.
    void _heapify_down(int index);

public:
    // Default constructor to create an empty min-heap.
    MinHeap() = default;

    // Constructor to create a min-heap from an existing array of elements.
    explicit MinHeap(const std::vector<std::pair<int, int>>& arr);

    // Builds a valid min-heap from the current heap elements.
    void _build_heap();

    // Inserts a new element into the min-heap.
    void insert(std::pair<int, int> element);

    // Retrieves the minimum element (root) of the min-heap.
    std::pair<int, int> get_min();

    // Removes and returns the minimum element (root) from the min-heap.
    std::pair<int, int> extract_min();

    // Checks if the min-heap is empty.
    bool is_empty();

    // Returns the current size (number of elements) of the min-heap.
    int size();
};

#endif // MINHEAP_H
