#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetCircleResolution(100);
	ofBackground(0);
	gui.setup();
	gui.add(brushSize.setup("size", 12, 5, 50));
	gui.add(brushSpread.setup("spread", 25, 1, 100));
	gui.add(brushSpill.setup("spill", 2.5, 0, 5));
	gui.add(worldWind.setup("wind", 0.2, -1, 1));
	gui.add(brushColor.setup("color", ofColor(255, 255, 255, 50), ofColor(0, 0), ofColor(255, 255)));

	// shader DISABLED
	/*fbo.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA8);
	fbo.begin();
	ofClear(0, 0, 0);
	fbo.end();

	chr.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA8);
	fbo.getTexture().bindAsImage(0, GL_READ_ONLY);
	shader.setupShaderFromFile(GL_COMPUTE_SHADER, "computeShader.cs");
	shader.linkProgram();
	chr.bindAsImage(1, GL_WRITE_ONLY);*/
}

//--------------------------------------------------------------
void ofApp::update(){
	// update each drip and erase them when they are off the screen
	for (int i = 0; i < Drips.size(); i++) {
		Drips[i].update();
		if (Drips[i].y > ofGetHeight()+100)
		{
			Drips.erase(Drips.begin() + i);
		}
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	//fbo.begin();
	ofSetBackgroundAuto(false);
	for (int i = 0; i < Drips.size(); i++) {
		Drips[i].draw();
	}
	//fbo.end();

	// shader DISABLED
	/*shader.begin();
	shader.dispatchCompute(ofGetWidth() / 32, ofGetHeight() / 32, 1);
	shader.end();
	chr.draw(0, 0);*/

	gui.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	// clear the screen
	if (key == ' ') {
		ofBackground(0);
		Drips.clear();
	}
	if (key == 'f') ofToggleFullscreen();
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
	// paint drips on mouseDragged
	Drip tempDrip;
	tempDrip.setup(mouseX, mouseY, brushSize, brushSpread, ofRandom(0, brushSpill), worldWind, brushColor);
	Drips.push_back(tempDrip);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
