//
//  Ball.cpp
//  ball_launcher_gravity
//
//  Created by TheAlkimist on 9/6/13.
//
//

#include "Ball.h"

Ball::Ball(){
    ofSeedRandom();
    
    position.x = ofGetWindowWidth()/4;
    position.y = ofGetWindowHeight()/2;
    
    velocity.x = ofRandom(0.0,4.0);
    velocity.y = ofRandom(-5.0,-20.0);
    
    ofSetRectMode( OF_RECTMODE_CENTER );
    
    gravity = 0.8;
}

void Ball::update(){
   
    
    if ( position.x >= ofGetWindowWidth() || position.x <= 0 ){
        velocity.x *=-1;
    }
    if ( position.y >= ofGetWindowHeight() || position.y <= 0 ){
        velocity.y *=(0-0.75);
    }
    
    position += velocity;
    velocity.y += gravity;
    
}

void Ball::draw(){
    ofSetColor(255, 50, 150);
    ofCircle(position.x, position.y, 50);
}
