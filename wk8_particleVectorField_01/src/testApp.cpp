#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    myField.setup( ofGetWindowWidth(), ofGetWindowHeight(), 20 );
    ofSetFrameRate(60);
    
    particleList.clear();
    
    for( int i=0; i<40000; i++ ){
        addParticle();
    }
    
    ofBackground(20, 40, 30);
    drawingField = false;
    frameRate = false;
}

void testApp::addParticle() {
    Particle part;
    part.pos = ofVec2f( ofRandomWidth(), ofRandomHeight() );
    part.pos2 = ofVec2f( part.pos.x + ofRandom(1.0, 10.0), part.pos.y + ofRandom(1.0, 7.0) );
    
    particleList.push_back( part );
}

//--------------------------------------------------------------
void testApp::update(){
    myField.update();
    
    for (vector<Particle>::iterator it = particleList.begin(); it != particleList.end(); it++){
        it -> applyForce( myField.getForceAtPosition( it -> pos ) * 0.005 );
        it -> update();
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    ofSetColor(255);
    
    if(drawingField){
        myField.draw();
    }
    
    if(frameRate){
        ofSetColor(200);
        ofDrawBitmapString("fps: "+ ofToString(ofGetFrameRate()), 20, 20);
    }
    
    
    ofSetColor(0, 255, 255);
    
    for (vector<Particle>::iterator it = particleList.begin(); it != particleList.end(); it++){
        it -> draw();
    }

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    if( key == '1'){
        myField.setRandom( 20.0 );
    }else if( key == '2' ){
        myField.setPerlin();
    }else if( key == 'r' ){
        
        for (vector<Particle>::iterator it = particleList.begin(); it != particleList.end(); it++){
            it -> pos = ofVec2f( ofRandomWidth(), ofRandomHeight() );
            it -> pos2 = ofVec2f( it -> pos.x + ofRandom(1.0, 10.0), it -> pos.y + ofRandom(1.0, 7.0) );
        }
    }
    if( key == '3' ){
        drawingField = true;
    }
    else if( key == '4' ){
        drawingField = false;
    }
    
    if( key == 'f' && frameRate == false ){
        frameRate = true;
        
    }else if( key == 'f' && frameRate == true ){
        frameRate = false;
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
    
    
    if( button == OF_MOUSE_BUTTON_1 ){
        //        myField.addRepelForce(x, y, 100, 2.0);
        myField.addCircularForce(x, y, 400, 4.0);
    }else{
        myField.addAttractForce(x, y, 200, 4.0);
    }
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    mouseDragged(x, y, button);
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
