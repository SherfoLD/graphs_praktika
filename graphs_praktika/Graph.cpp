//
//  Graph.cpp
//  graphs_praktika
//
//  Created by Dmitry Savelev on 13.11.2022.
//

#include "Graph.hpp"

void Graph::addVertex(string vertexName){
    if (adjacencyList.contains(vertexName))
        throw std::invalid_argument("\nEXCEPTION: Vertex already exists");

    adjacencyList[vertexName];
    Vertex newVertex = Vertex(vertexName);
    vertexHashMap[vertexName] = newVertex;
}

void Graph::addEdge(string originVertex, string destiantionVertex, int value){
    if (!adjacencyList.contains(originVertex) || !adjacencyList.contains(originVertex))
        throw  std::invalid_argument("\nEXCEPTION: One of the Vertexes doesn't exist");
    
    adjacencyList[originVertex].push_back(destiantionVertex);
    weightOfEdges[originVertex+destiantionVertex] = value;
}

void Graph::deleteVertex(string vertexName){
    if (!adjacencyList.contains(vertexName))
        throw std::invalid_argument("\nEXCEPTION: Vertex doesn't exists");
    
    adjacencyList.erase(vertexName);
    for(auto &position : adjacencyList) {
        position.second.remove(vertexName);
        if (weightOfEdges.contains(position.first+vertexName))
            weightOfEdges.erase(position.first+vertexName);
        if (weightOfEdges.contains(vertexName+position.first))
            weightOfEdges.erase(vertexName+position.first);
    };
    
    vertexHashMap.erase(vertexName);
}

void Graph::deleteEdge(string originVertex, string destinationVertex){
    if (!weightOfEdges.contains(originVertex+destinationVertex))
        throw std::invalid_argument("\nEXCEPTION: Edge doesn't exists");
    
    weightOfEdges.erase(originVertex+destinationVertex);
}

void Graph::editEdge(string originVertex, string destiantionVertex, int newValue){
    if (!weightOfEdges.contains(originVertex+destiantionVertex))
        throw std::invalid_argument("\nEXCEPTION: Edge doesn't exists");
    
    weightOfEdges[originVertex+destiantionVertex] = newValue;
}

string Graph::first(string vertexName){
    if (!adjacencyList.contains(vertexName) or adjacencyList[vertexName].size() == 0)
        return "";
    
    return adjacencyList[vertexName].front();
}

string Graph::next(string keyVertex, string startVertex){
    if (!adjacencyList.contains(keyVertex) or adjacencyList[keyVertex].size() == 0)
        return "";
    
    bool isStartVertexFound = false;
    for (auto const &valueOfList : adjacencyList[keyVertex]){
        if (valueOfList == startVertex)
            isStartVertexFound = true;
        if (isStartVertexFound)
            return valueOfList;
    }
    return "";
}

string Graph::vertex(string keyVertex, string adjacentVertex){
    if (!adjacencyList.contains(keyVertex) or adjacencyList[keyVertex].size() == 0)
        return "";
    
    for (auto const &valueOfList : adjacencyList[keyVertex]){
        if (valueOfList == adjacentVertex){
            return adjacentVertex;
        }
    }
    return "";
}

void Graph::print(){
    cout << "Graph:\n";
    for (auto const &key : adjacencyList){
        cout << key.first << ": ";
        for (auto const &valueOfList : key.second){
            cout << valueOfList << " ";
        }
        cout << "\n";
    }
}

void Graph::printSimplePaths(){
    cout << "\nSimple paths:\n";
    int i = 1;
    for (auto const &innerList : simplePaths){
        cout << i++ << ") ";
        for (auto const &valueOfList :innerList){
            cout << valueOfList << " ";
        }
        cout << "\n";
    }
}

void Graph::findSimpleAllSimplePaths(string originVertex, string destinationVertex){
    if (vertexHashMap[originVertex].mark == true)
        return;
    
    vertexHashMap[originVertex].editVertex(true);
    currentPath.push_back(originVertex);
    if (originVertex == destinationVertex){
        simplePaths.push_back(currentPath);
        vertexHashMap[originVertex].editVertex(false);
        currentPath.pop_back();
        return;
    };
    for (auto const &nextVertex : adjacencyList[originVertex]) {
        findSimpleAllSimplePaths(nextVertex, destinationVertex);
    }
    currentPath.pop_back();
    vertexHashMap[originVertex].editVertex(false);
}


