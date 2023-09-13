#ifndef GRAPHLIB_GRAPH_H
#define GRAPHLIB_GRAPH_H


#include <vector>
#include <map>

class Graph {

    int number_of_verts;                                       // Total number of vertices in the graph.
    std::vector<std::vector<std::pair<int, int> > > adj_list;  // Adjacency list for representing edges.
    std::map<std::string, int> vertex_indices;                 // Mapping of vertex labels to their indices.



public:

    // Default constructor to initialize an empty graph.
    Graph();

    // Add a new vertex with the specified label to the graph.
    void add_vertex(const std::string &label);

    // Add an edge between two vertices with an optional weight (default is 1).
    // Returns true if the edge was successfully added, false if either vertex doesn't exist.
    bool add_edge(const std::string &from, const std::string to, int weight = 1);

    // Get the total number of edges in the graph.
    int num_edges();

    // Get the total number of vertices in the graph.
    int num_verts() const;

    // Check if an edge exists between two vertices.
    bool has_edge(const std::string &from, const std::string to);

    // Get the weight of an edge between two vertices.
    int edge_weight(const std::string &from, const std::string to);

    // Get a vector of connected vertices for a given vertex label.
    std::vector<std::pair<int, int> > get_connected(std::string &label);


    // Compute the shortest distances from a source vertex using Dijkstra's algorithm.
    std::vector<int> dijkstra_shortest_distances(const std::string &source, std::vector<int>& previous_nodes);
    // Find the shortest path between a source and target vertex.
    std::string shortest_path(const std::string &source, const std::string &target);


    // Compute the Minimum Spanning Tree (MST) starting from a specified vertex label.
    std::vector<std::tuple<std::string, std::string, int> > minimum_spanning_tree(const std::string &start_label);
    // Display the Minimum Spanning Tree (MST) edges.
    static void display_minimum_spanning_tree(const std::vector<std::tuple<std::string, std::string, int>>& mst);

};

#endif //GRAPHLIB_GRAPH_H
