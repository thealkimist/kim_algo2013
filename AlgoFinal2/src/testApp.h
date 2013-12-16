// Algo Final Project
//
// By Albert Kim & Bobby Fata

#pragma once

#include "ofMain.h"

// Addons
#include "ofxOsc.h"
#include "ofxFX.h"
#include "ofxFluid.h"
#include "ofxFft.h"

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
    
    // Transition Mode
    void transitionState();
    void transitionUpdate();
    
    // Starfield Mode
    void starFieldState();
    void starFieldUpdate();
    
    // declare the mode of play
    int projectState;
    
    // OSC Communication
    ofxOscReceiver mReceiver;
    float fader1, fader2, fader3, fader1Value, fader2Value, fader3Value;
    float rotary1, rotary2, rotary3, rotary1Value, rotary2Value, rotary3Value;
    float push1, push2, push3;
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
    
    ofImage starImage;
    ofImage starInvert;
    int starAlpha;
    
    FlockController flocker;
};
