#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){
    myField.setup( ofGetWindowWidth(), ofGetWindowHeight(), 20 );
    
    ofBackground(0);
    

    
    ofxXmlSettings settings;
    if(settings.loadFile("positions.xml")){
        settings.pushTag("positions");
        //int numberOfSavedPoints = settings.getNumTags("positions");
        for(int y = 0; y < myField.flowList.size(); y++) {
            for (int x = 0; x < myField.flowList[y].size(); x++) {
                
                settings.pushTag("position", myField.flowList.size() * y + x);
                
                ofVec2f p;
                p.x = settings.getValue("X", 0.0);
                p.y = settings.getValue("Y", 0.0);
                
                
                myField.flowList[y][x] = p;
                settings.popTag();
            }
        }
        
        settings.popTag(); //pop position
    }
    else{
        ofLogError("Position file did not load!");
    }



}

void testApp::exit(){
    ofxXmlSettings positions;
    positions.addTag("positions");
    positions.pushTag("positions");
    
    for (int y = 0; y < myField.flowList.size(); y++){
        for (int x = 0; y < myField.flowList[y].size(); x++ ){
            
            positions.addTag("position");
            positions.pushTag("position", myField.flowList.size() * y + x);
            
            positions.addValue("X", myField.flowList[y][x].x);
            positions.addValue("Y", myField.flowList[y][x].y);
            positions.popTag();
        }
    }
    positions.popTag();
    positions.saveFile("positions.xml");
    
}

//--------------------------------------------------------------
void testApp::update(){
    //savePositions();
    
}

//--------------------------------------------------------------
void testApp::draw(){
    myField.draw();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    if ( key == '1' ){
        myField.reset();
    }else if( key == '2'){
        myField.setRandom();
    }else if( key == '3' ){
        myField.setPerlin();
    }else if( key == '4' ){
        myField.setSinLerp();
    }else if( key == '5' ){
        myField.setSinCos();
    }else if( key == '6' ){
        ofVec2f mouse;
        mouse.set(mouseX, mouseY);
        myField.setMouse(mouse);
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
