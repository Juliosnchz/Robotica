#include <ros/ros.h>
#include <geometry_msgs/Twist.h> 
#include <turtlesim/Pose.h>
#include <stdlib.h> 
#include <iostream>

double x, y, theta, linear, angular, dist, vel, tf, vf, contador, contador2;
int termino;
void poseMessageReceived(const turtlesim::Pose& msg){
	x=msg.x;
	y=msg.y;
	theta=msg.theta;
	linear=msg.linear_velocity;
	angular=msg.angular_velocity;
}

int main(int argc, char **argv){

ros::init(argc, argv, "publish_velocity");
ros::NodeHandle nh;

ros::Publisher pub=nh.advertise<geometry_msgs::Twist>("turtle1/cmd_vel", 1000);
ros::Subscriber sub=nh.subscribe("turtle1/pose", 1000, &poseMessageReceived);

geometry_msgs::Twist msg;
termino=1;
ros::Rate rate(10);
while(ros::ok()){
	if(termino==1){
		ROS_INFO_STREAM("Distancia a recorrer:");
		std::cin >> dist;
		ROS_INFO_STREAM("Velocidad: [1, 5]");
		std::cin >> vf;
		if(dist<0){
			dist=-dist;
		}
		tf=dist/vf;
		if(vf<0){
			tf=-tf;
		}
		termino=0;
		contador=0;
		contador2=1;
	}
	if(contador<1){
		contador=contador+0.1;
		vel=vf*contador;
	}
	else{
		if(contador>1 && contador<tf){
			contador=contador+0.1;
			vel=vf;
		}
		else{
			contador=contador+0.1;
			vel=vf*(contador2);
			contador2=contador2-0.1;
		}
	}
	if(contador2<0.03){
		termino=1;
		msg.linear.x=0;
	}
	else{
		msg.linear.x=vel;
	}
	pub.publish(msg);
	ros::spinOnce(); //llama al callback
	ROS_INFO_STREAM(std::setprecision(2) <<std::fixed
	 		<< "position=(" << x << "," << y <<")");
	ROS_INFO_STREAM("Tiempo: "<<tf);
	ROS_INFO_STREAM("contador: "<<contador);
rate.sleep();
	}
}