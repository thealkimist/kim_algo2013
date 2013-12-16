//
//  Boid.h
//  Flocking
//
//  Created by Charlie Whitney on 10/22/13.
//
//

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