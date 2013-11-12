//
//  Particle.h
//  wk4_fireworks
//
//  Created by TheAlkimist on 9/27/13.
//
//

#pragma once

#include "ofMain.h"

class Particle {
public:
    Particle(){};
    
    void setup( ofVec2f rVel);         // argument for velocity
    void update();
    void draw();
    
    ofVec2f pos;
    ofVec2f vel;
    int age, lifespan;          // declare age of particle and it's lifespan
    bool pVanish;
    float gravity;
    
    int r, g, b;
    
    

};
