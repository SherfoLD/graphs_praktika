#include <iostream>
#include <vector>
#include "Edge.hpp"
#include "Vertex.hpp"
#include "Graph.hpp"

int main(int argc, const char * argv[]) {
    
    Graph graph{};
    graph.addVertex("A");
    graph.addVertex("B");
    graph.addEdge("A", "B", 10);
    return 0;
}
