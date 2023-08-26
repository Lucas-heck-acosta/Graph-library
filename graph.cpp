#include "graph.h"

#include <iostream>



Graph::Graph(int number_of_verts) : number_of_verts(number_of_verts), adj_list(number_of_verts){}

void Graph::add_vertex()
{
    number_of_verts++;
    adj_list.emplace_back();
}

bool Graph::add_edge(int from_idx, int to_idx, int weight)
{
    if(from_idx < 0 || from_idx >= number_of_verts || to_idx < 0 || to_idx >= number_of_verts)
        return false;

    for (const auto& edge : adj_list[from_idx])
    {
        if(edge.first == to_idx)
        {
            return false;
        }

        adj_list[from_idx].emplace_back(to_idx, weight);
        return true;
    }
}

int Graph::num_edges()
{
    int num_edges =0;
    for (const auto &edges : adj_list)
    {
        num_edges += edges.size();
    }
    return num_edges;
}

int Graph::num_verts() {
    return 0;
}

bool Graph::has_edge(int from_idx, int to_idx)
{
    if (from_idx < 0 || from_idx >=number_of_verts || to_idx < 0 || to_idx >= number_of_verts)
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

int Graph::edge_weight(int from_idx, int to_idx)
{
    if (from_idx < 0 || from_idx >=number_of_verts || to_idx < 0 || to_idx >= number_of_verts)
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

std::vector<std::pair<int, int>> Graph::get_connected(int v)
{
    if (v < 0 || v >= number_of_verts)
        return std::vector<std::pair<int, int>>();

    return adj_list[v];
}

