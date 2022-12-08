//
//  Graph.cpp
//  graphs_praktika
//
//  Created by Dmitry Savelev on 13.11.2022.
//

#include "Graph.hpp"

Graph::Graph(){
    //map<string, map<string, Vertex>> adjacencyList;
}

void Graph::addVertex(string vertexName){
    Vertex *newVertex = new Vertex(vertexName);
    adjacencyList[vertexName][vertexName] = *newVertex;
}

void Graph::addEdge(string edgeFrom, string edgeTo, int value){
    if (!adjacencyList.contains(edgeFrom) || !adjacencyList.contains(edgeFrom))
        throw 0;
    
    Edge *newEdge = new Edge(value);
    adjacencyList[edgeFrom][edgeFrom].addEdge(newEdge);
    adjacencyList[edgeFrom][edgeTo].addEdge(newEdge);
    
    adjacencyList[edgeFrom][edgeTo] = adjacencyList[edgeTo][edgeTo];
}

