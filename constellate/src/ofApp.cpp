#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetFrameRate(24);
	ofBackground(0);

//	rectGhost = phantomRect(50, 50);
	ofSetRandomSeed(ofGetSystemTimeMicros());
//	centers = lineA(firstGhost.centerPosition, rectGhost.centerPosition);
//	
//	numRectangles = 5;
//	
//	rectangs.resize(numRectangles);
//	
//	triangle = phantomTriangle();
//	rectangle = phantomRect();
//	
//	
//	for (int i = 0; i < numRectangles; i ++){
//		rectangs[i] = phantomRect();
//	}
//	
//	centerLines.resize(numRectangles);
//	
//	for (int i = 0; i < numRectangles; i++){
//		centerLines[i] = lineB();
//	}
//	
//	phantomA = phantom();
//	
	ghosts.push_back(make_unique<phantom>());
	
	
}

//--------------------------------------------------------------
void ofApp::update(){
//	for (int i = 0; i < numRectangles; i ++){
//		rectangs[i].update();
//	}
//	
//	if (ofGetFrameNum() % 60 == 0){
//		for (int i = 0; i < numRectangles; i++){
//			if (ofRandom(0, 100) < 50)	rectangs[i].connectCorners = !(rectangs[i].connectCorners);
//		}
//		
//		triangle.connectCorners = true;
//		rectangle.connectCorners = true;
//	}
//
//	for (int i = 0; i < numRectangles - 1; i++){
//		centerLines[i].update(rectangs[i].centerPosition, rectangs[i+1].centerPosition);
//	}
//	
//	phantomA.update();
//	triangle.update();
//	rectangle.update();
//	
	for (int i = 0; i < ghosts.size(); i++){
		ghosts[i]->update();

//		ghosts[i]->connectCorners == true;
	}
	
	if (centerLines.size() > 0){
		for (int i = 0; i < centerLines.size(); i++){
			centerLines[i]->update(ghosts[i]->centerPosition, ghosts[i+1]->centerPosition);
		}
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
//	firstGhost.draw();
//	rectGhost.draw();
//	for (int i = 0; i < numRectangles; i ++){
//		rectangs[i].draw();
//	}
//	
//	for (int i = 0; i < numRectangles - 1; i++){
//		centerLines[i].draw();
//	}
//
//	phantomA.draw();
//	triangle.draw();
//	rectangle.draw();
	
	for (int i = 0; i < ghosts.size(); i++){
		ghosts[i]->draw();
	}
	
	for (int i = 0; i < centerLines.size(); i++){
		centerLines[i]->draw();
	}



}

//--------------------------------------------------------------
void ofApp::exit(){

}

void ofApp::mousePressed(int x, int y, int button){
	
	int option = floor(ofRandom(0, 3));
	
	if (option == 0){
		ghosts.push_back(make_unique<phantom>(x, y));
	}
	if (option == 1){
		ghosts.push_back(make_unique<phantomRect>(x, y));
	}
	if (option == 2){
		ghosts.push_back(make_unique<phantomTriangle>(x, y));
	}
	
	centerLines.push_back(make_unique<lineB>(ghosts[ghosts.size()-1]->centerPosition, ghosts[ghosts.size()-2]->centerPosition));
	
}

void ofApp::keyPressed(int key){
	if (key == ' '){
		ghosts.clear();
		centerLines.clear();
		ofBackground(0);
		ghosts.push_back(make_unique<phantom>());
	}
}

