//
//  Particle.h
//  FINAL_1
//
//  Created by TheAlkimist on 12/3/13.
//
//

#pragma once

#include "ofMain.h"

class Particle{
public:
    Particle();
    
    void draw();
    void update();
    void addDampening();
    void resetForce();
    void setInitCondition(float px, float py, float pz, float vx, float vy, float vz);  // starting force
    
    ofVec3f pos, vel, acc, force;
    
    float damping;
    float size;
    
};

