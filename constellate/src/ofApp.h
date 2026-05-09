#pragma once

#include "ofMain.h"
#include "phantom.hpp"
#include "phantomRect.hpp"
#include "phantomTriangle.hpp"
#include "lineA.hpp"
#include "lineB.hpp"
#include <vector>
#include <memory>
using namespace std;

class ofApp : public ofBaseApp{

	public:
		void setup() override;
		void update() override;
		void draw() override;
		void exit() override;
		void mousePressed(int x, int y, int button) override;
		void keyPressed(int key) override;
	
private:
	
	vector<phantomRect> rectangs;
	
	vector<lineA> rectLines;
	
//	vector<lineB> centerLines;
	
	phantomTriangle triangle;
	phantomRect rectangle;
	
	phantom phantomA;
	
	int numRectangles;
	
	vector<unique_ptr<phantom>> ghosts;
	vector<unique_ptr<lineB>> centerLines;
		
};
