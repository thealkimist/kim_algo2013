//
//  FlowField.cpp
//  VectorField
//
//  Code based on Charlie Whitney
//
//

#include "FlowField.h"

FlowField::FlowField() {
    ofPoint pos;
    
}

void FlowField::setup( int width, int height, int res ) {
    fieldWidth = width;
    fieldHeight = height;
    resolution = res;
    
    int cols = fieldWidth / resolution;
    int rows = fieldHeight / resolution;
    
    // Make a big list of forces.  We will store them in a 2 dimensional vector.
    for( int y=0; y<rows; y++){
        VectorList myList;
        flowList.push_back( myList );
        
        for( int x=0; x<rows; x++){
            ofVec2f dir(1,0);                   // direction of the arrows
            flowList[y].push_back( dir );
        }
    }
}

// Set all the forces in the field to random values

void FlowField::reset() {
    for( int y=0; y<flowList.size(); y++){
        for( int x=0; x<flowList[y].size(); x++){
            flowList[y][x].set(1,0);
        }
    }
}

void FlowField::setRandom() {
    for( int y=0; y<flowList.size(); y++){
        for( int x=0; x<flowList[y].size(); x++){
            flowList[y][x].set( ofRandom(-1,1), ofRandom(-1,1) );
        }
    }
}

// Set all the forces in the field based on perlin noise
void FlowField::setPerlin() {
    for( int y=0; y<flowList.size(); y++){
        for( int x=0; x<flowList[y].size(); x++){
            float noise = ofMap( ofNoise(x*0.05, y*0.05), 0, 1, 0, TWO_PI);
            flowList[y][x].set( ofVec2f( cos(noise), sin(noise) ) );
            
        }
    }
}

void FlowField::setSinLerp(){
    for ( int y =0; y < flowList.size(); y++ ){
        for (int x = 0; x < flowList[y].size(); x++ ){
            flowList[y][x].set( sin(y), ofLerp(-1, 1, 0.6) );
        }
    }
}

void FlowField::setSinCos(){
    for ( int y =0; y < flowList.size(); y++ ){
        for (int x = 0; x < flowList[y].size(); x++ ){
            flowList[y][x].set( sin(y*2.6), cos(x*2.6) );
        }
    }
}

void FlowField::setMouse(ofVec2f mousePos){
    for ( int y =0; y < flowList.size(); y++ ){
        for (int x = 0; x < flowList[y].size(); x++ ){
            ofVec2f pos;                                // declare vector for new object
            pos.set(x*resolution, y*resolution);        // set the object's position to resolution
            ofVec2f followMouse = mousePos - pos;       // declare new vector that follows mouse position
            flowList[y][x].set(followMouse);
        }
    }
}


void FlowField::draw() {
    for( int y=0; y<flowList.size(); y++){
        for( int x=0; x<flowList[y].size(); x++){
            ofVec2f np( x*resolution, y*resolution );
            drawVectorAt( flowList[y][x], np );
        }
    }
}

void FlowField::drawVectorAt( const ofVec2f &vec, const ofVec2f &pos ) {
    ofVec2f np = pos - (vec.normalized()) * 5.0;
    drawVector( np, np + vec.normalized() * 10.0, 5, 3 );
}

/**
 * This is a complicated one!  It's a translation of the one right out of the Cinder source, no need to understand it,
 * but it's an interesting one to look at anyway!
 * https://github.com/cinder/Cinder/blob/master/src/cinder/gl/gl.cpp line 915 if you're interested
 */
void FlowField::drawVector( const ofVec3f &start, const ofVec3f &end, float headLength, float headRadius ) {
	const int NUM_SEGMENTS = 32;
	float lineVerts[3*2];
	ofVec3f coneVerts[NUM_SEGMENTS+2];
	glEnableClientState( GL_VERTEX_ARRAY );
	glVertexPointer( 3, GL_FLOAT, 0, lineVerts );
	lineVerts[0] = start.x; lineVerts[1] = start.y; lineVerts[2] = start.z;
	lineVerts[3] = end.x; lineVerts[4] = end.y; lineVerts[5] = end.z;
	glDrawArrays( GL_LINES, 0, 2 );
	
	// Draw the cone
	ofVec3f axis = ( end - start ).normalized();
    ofVec3f temp = ( axis.dot( ofVec3f(0,1,0) ) > 0.999f ) ? axis.crossed( ofVec3f(1,0,0) ) : axis.crossed( ofVec3f(0,1,0) );
	ofVec3f left = ofVec3f(axis.crossed( temp )).normalized();
	ofVec3f up = axis.crossed( left ).normalized();
    
	glVertexPointer( 3, GL_FLOAT, 0, &coneVerts[0].x );
	coneVerts[0] = ofVec3f( end + axis * headLength );
	for( int s = 0; s <= NUM_SEGMENTS; ++s ) {
		float t = (float)s / (float)NUM_SEGMENTS;
		coneVerts[s+1] = ofVec3f( end + left * headRadius * cos( t * 2.0f * 3.14159f )
                                 + up * headRadius * sin( t * 2.0f * 3.14159f ) );
	}
	glDrawArrays( GL_TRIANGLE_FAN, 0, NUM_SEGMENTS+2 );
    
	// draw the cap
	glVertexPointer( 3, GL_FLOAT, 0, &coneVerts[0].x );
	coneVerts[0] = end;
	for( int s = 0; s <= NUM_SEGMENTS; ++s ) {
		float t = s / (float)NUM_SEGMENTS;
		coneVerts[s+1] = ofVec3f( end - left * headRadius * (float)cos( t * 2 * 3.14159f )
                                 + up * headRadius * (float)sin( t * 2 * 3.14159f ) );
	}
	glDrawArrays( GL_TRIANGLE_FAN, 0, NUM_SEGMENTS+2 );
    
	glDisableClientState( GL_VERTEX_ARRAY );
}