//
//  Edge.cpp
//  graphs_praktika
//
//  Created by Dmitry Savelev on 08.11.2022.
//

#include <iostream>
#include "Edge.hpp"

Edge::Edge(int value){
    this -> value = value;
}

void Edge::editEdge(int newValue){
    value = newValue;
}



