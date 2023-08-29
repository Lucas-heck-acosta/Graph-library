#include <iostream>
#include "graph.h"

int main() {
    // Create a graph with vertex labels A, B, C, D, E, F, G
    //                         INDEX ->  0, 1, 2, 3, 4, 5, 6
    Graph graph(7);

    // Add vertices and edges
    //A
    graph.add_edge(0, 1, 2); // A -> B with weight 2
    graph.add_edge(0, 2, 3); // A -> C with weight 3
    //B
    graph.add_edge(1, 0, 2); // B -> A with weight 2
    graph.add_edge(1, 4, 4); // B -> E with weight 4
    graph.add_edge(1, 6, 5); // B -> G with weight 5
    //C
    graph.add_edge(2, 1, 3); // C -> A with weight 3
    graph.add_edge(2, 3, 1); // C -> D with weight 1
    //D
    graph.add_edge(3, 2, 1); // D -> C with weight 1
    graph.add_edge(3, 4, 2); // D -> E with weight 2
    //E
    graph.add_edge(4, 3, 2); // E -> D with weight 2
    graph.add_edge(4, 1, 4); // E -> B with weight 4
    graph.add_edge(4, 5, 4); // E -> F with weight 4
    //F
    graph.add_edge(5, 4, 4); // F -> E with weight 4
    graph.add_edge(5, 6, 1); // F -> G with weight 1
    //G
    graph.add_edge(6, 5, 1); // G -> F with weight 1
    graph.add_edge(6, 1, 5); // G -> B with weight 5


    std::cout << "Number of vertices: " << graph.num_verts() << std::endl;
    std::cout << "Number of edges: " << graph.num_edges() << std::endl;


    int source = 0; // Source vertex
    int target = 5; // Target vertex

    // Using dijkstra_shortest_distances to calculate shortest distances
    std::vector<int> previous_nodes(graph.num_verts(), -1);
    std::vector<int> shortest_distances = graph.dijkstra_shortest_distances(source, previous_nodes);

    for (int i = 0; i < shortest_distances.size(); ++i) {
        std::cout << "Shortest distance from vertex " << source << " to vertex " << i << ": " << shortest_distances[i] << std::endl;
    }


    // Using shortest_path to calculate and display the shortest path
    std::string path = graph.shortest_path(source, target);

    std::cout << std::endl << "Shortest path from vertex " << source << " to vertex " << target << " is: " << path << std::endl;


    return 0;
}