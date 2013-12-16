//
//  Sphere.cpp
//  AlgoFinal3
//
//  Created by TheAlkimist on 12/10/13.
//
//

#include "Sphere.h"

Sphere::Sphere(){
    
}

void Sphere::setup(float posX, float posY, float posZ){
    pos.set(posX, posY, posZ);
    
}

void Sphere::update(float movement){
    vel.set(0.0, 0.0, movement);
    pos += vel;
    
}

void Sphere::draw(float spinX, float spinY){
    
    ofSetColor(0, 0, 0, 0);
    sphere.setPosition(pos);
    sphere.rotate(spinX, 1.0, 0.0, 0.0);
    sphere.rotate(spinY, 0, 1.0, 0.0);
    sphere.draw();
    
    ofSetColor(0, 0, 0, 0);
    cylinder.setPosition(pos);
    cylinder.rotate(spinX, 1.0, 0.0, 0.0);
    cylinder.rotate(spinY, 0, 1.0, 0.0);
    cylinder.draw();
    
    ofSetColor(0, 0, 0, 0);
    cone.setPosition(pos);
    cone.rotate(spinX, 1.0, 0.0, 0.0);
    cone.rotate(spinY, 0, 1.0, 0.0);
    cone.draw();
    
    ofSetColor(0, 0, 0, 0);
    icoSphere.setPosition(pos);
    icoSphere.rotate(spinX, 1.0, 0.0, 0.0);
    icoSphere.rotate(spinY, 0, 1.0, 0.0);
    icoSphere.draw();
    
    ofSetColor(0, 0, 0, 0);
    box.setPosition(pos);
    box.rotate(spinX, 1.0, 0.0, 0.0);
    box.rotate(spinY, 0, 1.0, 0.0);
    box.draw();
    
}