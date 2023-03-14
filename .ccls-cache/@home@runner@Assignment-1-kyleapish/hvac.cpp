//Kyle Pish
//02-25-22

#include <iostream>
#include "hvac.h"

//constructor for hvac that takes in the cooling differential, heating differential, and the CFM (cubic feet per minute)
hvac::hvac(double CoolingDifferential, double HeatingDifferential, int new_CFM) {
  
  //assigning values to all the attributes of the class from the constructor
  this->CoolingDifferential_ = CoolingDifferential;
  this->HeatingDifferential_ = HeatingDifferential;
  this->CFM_ = new_CFM;

  //starting with the fan set to auto and the system set to off
  this->FanSetting_ = 0;
  this->SystemSetting_ = 0;
  
  //starting timers at 0
  this->AcTime_ = 0;
  this->HeatTime_ = 0;

  //default value to start the threshold at
  this->CoolingThreshold_ = 75;
  this->HeatingThreshold_ = 75;
}

//destructor for any data on the heap
hvac::~hvac() {

}


//returns 1 or 0 to tell whether fan is on or auto
int hvac::GetFan(){
  return this->FanSetting_;
}

//User enters a 1 (representing auto) or 0 (representing On)
void hvac::SetFan(int FanSetting){
  this->FanSetting_ = FanSetting;
}

//returns either -1, 0, or 1 to tell the user whether the system is cooling, off, or heating
int hvac::GetSystem(){
  return this->SystemSetting_;
}

//user can enter -1 for cooling, 0 for off, and 1 for heat
void hvac::SetSystem(int SystemSetting){
  this->SystemSetting_ = SystemSetting;
}

//returns time ac was on for
int hvac::GetAcActive(){
  return this->AcTime_;
}

//returns time it was heating for
int hvac::GetHeatActive(){
  return this->HeatTime_;
}

//cheks to see where the temperature is relative to the threshold and will increase it if it is under the threshold
void hvac::IncreaseTemperature(){
  if (this->SystemSetting_ == -1 && this->CoolingThreshold_ < 99)
  {
    this->CoolingThreshold_ ++;
  }
  else if (this->SystemSetting_ == 1 && this->HeatingThreshold_ < 99){
    this->HeatingThreshold_ ++;
  }

}

//check to see where to temperature is relative to the threshold and will decrease the temperature if it is above the threshold
void hvac::DecreaseTemperature(){
  if (this->SystemSetting_ == -1 && this->CoolingThreshold_ > 50){
    this->CoolingThreshold_ --;
  
  }

  if (this-> SystemSetting_ == 1 && this->HeatingThreshold_ > 40){
    this->HeatingThreshold_ --;
  }
}

//checks to see what the current system is (cool, off, or heat) and returns the value of the threshold for that given system
//returns -1 if system is off
int hvac::GetTemperature(){
  if (this->SystemSetting_ == -1){
    return this->CoolingThreshold_;
  } 

  else if (this->SystemSetting_ == 1){
    return this->HeatingThreshold_;
  }

  else if (this->SystemSetting_ == 0){
    return -1;
  }
}

//set the timers back to 0
void hvac::ResetActive(){
  this->AcTime_ = 0;
  this->HeatTime_ = 0;
}

//operate function that takes the conditions of a house (the current temperature and the volume of the house) and does the calculation of how uch the temperature will change over a 5 minute period
double hvac::Operate(double CurrentTemp, double AirVolume){

  if (this->SystemSetting_ == -1){
    if(CurrentTemp < CoolingThreshold_){
        CurrentTemp -= (this->CFM_ * 5 / AirVolume) / this->CoolingDifferential_;
        this->AcTime_ += 5;
      }
  
  }
  else if (this->SystemSetting_ == -1){
    if(CurrentTemp < HeatingThreshold_){
        CurrentTemp += (this->CFM_ * 5 / AirVolume) / this->HeatingDifferential_;
        this->HeatTime_ += 5;
      }
  
  }
  //If the system is off there should be no change
  else if (this->SystemSetting_ == 0){
    return CurrentTemp;
  }

  return CurrentTemp;
}