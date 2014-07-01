// FADER 1 = Attraction
// FADER 2 = Repulsion
// FADER 3 = Size
// ROTARY 1 = Invert Tone
// ROTARY 2
// ROTARY 3 = Add more flow
// ROTARY 4 = Higher velocity
// ROTARY 5
// ROTARY 6


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
    loc1 = ofVec3f(ofGetWindowWidth()/3+100, ofGetWindowHeight()/3, -150);
    loc2 = ofVec3f(ofGetWindowWidth()-100, ofGetWindowHeight()/7, 150);
    loc3 = ofVec3f(ofGetWindowWidth()/2+700, ofGetWindowHeight()/2+250, -1000);
    loc4 = ofVec3f(ofGetWindowWidth()+300, ofGetWindowHeight()/2-450, -4000);
    loc5 = ofVec3f(300, ofGetWindowHeight()/2+150, -400);
    
    mySphere1.setup(loc1.x, loc1.y, loc1.z);
    mySphere1.sphere.setRadius(250);
    mySphere2.setup(loc2.x, loc2.y, loc2.z);
    mySphere2.sphere.setRadius(250);
    cone.setup(loc3.x, loc3.y, loc3.z);
    cone.cone.set(150,400);
    ico.setup(loc4.x, loc4.y, loc4.z);
    ico.icoSphere.setRadius(275);
    box.setup(loc5.x, loc5.y, loc5.z);
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
            shipUpdate();
            break;
        case 1:
            starFieldUpdate();
            break;
        case 2:
            
            break;
            
    }
    
    counter = counter + 0.0013f;
}
//--------------------------------------------------------------
void testApp::draw(){
    
    switch (projectState) {
        case 0:
            shipState();
            break;
        case 1:
            starFieldState();
            break;
        case 2:
           
            break;
    }
    
}

void testApp::shipUpdate(){
    
    for (int i = 0; i < particles.size(); i++){
        particles[i].resetForce();
        particles[i].addAttraction(ofGetWindowWidth()/2, ofGetWindowHeight()/2, fader1 * 20000, fader1 * 0.5);
        particles[i].addRepulsion(ofGetWindowWidth()/2, ofGetWindowHeight()/2, fader2 * 40, fader2 * 400);
        particles[i].addDamping();
        particles[i].update();
        
        particles[i].size = fader3 * 2;
        
    }
    
}

void testApp::shipState(){
    
    ofSetColor(255,220,50);
    ofCircle(ofGetWindowWidth()/2, ofGetWindowHeight()/2, 30);
    
    ofColor crazyColor = ofColor(particleR,255,255,255);
    
    for (int i = 0; i < particles.size(); i++){
        
        particles[i].draw(ofColor(255,150,50,200));
    }

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
    
    for( int i=0; i< rotary3 * 30; i++ ){
        addFlow();
    }
    
    float s1, s2, s3, s4, s5;
    s1 = ofMap(sin( ofGetElapsedTimef() / 40 ), -1, 1, 1.02, -1.02);
    s2 = ofMap(sin( ofGetElapsedTimef() / 30 ), -1, 1, 1.02, -1.02);
    s3 = ofMap(sin( ofGetElapsedTimef() / 10 ), -1, 1, -1.02, 1.02);
    s4 = ofMap(sin( ofGetElapsedTimef() / 20 ), -1, 1, -1.02, 1.02);
    s5 = ofMap(sin( ofGetElapsedTimef() / 20 ), -1, 1, -1.02, 1.02);
    
    mySphere1.update(s1);
    mySphere2.update(s2);
    cone.update(s3);
    ico.update(s4);
    box.update(s5);
    
    flocker.applyForces(40, 1.1, 1.75);
    flocker.update(loc1);
    
    vel1.set(0.0, 0.0, s1);
    vel2.set(0.0, 0.0, s2);
    vel3.set(0.0, 0.0, s3);
    vel4.set(0.0, 0.0, s4);
    vel5.set(0.0, 0.0, s5);
    loc1 += vel1;
    loc2 += vel2;
    loc3 += vel3;
    loc4 += vel4;
    loc5 += vel5;

    myRipples.update(mouseX, mouseY, 40, 40);
    
}

void testApp::starFieldState(){
    
    myRipples.draw();
    ofSetColor(255,200,50,210);
    
    float toneValue = rotary1;
    float toneMap = ofMap(toneValue, 0.0, 1.0, 0.0, 255.0);
    starInvert.draw(0,0);
    
    ofSetColor(170,90,255,toneMap);
    starImage.draw(0,0);

    float fr = ofMap(toneValue, 0, 1, 0, 255);
    float fg = ofMap(toneValue, 0, 1, 0, 50);
    float fb = ofMap(toneValue, 0, 1, 0, 150);
    
    for( vector<FlowField>::iterator it = flowList.begin(); it!=flowList.end(); it++){
        it->draw(fr,fb,fb);
    }
    
    ofPushMatrix();{
        ofRotateX(15);
        
        ofSetLineWidth(3);
        
        float s1r = ofMap(toneValue, 0, 1, 0, 255);
        float s1g = ofMap(toneValue, 0, 1, 0, 55);
        float s1b = ofMap(toneValue, 0, 1, 0, 155);
        mySphere1.draw(sin(ofGetElapsedTimef()*.35f)/4, cos(ofGetElapsedTimef()*.075f)/4); // (spinX,spinY)
        ofSetColor(s1r, s1g, s1b);
        mySphere1.sphere.setResolution(4);
        mySphere1.sphere.setScale(1.01f);
        mySphere1.sphere.drawWireframe();
        mySphere1.sphere.setScale(1.f);
        
        float s2r = ofMap(toneValue, 0, 1, 0, 55);
        float s2g = ofMap(toneValue, 0, 1, 0, 255);
        float s2b = ofMap(toneValue, 0, 1, 0, 190);
        mySphere2.draw(sin(ofGetElapsedTimef()*.1f)/4, cos(ofGetElapsedTimef()*.2f)/4);
        ofSetColor(s2r, s2g, s2b);
        mySphere2.sphere.setResolution(2);
        mySphere2.sphere.setScale(1.01f);
        mySphere2.sphere.drawWireframe();
        mySphere2.sphere.setScale(1.f);
        
        float i1r = ofMap(toneValue, 0, 1, 0, 155);
        float i1g = ofMap(toneValue, 0, 1, 0, 255);
        float i1b = ofMap(toneValue, 0, 1, 0, 150);
        ico.draw(sin(ofGetElapsedTimef()*.075f)/4, cos(ofGetElapsedTimef()*.3f)/4);
        ofSetColor(i1r, i1g, i1b);
        ico.icoSphere.setResolution(0);
        ico.icoSphere.setScale(1.01f);
        ico.icoSphere.drawWireframe();
        ico.icoSphere.setScale(1.f);
        
        float c1r = ofMap(toneValue, 0, 1, 0, 100);
        float c1g = ofMap(toneValue, 0, 1, 0, 235);
        float c1b = ofMap(toneValue, 0, 1, 0, 50);
        cone.draw(sin(ofGetElapsedTimef()*.075f)/4, cos(ofGetElapsedTimef()*.3f)/4);
        ofSetColor(c1r, c1g, c1g);
        cone.cone.setResolution(7,3,2);
        cone.cone.setScale(1.01f);
        cone.cone.drawWireframe();
        cone.cone.setScale(1.f);
        
        float b1r = ofMap(toneValue, 0, 1, 0, 55);
        float b1g = ofMap(toneValue, 0, 1, 0, 205);
        float b1b = ofMap(toneValue, 0, 1, 0, 255);
        box.draw(sin(ofGetElapsedTimef()*.075f)/4, cos(ofGetElapsedTimef()*.3f)/4);
        ofSetColor(b1r, b1g, b1b);
        box.box.setResolution(3);
        box.box.setScale(1.01f);
        box.box.drawWireframe();
        box.box.setScale(1.f);
        
        
        flocker.draw();
        
    }ofPopMatrix();
    
 
    
}

void testApp::addFlow(){
    FlowField f;
    
    ofVec2f rVel = ofVec2f( 0.0, rotary4 * 50.0 );
    f.setup( rVel );
    flowList.push_back( f );
}

//--------------------------------------------------------------

void testApp::checkOsc(){
    
    while (mReceiver.hasWaitingMessages() ) {
        ofxOscMessage m;
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
            
            rotary4 = m.getArgAsFloat(0);
            
        }
        if(addr == "/1/rotary5"){
            
            rotary5 = m.getArgAsFloat(0);
            
        }
        if(addr == "/1/rotary6"){
            
            rotary6 = m.getArgAsFloat(0);
            
        }

        if(addr == "/1/push1"){
            
            push1 = m.getArgAsFloat(0);
        }
        
        if(addr == "/1/push2"){
            
            push2 = m.getArgAsFloat(0);
        }
        if(addr == "/1/push3"){
            
            push3 = m.getArgAsFloat(0);
            
        }
        if(addr == "/1/push4"){
            
            push4 = m.getArgAsFloat(0);
            
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
    if(key == 'q'){
        fader1 = fader1 + 0.1;
        if (fader1 >= 1.0){
            fader1 = 1;
        }
        cout << fader1 << endl;
    }
    if(key == 'w'){
        fader1 = fader1 - 0.1;
        if (fader1 <= 0.0){
            fader1 = 0;
        }
        
        cout << fader1 << endl;
    }
    if(key == 'e'){
        fader2 = fader2 + 0.1;
        if(fader2 >= 1.0){
            fader2 = 1.0;
        }
    }
    if(key == 'r'){
        fader2 = fader2 - 0.1;
        if(fader2 <= 0.0){
            fader2 = 0.0;
        }
    }
    
    if(key == 't'){
        fader3 = fader3 + 0.1;
        if(fader3 >= 1){
            fader3 = 1;
        }
    }
    
    if(key == 'y'){
        fader3 = fader3 - 0.1;
        if (fader3 <= 0.1){
            fader3 = 0.1;
        }
    }

    
    if(key == 'a'){
        rotary1 = rotary1 + 1;
        if (rotary1 == 2){
            rotary1 = 1;
        }
    }
    if(key == 'z'){
        rotary1 = rotary1 - 1;
        if (rotary1 == -1){
            rotary1 = 0;
        }
    }
    if(key == 'd'){
        rotary3 = rotary3 + 0.1;
        if (rotary3 == 1.0){
            rotary3 = 1.0;
        }
    }
    if(key == 'c'){
        rotary3 = rotary3 - 0.1;
        if (rotary3 == 0){
            rotary3 = 0.1;
        }
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
