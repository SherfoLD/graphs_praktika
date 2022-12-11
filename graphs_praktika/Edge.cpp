//
//  Edge.cpp
//  graphs_praktika
//
//  Created by Dmitry Savelev on 08.11.2022.
//

#include <iostream>
#include "Edge.hpp"

Edge::Edge(Vertex originVertex, Vertex destinationVertex, int value){
    this -> originVertex = originVertex;
    this -> destinationVertex = destinationVertex;
    this -> value = value;
}

void Edge::editEdge(int newValue){
    value = newValue;
}



