#ifndef HOUSE_H_
#define HOUSE_H_

class house{
  public:
    int GetSize();
    double GetLeakage();
    double GetTempurature();
    int * GetHvac();
    void SimulateDay(double TempArr[], int ArrLength);

  private:
    int SquareFeet_;
    double leakage_;
    double cooling_;
    double heating_;
    int CFM_;
    int internalTemp_;

};

#endif