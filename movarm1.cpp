/*written by aneesh_pa on 19mar2016
The program publishes message gazebo_msgs/LinkState to
topic /gazebo/set_mode_state which is subscribed by gazebo node
The program creates a node "publink" for this purpose
The program was tested and verified on youbot simulated in gazebo*/

#include <ros/ros.h>
// /gazebo/set_model_state uses msg gazebo_msgs/LinkState 
#include <gazebo_msgs/LinkState.h>

int main(int argc, char **argv) {
  ros::init(argc, argv, "publink");
  ros::NodeHandle nh;

//Create publisher object
//1000 is the buffer size
  ros::Publisher pub = nh.advertise<gazebo_msgs::LinkState>("/gazebo/set_link_state", 1000);


//Loop at 2 Hz
  ros::Rate rate(2);
  while(ros::ok()) {
    gazebo_msgs::LinkState msg;
    msg.link_name = "youbot::arm_link_1";
    msg.pose.position.x = 0;
    msg.pose.position.y = 0;
    msg.pose.position.z = 0;

    msg.pose.orientation.x = 0;
    msg.pose.orientation.y = 0;
    msg.pose.orientation.z = 0;
    msg.pose.orientation.w = 0;

    msg.twist.linear.x = 0;
    msg.twist.linear.y = 0;
    msg.twist.linear.z = 0;

    msg.twist.angular.x = 0;
    msg.twist.angular.y = 0;
    msg.twist.angular.z = 1;
    
    msg.reference_frame = "youbot::base_footprint";
   
    pub.publish(msg);
 
    ROS_INFO_STREAM("Sending command to move arm_link_1 wrt. base_footprint with angular velocity (z) : "<< msg.twist.angular.z);
//Wait until its time for another iteration
    rate.sleep();
    }
}






