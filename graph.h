#ifndef GRAPHLIB_GRAPH_H
#define GRAPHLIB_GRAPH_H


#include <vector>

class Graph {

    int number_of_verts;
    std::vector<std::vector<std::pair<int, int>>> adj_list;


public:

    Graph(int number_of_verts);
    void add_vertex();
    bool add_edge(int from_idx, int to_idx, int weight = 1);
    int num_edges();
    int num_verts();
    bool has_edge(int from_idx, int to_idx);
    int edge_weight(int from_idx, int to_idx);
    std::vector<std::pair<int, int>> get_connected(int v);

};

#endif //GRAPHLIB_GRAPH_H
