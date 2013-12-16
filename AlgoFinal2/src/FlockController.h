//
//  FlockController.h
//  Flocking
//
//  Created by Charlie Whitney on 10/22/13.
//
//

#pragma once

#include "ofMain.h"
#include "Flock.h"

class FlockController {
public:
    FlockController();
    
    void applyForces( float zoneRadius, float separateThresh=0.4, float alignThresh=0.7 );
    
    void addParticle( int numParticles=1 );
    void update(ofVec3f center);
    void draw();
    
    vector<Flock> flockList;
};