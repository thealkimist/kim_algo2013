#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){
    ofBackground(242,229,197);
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    ofNoFill();
 
    interval = ofRandom(20,250);
    bLaunch = false;
    
    ofColor orange;
    ofColor red;
    ofColor teal;
    ofColor blue;
    orange.setHex(0xF7B444);
    red.setHex(0xEF6245);
    teal.setHex(0x3CBCA6);
    blue.setHex(0x117D84);
    
}

//--------------------------------------------------------------
void testApp::update(){
    
    // resets the time difference
    if(ofGetElapsedTimeMillis() - timeCapture > interval) {
        launchParticle();
        timeCapture = ofGetElapsedTimeMillis();
        interval = ofRandom(20 , 200);
    }
    
    
    for( vector<Particle>::iterator it = pList.begin(); it != pList.end(); ){
        
        it -> update(dampen());
        
        // if iterator finds dead particle, erase it
        if( it -> bVanish){
            it = pList.erase(it);
        }else{
            it++;
        }
    }
    
    
    for( vector<Launch>::iterator it = ballLaunch.begin(); it != ballLaunch.end(); ){
        
        it -> update();
        
        if( it -> pos.y < it -> exp.y ){
            explode( it -> pos );
            it = ballLaunch.erase(it);
        }else{
            it++;
        }
    }
    
}

//--------------------------------------------------------------
void testApp::draw(){
    
    for ( vector<Particle>::iterator it = pList.begin(); it != pList.end(); it++ ) {
        it -> draw();
    }
    
    for( vector<Launch>::iterator it = ballLaunch.begin(); it != ballLaunch.end(); it++){
        it -> draw();
    }
    
   
}

void testApp::explode(ofVec2f _expPos){

//    std::random_shuffle(colors.begin(),colors.end());
//    ofRandomize(colors);
    
    float pSize = ofRandom(2.0,10.0);
    int eSize = ofRandom(30,500);
    
    cout<<eSize<<endl;
    
    for (int i = 0; i < eSize; i++){
        Particle p;
        ofVec2f rVel = ofVec2f( ofRandom(1.0), ofRandom(1.0)) * 40.0 - 15.0;
        p.setup( rVel, _expPos, pSize);
        pList.push_back( p );
    }
}

void testApp::launchParticle(){
    
    // generates new explosion location every time
    explosionPos.x = ofRandom(150, ofGetWindowWidth()-150);
    explosionPos.y = ofRandom(0, ofGetWindowHeight()/2);
    
    Launch la;
    la.setup(explosionPos);
    ballLaunch.push_back(la);
    
    //cout<<explosionPos<<endl;
    
}

float testApp::dampen(){
    float d = 0.97;
    return d;
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
