#include <iostream>
#include "graph.h"

int main() {
    Graph graph(10); // Create a graph with 10 vertices

    graph.add_vertex(); // Add a new vertex
    graph.add_edge(0, 1); // Add an edge from vertex 0 to vertex 1

    std::cout << "Number of vertices: " << graph.num_verts() << std::endl;
    std::cout << "Number of edges: " << graph.num_edges() << std::endl;

    return 0;
}