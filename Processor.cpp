#include <iostream>
#include "Processor.h"

using namespace std;

void Processor::showInfo()
{
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

}
