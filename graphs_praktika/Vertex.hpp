//
//  Vertex.hpp
//  graphs_praktika
//
//  Created by Dmitry Savelev on 08.11.2022.
//

#ifndef Vertex_hpp
#define Vertex_hpp

#include <list>
#include <stdio.h>
#include "Edge.hpp"


class Vertex{ //vershina/uzel
private:
    std::string name;
    std::list<Edge> edges;
    
public:
    Vertex();
    Vertex(std::string name);
    ~Vertex();
    
    void editVertex(std::string newName);
    void addEdge(Edge *newEdge);
};

#endif /* Vertex_hpp */
