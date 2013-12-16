//
//  Particle.cpp
//  wk5_guiParticles
//
//  Created by TheAlkimist on 12/5/13.
//
//

#include "Particle.h"

Particle::Particle( ofVec2f position, ofVec2f velocity ) {
    pos = position;
    vel = velocity;
    radius = 2;
    age = 0;
    lifespan = floor( ofRandom(60,100) );
    gravity = 0.97;
    color = ofColor(r,g,b);
}

void Particle::update( ofVec2f mousePos ){
    
    pos += vel;
    vel *= gravity;
    age++;
    
    if( age > lifespan ){
        bDeadParticle = true;
    }
    
    float agePct = 1.0 - ((float)age / (float)lifespan);
    radius = agePct * 3.0;
}

void Particle::draw(int r, int g, int b) {
    ofSetColor(r, g, b);
    ofCircle(pos, radius);
}