#include <ros/ros.h>
#include <geometry_msgs/Twist.h> 
#include <turtlesim/Pose.h>
#include <stdlib.h> 
#include <iostream>

double x, y, theta, linear, angular, dist, vel, tiempo, contador;
int termino;
void poseMessageReceived(const turtlesim::Pose& msg){
	x=msg.x;
	y=msg.y;
	theta=msg.theta;
	linear=msg.linear_velocity;
	angular=msg.angular_velocity;
}
//callback llamado cuando el tiempo se agota en el timer
// void callbackTimer(const ros::TimerEvent& event){
//     ROS_INFO_STREAM("Distancia alcanzada");
//     ros::NodeHandle nh2;
//     ros::Publisher pub2=nh2.advertise<geometry_msgs::Twist>("turtle1/cmd_vel",1000);
//     geometry_msgs::Twist msg2 ;
//     msg2.linear.x=0;
//     pub2.publish (msg2);
//     termino=1;
// }

int main(int argc, char **argv){

ros::init(argc, argv, "publish_velocity");
ros::NodeHandle nh;

ros::Publisher pub=nh.advertise<geometry_msgs::Twist>("turtle1/cmd_vel", 1000);
ros::Subscriber sub=nh.subscribe("turtle1/pose",1000,&poseMessageReceived);
// ros::Timer timer=nh.createTimer(ros::Duration(0), callbackTimer, true);


geometry_msgs::Twist msg;
ros::Rate rate(10);
termino=1;
contador=0;
msg.angular.z=0;

while(ros::ok()){
	if(termino==1){
		ROS_INFO_STREAM("Distancia a recorrer:");
		std::cin >> dist;
		ROS_INFO_STREAM("Velocidad: [1,5]");
		std::cin >> vel;
		msg.linear.x=vel;
		if(dist<0){
			dist=-dist;
		}
		tiempo=dist/vel;
		if(vel<0){
			tiempo=-tiempo;
		}
		ROS_INFO_STREAM("Tiempo: "<<tiempo);
		termino=0;
		// timer.stop();
        // timer.setPeriod(ros::Duration(tiempo));
		// timer.start();
	}
	if((tiempo-contador)<0.03){
		msg.linear.x=0;
		termino=1;
		contador=0;
	}
	pub.publish(msg);
	contador=contador+0.1;
	ros::spinOnce(); //llama al callback
	ROS_INFO_STREAM(std::setprecision(2) <<std::fixed
			<< "position=(" << x << "," << y <<")");
	ROS_INFO_STREAM("Contador: "<<contador);
rate.sleep();
	}
}