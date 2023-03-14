//Kyle Pish
//02-25-22

#ifndef HVAC_H_
#define HVAC_H_

class hvac{
  public:

    //constructor
    hvac(double new_cooling, double new_heating, int new_CFM);
    //destructor
    ~hvac();

    //public methods (Getters and setters)
    void SetFan(int FanSetting);
    int GetFan();
    void SetSystem(int SystemSetting);
    int GetSystem();
    int GetTemperature();
    int GetAcActive();
    int GetHeatActive();

    //other public methods of hvac
    void IncreaseTemperature();
    void DecreaseTemperature();
    void ResetActive();
    double Operate(double CurrentTemp, double AirVolume);

  private:

    //private attributes of hvac class
    double CoolingDifferential_;
    double HeatingDifferential_;
    double CFM_;
    int FanSetting_;
    int SystemSetting_;
    int CoolingThreshold_;
    int HeatingThreshold_;
    int AcTime_;
    int HeatTime_;
    

};

#endif