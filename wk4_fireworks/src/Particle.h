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
    
    void setup( ofVec2f rVel, ofVec2f _expPos, float _pSize);
    void update( float dampen );
    void draw();
    
    ofVec2f pos;
    ofVec2f vel;
    ofVec2f expPos;
    
    // declare age of particle and it's lifespan
    int age, lifespan;
    bool bVanish;
    float gravity;
    float pSize;
    
    int r, g, b;

};
