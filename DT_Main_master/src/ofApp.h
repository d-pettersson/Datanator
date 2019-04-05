#pragma once

#include "ofMain.h"

// of addons
#include "ofxGui.h"
#include "ofxOsc.h"
#include "ofxNetworkUtils.h"

// custom classes
#include "pointMesh.h"
#include "kinectManager.h"
#include "gui.h"


class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
    
        // shader and texture
        ofShader shader;
        ofImage img;
    
        // cam and light
        ofCamera cam;
        ofLight light;
    
        // geo
        PointMesh pointMesh;
    
        // interaction
        KinectManager kinect;
    
        // GUI
        Gui gui;
    
        bool toggleGui;
    
//        ofx::Net::NetworkUtils::listNetworkInterfaces netUtils;
        
    
    
        // custom functions
        void displayFPS();
        void exit();

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
		
};
