//
//  Ripple.h
//  AlgoFinal2
//
//  Created by TheAlkimist on 12/13/13.
//
//

#pragma once

#include "ofMain.h"
#include "ofxFX.h"

class Ripple{
public:
    Ripple();
    
    void setup();
    void update();
    void draw();
    
    ofxRipples ripples;
    
};