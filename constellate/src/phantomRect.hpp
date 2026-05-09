//
//  phantomRect.hpp
//  amogh_dwivedi_final
//
//  Created by Amogh Dwivedi on 5/3/26.
//

#pragma once
#include "phantom.hpp"
#include "lineA.hpp"

class phantomRect: public phantom {
public:
	phantomRect();
	phantomRect(float x, float y);
	
	void update() override ;
	void draw() override;
	void keepInBounds() override;
	void moveRect();
	void drawLines();
	void updateAngles();
	
	ofVec2f p1;
	ofVec2f p2;
	ofVec2f p3;
	ofVec2f p4;
	
	
	vector<lineA> rectLines;
	vector<ofVec2f> points;
	vector<float> angles;
	vector<float> speeds;
	vector<float> circleSizes;
	
	vector<phantom> phantomPoints;
	
	float a1;
	float a2;
	float a3;
	float a4;
	
	float s1, s2, s3, s4;

	
	float length;
	float height;
	
	int rhythm;
	
};
