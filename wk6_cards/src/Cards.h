//
//  Cards.h
//  wk6_cards
//
//  Created by TheAlkimist on 10/7/13.
//
//

#pragma once

#include "ofMain.h"

class Cards{
public:
    ofVec2f pos;
    ofVec2f vel;
    ofVec2f acc;
    
    void setup();
    void draw();
    void update();
};
