//  ------------------------------------------
//  Point mesh creator
//  ------------------------------------------
//
//  Creates a mesh grid from indiv. vertices
//
//  ------------------------------------------

#include "pointMesh.h"

PointMesh::PointMesh(){};

void PointMesh::setupPointMesh() {
    mesh.setMode(OF_PRIMITIVE_POINTS);
    
    for (int x = 0; x < ofGetWidth(); x+=ofRandom(10)) {
        for (int y = 0; y < ofGetHeight(); y+=ofRandom(10)) {
            mesh.addVertex(ofVec3f(x, y, 0.0));
            mesh.addColor(ofColor(255));
            mesh.addNormal(ofVec3f(x, y, 10.0));
            mesh.addTexCoord(ofVec2f(x, y));
        }
    }
}

void PointMesh::updatePointMesh() {
    
}

void PointMesh::drawPointMesh() {
    ofBackground(0);
    ofSetColor(255);
    
    ofPushMatrix();
    
    ofTranslate(-ofGetWidth() * .5, -ofGetHeight() * .5);
    
    mesh.drawVertices();
    
    ofPopMatrix();
}


