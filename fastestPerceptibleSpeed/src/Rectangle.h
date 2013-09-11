//
//  Rectangle.h
//  fastestPerceptibleSpeed
//
//  Created by TheAlkimist on 9/3/13.
//
//

#pragma once

#include "ofMain.h"

class Rectangle {
    
public:
    Rectangle();
    
    void update();
    void draw();
    
    ofPoint pos;
    
    float vel;
    
};
