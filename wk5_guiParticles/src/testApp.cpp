#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetVerticalSync(true);
    ofBackground(0);
    ofEnableAlphaBlending();
    bMouseIsPressed = false;
    color = ofColor(r,g,b);
    
    gui = new ofxUICanvas;
    gui->addLabel("Particle Slider");
    gui->addSpacer();
    gui->addSlider("radius", 0, 100, 50);
    
    gui->loadSettings("myGuiSettings.xml");
    ofAddListener(gui->newGUIEvent, this, &testApp::onGuiEvent);
    
}

//--------------------------------------------------------------
void testApp::onGuiEvent ( ofxUIEventArgs &e ){
    
    if( e.getName() == "radius" ){
        ofxUISlider *radiusSlider = (ofxUISlider*)e.widget;
        
        radius = radiusSlider->getScaledValue();
    }else if( e.getName() == "myButton"){
        ofxUIButton *b = (ofxUIButton*) e.widget;
        b->getValue();
    }
    
}

//--------------------------------------------------------------

void testApp::addParticle(float x, float y){
    
    float xPos = x + ofRandom(10) - 5;
    float yPos = y + ofRandom(10) - 5;
    
    ofVec2f velOffset( ofRandom(-1,1), ofRandom(-1,1) );
    velOffset *= ofRandom(1,5);
    ofVec2f newVel = mouseVel * 0.3 + velOffset;
    
    myParticle.push_back( Particle( ofVec2f( xPos, yPos ), newVel ) );
    
}

//--------------------------------------------------------------
void testApp::update(){
    
    if( bMouseIsPressed ){
        for( int i=0; i<75; i++){
            addParticle( lastMousePos.x, lastMousePos.y );
        }
    }
    
    for( vector<Particle>::iterator it=myParticle.begin(); it!=myParticle.end();){
        
        if( it->bDeadParticle ){
            it = myParticle.erase( it );
        }else{
            it->update( lastMousePos );
            it++;
        }
    }
    

}

//--------------------------------------------------------------
void testApp::draw(){
    
    for( vector<Particle>::iterator it=myParticle.begin(); it!=myParticle.end(); it++ ){
        it->draw(255,50,150);
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
    
    mouseVel = ofVec2f(x,y) - lastMousePos;
    lastMousePos.set(x, y);

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
    
     mouseMoved(x, y);

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    
     bMouseIsPressed = true;

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

    bMouseIsPressed = false;

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
