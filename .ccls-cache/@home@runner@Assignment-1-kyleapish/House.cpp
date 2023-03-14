#include <iostream>
#include "house.h"

house::House(int SquareFeet, double leakage){
  this->SquareFeet_ = SquareFeet;
  this->leakage_ = leakage;

}

house::house(int SquareFeet, double leakage, double cooling, double heating, int CFM){

  this->SquareFeet_ = SquareFeet;
  this->leakage_ = leakage;
  this->cooling_ = cooling;
  this->heating_ = heating;
  this->CFM_ = CFM;

}

house::~house(){

}


int house::GetSize(){
  return this->SquareFeet_;
}

double house::GetLeakage(){
  return this->leakage_;
}

double house::GetTempurature(){
  return this->internalTemp_;
}

int * house::GetHvac(){
  
}

void house::SimulateDay(double TempArr[], int ArrLength){
  
}