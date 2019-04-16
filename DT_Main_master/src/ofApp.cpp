#include "ofApp.h"



//--------------------------------------------------------------
// setting up the application
// loading xml settings
// setting up geometry, kinect, blackoutscreen and GUI
// setting up camera and geometry
// loading up parameters for GUI
// loading up shader

void ofApp::setup(){
    
    ofBackground(0);
    ofSetFrameRate(60);
    ofSetVerticalSync(true);
    ofEnableSmoothing();
    
    // XML settings
    mainSettings.load("mainSettings.xml");
    oscLocalIp      = mainSettings.getValue("settings:oscHostIp", "127.0.0.1");
    oscLocalPort    = mainSettings.getValue("settings:oscHostPort", 57120);
    oscSender.setup(oscLocalIp, oscLocalPort);
    
    pointMesh.setupPointMesh();
    kinect.setupKinect();
    blkScreen.setupBlkScreen();
    blkScreen.isMaster = true;
    gui.setupGui();
    
    cam.setPosition(ofVec3f(0, 0, 900));
    cam.lookAt(ofVec3f(0, 0 , 0));
    
    displacementFbo.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA);
    outFbo.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA);

    
    // GUI

    Poco::Net::NetworkInterface::List siteLocalInterfaces = ofxNet::NetworkUtils::listNetworkInterfaces(ofxNet::NetworkUtils::SITE_LOCAL);

    gui.localIpLabel.setup("LAN IP", siteLocalInterfaces[0].address().toString());

    gui.settingsLoadedLabel.setup("Blackout settings loaded", to_string(blkScreen.settingsLoaded));
    if (blkScreen.settingsLoaded) gui.settingsLoadedLabel.setBackgroundColor(ofColor(0, 255, 0));
    else gui.settingsLoadedLabel.setBackgroundColor(ofColor(255, 0, 0));
    
    shader.load("shader.vert", "shader.frag");
    postShader.load("postshader.vert", "postshader.frag");
    
}

//--------------------------------------------------------------
// updating kinect and drawing depth texture
// display FPS in title bar
// updating blackoutscreen

void ofApp::update(){
    
    kinect.updateKinect();
    kinect.depthTexture.draw(0,0);
    displayFPS();
    blkScreen.updateBlkScreen();
    
    ofxOscMessage oscMsg;
    oscMsg.setAddress("/blkscreen/counterimg");
    oscMsg.addIntArg(blkScreen.counterImg);
    oscMsg.addBoolArg(blkScreen.isImageDrawn);
    oscSender.sendMessage(oscMsg);

    displacementFbo.begin();
    cam.begin();
    shader.begin();
    shader.setUniformTexture("texKinect", kinect.depthTexture.getTexture(), 0);
    shader.setUniform2f("texSize", ofGetWidth(), ofGetHeight());
    shader.setUniform2f("texKinectSize", kinect.depthTexture.getTexture().getWidth(), kinect.depthTexture.getTexture().getHeight());
    shader.setUniform1f("time", ofGetElapsedTimef());
    pointMesh.drawPointMesh();
    shader.end();
    cam.end();
    displacementFbo.end();

}

//--------------------------------------------------------------
// drawing shader and geometry
// toggling GUI
// drawing blackoutscreen

void ofApp::draw(){
    
    outFbo.begin();
    postShader.begin();
    postShader.setUniformTexture("texDisplacement", displacementFbo.getTexture(), 1);
    postShader.setUniform1f("time", ofGetElapsedTimef());
    displacementFbo.draw(0, 0);
    postShader.end();
    outFbo.end();
    outFbo.draw(0, 0);
    
    if (!toggleGui) {
        gui.drawGui();
    }
    
    blkScreen.drawBlkScreen();
    
}


//--------------------------------------------------------------
void ofApp::displayFPS() {
    ofSetWindowTitle(ofToString(ofGetFrameRate(), 2));
}

//--------------------------------------------------------------

void ofApp::exit() {
    kinect.exitKinect();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == 'g') {
        toggleGui = !toggleGui;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
