#include "ofApp.h"

static const int NUM = 1000;

float loc_x[NUM];
float loc_y[NUM];
float speed_x[NUM];
float speed_y[NUM];
float radius[NUM];
int red[NUM];
int green[NUM];
int blue[NUM];
bool mouse_pressed;

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0, 0, 0);
    ofSetFrameRate(60);
    ofSetCircleResolution(64);
    ofEnableAlphaBlending();
    mouse_pressed = false;
    
    for (int i=0; i<NUM; i++) {
        loc_x[i] = ofRandom(0, ofGetWidth());
        loc_y[i] = ofRandom(0, ofGetHeight());
        speed_x[i] = ofRandom(-5, 5);
        speed_y[i] = ofRandom(-5, 5);
        radius[i] = ofRandom(4, 40);
        red[i] = ofRandom(0, 255);
        green[i] = ofRandom(0, 255);
        blue[i] = ofRandom(0, 255);
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    for (int i=0; i<NUM; i++) {
        if (mouse_pressed) {
            speed_x[i] = (mouseX - loc_x[i]) / 8.0;
            speed_y[i] = (mouseY - loc_y[i]) / 8.0;
        }
        loc_x[i] = loc_x[i] + speed_x[i];
        loc_y[i] = loc_y[i] + speed_y[i];
        
        if (loc_x[i] < 0) {
            speed_x[i] = speed_x[i] * -1;
        }
        if (loc_x[i] > ofGetWidth()) {
            speed_x[i] = speed_x[i] * -1;
        }
        if (loc_y[i] < 0) {
            speed_y[i] = speed_y[i] * -1;
        }
        if (loc_y[i] > ofGetHeight()) {
            speed_y[i] = speed_y[i] * -1;
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    for (int i=0; i<NUM; i++) {
        ofSetColor(red[i], green[i], blue[i], 127);
        ofDrawCircle(loc_x[i], loc_y[i], radius[i]);
    }
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
    mouse_pressed = true;
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    mouse_pressed = false;
    
    for (int i=0; i<NUM; i++) {
        speed_x[i] = ofRandom(-5, 5);
        speed_y[i] = ofRandom(-5, 5);
    }
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
