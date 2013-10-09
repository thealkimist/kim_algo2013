#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    ofBackground(230,190,50);
    ofEnableAlphaBlending();
    
    for (int i = 0; i < 25000; i++){
        Particle myParticle;
        myParticle.setInitCondition(ofRandom(0,1000), ofRandom(0,1000), 0, 0);
        myParticle.damping = ofRandom(0.01,0.05);
        particles.push_back(myParticle);
        
        ofVec2f temp_points;
        temp_points.x = particles[i].pos.x;
        temp_points.y = particles[i].pos.y;
        particles.push_back(temp_points);

        
        //        distanceX = particles[i].pos.x - mouseX;
        //        distanceY = particles[i].pos.y - mouseY;
        //
        //        trans = ofMap(distanceX, 0, 5, 2, 20);
        //        particles[i].size = trans;
    }
    
}

//--------------------------------------------------------------
void testApp::update(){
    
    ofPoint points;
    
    for (int i = 0; i < particles.size(); i++){
        particles[i].resetForce();
        particles[i].addAttraction(mouseX, mouseY, 1000, 0.05);
        particles[i].addRepulsion(mouseX, mouseY, 30, 35);
        particles[i].addDamping();
        particles[i].update();
        
        if (particles.size() > 50){
            particles.erase(particles.begin());
        }
    }
    
 
    
    
    //    for (vector<Particle>::iterator it = particles.begin(); it != particles.end(); it++){
    //        it -> resetForce();
    //        it -> addAttraction(mouseX, mouseY, 1000, 0.02);
    //        it -> addRepulsion(mouseX, mouseY, 40, 20);
    //        it -> addDamping();
    //        it -> update();
    //
    //        // iterators look so simple and elegant
    //    }
    
    
}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofBeginShape();
    for (int i = 0; i < particles.size(); i++){
        ofNoFill();
        ofSetColor(0, 0, 0);
        ofVertex(particles[i].pos.x, particles[i].pos.y);
    }
    ofEndShape();
    
    for (int i = 0; i < particles.size(); i++){
        
        particles[i].draw();

    }
    
    //    for (vector<Particle>::iterator it = particles.begin(); it != particles.end(); it++){
    //        it -> draw(250,50,150);
    //    }
    
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
