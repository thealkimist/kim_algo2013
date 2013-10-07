//
//  Launch.h
//  wk4_fireworks
//
//  Created by TheAlkimist on 9/28/13.
//
//

#pragma once

#include "ofMain.h"

class Launch {
public:
    Launch();
        
        void update();
        void draw();
    
        ofPoint pos;
        ofVec2f vel;
        ofColor col;
        float gravity;

};