#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(0);
    
    ofSetFrameRate(60);
    
    ofEnableSmoothing();
    
    pointMesh.setupPointMesh();
    
    cam.setPosition(ofVec3f(0, 0, 900));
    cam.lookAt(ofVec3f(0, 0 , 0));
    
    shader.load("shader.vert", "shader.frag");
    
    img.allocate(ofGetWidth(), ofGetHeight(), OF_IMAGE_GRAYSCALE);
    
    kinect.setupKinect();
    
    gui.setupGui();
    
    // display LAN IP in GUI
    Poco::Net::NetworkInterface::List siteLocalInterfaces = ofxNet::NetworkUtils::listNetworkInterfaces(ofxNet::NetworkUtils::SITE_LOCAL);

    gui.localIpLabel.setup("LAN IP", siteLocalInterfaces[0].address().toString());
    
}

//--------------------------------------------------------------
void ofApp::update(){
//    float noiseScale = 0.005;
//    float noiseVel = ofGetElapsedTimef();
//
//    ofPixels &pixels = img.getPixels();
//    int w = img.getWidth();
//    int h = img.getHeight();
//    for(int y=0; y<h; y++) {
//        for(int x=0; x<w; x++) {
//            int i = y * w + x;
//            float noiseVelue = ofNoise(x * noiseScale, y * noiseScale, noiseVel);
//            pixels[i] = 255 * noiseVelue;
//        }
//    }
//    img.update();
    
    kinect.updateKinect();
    displayFPS();

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    cam.begin();
    
    shader.begin();
    shader.setUniformTexture("texNoise", img.getTexture(), 0);
    shader.setUniformTexture("texKinect", kinect.depthTexture.getTexture(), 1);
    shader.setUniform2f("texNoiseSize", img.getTexture().getWidth(), img.getTexture().getHeight());
    shader.setUniform2f("texKinectSize", kinect.depthTexture.getTexture().getWidth(), kinect.depthTexture.getTexture().getHeight());
    shader.setUniform1f("time", ofGetElapsedTimef());
    
    pointMesh.drawPointMesh();
    
    shader.end();
    
    cam.end();
    
    if (!toggleGui) {
        gui.drawGui();
        kinect.depthTexture.draw(0,0);
    }
    
    
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
