#include <iostream>
#include "GPU.h"

using namespace std;

void GPU::showInfo()
{
	cout << "Graphics Card Name: " << name << endl;
	cout << "Release date: " << releaseDate << endl;
	cout << "Manufacter suggested retail price: " << MSRP << endl;
}


//Constructor
GPU::GPU(string _name, string _releaseDate, int _MSRP)
	{
		name = _name;
		releaseDate = _releaseDate;
		MSRP = _MSRP;
	}
