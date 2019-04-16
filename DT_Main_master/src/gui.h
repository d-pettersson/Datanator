//  ------------------------------------------
//  UI Panel
//  ------------------------------------------
//
//  UI Creation and management
//
//  ------------------------------------------

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

    ofxLabel kinectCheckLabel;
    ofxLabel localIpLabel;
    ofxLabel settingsLoadedLabel;
    
    
};

#endif /* gui_h */
