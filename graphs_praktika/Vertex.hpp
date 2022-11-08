//
//  Vertex.hpp
//  graphs_praktika
//
//  Created by Dmitry Savelev on 08.11.2022.
//

#ifndef Vertex_hpp
#define Vertex_hpp

#include <iostream>
#include <stdio.h>
#include "Edge.hpp"

class Vertex{ //vershina/uzel
private:
    std::string name;
    Edge* edges[];
    
public:
    Vertex(std::string vertexName);
    ~Vertex();
    void editVertex(std::string newName);
};

#endif /* Vertex_hpp */
