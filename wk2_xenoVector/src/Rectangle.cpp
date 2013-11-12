//
//  Rectangle.cpp
//  multipleXeno
//
//  Created by TheAlkimist on 9/10/13.
//
//

#include "Rectangle.h"



Rectangle::Rectangle(){
	catchUpSpeed = 0.03f;
}

void Rectangle::draw() {
	ofFill();
	ofSetRectMode(OF_RECTMODE_CENTER); // center around the position
    ofSetColor(ofRandom(0,255),0,ofRandom(0,255));
    ofRect(pos.x, pos.y, 40, 40);
    
}


void Rectangle::xenoToPoint(float catchX, float catchY){
	pos.x = catchUpSpeed * catchX + (1-catchUpSpeed) * pos.x;
	pos.y = catchUpSpeed * catchY + (1-catchUpSpeed) * pos.y;
}
