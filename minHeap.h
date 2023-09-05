#ifndef MINHEAP_H
#define MINHEAP_H

#include <vector>
#include <stdexcept>

class MinHeap {
private:
    std::vector<std::pair<int, int>> heap;

    void _heapify_down(int index);

public:
    MinHeap() = default;
    MinHeap(const std::vector<std::pair<int, int> >& arr);

    void _build_heap();
    void insert(std::pair<int, int> element);
    std::pair<int, int> get_min();
    std::pair<int, int> extract_min();
    bool is_empty();
    int size();
};

#endif // MINHEAP_H
