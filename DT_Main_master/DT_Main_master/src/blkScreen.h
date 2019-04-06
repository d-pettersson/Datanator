//  ------------------------------------------
//  Blackout screen
//  ------------------------------------------


#ifndef blkScreen_h
#define blkScreen_h

#include <stdio.h>
#include "ofMain.h"

class BlkScreen {
public:
    BlkScreen();
    
    void setupBlkScreen();
    void drawBlkScreen();
    void updateBlkScreen();
    
    ofTrueTypeFont distortionFont;
    
    int timer;
    int random;
    
};

#endif /* blkScreen_h */
