#include "ofApp.h"

//--------------------------------------------------------------
ofApp::ofApp(int argc, char *argv[])
{
}

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundColor(0);
	count = 0;
}

//--------------------------------------------------------------
void ofApp::update(){

	
	/**
	* This is a message object. You stuff it with data, and then publish it.
	*/

	count++;
	if(ofGetWidth() < count || ofGetHeight() < count)
	{
		count = 0;
	}

	std::stringstream ss;
	ss << "hello world " << count;

	/**
	* The publish() function is how you send messages. The parameter
	* is the message object. The type of this object must agree with the type
	* given as a template parameter to the advertise<>() call, as was done
	* in the constructor above.
	*/
}
//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255,255,255);
	ofDrawRectangle(0,0,count,count);
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

