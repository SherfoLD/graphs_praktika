#include <iostream>
#include <vector>
#include "Graph.hpp"

int main(int argc, const char * argv[]) {
    Graph graph{};
    
    graph.addVertex("1");
    graph.addVertex("2");
    graph.addVertex("3");
    graph.addVertex("4");
    graph.addVertex("5");
    
    graph.addEdge("1", "2", 12);
    graph.addEdge("1", "3", 13);
    graph.addEdge("2", "3", 23);
    graph.addEdge("2", "4", 24);
    graph.addEdge("3", "5", 35);
    graph.addEdge("3", "4", 34);
    graph.addEdge("5", "4", 54);
    graph.addEdge("4", "5", 45);
    
    graph.print();
    graph.findAllSimplePaths("1", "4");
    graph.printSimplePaths();
    
    return 0;
}
