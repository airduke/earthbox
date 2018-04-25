//
//  runsandbox.cpp
//  myarsandbox
//
//  Created by Chris on 4/23/18.
//

#include "ros/ros.h"
#include "sensor_msgs/PointCloud2.h"
#include "core/sandbox.h"

int is_updating_sandbox = 0;
Sandbox mysandbox;

void updateSandbox()
{
 
  is_updating_sandbox = 0;
  return;
}

void pointcloudCallback(const sensor_msgs::PointCloud2ConstPtr& mypointcloud)
{
  mysandbox.nextPointcloud(mypointcloud);
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "runsandbox");
  ros::NodeHandle n;
  ros::Subscriber sub = n.subscribe<sensor_msgs::PointCloud2> ("junk_pointcloud_topic", 1, pointcloudCallback);
  ros::Rate loop_rate(10);
  int count = 0;

  while (ros::ok())
  {
    if(mysandbox.getStatus<1)
      mysandbox.initialize();
    else
      sandbox.run();  
  ros::spinOnce();
        
  loop_rate.sleep();
  }
  return 0;
}

// to create a subscriber, you can do this (as above):

