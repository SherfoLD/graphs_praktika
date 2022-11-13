//
//  Vertex.cpp
//  graphs_praktika
//
//  Created by Dmitry Savelev on 08.11.2022.
//

#include "Vertex.hpp"

Vertex::Vertex(std::string name){
    this -> name = name;
}

Vertex::~Vertex(){
    for (Edge edge : edges) {
        edge.~Edge();
    }
}

void Vertex::editVertex(std::string newName){
    name = newName;
}
