// Algo Final Project
//
// By Albert Kim & Bobby Fata

#pragma once

#include "ofMain.h"

// Addons
#include "ofxOsc.h"
#include "ofxFX.h"
#include "ofxRipples.h"
#include "ofxFluid.h"

// Classes
#include "Particle.h"
#include "Sphere.h"
#include "FlowField.h"
#include "Ripple.h"
#include "FlockController.h"
#include "Flock.h"


class testApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
//-------------------------------------------------
    void checkOsc();
    void addFlow();
    
    // First Mode
    void shipState();
    void shipUpdate();

    // Starfield Mode
    void starFieldUpdate();
    void starFieldState();
    
    // declare the mode of play
    int projectState;
    
    // OSC Communication
    ofxOscReceiver mReceiver;
    float fader1, fader2, fader3;
    float rotary1, rotary2, rotary3, rotary4, rotary5, rotary6;
    float push1, push2, push3, push4;
    float counter;
    
    //ball
    ofVec2f pos;
    
    // First Particle Field
    vector<Particle> particles;
    float particleCount;
    
    int particleR, particleG, particleB;
    int w, h;
    
    bool push;
    bool drawLines;

    // FLowing field
    vector<FlowField> flowList;
    FlowField myFlowField;
    
    // Ripple Effect
    Ripple myRipples;
    
    bool bdrawingField;
    bool bframeRate;
    bool bsettingPerlin;
    bool bDrawFluid;
    bool bWireframe;
    
    // Geometric Objects
    Sphere mySphere1;
    Sphere mySphere2;
    Sphere cone;
    Sphere ico;
    Sphere box;
    
    ofVec3f loc1, vel1;
    ofVec3f loc2, vel2;
    ofVec3f loc3, vel3;
    ofVec3f loc4, vel4;
    ofVec3f loc5, vel5;
    
    ofImage starImage;
    ofImage starInvert;
    int starAlpha;
    
    FlockController flocker;
};
