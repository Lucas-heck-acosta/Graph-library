#include <queue>
#include <string>
#include "graph.h"

// Constructor for the Graph class
Graph::Graph(int number_of_verts) : number_of_verts(number_of_verts), adj_list(number_of_verts) {}

// Method to add a new vertex to the graph
void Graph::add_vertex()
{
    number_of_verts++;
    adj_list.emplace_back();
}

// Method to add an edge between two vertices with an optional weight
bool Graph::add_edge(int from_idx, int to_idx, int weight)
{
    if (from_idx < 0 || from_idx >= number_of_verts || to_idx < 0 || to_idx >= number_of_verts)
        return false;

    for (const auto &edge : adj_list[from_idx])
    {
        if (edge.first == to_idx)
        {
            return false;
        }
    }

    // The following line should be outside the loop
    adj_list[from_idx].emplace_back(to_idx, weight);
    return true;
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
bool Graph::has_edge(int from_idx, int to_idx)
{
    if (from_idx < 0 || from_idx >= number_of_verts || to_idx < 0 || to_idx >= number_of_verts)
        return false;

    for (const auto &edge : adj_list[from_idx])
    {
        if (edge.first == to_idx)
        {
            return true;
        }
    }

    return false;
}

// Method to get the weight of an edge between two vertices
int Graph::edge_weight(int from_idx, int to_idx)
{
    if (from_idx < 0 || from_idx >= number_of_verts || to_idx < 0 || to_idx >= number_of_verts)
        return -1;

    for (const auto &edge : adj_list[from_idx])
    {
        if (edge.first == to_idx)
        {
            return edge.second;
        }
    }

    return -1;
}

// Method to get a list of vertices connected to a given vertex
std::vector<std::pair<int, int>> Graph::get_connected(int v)
{
    if (v < 0 || v >= number_of_verts)
        return std::vector<std::pair<int, int>>();

    return adj_list[v];
}




std::vector<int> Graph::dijkstra_shortest_distances(int source, std::vector<int>& previous_nodes)
{
    const int max = std::numeric_limits<int>::max();

    std::vector<int>distances(number_of_verts, max);
    distances[source] = 0;

    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int> >, std::greater<> > pq;
    pq.push({0, source});

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        if (distances[u] < max)
        {
            for (const auto &edge : adj_list[u]) {
                int v = edge.first;
                int weight = edge.second;

                if (distances[u] + weight < distances[v])
                {
                    distances[v] = distances[u] + weight;
                    pq.push({distances[v], v});
                    previous_nodes[v] = u;
                }
            }
        }
    }
    return distances;
}

std::string Graph::shortest_path(int source, int target)
{
    std::vector<int> previous_nodes(number_of_verts, -1);
    std::vector<int> distances = dijkstra_shortest_distances(source, previous_nodes);

    std::vector<int> path;
    int current = target;

    while (current != -1)
    {
        path.insert(path.begin(), current);
        current = previous_nodes[current];
    }

    std::string path_string;
    for (int i = 0; i < path.size(); i++)
    {
        path_string += std::to_string(path[i]);
        if (i < path.size() - 1) {
            path_string += " - ";
        }
    }

    return path_string;
}
