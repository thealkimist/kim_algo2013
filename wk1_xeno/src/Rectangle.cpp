//
//  Rectangle.cpp
//  xeno
//
//  Created by TheAlkimist on 9/10/13.
//
//

#include "Rectangle.h"

Rectangle::Rectangle() {
    ofRectMode( OF_RECTMODE_CENTER );
    catchUpSpeed = 0.03f;
}

void Rectangle::xenoToPoint(float catchX, float catchY){
	pos.x = catchUpSpeed * catchX + (1-catchUpSpeed) * pos.x;
	pos.y = catchUpSpeed * catchY + (1-catchUpSpeed) * pos.y;
}


void Rectangle::draw() {
    
    ofSetColor(255 * (pos.y / ofGetHeight() ), 0, 0 );
    
    ofRect( pos.x, pos.y, 20, 20 );
}