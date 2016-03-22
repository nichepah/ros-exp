/*based on roscpp_tutorials from
wiki.ros.org/roscpp_tutorials/Tutorials/WritingPublisherSubscriber*/

#include "ros/ros.h"
#include "std_msgs/String.h"

#include <sstream>

//This demonstrates msg sending over ROS

int main(int argc, char **argv) {
  
  ros::init(argc, argv, "talker");
  ros::NodeHandle n;
  //chatter is the topic, 1000 the size of queue
  ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter",1000);
  ros::Rate loop_rate(1);

  int count = 0;
  while (ros::ok())
    {
      std_msgs::String msg;
      std::stringstream ss;
      ss <<"hellowww...." << count;
      msg.data = ss.str();
    
      ROS_INFO("%s", msg.data.c_str());

      chatter_pub.publish(msg);
      ros::spinOnce();
      loop_rate.sleep();
      ++count;
     }
   return 0;
} 
