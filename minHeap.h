#ifndef MINHEAP_H
#define MINHEAP_H

#include <vector>
#include <stdexcept>

class MinHeap {
private:
    std::vector<int> heap;

    void _heapify_down(int index);

public:
    MinHeap(const std::vector<int>& arr = {});

    void _build_heap();
    void insert(int element);
    int get_min();
    int extract_min();
    bool is_empty();
    int size();
};

#endif // MINHEAP_H
