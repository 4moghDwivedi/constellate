//
//  phantomTriangle.cpp
//  amogh_dwivedi_final
//
//  Created by Amogh Dwivedi on 5/4/26.
//

#include "phantomTriangle.hpp"
#include "lineA.hpp"

phantomTriangle::phantomTriangle() :
phantomTriangle(ofRandom(100, 250), ofRandom(100, 250)) {

}

phantomTriangle::phantomTriangle(float x, float y) :  phantom(x, y){
	
	length = ofRandom(100, 250);

	points.resize(3);
	speeds.resize(3);
	angles.resize(3);
	triLines.resize(3);
	circleSizes.resize(3);
	phantomPoints.resize(3);
	
	angles[0] = ofDegToRad(ofRandom(0, 120));
	angles[1] = ofDegToRad(ofRandom(120, 240));
	angles[2] = ofDegToRad(ofRandom(240, 360));
	
	float lowSpeed = 0.01;
	float highSpeed = 0.05;
	
	for (int i = 0; i < 3; i++){
		speeds[i] = ofRandom(lowSpeed, highSpeed);
		points[i].x = centerPosition.x + (0.5 * length) * cos(angles[i]);
		points[i].y = centerPosition.y + (0.5 * length) * sin(angles[i]);
		circleSizes[i] = ofRandom(2, 5);
		phantomPoints[i] = phantom(centerPosition.x, centerPosition.y);
	}
	
	
	for (int i = 0; i < 2; i++){
		triLines[i] = lineA(points[i], points[i+1]);
	}
	triLines[2] = lineA(points[2], points[0]);
	
	rhythm = 15 * floor(ofRandom(1, 9));
	
}

void phantomTriangle::drawLines(){
	
	for (int i = 0; i < 3; i++){
		int randomColor = ofRandom(50, 255);
		ofSetColor(randomColor, randomColor, randomColor);
		triLines[i].draw();
	}

}


void phantomTriangle::update(){
	
	centerPosition.x += direction.x;
	centerPosition.y += direction.y;
	
	updateAngles();
	moveRect();
	keepInBounds();
	
	if(ofGetFrameNum() % rhythm == 0)
	{
		connectCorners = !connectCorners;
	}
	
	for (int i = 0; i < 2; i++){
		triLines[i].update(points[i], points[i+1]);
	}
	triLines[2].update(points[2], points[0]);
	
	for (int i = 0; i < 3; i++){
		phantomPoints[i].centerPosition.x = points[i].x;
		phantomPoints[i].centerPosition.y = points[i].y;
		
		phantomPoints[i].animate();
	}

	
}

void phantomTriangle::draw(){
	
	ofSetColor(centerR, centerG, centerB);
	for (int i = 0; i < 3; i++){
//		ofDrawCircle(points[i].x, points[i].y, circleSizes[i]);
		phantomPoints[i].draw();
	}
	
	if (connectCorners == true){
		drawLines();
	}
//
	
}

void phantomTriangle::updateAngles(){
	
	for (int i = 0; i < 3; i++){
		angles[i] += speeds[i];
		speeds[i] += ofRandom(-0.01, 0.01);
		speeds[i] = ofClamp(speeds[i], -0.05, 0.05);
	}

}

void phantomTriangle::moveRect(){
	
	for (int i = 0; i < 3; i++){
		points[i].x = centerPosition.x + (0.5 * length) * cos(angles[i]);
		points[i].y = centerPosition.y + (0.5 * length) * sin(angles[i]);
	}
}

void phantomTriangle::keepInBounds(){
	
	if (centerPosition.x - length < 0) 	direction.x = 1;
	if (centerPosition.x + length > ofGetWidth()) 	direction.x = -1;
	if (centerPosition.y - length < 0)		direction.y = 1;
	if (centerPosition.y + length > ofGetHeight())	direction.y = -1;
}
