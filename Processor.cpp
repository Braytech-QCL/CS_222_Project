#include <iostream>
#include "Processor.h"

using namespace std;

void Processor::showInfo()
{
	cout << "Base clock: " << baseClock << endl;
	cout << "Boost clock: " << boostClock << endl;
	cout << "Bus interface: " << busInterface << endl;
	cout << "Die size: " << dieSize << endl;
	cout << "Number of transistors (in millions): " << transistors << endl;
	cout << "Proccessor Size: " << processorSize << endl;

	cout << "Memory size: " << memorySize << endl;
	cout << "Memory generation: " << memoryGen << endl;
	cout << "Memory Bus: " << memoryBus << endl;
	cout << "Memory clock: " << memoryClock << endl;

}
