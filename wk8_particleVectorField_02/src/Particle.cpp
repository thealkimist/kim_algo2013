//
//  Particle.cpp
//  wk8_particleVectorField_01
//
//  Created by TheAlkimist on 10/21/13.
//
//

#include "Particle.h"

Particle::Particle(){
    mass = 1.0;
}

void Particle::applyForce( ofVec2f force ){
    accel += ( force/ mass );
}

void Particle::update(){
    vel += accel;
    pos += vel;
    pos2 += vel;
    
    vel *= 0.97;
    
    accel.set(0);
}

void Particle::draw(){
    
    ofSetColor(255, 50, 150, 70);
    ofSetLineWidth(1);
    ofLine(pos, pos2);
}