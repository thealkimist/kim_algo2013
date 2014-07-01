//
//  Particle.cpp
//  wk4_fireworks
//
//  Created by TheAlkimist on 9/27/13.
//
//

#include "Particle.h"

void Particle::setup( ofVec2f rVel, ofVec2f _expPos, float _pSize){
    ofSetCircleResolution(100);
    
    expPos = _expPos;
    vel = rVel;
    vel.normalize();
    float mag = ofRandom(0.5,5.0);
    vel *= mag;
    age = 0;
    lifespan = ofRandom(50,150);
    
    bVanish = false;
    gravity = 0.04;
    pSize = _pSize;
    
    r = ofRandom(255);
    g = 98;
    b = 69;
    
}

void Particle::update( float dampen ){
    
    float noise = ofNoise(expPos.x * 0.005, expPos.y*0.005, ofGetElapsedTimef() * 0.1) * 15.0;
    
    float ageOfParticle = 1.0 - ( (float)age / (float) lifespan );  //starts at 100% and counts down to 0%
    
    expPos += ofVec2f( cos(noise), sin(noise) ) * (1.0 - ageOfParticle );
    expPos += vel;
    vel.y += gravity;
    vel *= dampen;
    
    age++;
    
    if( age > lifespan ){
        bVanish = true;
    }
}

void Particle::draw(){
    if ( bVanish ) {
        return;
    }
    
    float ageOfParticle = 1.0 - ( (float)age / (float)lifespan );
    
    ofSetColor(r,g,b);
    //ofSetLineWidth(10.0);
    ofCircle( expPos, pSize * ageOfParticle );

}




