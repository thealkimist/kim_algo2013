//
//  Particle.h
//  wk9_squashSquishParticles
//
//  Created by TheAlkimist on 11/16/13.
//
//

#pragma once

#include "ofMain.h"

class Particle{
public:
    Particle();
    Particle( ofVec2f position );
    
    void applyForce( ofVec2f force );
    void update();
    void draw();
    
    ofVec2f pos;
    ofVec2f acc;
    ofVec2f vel;
    
    float mass;
    
    
};
