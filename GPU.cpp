#include <iostream>
#include "GPU.h"

using namespace std;

void GPU::showInfo() 
{
	cout << "Graphics Card Name: " << name << endl;
	cout << "Release date: " << releaseDate << endl;
	cout << "Manufacter suggested retail price: " << MSRP << endl;

    processorVar.showInfo();

	
}


//Constructor
GPU::GPU(string _name = "", string _releaseDate = "", int _MSRP = 0, double slotW = 0, int tdp = 0, string output = "",
	string powerCon = "", double len = 0, double wid = 0, double hei = 0, int baseC = 0, int boostC = 0, string busI = "",
	int dieS = 0, int trans = 0, int processorS = 0, int memoryS = 0,
	int memoryG = 0, int memoryB = 0, int memoryC = 0,string b = "", string g = "", string a = "")
	{
        processorVar = Processor(baseC, boostC, busI, dieS, trans, processorS,memoryS,
                                memoryG,memoryB,memoryC, slotW, tdp, output, powerCon, len, wid, hei);
		name = _name;
		releaseDate = _releaseDate;
		MSRP = _MSRP;
		brand = b;
		generation = g;
		architecture = a;
	}
