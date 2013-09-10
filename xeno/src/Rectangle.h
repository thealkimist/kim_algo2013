//
//  Rectangle.h
//  xeno
//
//  Created by TheAlkimist on 9/10/13.
//
//

#pragma once

#include "ofMain.h"

class Rectangle {
public:
    Rectangle();
    
    void xenoToPoint ( float catchX, float catchY );
    void draw();
    
    ofPoint pos, targetPos;
    
    float catchUpSpeed;
    
};
