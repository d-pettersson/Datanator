//  ------------------------------------------
//  Kinect Manager
//  ------------------------------------------
//
//  Setup, init and management of kinect v1.
//
//  ------------------------------------------

#include "kinectManager.h"

KinectManager::KinectManager() {}

void KinectManager::setupKinect() {
    
    // initialize without using the video image (faster FPS)
    kinect.init(false, false);
    kinect.setDepthClipping(0, 1000);
    kinect.open();
    
    if(kinect.isConnected()) {
        ofLogNotice() << "sensor-emitter dist: " << kinect.getSensorEmitterDistance() << "cm";
        ofLogNotice() << "sensor-camera dist:  " << kinect.getSensorCameraDistance() << "cm";
        ofLogNotice() << "zero plane pixel size: " << kinect.getZeroPlanePixelSize() << "mm";
        ofLogNotice() << "zero plane dist: " << kinect.getZeroPlaneDistance() << "mm";
    }
    
    depthTexture.allocate(kinect.width, kinect.height);
}

void KinectManager::updateKinect() {
    
    kinect.update();
    
    if (kinect.isFrameNew()) {
        depthTexture.setFromPixels(kinect.getDepthPixels());
        for (int i = 0; i < dilatePasses; i++) {
            depthTexture.dilate();
        }
        depthTexture.blurGaussian(20);
        depthTexture.mirror(true, true);
    }
}


void KinectManager::exitKinect() {
    kinect.close();
}
