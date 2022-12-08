//
//  Vertex.cpp
//  graphs_praktika
//
//  Created by Dmitry Savelev on 08.11.2022.
//

#include "Vertex.hpp"

Vertex::Vertex(){};

Vertex::Vertex(std::string name){
    this -> name = name;
}

Vertex::~Vertex(){
    for (Edge edge : edges) {
        edge.~Edge();
    }
    delete this;
}

void Vertex::editVertex(std::string newName){
    name = newName;
}

void Vertex::addEdge(Edge *newEdge){
    edges.push_back(*newEdge);
}
