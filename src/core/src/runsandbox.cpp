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

void updateSandbox()
{
 
  is_updating_sandbox = 0;
  return;
}

void pointcloudCallback(const sensor_msgs::PointCloud2ConstPtr& mypointcloud)
{
  if(!is_updating_sandbox)
  {
    is_updating_sandbox = 1;
    updateSandbox();
  }
  return;
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
  ros::spinOnce();
        
  loop_rate.sleep();
  ++count;
  }
  return 0;
}

// to create a subscriber, you can do this (as above):

