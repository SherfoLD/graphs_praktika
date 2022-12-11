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
    for (iterator = adjacencyList.begin(); iterator != adjacencyList.end(); iterator++)
    {
        list<string> innerList = *iterator;
        if (innerList.front() == vertexName)
            return true;
    }
    return false;
}

list<string> Graph::findInnerList(string vertexName){
    list<list<string>>::iterator iterator;
    for (iterator = adjacencyList.begin(); iterator != adjacencyList.end(); iterator++)
    {
        list<string> innerList = *iterator;
        if (innerList.front() == vertexName)
            return innerList;
    }
    throw "\nEXCEPTION: Inner list can't be found";
}

void Graph::addVertex(string vertexName){
    if (isContainsInList(vertexName))
        throw "\nEXCEPTION: Vertex already exists";
    
    list<string> newVertexList {vertexName};
    adjacencyList.push_back(newVertexList);
    
    Vertex *newVertex = new Vertex(vertexName);
    vertexHashMap[vertexName] = *newVertex;
}

void Graph::addEdge(string originVertex, string destiantionVertex, int value){
    if (!isContainsInList(originVertex) || !isContainsInList(destiantionVertex))
        throw "\nEXCEPTION: One of the Vertexes doesn't exist";
    
    list<string> innerList = findInnerList(originVertex);
    innerList.push_back(originVertex);
}

//deleteVertex, first, next. на edge похуй
/*
list<string>::iterator innerIterator;
for (innerIterator=innerList.begin(); innerIterator != innerList.end(); innerIterator++)
{
    if (*innerIterator == vertexName)
        return true;
}*/
