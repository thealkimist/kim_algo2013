//
//  Ball.h
//  ball_launcher_gravity
//
//  Created by TheAlkimist on 9/6/13.
//
//

#pragma once

#include "ofMain.h"

class Ball{
public:
    Ball();
    
    void update();
    void draw();
    
    ofPoint position;
    ofVec2f velocity;
    
    float gravity;
    
};

