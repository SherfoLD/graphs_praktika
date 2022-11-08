//
//  Edge.cpp
//  graphs_praktika
//
//  Created by Dmitry Savelev on 08.11.2022.
//

#include <iostream>
#include "Edge.hpp"
#include "Vertex.hpp"

Edge::Edge(Vertex* edgeFrom, Vertex* edgeTo, int value){
    this -> edgeFrom = edgeFrom;
    this -> edgeTo = edgeTo;
    this -> value = value;
}

void Edge::editEdge(int newValue){
    value = newValue;
}



