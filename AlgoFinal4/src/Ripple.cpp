//
//  Ripple.cpp
//  AlgoFinal2
//
//  Created by TheAlkimist on 12/13/13.
//
//

#include "Ripple.h"

Ripple::Ripple(){
    
}

void Ripple::setup(){
    ripples.allocate(ofGetWindowWidth(), ofGetWindowHeight());
}

void Ripple::update(int x, int y, int rippleX, int rippleY){
    
    ripples.begin();
        ofFill();
        ofSetColor(ofNoise( ofGetFrameNum() ) * 255 * 5, 255);
        ofEllipse(x, y, rippleX, rippleY);
    ripples.end();
    ripples.update();
    
}

void Ripple::draw(){
    ofBackground(0);
    ofSetColor(255);
    
    ofPushMatrix();
    ofTranslate(0, ofGetWindowHeight()/2 + ofGetWindowHeight()/5);
    ofRotateX(98);
    ripples.draw(0,0);
    ofPopMatrix();
    
}