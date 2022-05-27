#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "drip.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		vector <Drip> Drips; // container for the sigle droplets

		ofxFloatSlider brushSize;
		ofxFloatSlider brushSpread;
		ofxFloatSlider brushSpill;
		ofxFloatSlider worldWind;
		ofxColorSlider brushColor;

		ofxPanel gui; // setup for the gui

		// shader DISABLED
		/*ofFbo fbo;
		ofTexture chr;
		ofShader shader;*/
};
