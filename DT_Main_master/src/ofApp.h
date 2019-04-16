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
#include "blkScreen.h"


class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
    
        // shader and texture
        ofShader shader;
        ofShader postShader;
        ofFbo displacementFbo;
        ofFbo outFbo;
    
        // cam and light
        ofCamera cam;
    
        // geo
        PointMesh pointMesh;
    
        // interaction
        KinectManager kinect;
    
        // GUI
        Gui gui;
    
        // BlackoutScreen
        BlkScreen blkScreen;
    
        bool toggleGui;
    
        ofxXmlSettings mainSettings;
    
        // OSC
        string oscLocalIp;
        int oscLocalPort;
        ofxOscSender oscSender;
        ofxOscReceiver oscReceive;
    
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
