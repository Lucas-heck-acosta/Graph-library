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
    graph.add_edge(0, 2, 2); // A -> C with weight 3
    //B
    graph.add_edge(1, 4, 4); // B -> E with weight 4
    graph.add_edge(1, 6, 5); // B -> G with weight 5
    //C
    graph.add_edge(2, 3, 1); // C -> D with weight 1
    //D
    graph.add_edge(3, 4, 2); // D -> E with weight 2
    //E
    graph.add_edge(4, 5, 4); // E -> F with weight 4
    //F
    graph.add_edge(5, 6, 1); // F -> G with weight 1


    // ... other operations ...

    return 0;
}
```
