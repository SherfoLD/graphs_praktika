//
//  Vertex.cpp
//  graphs_praktika
//
//  Created by Dmitry Savelev on 08.11.2022.
//

#include "Vertex.hpp"


Vertex::Vertex(){
    this -> name = nullptr;
    this -> mark = false;
};

Vertex::Vertex(std::string name){
    this -> name = name;
    this -> mark = false;
}

void Vertex::editVertex(bool newMark){
    this -> mark = newMark;
}
