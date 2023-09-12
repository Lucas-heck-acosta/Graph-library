#include "minHeap.h"

/**
 * Private function to maintain the heap property by "bubbling down" the element at the given index.
 *
 * @param index The index of the element to be heapified.
 */
void MinHeap::_heapify_down(int index)
{
    int n = heap.size();
    while (true)
    {
        int left_child_idx = 2 * index + 1;
        int right_child_idx = 2 * index + 2;
        int smallest = index;

        // Check if the left child exists and is smaller than the current smallest.
        if (left_child_idx < n && heap[left_child_idx] < heap[smallest])
        {
            smallest = left_child_idx;
        }

        // Check if the right child exists and is smaller than the current smallest.
        if (right_child_idx < n && heap[right_child_idx] < heap[smallest])
        {
            smallest = right_child_idx;
        }

        // If the smallest element is not the current index, swap them and update the index.
        if (smallest != index)
        {
            std::swap(heap[index], heap[smallest]);
            index = smallest;
        }
        else
        {
            break; // The heap property is preserved.
        }
    }
}

/**
 * Constructor to initialize the heap with an optional vector of elements.
 *
 * @param arr An optional vector of pairs to initialize the heap.
 */
MinHeap::MinHeap(const std::vector<std::pair<int, int>>& arr) : heap(arr)
{
    _build_heap(); // Build the heap from the given elements.
}

/**
 * Private function to build the heap from the vector elements.
 */
void MinHeap::_build_heap()
{
    int n = heap.size();
    for (int i = (n / 2) - 1; i >= 0; --i)
    {
        _heapify_down(i); // Heapify each subtree.
    }
}

/**
 * Insert a new element into the heap while maintaining the heap property.
 *
 * @param element The element to be inserted into the heap.
 */
void MinHeap::insert(std::pair<int, int> element)
{
    heap.push_back(element); // Add the element to the end of the vector.
    int position = heap.size() - 1; // Get the position of the newly added element.

    // "Bubble up" the element to its correct position in the heap.
    while (position > 0)
    {
        int parent = (position - 1) / 2;
        if (element < heap[parent])
        {
            std::swap(heap[position], heap[parent]);
            position = parent;
        }
        else
        {
            break; // The element is in its correct position.
        }
    }
}

/**
 * Get the minimum element from the heap (the root).
 *
 * @return The minimum element in the heap.
 * @throws std::runtime_error if the heap is empty.
 */
std::pair<int, int> MinHeap::get_min()
{
    if (heap.empty())
    {
        throw std::runtime_error("Heap is empty");
    }
    return heap[0]; // Return the root element (minimum).
}

/**
 * Extract and remove the minimum element from the heap.
 *
 * @return The extracted minimum element.
 * @throws std::runtime_error if the heap is empty.
 */
std::pair<int, int> MinHeap::extract_min()
{
    if (heap.empty())
    {
        throw std::runtime_error("Heap is empty");
    }
    std::pair<int, int> min_val = heap[0]; // Store the minimum element.
    std::pair<int, int> last_val = heap.back(); // Get the last element in the vector.
    heap.pop_back(); // Remove the last element.

    if (!heap.empty())
    {
        heap[0] = last_val; // Replace the root with the last element.
        _heapify_down(0); // Restore the heap property.
    }
    return min_val; // Return the extracted minimum element.
}

/**
 * Check if the heap is empty.
 *
 * @return True if the heap is empty, otherwise false.
 */
bool MinHeap::is_empty()
{
    return heap.empty();
}

/**
 * Get the current size (number of elements) of the heap.
 *
 * @return The number of elements in the heap.
 */
int MinHeap::size()
{
    return heap.size();
}
