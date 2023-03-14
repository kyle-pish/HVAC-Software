#include <iostream>
#include <fstream>

void hot_day() {
  // Data structures for storage
	char buffer[256];
	double hot_day[288] = {};   // 288 5-minute periods in 24 hours

  // Load external temperatures into an array
	std::ifstream myfile ("temps1.txt");
	if (myfile.is_open())	{
    // read the initial comment line
		myfile.getline(buffer, 256);
    // read a numeric value from each subsequent line
		for (int i=0; i<sizeof(hot_day)/sizeof(double); i++) {
			myfile.getline(buffer, 256);
			hot_day[i] = atof(buffer);
		}
		myfile.close();
	}
	else {
		std::cout << "Unable to open file"; 
	}

  // Create a house, simulate it without an HVAC system.
  House test_house = House(2709, 0.05);
	test_house.SimulateDay(hot_day, 288);

  // Same house, but now with an HVAC system.
	House test_house2 = House(2709, 0.05, 20, 50, 1000);
	test_house2.GetHvac()->SetSystem(0);
  test_house2.GetHvac()->SetFan(0);
	while (test_house2.GetHvac()->GetTemperature() < 75) {
		test_house2.GetHvac()->IncreaseTemperature();
	}
  while (test_house2.GetHvac()->GetTemperature() > 75) {
		test_house2.GetHvac()->DecreaseTemperature();
	}
	//test_house2.SimulateDay(hot_day, 288);

}

void cold_day() {
  // Data structures for storage
	char buffer[256];
	double cold_day[288] = {};   // 288 5-minute periods in 24 hours

  // Load external temperatures into an array
	std::ifstream myfile ("temps2.txt");
	if (myfile.is_open())	{
    // read the initial comment line
		myfile.getline(buffer, 256);
    // read a numeric value from each subsequent line    
		for (int i=0; i<sizeof(cold_day)/sizeof(double); i++) {
			myfile.getline(buffer, 256);
			cold_day[i] = atof(buffer);
		}
		myfile.close();
	}
	else {
		std::cout << "Unable to open file";
	}

  // Create a house, simulate it without an HVAC system.
  House test_house = House(7999, 0.20);
	test_house.SimulateDay(cold_day, 288);

  // Same house, but now with an HVAC system.
	House test_house2 = House(7999, 0.10, 20, 50, 2000);
	test_house2.GetHvac()->SetFan(0);
	test_house2.GetHvac()->SetSystem(2);
	while (test_house2.GetHvac()->GetTemperature() < 70) {
		test_house2.GetHvac()->IncreaseTemperature();
	}
  while (test_house2.GetHvac()->GetTemperature() > 70) {
		test_house2.GetHvac()->DecreaseTemperature();
	}
	//test_house2.SimulateDay(cold_day, 288);
  	//std::cout << test_house2.GetHvac()->GetHeatActive() << std::endl;  // Heater should have been active for 1190 minutes.
}

int main() {
  // You can call one of the two following functions
  // to test your code against one of the two temperature
  // files (temps1.txt or temps2.txt) and with or without
  // an HVAC system simulated in the house (see comments
  // in above function definitions).

  hot_day();
  // cold_day();
}