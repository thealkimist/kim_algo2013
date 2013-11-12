#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetFrameRate(60);
    ofSetVerticalSync(true);
  
    
    mSender.setup("localhost", 12345);  // 127.0.0.1
    ofBackground(0);
    
    pos = ofGetWindowSize() / 2;
    vel = ofVec2f(10,4);
    
    ofSetWindowPosition(0,0);
    
}

//--------------------------------------------------------------
void testApp::update(){
    pos += vel;
    
    if (pos.x < 0 || pos.x > ofGetWindowWidth() * 2){
        vel.x *= -1;
    }
    
    if (pos.y < 0 || pos.y > ofGetWindowWidth() * 2){
        vel.y *= -1;
    }

    ofxOscMessage m;
    m.setAddress("/ball/pos");
    m.addFloatArg(pos.x);
    m.addFloatArg(pos.y);
    
    mSender.sendMessage( m );
    
}

//--------------------------------------------------------------
void testApp::draw(){

    
    ofCircle(pos, 20);
    

    
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){
    
}
