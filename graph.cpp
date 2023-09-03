#include <queue>
#include <string>
#include "graph.h"
#include "minHeap.h"

// Constructor for the Graph class
Graph::Graph() : number_of_verts(0){}

// Method to add a new vertex to the graph
void Graph::add_vertex(const std::string &label)
{
    if(vertex_indices.find(label) == vertex_indices.end())
    {
        vertex_indices[label] = number_of_verts++;
        adj_list.emplace_back();
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
