
//
//  Project by Albert Kim & Bobby Fata
//
//

#include "FlowField.h"

void FlowField::setup( ofVec2f rVel ){
    vel = rVel;
    age = 0;
    lifespan = ofRandom(50, 100);
    
    pos.set(ofRandom(ofGetWindowWidth()), 0.0);
    gravity.set(0.0, 0.05);
    
    bIsDead = false;
};

void FlowField::update(){
    
    float noise = ofNoise(pos.x * 0.005, pos.y*0.005, ofGetElapsedTimef() * 0.1) * 2.0;
    
    float agePct = 1.0 - ((float)age / (float)lifespan);
    
    // use sin and cos to give us some sweepy circular motion.  The closer we are to death, the more noise we add.
    pos += ofVec2f( cos(noise), sin(noise) ) * (1.0-agePct);
    pos += vel;
    vel += gravity;
    
    age++;
    
    if( age > lifespan ) {
        bIsDead = true;         // we've had a good life.
    }
};

void FlowField::draw(){
    if( bIsDead ){
        return;
    }
    
    float agePct = 1.0 - ((float)age / (float)lifespan);
    
    ofPushMatrix();{
        ofTranslate(0, ofGetWindowHeight()/2 + 200);
        ofRotateX(86);
    
            ofSetColor(255, 50, 150);
            ofCircle( pos, 4.0 * agePct  );         // The older pour particle is, the smaller it gets.
        
    }ofPopMatrix();
};

