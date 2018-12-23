#include "ofApp.h"

//--------------------------------------------------------------
ofApp::ofApp(int argc, char *argv[])
{
	sub_message = n.subscribe("chatter", 1000, &ofApp::getMessage, this);
	pub_message = n.advertise<std_msgs::String>("chatter", 1000);
}

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundColor(0);
	count = 0;
}

//--------------------------------------------------------------
void ofApp::update(){
    ros::Rate r(60);
    
	if(ros::ok())
	{
       /**
        * This is a message object. You stuff it with data, and then publish it.
        */

	   count++;
	   if(ofGetWidth() < count || ofGetHeight() < count)
	   {
		   count = 0;
	   }

       std_msgs::String msg;
   
	   std::stringstream ss;
       ss << "hello world " << count;
       msg.data = ss.str();
   
       ROS_INFO("%s", msg.data.c_str());
   
       /**
        * The publish() function is how you send messages. The parameter
        * is the message object. The type of this object must agree with the type
        * given as a template parameter to the advertise<>() call, as was done
        * in the constructor above.
 	    */

		pub_message.publish(msg);

		r.sleep();
		ros::spinOnce();
	}
	else
	{
		ofExit();
	}
}
//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255,255,255);
	ofDrawRectangle(0,0,count,count);
}

//--------------------------------------------------------------
void ofApp::getMessage(const std_msgs::String::ConstPtr& msg){
    ROS_INFO("I heard: [%s]", msg->data.c_str());
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

