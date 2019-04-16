//  ------------------------------------------
//  Point mesh creator
//  ------------------------------------------
//
//  Creates a mesh grid from indiv. vertices
//
//  ------------------------------------------

#ifndef pointMesh_h
#define pointMesh_h

#include <stdio.h>
#include "ofMain.h"

class PointMesh {
    
public:
    PointMesh();
    
    void setupPointMesh();
    void updatePointMesh();
    void drawPointMesh();
    
    ofMesh mesh;
    
};

#endif /* pointMesh_h */
