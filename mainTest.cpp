#include <iostream>
#include "graph.h"

std::vector<std::string> vertex_labels = {"A", "B", "C", "D", "E", "F", "G"};

int main() {
    Graph graph;

    // Add vertices
    // Create a graph with vertex labels A, B, C, D, E, F, G
    for (std::string s : vertex_labels)
    {
        graph.add_vertex(s);
    }

    // Add edges
    graph.add_edge("A", "B", 2);    //A -> B with weight 2
    graph.add_edge("A", "C", 3);    //A -> C with weight 3
    graph.add_edge("B", "E", 4);    //B -> E with weight 4
    graph.add_edge("B", "G", 5);    //B -> G with weight 5
    graph.add_edge("C", "D", 1);    //C -> D with weight 1
    graph.add_edge("D", "E", 2);    //D -> E with weight 2
    graph.add_edge("E", "F", 4);    //E -> F with weight 4
    graph.add_edge("F", "G", 1);    //G -> F with weight 1

    std::cout << "Number of vertices: " << graph.num_verts() << std::endl;
    std::cout << "Number of edges: " << graph.num_edges() << std::endl;

    std::string source = "A"; // Source vertex
    std::string target = "F"; // Target vertex

    std::vector<int> previous_nodes(graph.num_verts(), -1);
    std::vector<int> shortest_distances = graph.dijkstra_shortest_distances(source, previous_nodes);

    std::cout << std::endl << std::endl << "---Dijkstra's Algorithm---" << std::endl;
    for (int i = 0; i < shortest_distances.size(); i++)
    {
        std::cout << "Shortest distance from vertex " << source << " to vertex " << vertex_labels[i] << ": " << shortest_distances[i] << std::endl;
    }

    std::string path = graph.shortest_path(source, target);

    std::cout << std::endl << "Shortest path from vertex " << source << " to vertex " << target << " is: " << path << std::endl;

    std::cout << std::endl << std::endl;

    auto mst = graph.minimum_spanning_tree("A");
    graph.display_minimum_spanning_tree(mst, "A");

    return 0;
}
