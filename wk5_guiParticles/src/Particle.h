//
//  Particle.h
//  wk5_guiParticles
//
//  Created by TheAlkimist on 12/5/13.
//
//

#pragma once

#include "ofMain.h"

class Particle {
public:
    Particle( ofVec2f position, ofVec2f velocity );
    
    void update( ofVec2f mousePos );
    void draw(int r, int g, int b);
    
    ofVec2f pos, vel;
    
    float   radius;
    float   gravity;
    int     age, lifespan;
    bool    bDeadParticle;
    int         r, g, b;
    ofColor     color;
    
};
