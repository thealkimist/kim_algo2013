#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){
    ofBackground(0);
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    ofNoFill();
 
    
    for( int i = 0; i < 100; i++ ){
        addParticle();
    }

}

//--------------------------------------------------------------
void testApp::update(){
    
    for( vector<Particle>::iterator it = pList.begin(); it != pList.end(); ){
        it -> update();
        
        if( it -> pVanish){                         // if iterator finds dead particle, erase it
            it = pList.erase(it);
        }else{
            it++;
        }
    }
    
    ballLaunch.update();

    
}

//--------------------------------------------------------------
void testApp::draw(){
    
    
    for ( vector<Particle>::iterator it = pList.begin(); it != pList.end(); it++ ) {
        it -> draw();
    }
    
    ballLaunch.draw();
   
}

void testApp::addParticle(){
    Particle p;
    
    ofVec2f rVel = ofVec2f( ofRandom(1.0), ofRandom(1.0)) * 10.0 - 5.0;
    p.setup( rVel );
    pList.push_back( p );
}

//void testApp::launchBall(){
//    
//    ballLaunch.draw();
//    
//}

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
