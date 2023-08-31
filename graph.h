#ifndef GRAPHLIB_GRAPH_H
#define GRAPHLIB_GRAPH_H


#include <vector>
#include <map>

class Graph {

    int number_of_verts;
    std::vector<std::vector<std::pair<int, int> > > adj_list;
    std::map<std::string , int> vertex_indices;


public:

    Graph();
    void add_vertex(const std::string &label);
    bool add_edge(const std::string &from, const std::string to, int weight = 1);
    int num_edges();
    int num_verts();
    bool has_edge(const std::string &from, const std::string to);
    int edge_weight(const std::string &from, const std::string to);
    std::vector<std::pair<int, int> > get_connected(std::string &label);


    std::vector<int> dijkstra_shortest_distances(const std::string &source, std::vector<int>& previous_nodes);
    std::string shortest_path(const std::string &source, const std::string &target);


};

#endif //GRAPHLIB_GRAPH_H
