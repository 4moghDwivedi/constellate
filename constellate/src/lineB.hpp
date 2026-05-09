//
//  lineB.hpp
//  amogh_dwivedi_final
//
//  Created by Amogh Dwivedi on 5/3/26.
//

#pragma once
#include "lineA.hpp"

class lineB: public lineA {
public:
	
	lineB();
	lineB(ofVec2f pointA, ofVec2f pointB);
	
	void alterSegments();
	void update(ofVec2f pointA, ofVec2f pointB) override;
	void draw() override;
	
	
	
	vector<float> lineWidths;
	vector<ofVec2f> lineAlter;

};
