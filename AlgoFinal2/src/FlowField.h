
//  Project by Albert Kim & Bobby Fata
//
//

#pragma once

#include "ofMain.h"

class FlowField {
public:
    FlowField(){};
    void setup( ofVec2f rVel );
    void update();
    void draw();
    
    ofVec2f pos;
    ofVec2f vel;
    ofVec2f gravity;
    int age, lifespan;
    bool bIsDead;
};
