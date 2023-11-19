#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(25);
	ofSetWindowTitle("openframeworks");

	ofBackground(0);
	ofSetLineWidth(2);
	ofEnableBlendMode(ofBlendMode::OF_BLENDMODE_ADD);
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	ofTranslate(ofGetWidth() * 0.5, ofGetHeight() * 0.5);

	ofColor color;
	for (int k = 0; k < 40; k++) {

		ofRotate(9);

		color.setHsb(ofMap(k, 0, 40, 0, 255), 200, 255);
		ofSetColor(color);

		vector<glm::vec2> vertices;
		for (int i = 0; i < 60; i++) {

			auto radius = k % 2 == 0 ? ofMap(sin((ofGetFrameNum() + i) * 0.314 * 0.7), -1, 1, 150, 300) : ofMap(sin((ofGetFrameNum() + i) * 0.314 * 0.7), -1, 1, 300, 150);
			auto deg = (ofGetFrameNum() + i) * 4;
			auto location = glm::vec2(radius * cos(deg * DEG_TO_RAD), radius * sin(deg * DEG_TO_RAD));

			vertices.push_back(location);
		}

		ofNoFill();
		ofBeginShape();
		ofVertices(vertices);
		ofEndShape();

		ofFill();
		ofDrawCircle(vertices[0], 3);
		ofDrawCircle(vertices[vertices.size() - 1], 3);
	}

	/*
	int start = 150;
	if (ofGetFrameNum() > start) {

		ostringstream os;
		os << setw(4) << setfill('0') << ofGetFrameNum() - start;
		ofImage image;
		image.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
		image.saveImage("image/cap/img_" + os.str() + ".jpg");
		if (ofGetFrameNum() - start >= 25 * 20) {

			std::exit(1);
		}
	}
	*/
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}