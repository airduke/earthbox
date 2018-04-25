//
//  sandbox.h
//  myarsandbox
//
//  Created by Chris on 4/22/18.
//
//  class for the sandbox for all manipulations and calculations

#ifndef sandbox_h
#define sandbox_h

#include "geometry_msgs/Point.h"
#include "sensor_msgs/PointCloud2.h"
#include <opencv2/highgui.h>


class Sandbox
{
public:
  Sandbox()
  {
    rainsim_running = false;
    rain_center.x = -1;
    rain_center.y = -1;
    rain_center.z = -1;
    running = false;
    using_cloud = false;
    cloud = NULL;
    status = 0;
  }
  ~Sandbox();

  void shutdown() {running = false;}

  void nextPointcloud(const sensor_msgs::PointCloud2ConstPtr& nextcloud)
  {
    if(!using_cloud)
      cloud = *nextcloud;
  }

  void initialize();
  int getStatus();
  void run();

  void runRainSim(bool running) {rainsim_running = running;}

private:
  bool rainsim_running;
  bool running;
  bool using_cloud;
  sensor_msgs::PointCloud2 cloud;
  geometry_msgs::Point rain_center;
  int status;
  

  void checkRaining();
  void updateMap();
  void updateWater();  
  void updateProjection();
  void displayImage(); 

};

#endif /* sandbox_h */
