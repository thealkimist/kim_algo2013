#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    ofSetVerticalSync(true);
    
	ofEnableAlphaBlending();
    
	// set the position of the rectangle:
    
    for (int i = 0; i < 9; i++){
	myRectangle[i].pos.x = ofRandom(250);
        myRectangle[i].pos.y = ofRandom(200);
    }

}

//--------------------------------------------------------------
void testApp::update(){
    for (int i = 0; i < 9; i++){
        myRectangle[i].xenoToPoint(mouseX, mouseY);
    }

}

//--------------------------------------------------------------
void testApp::draw(){
    
    for (int i = 0; i < 9; i++){
    myRectangle[i].draw();
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

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}
