#include <iostream>
#include "GPU.h"

using namespace std;

/**

	This function prints information about a GPU object to the console.
	Preconditions:
		'processorVar' is a valid Processor object
	Postconditions:
		the information of the GPU and its associated Processor object
	are printed to the console
	*/
void GPU::showInfo() {
	cout << "###General Info###" << endl;
	cout << "Graphics Card Name: " << name << endl;
	cout << "Graphics Card Manufacturer: " << brand << endl;
	cout << "Generation: " << generation << endl;
	cout << "Architecture: " << architecture << endl;
	cout << "Release date: " << releaseDate << endl;
	cout << "Manufacter suggested retail price: " << MSRP << endl;
	processorVar.showInfo();
}



/**
    This is the constructor for the GPU class. It initializes a new GPU object
    with the given information.

    Preconditions:
        'processorVar' is a valid Processor object

    Postconditions:
        a new GPU object is created with the given information

    @param _name The name of the GPU
    @param _releaseDate The release date of the GPU
    @param _MSRP The manufacturer's suggested retail price of the GPU
    @param slotW The width of the slot that the Processor occupies on a motherboard
    @param tdp The thermal design power of the Processor
    @param output The video output options of the Processor
    @param powerCon The power connector type of the Processor
    @param len The length of the Processor
    @param wid The width of the Processor
    @param hei The height of the Processor
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
    @param b The brand of the GPU
    @param g The generation of the GPU
    @param a The architecture of the GPU
    */
GPU::GPU(string _name, int _releaseDate, int _MSRP, double slotW, int tdp, string output,
	string powerCon, double len, double wid, double hei, int baseC, int boostC, string busI,
	int dieS, int trans, int processorS, int memoryS,
	int memoryG, int memoryB, int memoryC, string b, string g, string a)
{
	// Initialize the processorVar object with the given values
	processorVar = Processor(baseC, boostC, busI, dieS, trans, processorS, memoryS,
		memoryG, memoryB, memoryC, slotW, tdp, output, powerCon, len, wid, hei);

	// Assign values to the name, release date, and MSRP variables
	name = _name;
	releaseDate = _releaseDate;
	MSRP = _MSRP;

	// Assign values to the brand, generation, and architecture variables
	brand = b;
	generation = g;
	architecture = a;
}

