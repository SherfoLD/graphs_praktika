//
//  Graph.hpp
//  graphs_praktika
//
//  Created by Dmitry Savelev on 13.11.2022.
//

#ifndef Graph_hpp
#define Graph_hpp

#include <stdio.h>
#include <list>
#include <unordered_map>
#include <map>
#include "Vertex.hpp"
#include "Edge.hpp"
using namespace std;


class Graph{
private:
    map<string, list<string>> adjacencyList;
    unordered_map<string, unique_ptr<Vertex>> vertexHashMap;
    unordered_map<string, int> weightOfEdges;
    
    list<string> currentPath;
    list<list<string>> simplePaths;
    
public:
    void addVertex(string name);
    void addEdge(string originVertex, string destinationVertex, int value);
    void deleteVertex(string name);
    void deleteEdge(string originVertex, string destinationVertex);
    void editEdge(string originVertex, string destiantionVertex, int newValue);
    string first(string vertexName);
    string next(string keyVertex, string startVertex);
    string vertex(string keyVertex, string adjacentVertex);
    void findSimpleAllSimplePaths(string originVertex, string destinationVertex);
    void print();
    void printSimplePaths();
};

#endif /* Graph_hpp */
