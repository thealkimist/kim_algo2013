//
//  point.cpp
//  changingMousePosition
//
//  Created by TheAlkimist on 9/3/13.
//
//

#include "point.h"

point::point(){
    
}

void point::setup(){
    
    posa.x = ofRandom(ofGetWindowWidth());
    posa.y = ofRandom(ofGetWindowHeight());
    
    posb.x = ofRandom(ofGetWindowWidth());
    posb.y = ofRandom(ofGetWindowHeight());
    
}

void point::draw(){
    
    ofEnableAlphaBlending();
    ofSetColor(255, 50, 150);
    ofCircle(posa.x, posa.y, 100);
    
    ofSetColor(150, 50, 255);
    ofCircle(posb.x, posb.y, 100);
    
}
