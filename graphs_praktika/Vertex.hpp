//
//  Vertex.hpp
//  graphs_praktika
//
//  Created by Dmitry Savelev on 08.11.2022.
//

#ifndef Vertex_hpp
#define Vertex_hpp

#include <string>
#include <list>
#include <stdio.h>


class Vertex{ //vershina/uzel
private:
    std::string name;
    
public:
    bool mark;

    Vertex();
    Vertex(std::string name);
    void editVertex(bool newMark);
};

#endif /* Vertex_hpp */
