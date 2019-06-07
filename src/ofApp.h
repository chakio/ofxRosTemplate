#pragma once
//C++ include
#include <iostream>
#include <sstream>
#include <string>

//oF include
#include "ofMain.h"

//ROS include
#include <ros/ros.h>
#include <std_msgs/String.h>

using namespace std;

class ofApp : public ofBaseApp{

	public:
		ofApp(int argc, char *argv[]);
		void setup();
		void update();
		void draw();

		void getMessage(const std_msgs::String::ConstPtr& msg);

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);

	   	ros::NodeHandle n;
		ros::Subscriber sub_message;
		ros::Publisher  pub_message;

		int count = 0;
};
