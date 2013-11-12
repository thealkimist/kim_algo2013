#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    for( int i=0; i<5; i++ ){
        Rectangle myRect;
        rectList.push_back( myRect );
    }

}

//--------------------------------------------------------------
void testApp::update(){
    
    for( int i=0; i<rectList.size(); i++ ){
        
        if( i==0 ){
            rectList[i].xenoToPoint(mouseX, mouseY);
        }else{
            rectList[i].xenoToPoint(rectList[i-1].pos.x, rectList[i-1].pos.y);
        }
    }

}

//--------------------------------------------------------------
void testApp::draw(){
    
    for( int i=0; i<rectList.size(); i++ ){
        rectList[i].draw();
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
