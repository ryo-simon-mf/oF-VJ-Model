#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    //medel loading setup
    model_path = "sample.obj";
    model.setScale(scale * -1, scale, scale);
    model.loadModel(model_path);
    
    //rolling cam setup
    rollcam.setup();//rollCam's setup.
    rollcam.setCamSpeed(0.1);//rollCam's speed set;
    ofBackground(0);
    
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    
    fbo.allocate(ofGetWidth(), ofGetHeight());
    
    glitch.setup(&fbo);

}

//--------------------------------------------------------------
void ofApp::update(){
    model.update();
    rollcam.update();
    
    fbo.begin();//fbo begin
    ofClear(0, 0, 0, 255);
    
    rollcam.begin();//rollcam begin
    
    ofEnableDepthTest();
    ofSetLineWidth(0.1);

    ofPushMatrix();
    ofTranslate(0,350);//change position
    model.drawWireframe();
    
    ofPopMatrix();
    
    
    rollcam.end();  //rollcam end
    
    fbo.end();//fbo end

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    glitch.generateFx();
    
    ofSetColor(255);
    
    fbo.draw(0,0);

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key=='z') {//All Random.
        rollcam.setRandomScale(0.5, 1.5);
        rollcam.setRandomPos(270);
    }
    if (key=='x') {//Random rotate.
        rollcam.setRandomPos(270);
    }
    if (key=='c') {//Inputting optional rotate.
        rollcam.setPos(0, 0, 0);
    }
    if (key=='v') {//Random distance.
        rollcam.setRandomScale(0.5, 1.5);
    }
    if (key=='b') {//Inputting optional distance.
        rollcam.setScale(1);
    }
    if (key=='n') {//Random distance.
        
    }
    
//    if (key=='f') {
//        ofToggleFullscreen();
//    }
    
    
    if (key == '1') glitch.setFx(OFXPOSTGLITCH_CONVERGENCE    , true);
    if (key == '2') glitch.setFx(OFXPOSTGLITCH_GLOW            , true);
    if (key == '3') glitch.setFx(OFXPOSTGLITCH_SHAKER            , true);
    if (key == '4') glitch.setFx(OFXPOSTGLITCH_CUTSLIDER        , true);
    if (key == '5') glitch.setFx(OFXPOSTGLITCH_TWIST            , true);
    if (key == '6') glitch.setFx(OFXPOSTGLITCH_OUTLINE        , true);
    if (key == '7') glitch.setFx(OFXPOSTGLITCH_NOISE            , true);
    if (key == '8') glitch.setFx(OFXPOSTGLITCH_SLITSCAN        , true);
    if (key == '9') glitch.setFx(OFXPOSTGLITCH_SWELL            , true);
    if (key == '0') glitch.setFx(OFXPOSTGLITCH_INVERT            , true);
    
    if (key == 'q') glitch.setFx(OFXPOSTGLITCH_CR_HIGHCONTRAST, true);
    if (key == 'w') glitch.setFx(OFXPOSTGLITCH_CR_BLUERAISE    , true);
    if (key == 'e') glitch.setFx(OFXPOSTGLITCH_CR_REDRAISE    , true);
    if (key == 'r') glitch.setFx(OFXPOSTGLITCH_CR_GREENRAISE    , true);
    if (key == 't') glitch.setFx(OFXPOSTGLITCH_CR_BLUEINVERT    , true);
    if (key == 'y') glitch.setFx(OFXPOSTGLITCH_CR_REDINVERT    , true);
    if (key == 'u') glitch.setFx(OFXPOSTGLITCH_CR_GREENINVERT    , true);
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    if (key == '1') glitch.setFx(OFXPOSTGLITCH_CONVERGENCE    , false);
    if (key == '2') glitch.setFx(OFXPOSTGLITCH_GLOW            , false);
    if (key == '3') glitch.setFx(OFXPOSTGLITCH_SHAKER            , false);
    if (key == '4') glitch.setFx(OFXPOSTGLITCH_CUTSLIDER        , false);
    if (key == '5') glitch.setFx(OFXPOSTGLITCH_TWIST            , false);
    if (key == '6') glitch.setFx(OFXPOSTGLITCH_OUTLINE        , false);
    if (key == '7') glitch.setFx(OFXPOSTGLITCH_NOISE            , false);
    if (key == '8') glitch.setFx(OFXPOSTGLITCH_SLITSCAN        , false);
    if (key == '9') glitch.setFx(OFXPOSTGLITCH_SWELL            , false);
    if (key == '0') glitch.setFx(OFXPOSTGLITCH_INVERT            , false);
    
    if (key == 'q') glitch.setFx(OFXPOSTGLITCH_CR_HIGHCONTRAST, false);
    if (key == 'w') glitch.setFx(OFXPOSTGLITCH_CR_BLUERAISE    , false);
    if (key == 'e') glitch.setFx(OFXPOSTGLITCH_CR_REDRAISE    , false);
    if (key == 'r') glitch.setFx(OFXPOSTGLITCH_CR_GREENRAISE    , false);
    if (key == 't') glitch.setFx(OFXPOSTGLITCH_CR_BLUEINVERT    , false);
    if (key == 'y') glitch.setFx(OFXPOSTGLITCH_CR_REDINVERT    , false);
    if (key == 'u') glitch.setFx(OFXPOSTGLITCH_CR_GREENINVERT    , false);

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
