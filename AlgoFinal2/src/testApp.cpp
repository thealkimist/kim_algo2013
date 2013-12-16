#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    //OSC Receiver Port
    mReceiver.setup( 12345 );
    
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    ofBackground(0);
    ofEnableAlphaBlending();
    ofEnableSmoothing();
    
    projectState = 0;
    
    particleCount = 2000;
    
    w = ofGetWindowWidth();
    h = ofGetWindowHeight();
    
    for (int i = 0; i < particleCount; i++){
        Particle myParticle;
        myParticle.setInitCondition(ofRandom(ofGetWindowWidth()), ofRandom(0,ofGetWindowHeight()+20), 0, 0);
        myParticle.damping = ofRandom(0.01,0.05);
        particles.push_back(myParticle);
    }

    particleR = 255;
    
    // Ripples
    myRipples.setup();
    
    // Sphere Setup
    mySphere1.setup(ofGetWindowWidth()/3+100, ofGetWindowHeight()/3, -150);
    mySphere1.sphere.setRadius(250);
    mySphere2.setup(ofGetWindowWidth()-100, ofGetWindowHeight()/7, 150);
    mySphere2.sphere.setRadius(250);
    cone.setup(ofGetWindowWidth()/2+700, ofGetWindowHeight()/2+250, -1000);
    cone.cone.set(150,400);
    ico.setup(ofGetWindowWidth()+300, ofGetWindowHeight()/2-450, -4000);
    ico.icoSphere.setRadius(275);
    box.setup(300, ofGetWindowHeight()/2+150, -400);
    box.box.set(200);
    bWireframe = false;
    
    // Load Images
    starImage.loadImage("stars1.jpg");
    starInvert.loadImage("starsinvert.jpg");
    starAlpha = 255;
    
    flocker.addParticle( 800 );
    
}

//--------------------------------------------------------------
void testApp::update(){
    checkOsc();
    
    switch (projectState) {
        case 0:
            // FADER 1 = Attraction
            // FADER 2 = Repulsion
            // FADER 3 = Size
            shipUpdate();
            break;
        case 1:
            transitionUpdate();
            break;
        case 2:
            // FADER 1 = Invert Tone
            starFieldUpdate();
            break;
            
    }
    
    counter = counter + 0.0013f;
}
//--------------------------------------------------------------
void testApp::draw(){
    
    switch (projectState) {
        case 0:
            // FADER 1 = Attraction
            // FADER 2 = Repulsion
            // FADER 3 = Size
            shipState();
            break;
        case 1:
            transitionState();
            break;
        case 2:
            // FADER 1 = Invert Tone
            starFieldState();
            break;
    }
    
}

void testApp::shipState(){
    
    ofSetColor(255,220,50);
    ofCircle(ofGetWindowWidth()/2, ofGetWindowHeight()/2, 30);
    
    ofColor crazyColor = ofColor(particleR,255,255,255);
    
    for (int i = 0; i < particles.size(); i++){
        
        particles[i].draw(fader1, ofColor(255,150,50,200));
    }

}

void testApp::shipUpdate(){
    
    for (int i = 0; i < particles.size(); i++){
        particles[i].resetForce();
        particles[i].addAttraction(ofGetWindowWidth()/2, ofGetWindowHeight()/2, fader1 * 20000, fader1 * 0.5);
        particles[i].addRepulsion(ofGetWindowWidth()/2, ofGetWindowHeight()/2, fader2 * 40, fader2 * 40);
        particles[i].addDamping();
        particles[i].update();
        
        particles[i].size = fader3 * 5;
        
//        if (i == 0){
//            particles[i].trail(ofGetWindowWidth()/2, ofGetWindowHeight()/2);
//        }else{
//            particles[i].trail(particles[i-1].pos.x, particles[i-1].pos.y);
//        }
        
    }

}

void testApp::transitionState(){
    
}

void testApp::transitionUpdate(){
    
}

void testApp::starFieldState(){
    
    myRipples.draw();
    ofSetColor(255,200,50,210);
    
    int toneValue = fader1;
    int toneMap = ofMap(toneValue, 0, 1, 0, 255);
    starInvert.draw(0,0);
    ofSetColor(170,90,255,toneMap);
    starImage.draw(0,0);

    int fr = ofMap(toneValue, 0, 1, 0, 255);
    int fg = ofMap(toneValue, 0, 1, 0, 50);
    int fb = ofMap(toneValue, 0, 1, 0, 150);
    
    for( vector<FlowField>::iterator it = flowList.begin(); it!=flowList.end(); it++){
        it->draw(fr,fb,fb);
    }
    
    ofPushMatrix();{
        ofRotateX(15);
        
        ofSetLineWidth(3);
        
        int s1r = ofMap(toneValue, 0, 1, 0, 255);
        int s1g = ofMap(toneValue, 0, 1, 0, 55);
        int s1b = ofMap(toneValue, 0, 1, 0, 155);
        mySphere1.draw(sin(ofGetElapsedTimef()*.35f)/4, cos(ofGetElapsedTimef()*.075f)/4); // (spinX,spinY)
        ofSetColor(s1r, s1g, s1b);
        mySphere1.sphere.setResolution(4);
        mySphere1.sphere.setScale(1.01f);
        mySphere1.sphere.drawWireframe();
        mySphere1.sphere.setScale(1.f);
        
        int s2r = ofMap(toneValue, 0, 1, 0, 55);
        int s2g = ofMap(toneValue, 0, 1, 0, 255);
        int s2b = ofMap(toneValue, 0, 1, 0, 190);
        mySphere2.draw(sin(ofGetElapsedTimef()*.1f)/4, cos(ofGetElapsedTimef()*.2f)/4);
        ofSetColor(s2r, s2g, s2b);
        mySphere2.sphere.setResolution(2);
        mySphere2.sphere.setScale(1.01f);
        mySphere2.sphere.drawWireframe();
        mySphere2.sphere.setScale(1.f);
        
        int i1r = ofMap(toneValue, 0, 1, 0, 155);
        int i1g = ofMap(toneValue, 0, 1, 0, 255);
        int i1b = ofMap(toneValue, 0, 1, 0, 150);
        ico.draw(sin(ofGetElapsedTimef()*.075f)/4, cos(ofGetElapsedTimef()*.3f)/4);
        ofSetColor(i1r, i1g, i1b);
        ico.icoSphere.setResolution(0);
        ico.icoSphere.setScale(1.01f);
        ico.icoSphere.drawWireframe();
        ico.icoSphere.setScale(1.f);
        
        int c1r = ofMap(toneValue, 0, 1, 0, 100);
        int c1g = ofMap(toneValue, 0, 1, 0, 235);
        int c1b = ofMap(toneValue, 0, 1, 0, 50);
        cone.draw(sin(ofGetElapsedTimef()*.075f)/4, cos(ofGetElapsedTimef()*.3f)/4);
        ofSetColor(c1r, c1g, c1g);
        cone.cone.setResolution(7,3,2);
        cone.cone.setScale(1.01f);
        cone.cone.drawWireframe();
        cone.cone.setScale(1.f);
        
        int b1r = ofMap(toneValue, 0, 1, 0, 55);
        int b1g = ofMap(toneValue, 0, 1, 0, 205);
        int b1b = ofMap(toneValue, 0, 1, 0, 255);
        box.draw(sin(ofGetElapsedTimef()*.075f)/4, cos(ofGetElapsedTimef()*.3f)/4);
        ofSetColor(b1r, b1g, b1b);
        box.box.setResolution(3);
        box.box.setScale(1.01f);
        box.box.drawWireframe();
        box.box.setScale(1.f);
        
        
        flocker.draw();
        
    }ofPopMatrix();
    
 
    
}

void testApp::starFieldUpdate(){
    
    for( vector<FlowField>::iterator it=flowList.begin(); it!=flowList.end(); ){
        it->update();
        
        if( it->bIsDead ){
            it = flowList.erase(it);   // When we erase one, it returns the next particle automatically.  It's done the "it++" for us!
            //ofLog( OF_LOG_NOTICE, "size is " + ofToString(flowList.size()) );
        }else {
            it++;
        }
    }
    
    for( int i=0; i< rotary2 * 40; i++ ){
        addFlow();
    }
    
    float s1, s2, s3, s4, s5, s6;
    s1 = ofMap(sin( ofGetElapsedTimef() / 40 ), -1, 1, 1.02, -1.02);
    s2 = ofMap(sin( ofGetElapsedTimef() / 30 ), -1, 1, 1.02, -1.02);
    s3 = ofMap(sin( ofGetElapsedTimef() / 10 ), -1, 1, -1.02, 1.02);
    s4 = ofMap(sin( ofGetElapsedTimef() / 20 ), -1, 1, -1.02, 1.02);
    s5 = ofMap(sin( ofGetElapsedTimef() / 20 ), -1, 1, -1.02, 1.02);
    s6 = ofMap(sin( ofGetElapsedTimef() / 20 ), -1, 1, -1.02, 1.02);
    
    mySphere1.update(s1);
    mySphere2.update(s2);
    cone.update(s4);
    ico.update(s5);
    box.update(s6);
    
    myRipples.update();
    
    flocker.applyForces(80, 0.4, 0.75);
    flocker.update(ofVec3f(ofGetWindowWidth()/3+100, ofGetWindowHeight()/3, -150));

   
    
}

void testApp::addFlow(){
    FlowField f;
    
    ofVec2f rVel = ofVec2f( 0.0, rotary1 * 50.0 );
    f.setup( rVel );
    flowList.push_back( f );
}

//--------------------------------------------------------------

void testApp::checkOsc(){
    
    while (mReceiver.hasWaitingMessages() ) {
        ofxOscMessage  m;
        mReceiver.getNextMessage(&m);
        
        string addr = m.getAddress();
        
        //Faders
        if(addr == "/1/fader1"){
            fader1 = m.getArgAsFloat(0);
            
        }
        if(addr == "/1/fader2"){
            
            fader2 = m.getArgAsFloat(0);
        
        }
        if(addr == "/1/fader3"){
            
            fader3 = m.getArgAsFloat(0);
        
        }
        
        //Rotary Knobs
        if(addr == "/1/rotary1"){
            
            rotary1 = m.getArgAsFloat(0);
            
        }
        if(addr == "/1/rotary2"){
            
            rotary2 = m.getArgAsFloat(0);
            
        }
        if(addr == "/1/rotary3"){
            
            rotary3 = m.getArgAsFloat(0);
            
        }
        if(addr == "/1/rotary4"){
            
            rotary1 = m.getArgAsFloat(0);
            
        }
        if(addr == "/1/rotary5"){
            
            rotary2 = m.getArgAsFloat(0);
            
        }
        if(addr == "/1/rotary6"){
            
            rotary3 = m.getArgAsFloat(0);
            
        }

        if(addr == "/1/push1"){
            
            push1 = m.getArgAsFloat(0);
//            if (push1 == 127) {
//                push = true;
//                // SPLODE
//                if( push ==true){
//                    for (int i = 0; i < particles.size(); i++){
//                        
//                        
//                        particles[i].resetForce();
//                        particles[i].addRepulsion(ofGetWindowWidth()/2, ofGetWindowHeight()/2, 50, 65);
//                        particles[i].addDamping();
//                        particles[i].update();
//                    }
//                }
//
//            }else{
//            push = false;
//            }
        }
        
        if(addr == "/1/push2"){
            
        }
        if(addr == "/1/push3"){
            
        }
        if(addr == "/1/push4"){
            
        }
        
        //Button "Push"
        if(addr == "/3/xyz"){
            float accX = m.getArgAsFloat(0);
            float accY = m.getArgAsFloat(1);
            float accZ = m.getArgAsFloat(2);
            
            cout << accX << endl;
            
        }

    }
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    if (key == '1') {
        //particleR = 0;
        projectState = 0;
    }
    if(key == '2'){
        projectState = 1;
    }
    if(key == '3'){
        projectState = 2;
    }
    if(key == '4'){
        
    }
    if(key == '5'){
        
    }
    if(key == '6'){
        
    }
    if(key == '7'){
        
    }
    if(key == '8'){
        
    }
    if(key == '9'){
        
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
//    for (int i = 0; i < particles.size(); i++){
//        particles[i].resetForce();
//        particles[i].addRepulsion(x, y, 50, 80);
//        particles[i].addDamping();
//        particles[i].update();
//    }

    
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
