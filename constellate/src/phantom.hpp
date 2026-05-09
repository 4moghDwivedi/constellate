//
//  phantom.hpp
//  amogh_dwivedi_final
//
//  Created by Amogh Dwivedi on 5/3/26.
//

#pragma once
#include "ofMain.h"

class phantom {
public:
	phantom();
	phantom(float x, float y);
	
	virtual void update();
	virtual void draw();
	virtual void keepInBounds();
	void animate();
	
	ofVec2f centerPosition;
	
protected:

	ofVec2f direction;
	
	int centerR;
	int centerG;
	int centerB;
	
	int numLines;
	
	bool connectCorners;
	
	vector<float> angles;
	vector<float> lengths;
	vector<int> alpha;
	
};
