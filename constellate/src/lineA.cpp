//
//  lineA.cpp
//  amogh_dwivedi_final
//
//  Created by Amogh Dwivedi on 5/3/26.
//

#include "lineA.hpp"


lineA::lineA(){
	subdivisions = floor(ofRandom(30, 90));
	segments.resize(subdivisions + 1);
}


lineA::lineA(ofVec2f pointA, ofVec2f pointB){
	
	a = pointA;
	b = pointB;
	
	subdivisions = floor(ofRandom(30, 90));
	segments.resize(subdivisions + 1);
	
}

void lineA::update(ofVec2f pointA, ofVec2f pointB){
	
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

}

void lineA::draw(){
	
	if (ofRandom(0, 100) < 5){
		int index1 = floor(ofRandom(0, subdivisions + 1));
		int index2 = floor(ofRandom(0, subdivisions + 1));
		while(index1 == index2){
			index2 = floor(ofRandom(0, subdivisions + 1));
		}
		ofSetColor(55, 55, 55);
		ofDrawLine(segments[index1].x,segments[index1].y, segments[index2].x,segments[index2].y);
	}
	
	for (int i = 0; i < subdivisions + 1; i++){
		int black = ofRandom(0, 255);
		ofSetColor(black, black, black, ofRandom(0, 255));
		ofDrawCircle(segments[i].x, segments[i].y, ofRandom(0.01, 1.0));
		ofSetColor(255, 255, 255, 50);
		ofDrawCircle(segments[i].x + ofRandom(-5, 5), segments[i].y + ofRandom(-5, 5), ofRandom(0.01, 1.0));

	}
}
