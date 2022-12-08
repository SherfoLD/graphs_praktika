//
//  Graph.hpp
//  graphs_praktika
//
//  Created by Dmitry Savelev on 13.11.2022.
//

#ifndef Graph_hpp
#define Graph_hpp

#include <stdio.h>
#include <vector>
#include <map>
#include "Vertex.hpp"
#include "Edge.hpp"
using namespace std;


class Graph{
private:
    //map<Vertex, set<Vertex>> adjacencyList;
    map<string, map<string, Vertex>> adjacencyList;
    
public:
    Graph();
    //~Graph();
    void addVertex(string name);
    void addEdge(string edgeFrom, string edgeTo, int value);

};

#endif /* Graph_hpp */
