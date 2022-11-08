//
//  Edge.hpp
//  graphs_praktika
//
//  Created by Dmitry Savelev on 08.11.2022.
//

#ifndef Edge_hpp
#define Edge_hpp

#include <stdio.h>
#include <iostream>
#include "Vertex.hpp"

class Edge{ //duga
private:
    Vertex* edgeFrom;
    Vertex* edgeTo;
    int value;
    
public:
    Edge(Vertex* edgeFrom, Vertex* edgeTo, int value);
    ~Edge();
    void editEdge(int newValue);
};

#endif /* Edge_hpp */
