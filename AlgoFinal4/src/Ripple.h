// Algo Final Project
//
// By Albert Kim & Bobby Fata

#pragma once

#include "ofMain.h"
#include "ofxFX.h"
#include "ofxRipples.h"

class Ripple{
public:
    Ripple();
    
    void setup();
    void update(int x, int y, int rippleX, int rippleY);
    void draw();
    
    ofxRipples ripples;
    
};