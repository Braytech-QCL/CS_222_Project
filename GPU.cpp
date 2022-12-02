#include <iostream>
#include "GPU.h"

using namespace std;

void GPU::showInfo() 
{
	cout << "Graphics Card Name: " << name << endl;
	cout << "Release date: " << releaseDate << endl;
	cout << "Manufacter suggested retail price: " << MSRP << endl;

	boardVar.showInfo();
    processorVar.showInfo();

	
}


//Constructor
GPU::GPU(string _name, string _releaseDate, int _MSRP, double slotW, int tdp, string output,
	string powerCon, double len, double wid, double hei, int baseC, int boostC, string busI,
         int dieS, int trans, int processorS, int memoryS,
               int memoryG, int memoryB, int memoryC)
	{
		boardVar = BoardDesign(slotW, tdp, output, powerCon, len, wid, hei);
        processorVar = Processor(baseC, boostC, busI, dieS, trans, processorS,memoryS,
                                memoryG,memoryB,memoryC);
		name = _name;
		releaseDate = _releaseDate;
		MSRP = _MSRP;
	}
