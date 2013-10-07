#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    ofBackground(200,210,230);
    ofEnableAlphaBlending();
    
    for (int i = 0; i < 20000; i++){
        Particle myParticle;
        myParticle.setInitCondition(ofRandom(0,1000), ofRandom(0,1000), 0, 0);
        myParticle.damping = ofRandom(0.01,0.05);
        particles.push_back(myParticle);
        
//        distanceX = particles[i].pos.x - mouseX;
//        distanceY = particles[i].pos.y - mouseY;
//        
//        trans = ofMap(distanceX, 0, 5, 2, 20);
//        particles[i].size = trans;
    }
    
}

//--------------------------------------------------------------
void testApp::update(){
    
    for (int i = 0; i < particles.size(); i++){
        particles[i].resetForce();
        particles[i].addAttraction(mouseX, mouseY, 1000, 0.05);
        particles[i].addRepulsion(mouseX, mouseY, 30, 35);
        particles[i].addDamping();
        particles[i].update();
        
        if (i == i+3){
            particles[i].trail(mouseX, mouseY);
        }else{
            particles[i].trail(particles[i-1].pos.x, particles[i-1].pos.y);
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
