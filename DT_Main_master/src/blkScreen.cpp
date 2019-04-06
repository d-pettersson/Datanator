//  ------------------------------------------
//  Blackout screen
//  ------------------------------------------
//
//  Creates a blackout screen.
//  Randomised appearance in time and visuals.
//  Sends out the screen via syphon to slaves.
//
//  ------------------------------------------

#include "blkScreen.h"

BlkScreen::BlkScreen() {};

void BlkScreen::setupBlkScreen() {
    distortionFont.load("Distortion.ttf", 32);
}

void BlkScreen::updateBlkScreen() {

}

void BlkScreen::drawBlkScreen() {
    string s = "tis a test";
    float widthString = distortionFont.stringWidth(s);
    
    timer++;
    if (timer > 120) {
        random = ofRandom(50);
        ofBackground(0);
        ofSetColor(255);
        distortionFont.drawString(s, ofGetWidth() * .5 - widthString * .5, ofGetHeight() * .5);
        if (random == 4) {
            timer--;
            cout << timer << endl;
            if (timer < 0 || timer > 120) {
                timer = 0;
            }
        }
    }
}
