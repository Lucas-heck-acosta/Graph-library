# Graph-Library

This is a C++ library that provides a basic implementation of a graph data structure with various functionalities.

## Features

- Create a graph with a specified number of vertices.
- Add and remove vertices.
- Add edges between vertices with optional weights.
- Check the existence of edges between vertices.
- Retrieve connected vertices and their weights.
- Count the number of vertices and edges in the graph.

## Getting Started

1. Clone this repository to your local machine.

```bash
git clone https://github.com/your-username/graph-library.git
```

2. Build the library and program
```bash
  cd graph-library
  mkdir build
  cd build
  cmake ..
  make
```

3. Run the program
```bash
  ./example
```

## Usage

To use this graph library in your own projects, include the graph.h header file and link against the library during compilation.
Make sure to include the appropriate path to the header and library files in your build configuration.



## Example Graph

A graph like this can be built using this library:
![grap view](graphView.png)


see bellow how to create a similar representation.
## Example Usage

```cpp
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

    // ... other operations ...

    return 0;
}
```


## Dijkstra's Algorithm
Dijkstra's Algorithm is an algorithm for finding the shortest path from one vertex to every other vertex. This algorithm is an example
of a greedy algorithm. Greedy algorithms are algorithms that find a solution by picking the best solution encountered thus far and expand
on the solution. Dijkstra's Algorithm was first conceived by Edsger W. Dijkstra.

The algorithm works as follows:

1. Start at chosen vertex.
2. Store the weight to travel to each connected vertex.
3. Go to the vertex with the least weight.
4. Continue traversing through the "lightest" path (cost should be calculated from total path, not just the current weight).

### Example
From the same graph above, apply the Dijkstra's algorithm:

```cpp
// ... graph creation ...

// Using dijkstra_shortest_distances to calculate shortest distances
    int source = 0; // Source vertex
    std::vector<int> previous_nodes(graph.num_verts(), -1);
    std::vector<int> shortest_distances = graph.dijkstra_shortest_distances(source, previous_nodes);

    for (int i = 0; i < shortest_distances.size(); ++i)
    {
        std::cout << "Shortest distance from vertex " << source << " to vertex " << i << ": " << shortest_distances[i] << std::endl;
    }
```

Code output:
```
Shortest distance from vertex 0 to vertex 0: 0
Shortest distance from vertex 0 to vertex 1: 2
Shortest distance from vertex 0 to vertex 2: 3
Shortest distance from vertex 0 to vertex 3: 4
Shortest distance from vertex 0 to vertex 4: 6
Shortest distance from vertex 0 to vertex 5: 8
Shortest distance from vertex 0 to vertex 6: 7
```

This represents the shortest path vertex 0 (A) can get to each of the other vertexes.


### Shortest path representation

```cpp
// ... code from above ...
// Using shortest_path to calculate and display the shortest path
    int target = 5; // Target vertex
    std::string path = graph.shortest_path(source, target);
    std::cout << std::endl << "Shortest path from vertex " << source << " to vertex " << target << " is: " << path << std::endl;
```

Code output:
```
Shortest path from vertex 0 to vertex 5 is: 0 - 1 - 6 - 5
```

Let's visualize this path in the graph:
![grap view](shortestPath.png)

The red colored edged represent the path showed in function shortest_path.

it is, calculated using Dijkstra's algorithms, the least costly way to traverse from A to F.





## References
https://seneca-ictoer.github.io/data-structures-and-algorithms/G-Graphs/dijkstra
