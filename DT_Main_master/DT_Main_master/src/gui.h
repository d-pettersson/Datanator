// ----- //
//  GUI  //
// ----- //

#ifndef gui_h
#define gui_h

#include <stdio.h>
#include "ofMain.h"
#include "ofxGui.h"

class Gui {
public:
    
    Gui();
    
    void setupGui();
    void updateGui();
    void drawGui();
    
    ofxPanel guiPanel;
    
    ofxFloatSlider nearThreshold;
    ofxFloatSlider farThreshold;

    ofxLabel thresholdLabel;
    ofxLabel kinectCheckLabel;
    ofxLabel localIpLabel;
    
    
};

#endif /* gui_h */
