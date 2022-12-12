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

bool Graph::isContainsInList(string vertexName){
    list<list<string>>::iterator iterator;
    for (iterator = adjacencyList -> begin(); iterator != adjacencyList -> end(); iterator++)
    {
        list<string> innerList = *iterator;
        if (innerList.front() == vertexName)
            return true;
    }
    return false;
}

list<string> *Graph::findInnerList(string vertexName){
    list<list<string>>::iterator iterator;
    for (iterator = adjacencyList -> begin(); iterator != adjacencyList -> end(); iterator++)
    {
        list<string> innerList = *iterator;
        if (innerList.front() == vertexName)
            return &innerList;
    }
    throw  std::invalid_argument("\nEXCEPTION: Inner list can't be found");
}

void Graph::addVertex(string vertexName){
    if (isContainsInList(vertexName))
        throw std::invalid_argument("\nEXCEPTION: Vertex already exists");
    
    list<string> *newVertexList = new list<string>{vertexName};
    adjacencyList -> push_back(*newVertexList);
    
    Vertex *newVertex = new Vertex(vertexName);
    vertexHashMap[vertexName] = *newVertex;
}

void Graph::addEdge(string originVertex, string destiantionVertex, int value){
    if (!isContainsInList(originVertex) || !isContainsInList(destiantionVertex))
        throw  std::invalid_argument("\nEXCEPTION: One of the Vertexes doesn't exist");
    
    list<list<string>>::iterator iterator;
    for (iterator = adjacencyList -> begin(); iterator != adjacencyList -> end(); iterator++)
    {
        (*iterator).push_back(destiantionVertex);
    }
    //findInnerList(originVertex).push_back(destiantionVertex);
    //innerList -> push_back(destiantionVertex);
}

void Graph::deleteVertex(string vertexName){
    list<list<string>>::iterator iterator;
    for (iterator = adjacencyList -> begin(); iterator != adjacencyList -> end(); iterator++)
    {
        list<string> innerList = *iterator;
        innerList.remove(vertexName);
    }
    vertexHashMap[vertexName].~Vertex();
    vertexHashMap.erase(vertexName);
    
    adjacencyList->remove(*findInnerList(vertexName));
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
    /*list<string> *currrentInnerList = findInnerList(originVertex);
    list<string>::iterator iterator;
    bool flag = false;
    for (iterator = currrentInnerList -> begin(); iterator != currrentInnerList -> end(); iterator++)
    {
        if (flag == true)
            findSimpleAllSimplePaths(*iterator, destinationVertex);
        else
            flag = true;
    }*/
}
//first, next. на edge похуй

