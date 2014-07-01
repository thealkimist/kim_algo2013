//
//  Launch.cpp
//  wk4_fireworks
//
//  Created by TheAlkimist on 9/28/13.
//
//

#include "Launch.h"

Launch::Launch(){
    
}

void Launch::setup(ofVec2f _exp){
    gravity = 0.05;
    exp = _exp;
    pos.x = exp.x;
    pos.y = ofGetWindowHeight()-10;
    vel = ofVec2f(0.0, -11.5);
    cVel = ofVec2f(ofRandom(1.1,1.7),(ofRandom(1.4,3.2)));

}

void Launch::update(){

    pos += vel;
    vel.y += gravity;
    
}

void Launch::draw(){
    
    ofSetColor(17, 125, 132);
    ofFill();
    ofCircle(pos.x, pos.y, 2.4);
}