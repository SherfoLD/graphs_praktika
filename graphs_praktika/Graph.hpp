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
#include "Vertex.hpp"
#include "Edge.hpp"
using namespace std;


class Graph{
private:
    list<list<string>> adjacencyList;
    unordered_map<string, Vertex> vertexHashMap;
    
public:
    Graph();
    //~Graph();
    void addVertex(string name);
    void addEdge(string originVertex, string destinationVertex, int value);
    bool isContainsInList(string vertexName);
    list<string> findInnerList(string vertexName);
};

#endif /* Graph_hpp */
