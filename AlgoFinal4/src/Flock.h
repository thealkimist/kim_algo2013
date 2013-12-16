// Algo Final Project
//
// By Albert Kim & Bobby Fata

#pragma once

#include "ofMain.h"

class Flock {
public:
    Flock();
    
    void applyForce( ofVec3f force );
    void pullToCenter( ofVec3f center );
    
    void update();
    void draw();
    
    float damping;
    ofVec3f pos, vel, acc;
};