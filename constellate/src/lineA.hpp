//
//  lineA.hpp
//  amogh_dwivedi_final
//
//  Created by Amogh Dwivedi on 5/3/26.
//

#pragma once
#include "ofMain.h"

// line A is like ................

class lineA {
public:
	lineA();
	lineA(ofVec2f pointA, ofVec2f pointB);
	
	ofVec2f a;
	ofVec2f b;
	
	int subdivisions;
	
	virtual void update(ofVec2f pointA, ofVec2f pointB);
	virtual void draw();
	void alterSegments();


	vector<ofVec2f> segments;
};
