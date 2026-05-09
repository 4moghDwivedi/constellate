//
//  phantom.cpp
//  amogh_dwivedi_final
//
//  Created by Amogh Dwivedi on 5/3/26.
//

#include "phantom.hpp"

phantom::phantom()
: phantom(ofRandom(0, ofGetWidth()), ofRandom(0, ofGetHeight())){

}

phantom::phantom(float x, float y){
	centerPosition = ofVec2f(x, y);
	direction = ofVec2f(ofRandom(-1, 1), ofRandom(-1, 1));
	
	connectCorners = false;
	
	while (direction.x == 0){
		direction.x = ofRandom(-1, 1);
	}
	while (direction.y == 0){
		direction.y = ofRandom(-1, 1);
	}
	
	centerR = ofRandom(0, 255);
	centerG = ofRandom(0, 255);
	centerB = ofRandom(0, 255);
	
	numLines = ofRandom(20, 40);
	
	angles.resize(numLines);
	lengths.resize(numLines);
	alpha.resize(numLines);
	
	for (int i = 0; i < numLines; i++){
		angles[i] = ofDegToRad(ofRandom(0, 360));
		lengths[i] = ofRandom(0.1, 20);
		alpha[i] = ofRandom(0, 155);
		
	}
}


void phantom::update(){
	
	centerPosition.x += direction.x;
	centerPosition.y += direction.y;
	
	keepInBounds();
	
	if(ofGetFrameNum() % 120 == 0)
	{
		connectCorners = !connectCorners;
	}
	
	animate();

}

void phantom::animate(){
	
	for (int i = 0; i < numLines; i++){
		angles[i] += ofRandom(0.01, 0.3);
		lengths[i] += ofRandom(-0.1, 0);
		lengths[i] = ofClamp(lengths[i], 0.05, 20);

		alpha[i] += ofRandom(-30, 30);
		
		alpha[i] = ofClamp(alpha[i], 0, 155);
	}
}

void phantom::keepInBounds(){
	if (centerPosition.x - 5 < 0) 	direction.x *= -1;
	if (centerPosition.x + 5 > ofGetWidth()) 	direction.x *= -1;
	if (centerPosition.y - 5 < 0)	direction.y *= -1;
	if (centerPosition.y + 5 > ofGetHeight())	direction.y = -1;
}


void phantom::draw(){
	
	for (int i = 0; i < numLines; i++){
		ofSetColor(centerR, centerG, centerB, alpha[i]);
		ofDrawLine(centerPosition.x,
				   centerPosition.y,
				   centerPosition.x + lengths[i] * cos(angles[i]),
				   centerPosition.y + lengths[i] * sin(angles[i]));
		
		ofSetColor(centerR, centerG, centerB, alpha[i] * 0.5);
		ofDrawLine(centerPosition.x + ofRandom(-5, 5),
				   centerPosition.y + ofRandom(-5, 5),
				   centerPosition.x + lengths[i] * cos(angles[i]) + ofRandom(-5, 5),
				   centerPosition.y + lengths[i] * sin(angles[i]) + ofRandom(-5, 5));
		
		ofSetColor(centerR, centerG, centerB, alpha[i] * 0.1);
		ofDrawLine(centerPosition.x + ofRandom(-15, 15),
				   centerPosition.y + ofRandom(-15, 15),
				   centerPosition.x + lengths[i] * cos(angles[i]) + ofRandom(-15, 15),
				   centerPosition.y + lengths[i] * sin(angles[i]) + ofRandom(-15, 15));
		
	}
	
}
