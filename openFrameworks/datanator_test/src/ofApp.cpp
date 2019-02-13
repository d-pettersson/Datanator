#include "ofApp.h"
#include "ofxOsc.h"

//--------------------------------------------------------------
void ofApp::setup(){
    receiver.setup(57120);
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofColor(255);
    ofBackground(0);
    
    ofxOscMessage m;
    string message;
    
    while (receiver.hasWaitingMessages()) {
        receiver.getNextMessage(m);
        message = m.getArgAsString(0);
        messages.push_back(message);
        if (messages.size() > 20) {
            messages.pop_front();
        }
    }
    
    ofPushMatrix();
    ofTranslate(ofGetWidth()/3, ofGetHeight()/3);
    for(int i = 0; i < messages.size(); i++) {
        ofDrawBitmapString(messages[i], 0, i * 20);
    }
    ofPopMatrix();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
