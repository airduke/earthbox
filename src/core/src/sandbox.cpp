//sandbox.cpp
//testtest

#include "sandbox.h"


const int screenSize_X = 640;
const int screenSize_Y = 480;


void Sandbox::initialize()
{
  printf("Initializing");
  status = 0;
  if(cloud == NULL)
  {
    printf("no initial cloud");
    return;
  }
 /*
 connect to projector
 define working area
   find frame
   find bottom plane
   determine top plane
   determine rain height
   test project on frame
   test project on bottom
 */
}

int Sandbox::getStatus()
{
  return status;
}

void Sandbox::displayImage()
{
  const cv::Mat img(screenSize_X, screenSize_Y,BYTE*3,&img_data);
  cv::namedWindow("img");
  cv::imshow("img",img);
  cv:waitKey(0);
  
}


void Sandbox::checkRaining()
{
/*
 check for rain
   check rain area for anything
     determine x/y
   return x/y or -1/-1
*/
}

void Sandbox::updateMap()
{
/*
  get pointcloud
  filter to needed area
*/}

void Sandbox::updateWater()
{
//drain out bottom
}

void Sandbox::updateProjection()  
{
}

void Sandbox::run()
{
  if(status>0)
  {
    updateMap();
    if(rainsim_running)
    {
      checkRaining();
      updateWater();
    }
    updateProjection();
  }
}


