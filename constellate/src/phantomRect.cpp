
//  phantomRect.cpp
//  amogh_dwivedi_final
//
//  Created by Amogh Dwivedi on 5/3/26.
//

#include "phantomRect.hpp"
#include "lineA.hpp"

phantomRect::phantomRect() :
phantomRect(ofRandom(5, 250), ofRandom(5, 250)) {

}

phantomRect::phantomRect(float x, float y) :  phantom(x, y){
	
	length = ofRandom(5, 250);
	height = ofRandom(5, 250);

	points.resize(4);
	speeds.resize(4);
	angles.resize(4);
	rectLines.resize(4);
	circleSizes.resize(4);
	phantomPoints.resize(4);
	
	angles[0] = ofDegToRad(ofRandom(0, 90));
	angles[1] = ofDegToRad(ofRandom(90, 180));
	angles[2] = ofDegToRad(ofRandom(180, 270));
	angles[3] = ofDegToRad(ofRandom(270, 360));
	
	float lowSpeed = 0.01;
	float highSpeed = 0.05;
	
	for (int i = 0; i < 4; i++){
		speeds[i] = ofRandom(lowSpeed, highSpeed);
		points[i].x = centerPosition.x + length * cos(angles[i]);
		points[i].y = centerPosition.y + length * sin(angles[i]);
		circleSizes[i] = ofRandom(0, 1);
		phantomPoints[i] = phantom(centerPosition.x, centerPosition.y);
	}
	
	for (int i = 0; i < 3; i++){
		rectLines[i] = lineA(points[i], points[i+1]);
	}
	rectLines[3] = lineA(points[3], points[0]);
	
	rhythm = 15 * floor(ofRandom(1, 9));

}

void phantomRect::drawLines(){
	
	for (int i = 0; i < 4; i++){
		int randomColor = ofRandom(50, 255);
		ofSetColor(randomColor, randomColor, randomColor);
		rectLines[i].draw();
	}

}


void phantomRect::update(){
	
	centerPosition.x += direction.x;
	centerPosition.y += direction.y;
	
	updateAngles();
	moveRect();
	keepInBounds();
	
	for (int i = 0; i < 3; i++){
		rectLines[i].update(points[i], points[i+1]);
	}
	rectLines[3].update(points[3], points[0]);
	
	for (int i = 0; i < 4; i++){
		phantomPoints[i].centerPosition.x = points[i].x;
		phantomPoints[i].centerPosition.y = points[i].y;
		
		phantomPoints[i].animate();
	}
	
	if(ofGetFrameNum() % rhythm == 0)
	{
		connectCorners = !connectCorners;
	}
	
}

void phantomRect::draw(){
	
	ofSetColor(centerR, centerG, centerB);
	for (int i = 0; i < 4; i++){
//		ofDrawCircle(points[i].x, points[i].y, circleSizes[i]);
		phantomPoints[i].draw();
	}
	
	if (connectCorners == true){
		drawLines();
	}
//
	
}

void phantomRect::updateAngles(){
	
	for (int i = 0; i < 4; i++){
		angles[i] += speeds[i];
		speeds[i] += ofRandom(-0.01, 0.01);
		speeds[i] = ofClamp(speeds[i], -0.05, 0.05);
	}
	
}

void phantomRect::moveRect(){
	
	for (int i = 0; i < 4; i++){
		points[i].x = centerPosition.x + length * cos(angles[i]);
		points[i].y = centerPosition.y + length * sin(angles[i]);
	}
}

void phantomRect::keepInBounds(){
	
	if (centerPosition.x - length < 0) 	direction.x = 1;
	if (centerPosition.x + length > ofGetWidth()) 	direction.x = -1;
	if (centerPosition.y - height < 0)	direction.y = 1;
	if (centerPosition.y + height > ofGetHeight())	direction.y = -1;
}
