//sandbox.cpp
//testtest

#include "sandbox.h"


void Sandbox::initialize()
{

}

int Sandbox::getStatus()
{
  return -1;
}

void Sandbox::checkRaining()
{
}

void Sandbox::updateMap()
{
}

void Sandbox::updateWater()
{
}

void Sandbox::updateProjection()  
{
}

void Sandbox::run()
{
  running = true;
  while(running)
  {
    updateMap();
    if(rainsim_running)
    {
      checkRaining();
      updateWater();
    }
  }

}


