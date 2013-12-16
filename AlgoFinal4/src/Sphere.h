// Algo Final Project
//
// By Albert Kim & Bobby Fata

#pragma once

#include "ofMain.h"

class Sphere{
public:
    Sphere();
    
    void setup(float posX, float posY, float posZ);
    void update(float movement);
    void draw(float spinX, float spinY);
    
    ofVec3f pos, vel;
    ofSpherePrimitive sphere;
    ofCylinderPrimitive cylinder;
    ofConePrimitive cone;
    ofIcoSpherePrimitive icoSphere;
    ofBoxPrimitive box;
    int r, g, b;
    
    
};
