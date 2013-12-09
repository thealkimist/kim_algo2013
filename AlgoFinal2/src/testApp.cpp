#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofBackground(0);
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    ofEnableAlphaBlending();
    
    // make 50 particles up front!
    for( int i=0; i<50; i++ ){
        addFlow();
    }
    
    fluid.allocate(ofGetWindowWidth()/2,ofGetWindowHeight()/2,5);
}

//--------------------------------------------------------------
void testApp::update(){
    
    // This is how you loop through and delete a particle using iterators and vectors
    // Note how we don't put it++ up in the top of the loop.
    for( vector<FlowField>::iterator it=flowList.begin(); it!=flowList.end(); ){
        it->update();
        
        if( it->bIsDead ){
            it = flowList.erase(it);   // When we erase one, it returns the next particle automatically.  It's done the "it++" for us!
            ofLog( OF_LOG_NOTICE, "size is " + ofToString(flowList.size()) );
        }else {
            it++;
        }
    }
    
    for( int i=0; i<50; i++ ){
        addFlow();
    }

}

//--------------------------------------------------------------
void testApp::draw(){
    for( vector<FlowField>::iterator it = flowList.begin(); it!=flowList.end(); it++){
        it->draw();
    }
}

void testApp::addFlow(){
    FlowField f;
    
    ofVec2f rVel = ofVec2f( 0.0, ofRandom(1.0) ) * 10.0 - 5.0;
    f.setup( rVel );
    flowList.push_back( f );
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
