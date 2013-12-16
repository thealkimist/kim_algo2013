//
//  FlockController.cpp
//  Flocking
//
//  Created by Charlie Whitney on 10/22/13.
//
//

#include "FlockController.h"

FlockController::FlockController(){
    
}

void FlockController::addParticle(int numParticles) {
    for( int i=0; i<numParticles; i++){
        
        float phi = ofRandom( 0, TWO_PI );
		float costheta = ofRandom( -1.0f, 1.0f );
		
		float rho = sqrt( 1.0f - costheta * costheta );
		float x = rho * cos( phi );
		float y = rho * sin( phi );
		float z = costheta;
		
        ofVec3f randVec(x, y, z);
        
		ofVec3f pos = randVec * ofRandom( 100.0f, 600.0f );
		ofVec3f vel = -randVec;
        
        Flock b;
        b.pos = pos;
        b.vel = vel;
        
        flockList.push_back( b );
    }
}

void FlockController::applyForces( float zoneRadius, float separateThresh, float alignThresh ){
    
    float zoneRadiusSq = zoneRadius * zoneRadius;
    
    for( vector<Flock>::iterator b1=flockList.begin(); b1!= flockList.end(); ++b1){
        
        vector<Flock>::iterator b2 = b1+1;
        
        for( b2; b2!= flockList.end(); ++b2){
            
            
            ofVec3f dir = b1->pos - b2->pos;
            float lenSq = dir.lengthSquared();
            
            // do some flocking
            if( lenSq < zoneRadiusSq ){
                float pct = lenSq / zoneRadiusSq;
                if( pct == 0){
                    pct = 0.00000001;
                }
                
                // separate!
                if( pct < separateThresh ){
                    float adjustedPct = 1.0 - ofMap(pct, 0.0, separateThresh, 0.0, 1.0 );
                    
                    ofVec3f F = dir.normalized() * adjustedPct * 0.01;
                    
                    b1->applyForce( F );
                    b2->applyForce( -F );
                }
                
                // align!
                else if( pct < alignThresh ){
                    
                }
                
                // attract!
                else{
                    
                }
                
                
            }
        }
    }
    
}

void FlockController::update(ofVec3f center){
    for( int i=0; i<flockList.size(); i++ ){
        flockList[i].pullToCenter( center );
        flockList[i].update();
    }
}

void FlockController::draw(){
    for( int i=0; i<flockList.size(); i++ ){
        flockList[i].draw();
    }
}










