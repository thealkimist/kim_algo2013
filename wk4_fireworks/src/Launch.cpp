//
//  Launch.cpp
//  wk4_fireworks
//
//  Created by TheAlkimist on 9/28/13.
//
//

#include "Launch.h"

Launch::Launch(){
    gravity = 0.20;
    pos.x = ofGetWindowWidth() / 2.0;
    pos.y = ofGetWindowHeight() - 100;
    vel = ofVec2f(0.0, -15.0);
    
}

void Launch::update(){

    pos += vel;
    vel.y += gravity;
    
}

void Launch::draw(){
 
    ofSetColor(250, 50, 150);
    ofFill();
    ofCircle(pos.x, pos.y, 5);
}