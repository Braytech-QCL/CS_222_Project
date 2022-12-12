#include <iostream>
#include "Processor.h"

using namespace std;

void Processor::showInfo()
{
	boardDesign.showInfo();

	cout << "Base clock: " << baseClock << " MHz" << endl;
	cout << "Boost clock: " << boostClock << " MHz" << endl;
	cout << "Bus interface: " << busInterface << endl;
	cout << "Die size: " << dieSize << " mm^2" << endl;
	cout << "Number of transistors: " << transistors << " million" << endl;
	cout << "Proccessor Size: " << processorSize << " nm" << endl;

	cout << "Memory size: " << memorySize << " GB" << endl;
	cout << "Memory generation: GDDR" << memoryGen << endl;
	cout << "Memory Bus: " << memoryBus << " bit" << endl;
	cout << "Memory clock: " << memoryClock << " MHz" << endl;

	Processor::Processor(int baseC, int boostC, string busI,
		int dieS, int trans, int processorS, int memoryS,
		int memoryG, int memoryB, int memoryC, double slotW, int tdp, string output,
		string powerCon, double len, double wid,  double hei)
	{
		//Parameters
		boardDesign = BoardDesign(slotW, tdp, output, powerCon, len, wid, hei);  //TODO: call set info isntead

		baseClock = baseC;
		boostClock = boostC;
		busInterface = busI;
		dieSize = dieS;
		transistors = trans;
		processorSize = processorS;
		memorySize = memoryS;
		memoryGen = memoryG;
		memoryBus = memoryB;
		memoryClock = memoryC;

	}
}
