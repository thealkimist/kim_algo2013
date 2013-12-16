//
//  Boid.cpp
//  Flocking
//
//  Created by Charlie Whitney on 10/22/13.
//
//

#include "Flock.h"

Flock::Flock() {
    damping = ofRandom(0.95, 0.99);
}

void Flock::applyForce(ofVec3f force){
    acc += force;
}

void Flock::pullToCenter(ofVec3f center){
    ofVec3f dir = pos - center;
    float dist = dir.length();
    float maxDistance = 300.0;
    
    if( dist > maxDistance ){
        dir.normalize();
        vel -= dir * (dist - maxDistance) * 0.0001f;
    }
}

void Flock::update(){
    float minSpeed = 1.0;
    
    vel += acc;
    vel.limit(3.0);
    
    if( vel.lengthSquared() < minSpeed * minSpeed ){
        vel = vel.normalized() * minSpeed;
    }
    
    pos += vel;
    vel *= damping;
    
    acc.set(0);
}

void Flock::draw(){
    ofSetColor(0,130,155);
    ofCircle(pos, 3);
    
}