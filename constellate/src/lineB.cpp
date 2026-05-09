//
//  lineB.cpp
//  amogh_dwivedi_final
//
//  Created by Amogh Dwivedi on 5/3/26.
//

#include "lineB.hpp"

lineB::lineB() : lineA(){
	
	lineAlter.resize(subdivisions + 1);
	
	lineWidths.resize(subdivisions);
	for (int i = 0; i < subdivisions; i++){
		lineWidths[i] = ofRandom(5, 10);
	}
}

lineB::lineB(ofVec2f pointA, ofVec2f pointB) : lineA(){
	
	lineAlter.resize(subdivisions + 1);
	
	lineWidths.resize(subdivisions);
	for (int i = 0; i < subdivisions; i++){
		lineWidths[i] = ofRandom(0.01, 5);
	}
}


void lineB::update(ofVec2f pointA, ofVec2f pointB){
	
	a = pointA;
	b = pointB;
	
	ofVec2f distance = b - a;
	
	ofVec2f segment;
	segment.x = distance.x / subdivisions;
	segment.y = distance.y / subdivisions;
	
	for (int i = 0; i < subdivisions + 1; i++){
		segments[i].x = a.x + (i * segment.x);
		segments[i].y = a.y + (i * segment.y);
	}
	
//	updateLineWidth();
	
//	/*if (ofRandom(0, 100) < 3)*/ alterSegments();
	
}

void lineB::alterSegments(){
	for (int i = 1; i < subdivisions; i++){
		lineAlter[i].x += ofRandom(-5, 5);
		lineAlter[i].y += ofRandom(-5, 5);
				
		lineAlter[i].x = ofClamp(lineAlter[i].x, -25, 25);
		lineAlter[i].y = ofClamp(lineAlter[i].y, -25, 25);
	}
	
	
}


void lineB::draw(){
//	ofDrawLine(a.x, a.y, b.x, b.y);
	
	ofSetColor(255, 255, 0, ofRandom(200, 255));
	ofDrawCircle(segments[0].x, segments[0].y, ofRandom(3, 6));
	
	for(int i = 0; i < 5; i++){
		ofSetColor(0);
		ofSetLineWidth(ofRandom(1, 5));
		ofDrawLine(segments[0].x + ofRandom(-5, 0),
				   segments[0].y + ofRandom(-5, 0),
				   segments[0].x + ofRandom(0, 5),
				   segments[0].y + ofRandom(0, 5));
	}

	int dotted = floor(ofRandom(2, 12));
	
	if (ofGetFrameNum() % 120 == 0){
		dotted = floor(ofRandom(6, 12));
	}

	
	for (int i = 0; i < subdivisions - 1; i = i + dotted){
		ofSetLineWidth(lineWidths[i]);
		ofSetColor(ofRandom(0, 255), 0, 0, ofRandom(200, 255));
		ofDrawLine(segments[i].x, segments[i].y, segments[i+1].x + lineAlter[i].x, segments[i+1].y + lineAlter[i].y);
		ofSetColor(ofRandom(0, 255), 0, ofRandom(0, 255), ofRandom(50, 150));
		ofDrawLine(segments[i].x + ofRandom(-5, 5),
				   segments[i].y + ofRandom(-5, 5),
				   segments[i+1].x + lineAlter[i].x  + ofRandom(-5, 5),
				   segments[i+1].y + lineAlter[i].y + ofRandom(-5, 5));
	}
}
