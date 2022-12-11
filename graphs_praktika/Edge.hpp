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
    int value;
    Vertex originVertex;
    Vertex destinationVertex;
    
public:
    Edge(Vertex originVertex, Vertex destinationVertex, int value);
    void editEdge(int newValue);
};

#endif /* Edge_hpp */
