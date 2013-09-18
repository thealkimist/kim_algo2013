#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofBackground(0, 0, 0);
    ofSetVerticalSync(TRUE);
    ofEnableAlphaBlending();
    
    blush.loadSound("blush.mp3");
    
    stringLoc.x = ofGetWindowWidth()/30;
    stringLoc.y = ofGetWindowHeight()/24;
    
    boxRadius = 300.0;
    ballPos = ofVec3f( 0.0, 0.0, 0.0);
    ballVel = ofVec3f( ofRandom(10,15), ofRandom(6,10), ofRandom(10,17) );


}

//--------------------------------------------------------------
void testApp::update(){
    
    drops.update();
    
    ballPos += ballVel;
    
    if ( ballPos.x > boxRadius || ballPos.x < -boxRadius ){
        ballVel.x *= -1;
    }
    if ( ballPos.y > boxRadius || ballPos.y < -boxRadius ){
        ballVel.y *= -1;
    }
    if ( ballPos.z > boxRadius || ballPos.z < -boxRadius ){
        ballVel.z *= -1;
    }


}

//--------------------------------------------------------------
void testApp::draw(){
    
    float angle = ofGetElapsedTimef()   * 0.5;
    float radius = 40;
    
    float x = radius * cos(angle);
    float y = radius * sin(angle);
    
    ofPoint temp;
    temp.x = x;
    temp.y = y;
    pointList.push_back(temp);          // store the vector
    if( pointList.size() > 30 ){
        pointList.erase( pointList.begin());
    }
    
    for (int i=0; i<pointList.size(); i++) {
        ofPushMatrix();{
            ofSetRectMode(OF_RECTMODE_CENTER);
            ofTranslate(ofGetWindowWidth()/2, ofGetWindowHeight()/2);
            ofNoFill();
            ofSetColor(155*0.05*i,55,255);
            ofRect(x,y,40*i,40*i);
        }ofPopMatrix();
    }
    
    drops.draw();
    
    ofPushMatrix();{
        ofSetColor(150, 50, 255, 75);
        
        ofTranslate( ofGetWindowSize()/2 );
        ofDrawSphere( ballPos, 15 );
        
        ofSetColor(255, 50, 150, 255*0.2);
        
    }ofPopMatrix();
    
    ofSetColor(155, 20, 110);
    ofDrawBitmapString("p for play", stringLoc );


}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    
    if (key == 'p'){
    blush.play();
    }
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
