//
//  Rectangle.cpp
//  fastestPerceptibleSpeed
//
//  Created by TheAlkimist on 9/3/13.
//
//

#include "Rectangle.h"

Rectangle::Rectangle(){
    
}

void Rectangle::update(){
    vel = 19;
    pos.y = ofGetWindowHeight()/2;
    pos.x = pos.x + vel;
    
    if (pos.x >= ofGetWindowWidth()){
        pos.x = 0;
    }
}

void Rectangle::draw(){
    
    ofEnableAlphaBlending();
    ofSetColor(255, 50, 150);
    
    ofRect(pos.x, pos.y, 250, 250);
}