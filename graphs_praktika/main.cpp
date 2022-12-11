#include <iostream>
#include <vector>
#include "Edge.hpp"
#include "Vertex.hpp"
#include "Graph.hpp"

int main(int argc, const char * argv[]) {
    
    Graph graph{};
    graph.addVertex("A");
    graph.addVertex("B");
    cout << graph.isContainsInList("A");
    cout << graph.isContainsInList("B");
    cout << graph.isContainsInList("D");
    //graph.addEdge("A", "B", 10);
    return 0;
}
