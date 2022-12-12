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
    if (adjacencyList.contains(vertexName))
        throw std::invalid_argument("\nEXCEPTION: Vertex already exists");

    adjacencyList[vertexName];
    
    Vertex *newVertex = new Vertex(vertexName);
    vertexHashMap[vertexName] = *newVertex;
}

void Graph::addEdge(string originVertex, string destiantionVertex, int value){
    if (!adjacencyList.contains(originVertex) || !adjacencyList.contains(originVertex))
        throw  std::invalid_argument("\nEXCEPTION: One of the Vertexes doesn't exist");
    
    adjacencyList[originVertex].push_back(destiantionVertex);
}

void Graph::deleteVertex(string vertexName){
    adjacencyList.erase(vertexName);
    for(auto &key : adjacencyList) {
        key.second.remove(vertexName);
    };
    
    vertexHashMap[vertexName].~Vertex();
    vertexHashMap.erase(vertexName);
    
}

void Graph::findSimpleAllSimplePaths(string originVertex, string destinationVertex){
    if (vertexHashMap[originVertex].mark == true)
        return;
    
    vertexHashMap[originVertex].mark = true;
    currentPath.push_back(originVertex);
    if (originVertex == destinationVertex){
        simplePaths.push_back(currentPath);
        vertexHashMap[originVertex].mark = false;
        currentPath.pop_back();
        return;
    };
    for (auto const &nextVertex : adjacencyList[originVertex]) {
        findSimpleAllSimplePaths(nextVertex, destinationVertex);
    }
    currentPath.pop_back();
    vertexHashMap[originVertex].mark = false;
}
//first, next. на edge похуй

