//  -------------------------------------------
//  Blackout screen
//  -------------------------------------------
//
//  Creates a blackout screen.
//  Randomised appearance in time and visuals.
//  Sends out the screen num via osc
//  to clients.
//
//  -------------------------------------------


#ifndef blkScreen_h
#define blkScreen_h

#include <stdio.h>
#include "ofMain.h"
#include "ofxThreadedImageLoader.h"
#include "ofxXmlSettings.h"

class BlkScreen {
public:
    BlkScreen();
    
    void setupBlkScreen();
    void drawBlkScreen();
    void updateBlkScreen();
    void selectRandom();
    
    ofTrueTypeFont distortionFont;
    
    ofxThreadedImageLoader loader;
    vector<ofImage> images;
    string urlImages;
    string nameImages;
    string formatImages;
    size_t numImages;
    int counterImg = 0;
    bool isImageDrawn;
    
    float lastTime;
    float delayTime;
    
    ofxXmlSettings blkScreenSettings;
    bool settingsLoaded;
    
    int timer;
    int random;
    int randomSeed;
    int occurenceTimer;
    
    bool isMaster;
};

#endif /* blkScreen_h */
