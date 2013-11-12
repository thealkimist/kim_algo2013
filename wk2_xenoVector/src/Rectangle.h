//
//  Rectangle.h
//  multipleXeno
//
//  Created by TheAlkimist on 9/10/13.
//
//

#pragma once

#include "ofMain.h"

class Rectangle {
    
public:
    
    Rectangle();
    
    void draw();
    void xenoToPoint(float catchX, float catchY);
    
    ofVec2f	pos;
    float catchUpSpeed;
    
};
