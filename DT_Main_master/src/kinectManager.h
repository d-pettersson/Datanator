//  ------------------------------------------
//  Kinect Manager
//  ------------------------------------------


#ifndef kinectManager_h
#define kinectManager_h

#include <stdio.h>
#include "ofMain.h"
#include "ofxKinect.h"
#include "ofxOpenCv.h"

class KinectManager {
    
public:
    KinectManager();
    
    void setupKinect();
    void updateKinect();
    void drawKinect();
    void exitKinect();
    
    ofxKinect kinect;
    
    ofxCvGrayscaleImage depthTexture;
    
    int nearThreshold = 0;
    int farThreshold = 1000;
};

#endif /* kinectManager_h */
