//
//  Particle.cpp
//  wk4_fireworks
//
//  Created by TheAlkimist on 9/27/13.
//
//

#include "Particle.h"

void Particle::setup( ofVec2f rVel){
    ofSetCircleResolution(100);
    vel = rVel;
    age = 0;
    lifespan = ofRandom(50,150);
    
    pos = ofGetWindowSize() / 2.0;
    pVanish = false;
    gravity = 0.04;
    
    r = 255;
    g = ofRandom(10,80);
    b = ofRandom(90,220);
    
}

void Particle::update(){
    
    float noise = ofNoise(pos.x * 0.005, pos.y*0.005, ofGetElapsedTimef() * 0.1) * 2.0;
    
    float ageOfParticle = 1.0 - ( (float)age / (float) lifespan );  //starts at 100% and counts down to 0%
    
    pos += ofVec2f( cos(noise), sin(noise) ) * (1.0 - ageOfParticle );
    pos += vel;
    vel.y += gravity;
    vel *= 0.97;
    
    age++;
    
    if( age > lifespan ){
        pVanish = true;
    }
}

void Particle::draw(){
    if ( pVanish ) {
        return;
    }
    
    float ageOfParticle = 1.0 - ( (float)age / (float)lifespan );
    
    ofSetColor(r,g,b);
    //ofSetLineWidth(10.0);
    ofCircle( pos, 4.0 * ageOfParticle );

}




