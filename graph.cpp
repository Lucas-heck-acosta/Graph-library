#include <queue>
#include <string>
#include "graph.h"
#include "minHeap.h"
#include <set>
#include <iostream>


// Constructor for the Graph class
Graph::Graph() : number_of_verts(0){}

// Method to add a new vertex to the graph
void Graph::add_vertex(const std::string &label)
{
    if (vertex_indices.find(label) == vertex_indices.end())
    {
        vertex_indices[label] = number_of_verts;
        adj_list.emplace_back();
        number_of_verts++;
    }
}

// Method to add an edge between two vertices with an optional weight
bool Graph::add_edge(const std::string &from, const std::string to, int weight)
{
    if(vertex_indices.find(from) != vertex_indices.end() && vertex_indices.find(to) != vertex_indices.end())
    {
        int from_idx = vertex_indices[from];
        int to_idx = vertex_indices[to];

        adj_list[from_idx].emplace_back(to_idx, weight);
        adj_list[to_idx].emplace_back(from_idx, weight);

        return true;
    }
    return false;
}

// Method to count the total number of edges in the graph
int Graph::num_edges()
{
    int num_edges = 0;
    for (const auto &edges : adj_list)
    {
        num_edges += edges.size();
    }
    return num_edges;
}

// Method to get the total number of vertices in the graph
int Graph::num_verts()
{
    return number_of_verts;
}

// Method to check if there's an edge between two vertices
bool Graph::has_edge(const std::string &from, const std::string to)
{
    if (vertex_indices.find(from) != vertex_indices.end() && vertex_indices.find(to) != vertex_indices.end())
    {
        int from_idx = vertex_indices[from];
        int to_idx = vertex_indices[to];

        for (const auto &edge : adj_list[from_idx])
        {
            if (edge.first == to_idx)
            {
                return true;
            }
        }
    }


    return false;
}

// Method to get the weight of an edge between two vertices
int Graph::edge_weight(const std::string &from, const std::string to)
{
    if (vertex_indices.find(from) != vertex_indices.end() && vertex_indices.find(to) != vertex_indices.end())
    {
        int from_idx = vertex_indices[from];
        int to_idx = vertex_indices[to];

        for (const auto &edge : adj_list[from_idx])
        {
            if (edge.first == to_idx)
            {
                return edge.second;
            }
        }
    }
    return -1;
}

// Method to get a list of vertices connected to a given vertex
std::vector<std::pair<int, int> > Graph::get_connected(std::string &label)
{
    if (vertex_indices.find(label) != vertex_indices.end())
    {
        int idx = vertex_indices[label];
        return adj_list[idx];
    }
    return std::vector<std::pair<int, int>>();

}




std::vector<int> Graph::dijkstra_shortest_distances(const std::string &source, std::vector<int>& previous_nodes)
{
    const int max = std::numeric_limits<int>::max();

    std::vector<int>distances(number_of_verts, max);
    distances[vertex_indices[source]] = 0;

    std::vector<std::pair<int, int>> initial_data;
    for (int i = 0; i < number_of_verts; i++)
    {
        initial_data.push_back({distances[i], i});
    }
    MinHeap min_heap(initial_data);

    while (!min_heap.is_empty())
    {
        std::pair<int, int> min_distance_vertex = min_heap.extract_min();
        int u = min_distance_vertex.second;

        if (distances[u] < max)
        {
            for (const auto &edge : adj_list[u]) {
                int v = edge.first;
                int weight = edge.second;

                if (distances[u] + weight < distances[v])
                {
                    distances[v] = distances[u] + weight;
                    min_heap.insert({distances[v], v});
                    previous_nodes[v] = u;
                }
            }
        }
    }
    return distances;
}
std::string Graph::shortest_path(const std::string &source, const std::string &target)
{
    std::vector<int> previous_nodes(number_of_verts, -1);
    std::vector<int> distances = dijkstra_shortest_distances(source, previous_nodes);

    std::vector<int> path;
    int current = vertex_indices[target];

    while (current != -1)
    {
        path.insert(path.begin(), current);
        current = previous_nodes[current];
    }

    std::string path_string;
    for (int i = 0; i < path.size(); i++)
    {
        for (const auto& label_idx_pair : vertex_indices)
        {
            if (label_idx_pair.second == path[i])
            {
                path_string += label_idx_pair.first;
                break;
            }
        }
        if (i < path.size() - 1)
        {
            path_string += " - ";
        }
    }

    return path_string;
}


/**
 * Calculates the Minimum Spanning Tree (MST) of the graph using Prim's Algorithm.
 *
 * @param start_label The label of the vertex from which to start building the MST.
 * @return A vector of tuples representing the edges in the MST. Each tuple contains:
 *         - The label of the source vertex.
 *         - The label of the destination vertex.
 *         - The weight of the edge.
 */
std::vector<std::tuple<std::string, std::string, int>> Graph::minimum_spanning_tree(const std::string& start_label)
{
    // Check if the starting vertex label exists in the graph.
    if (vertex_indices.find(start_label) == vertex_indices.end())
    {
        std::cerr << "Start vertex label not found in the graph." << std::endl;
        return {};
    }

    // Get the index of the starting vertex.
    int start = vertex_indices[start_label];

    // Initialize the MST and data structures for the algorithm.
    std::vector<std::tuple<std::string, std::string, int>> mst;
    MinHeap min_heap;
    std::set<int> visited;

    // Keep track of the current "from" label.
    std::string fromLabel = start_label;

    // Insert edges from the starting vertex into the min heap.
    for (const auto& edge : adj_list[start])
    {
        min_heap.insert({ edge.second, edge.first });
    }

    // Mark the starting vertex as visited.
    visited.insert(start);

    // Prim's Algorithm: Build the MST.
    while (!min_heap.is_empty())
    {
        auto [weight, v] = min_heap.extract_min();

        // Skip if the destination vertex has already been visited.
        if (visited.count(v) > 0)
        {
            continue;
        }

        // Find the label of the destination vertex using its index.
        std::string toLabel;

        for (const auto& labelIdxPair : vertex_indices)
        {
            if (labelIdxPair.second == v)
            {
                toLabel = labelIdxPair.first;
            }
        }

        // Add the edge to the MST and mark the destination vertex as visited.
        mst.push_back({ fromLabel, toLabel, weight });
        visited.insert(v);

        // Update the "from" label for the next iteration.
        fromLabel = toLabel;

        // Insert edges from the destination vertex into the min heap.
        for (const auto& edge : adj_list[v])
        {
            if (visited.count(edge.first) == 0)
            {
                min_heap.insert({ edge.second, edge.first });
            }
        }
    }

    return mst;
}

/**
 * Displays the Minimum Spanning Tree (MST) of the graph.
 *
 * @param mst A vector of tuples representing the edges in the MST. Each tuple contains:
 *            - The label of the source vertex.
 *            - The label of the destination vertex.
 *            - The weight of the edge.
 */
void Graph::display_minimum_spanning_tree(const std::vector<std::tuple<std::string, std::string, int>>& mst)
{
    // Print a header indicating the Minimum Spanning Tree.
    std::cout << "---Minimum Spanning Tree---" << std::endl;

    // Initialize a variable to store the total weight of the MST.
    int totalWeight = 0;

    // Iterate through the edges in the MST and display them.
    for (const auto& edge : mst)
    {
        // Extract the weight, source label, and destination label from the tuple.
        int weight = std::get<2>(edge);
        std::string fromLabel = std::get<0>(edge);
        std::string toLabel = std::get<1>(edge);

        // Display the edge with its weight.
        std::cout << fromLabel << " - " << toLabel << " (Weight: " << weight << ")" << std::endl;

        // Update the total weight of the MST.
        totalWeight += weight;
    }

    // Display the total weight of the MST.
    std::cout << "Total Weight of MST: " << totalWeight << std::endl;
}

