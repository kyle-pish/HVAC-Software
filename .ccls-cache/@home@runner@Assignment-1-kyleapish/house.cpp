//Kyle Pish
//02-25-22

#include <iostream>
#include "house.h"
#include "hvac.h"

//constructor for a house without an hvac system
//takes in the size of the house and the percent leakage
house::house(double SquareFeet, double leakage){
  this->SquareFeet_ = SquareFeet;
  this->leakage_ = leakage;

  //assign the starting temp for the house
  this->InternalTemp_ = 32.0;

  //there is no pointer to an hvac system
  this->hvacPTR_ = 0;

}

//constructor for a house with an hvac system
//takes in values for the size of the house, percent leakage, cooling differential, hheating differential, and the cfm
house::house(double SquareFeet, double leakage, double CoolingDiff, double HeatingDiff, int CFM){

  this->SquareFeet_ = SquareFeet;
  this->leakage_ = leakage;

  //create a pointer to the hvac
  //this will be allocated on the heap (use of "new" keyword)
  this->hvacPTR_ = new hvac(CoolingDiff, HeatingDiff, CFM);
    
  this->InternalTemp_ = 32.0;
}

//destructor for heap allocated data
house::~house(){

  //if there is a pointer to an hvac for this house obeject it will be deleted from the heap
  if (this->hvacPTR_ != 0){
    delete this->hvacPTR_;
  }
}

//returns the square footage of the house
int house::GetSize(){
  return this->SquareFeet_;
}

//returns the percentage of air leakage
double house::GetLeakage(){
  return this->leakage_;
}

//returns the current internal temperature of the house
double house::GetTemperature(){
  return this->InternalTemp_;
}

//returns pointer to the hvac of this house
hvac * house::GetHvac(){
  return this->hvacPTR_;
}


//simuklates the operation of the hvac system as well as the leakage for a 5 minute period
void house::SimulateDay(double TempArr[], int ArrLength){

  //loop over all the provided temperatures
  for (int i = 0; i < ArrLength; i++){

    //compares the internal and external temperatures and simulates the leakage if it is colder inside
    if (this->InternalTemp_ < TempArr[i]){
      if (TempArr[i] - InternalTemp_ < 0.01){
        this->InternalTemp_ = TempArr[i];
      }
        this->InternalTemp_ += 0.01;
    
        this->InternalTemp_ = this->InternalTemp_ + (TempArr[i] - this->InternalTemp_) * this->leakage_;

        //if this house has an hvac system it will then pass all the values through the operate method to calculate the new temperature inside the house
        if (this->hvacPTR_ != 0){
          this->InternalTemp_ = (*hvacPTR_).Operate(this->InternalTemp_, this->SquareFeet_ * 8);
        }

        //output the new temperature in the house
        std::cout << this->InternalTemp_ << std::endl;
      }

    //if the temperature inside the house is the same as outside then it will just reain the same
    else if(this->InternalTemp_ == TempArr[i]){
      std::cout << InternalTemp_ << std::endl;
    }

    //compares the internal and external temperatures and simulates leakage if it is colder outside
    else if (TempArr[i] < this->InternalTemp_){
      if (this->InternalTemp_ - TempArr[i] < 0.01){
        this->InternalTemp_ = TempArr[i];
      }

      this->InternalTemp_ -= 0.01;

      this->InternalTemp_ = this->InternalTemp_ + ((TempArr[i] - this->InternalTemp_) * this->leakage_);

        //if this house has an hvac system it will then pass all the values through the operate method to calculate the new temperature inside the house
      if (this->hvacPTR_ != 0){
        this->InternalTemp_ = (*hvacPTR_).Operate(this->InternalTemp_, this->SquareFeet_ * 8);
    }

    //return the new temperature inside the house
    std::cout << this->InternalTemp_ << std::endl;

    }
  }
  
}