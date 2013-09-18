
#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
	ofSetVerticalSync(true);
    ofBackground(0,0,0);
    ofSetCircleResolution(150);
    ofEnableSmoothing();
    
    
    for (int i = 0; i<20; i++){
        myCirclesX[i] = ofGetWindowWidth()/2;
        myCirclesY[i] = ofGetWindowHeight()/2;
    }
    
    for (int i = 0; i<100; i++){
        myCirclesX2[i] = ofGetWindowWidth()/2;
        myCirclesY2[i] = ofGetWindowHeight()/2;
    }
    
}

//--------------------------------------------------------------
void testApp::update(){
    
    
}

//--------------------------------------------------------------
void testApp::draw(){
    
    for (int i = 0; i < 20; i++){
        float sinOfTime = sin( ofGetElapsedTimef()/1.5 );
        float sinMapped = ofMap( sinOfTime, -1, 1, 1, 380 );
        ofSetColor(50, 255, 200);
        ofSetLineWidth(i+3.0);
        ofNoFill();
        ofCircle(myCirclesX[i], myCirclesY[i], sinMapped+(i*20));
    }
    
    for (int i = 0; i < 20; i++){
        float sinOfTime = sin( ofGetElapsedTimef()/1.5 );
        float sinMapped = ofMap( sinOfTime, -7, 1, -30, 380 );
        ofSetColor(255, 55, 120);
        ofSetLineWidth(i+2.0);
        ofNoFill();
        ofCircle(myCirclesX[i], myCirclesY[i], sinMapped+(i*21));
    }
    
    for (int i = 0; i < 20; i++){
        float sinOfTime = sin( ofGetElapsedTimef()/1.5 );
        float sinMapped = ofMap( sinOfTime, -7, 1, 1, 500 );
        ofSetColor(50, 55, 255);
        ofSetLineWidth(i+2.0);
        ofNoFill();
        ofCircle(myCirclesX2[i], myCirclesY2[i], sinMapped+(i*21));
    }

    for (int i = 0; i < 20; i++){
        float sinOfTime = sin( ofGetElapsedTimef()/1.5 );
        float sinMapped = ofMap( sinOfTime, 1, -1, 1, 500 );
        ofSetColor(150, 55, 255);
        ofSetLineWidth(i+2.0);
        ofNoFill();
        ofCircle(myCirclesX2[i], myCirclesY2[i], sinMapped+(i*21));
    }
    
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
