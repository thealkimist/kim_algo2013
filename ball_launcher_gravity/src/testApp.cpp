#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    ofSetVerticalSync(true);
    ofBackground( 255 );
    
    for (int i = 0; i < 1; i++){
        Ball myBall;
        ballList.push_back( myBall );
    }

}

//--------------------------------------------------------------
void testApp::update(){
    
    myBall.update();

}

//--------------------------------------------------------------
void testApp::draw(){
    myBall.draw();
    
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
    
        myBall.position.x = ofGetWindowWidth()/4;
        myBall.position.y = ofGetWindowHeight()/2;
    
        myBall.velocity.x = ofRandom(2.0,8.0);
        myBall.velocity.y = ofRandom(-5.0,-30.0);

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
