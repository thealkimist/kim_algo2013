//
//  Particle.cpp
//  wk9_squashSquishParticles
//
//  Created by TheAlkimist on 11/16/13.
//
//

#include "Particle.h"

Particle::Particle(){
    mass = 1.0;
}

Particle::Particle( ofVec2f position ){
    mass = 1.0;
    position = ofGetWindowSize()/2;
}

void Particle::applyForce( ofVec2f force ){
    acc += (force/mass);
}

void Particle::update(){
    vel += acc;
    pos += vel;
    
    if( pos.x < 0 || pos.x > ofGetWindowWidth() ){
        vel.x = -vel.x;
    }
    
    if( pos.y < 0 || pos.y > ofGetWindowHeight() ){
        vel.y = -vel.y;
    }
    
    acc.set(0);
}

void Particle::draw(){
    ofEllipse(pos, 10 * mass, 10 * mass);
}