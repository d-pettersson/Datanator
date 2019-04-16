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

#include "blkScreen.h"

BlkScreen::BlkScreen() {};

void BlkScreen::setupBlkScreen() {
    lastTime = ofGetElapsedTimef();
    
    blkScreenSettings.load("blkScreenSettings.xml");
    
    if (blkScreenSettings.load("blkScreenSettings.xml")) settingsLoaded = true;

    urlImages       = blkScreenSettings.getValue("settings:urlImages", "http://localhost:8888/images/");
    nameImages      = blkScreenSettings.getValue("settings:nameImages", "blackoutScreen_");
    formatImages    = blkScreenSettings.getValue("settings:formatImages", ".jpg");
    delayTime       = blkScreenSettings.getValue("settings:delayTime", 5.0);
    numImages       = blkScreenSettings.getValue("settings:numImages", 5);
    randomSeed      = blkScreenSettings.getValue("settings:randomSeed", 50);
    occurenceTimer  = blkScreenSettings.getValue("settings:occurenceTimer", 120);
    
    distortionFont.load("Distortion.ttf", 32);
    
    images.resize(numImages);
    for (int i = 0; i < numImages; i++) {
        loader.loadFromURL(images[i], urlImages + nameImages + ofToString(i) + formatImages);
    }
}

void BlkScreen::updateBlkScreen() {
    if (isMaster) {
        float currentTime = ofGetElapsedTimef();
        float passedTime;
        
        passedTime = currentTime - lastTime;
        if (passedTime > delayTime) {
            counterImg++;
            lastTime = currentTime;
        }
        
        counterImg > 4 ? counterImg = 0 : counterImg;
        selectRandom();
    }
}

void BlkScreen::drawBlkScreen() {
//
//    string s = "tis a test";
//    float widthString = distortionFont.stringWidth(s);
//
//    timer++;
//
//        ofBackground(0);
//        ofSetColor(255);
//        distortionFont.drawString(s, ofGetWidth() * .5 - widthString * .5, ofGetHeight() * .5);
//
//    }
    if (isImageDrawn)
        images[counterImg].draw(0, 0);
}

void BlkScreen::selectRandom() {
    isImageDrawn = false;
    
    timer++;
    if (timer > occurenceTimer) {
        random = ofRandom(randomSeed);
        
        isImageDrawn = true;
        
        if (random == 4) {
            timer--;
            
            if (timer < 0 || timer > occurenceTimer) {
                timer = 0;
            }
        }
    }
}



