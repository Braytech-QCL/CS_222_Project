#include <iostream>
#include "Processor.h"

using namespace std;

/**
	This function sets information for a Processor object.

	Preconditions:
		'boardDesign' is a valid BoardDesign object

	Postconditions:
		the 'baseClock', 'boostClock', 'busInterface', 'dieSize', 'transistors',
	'processorSize', 'memorySize', 'memoryGen', 'memoryBus', and 'memoryClock'
	fields of the Processor object are set to the corresponding input arguments
		the 'slotW', 'tdp', 'output', 'powerCon', 'len', 'wid', and 'hei' fields
	of the 'boardDesign' object are set to the corresponding input arguments

	@param baseC The base clock speed of the Processor
	@param boostC The boost clock speed of the Processor
	@param busI The bus interface of the Processor
	@param dieS The die size of the Processor
	@param trans The number of transistors in the Processor
	@param processorS The size of the Processor
	@param memoryS The size of the memory in the Processor
	@param memoryG The generation of the memory in the Processor
	@param memoryB The memory bus width of the Processor
	@param memoryC The clock speed of the memory in the Processor
	@param slotW The width of the slot that the Processor occupies on a motherboard
	@param tdp The thermal design power of the Processor
	@param output The output power of the Processor
	@param powerCon The power connector type of the Processor
	@param len The length of the Processor
	@param wid The width of the Processor
	@param hei The height of the Processor
	*/
void Processor::setInfo(int baseC, int boostC, string busI,
	int dieS, int trans, int processorS, int memoryS,
	int memoryG, int memoryB, int memoryC, double slotW, int tdp, string output,
	string powerCon, double len, double wid, double hei)
{
	boardDesign.setInfo(slotW, tdp, output, powerCon, len, wid, hei);

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

/**

	This function prints information about a Processor object to the console.

	Preconditions:
		'boardDesign' is a valid BoardDesign object
	Postconditions:
		the information of the Processor and its associated BoardDesign object
	are printed to the console
	*/
void Processor::showInfo()
{
	boardDesign.showInfo();

	cout << "\n###Processor Info###" << endl;
	cout << "Base clock: " << baseClock << " MHz" << endl;
	cout << "Boost clock: " << boostClock << " MHz" << endl;
	cout << "Bus interface: " << busInterface << endl;
	cout << "Die size: " << dieSize << " mm^2" << endl;
	cout << "Number of transistors: " << transistors << " million" << endl;
	cout << "Proccessor Size: " << processorSize << " nm" << endl;

	cout << "\n###Memory Info###" << endl;
	cout << "Memory size: " << memorySize << " GB" << endl;
	cout << "Memory generation: GDDR" << memoryGen << endl;
	cout << "Memory Bus: " << memoryBus << " bit" << endl;
	cout << "Memory clock: " << memoryClock << " MHz" << endl;
	cout << endl;

}

