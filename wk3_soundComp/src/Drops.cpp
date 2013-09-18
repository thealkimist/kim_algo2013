//
//  Drops.cpp
//  wk3_soundComp
//
//  Created by TheAlkimist on 9/16/13.
//
//

#include "Drops.h"

Drops::Drops(){
    drips.x = ofRandom(150, ofGetWindowWidth()-150);
    drips.y = ofRandom(150, ofGetWindowHeight()-150);
    
    dripSize = ofRandom(5,15);
    timer = 0;
    
}

void Drops::update(){
    if (timer == 0) {
        timer++;
        ofLog(OF_LOG_NOTICE, "%i",timer);
        if (timer == 1){
            timer = 0;
            drips.x = ofRandom(250, ofGetWindowWidth()-250);
            drips.y = ofRandom(200, ofGetWindowHeight()-200);
            dripSize = ofRandom(5,20);
        
            ofLog(OF_LOG_NOTICE, "%i",timer);

        }
        
    }
}

void Drops::draw(){
    ofSetColor(ofRandom(120,240), ofRandom(50,100), ofRandom(150,255));
    ofFill();
    ofCircle(drips.x, drips.y, dripSize, 10);
    
}