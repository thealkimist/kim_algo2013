//
//  Drops.h
//  wk3_soundComp
//
//  Created by TheAlkimist on 9/16/13.
//
//

#pragma once

#include "ofMain.h"

class Drops{
public:
    Drops();

    void update();
    void draw();

    ofPoint drips;
    float dripSize;
    int timer;
};
