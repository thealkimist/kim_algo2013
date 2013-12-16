
//
//  Project by Albert Kim & Bobby Fata
//
//

#include "FlowField.h"

void FlowField::setup( ofVec2f rVel ){
    vel = rVel;
    age = 0;
    lifespan = 150;
    
    pos.set(ofRandom(ofGetWindowWidth()), 0.0);
    gravity.set(0.0, 0.15);
    
    bIsDead = false;
   
};

void FlowField::update(){
    
    float noise = ofNoise(pos.x * 0.005, pos.y*0.005, ofGetElapsedTimef() * 0.1) * 2.0;
    
    float agePct = 1.0 - ((float)age / (float)lifespan);
    
    pos += ofVec2f( cos(noise), sin(noise) ) * (1.0-agePct);
    pos += vel;
    vel += gravity;
    
    age++;
    
    if( age > lifespan ) {
        bIsDead = true;         // we've had a good life.
    }
};

void FlowField::draw(int r, int g, int b){
    if( bIsDead ){
        return;
    }
    
    //float agePct = 1.0 - ((float)age / (float)lifespan);
    
    ofPushMatrix();{
        ofTranslate(0, ofGetWindowHeight()/2 + ofGetWindowHeight()/5);
        ofRotateX(99);
        
        ofSetColor(r, g, b);
        ofCircle( pos, 3.5 );         // The older pour particle is, the smaller it gets.
        
    }ofPopMatrix();
};

