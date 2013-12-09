//
//  Particle.cpp
//  FINAL_1
//
//  Created by TheAlkimist on 12/3/13.
//
//

#include "Particle.h"

Particle::Particle(){
    
    damping = 0.09f;
    size = 1.0;
}

void Particle::update(){
    
    vel += force;
    pos += vel;
}

void Particle::draw(){
    
    ofSetColor(255,50,150);
    ofCircle(pos.x, pos.y, pos.z, size);
    
}

void Particle::addDampening(){
    
    force.x = force.x - vel.x * damping;
    force.y = force.y - vel.y * damping;
    force.z = force.z - force.z * damping;
    
}

void Particle::resetForce(){
    
    force.set(0,0);
}

void Particle::setInitCondition(float px, float py, float pz, float vx, float vy, float vz){
    
    pos.set(px,py,pz);
    vel.set(vx,vy,vz);
}
