//
//  FlowField.h
//  VectorField
//
//  Based off of Charlie Whitney
//
//

#pragma once
#include "ofMain.h"

typedef vector<ofVec2f> VectorList;

class FlowField : public ofBaseApp {
public:
    FlowField();
    
    void setup( int width, int height, int res );
    void reset();
    void setRandom();
    void setPerlin();
    void setSinLerp();
    void setSinCos();
    
    void draw();
    
    void drawVectorAt( const ofVec2f &vec, const ofVec2f &pos );
    void drawVector( const ofVec3f &start, const ofVec3f &end, float headLength = 0.2f, float headRadius = 0.05f );
    
    vector<VectorList>  flowList;
    int                 fieldWidth, fieldHeight, resolution;
    
    ofPoint mousePos;
};