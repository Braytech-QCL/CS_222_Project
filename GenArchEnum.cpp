#include <iostream>
#include "GenArchEnum.h"

using namespace std;


void GenArchEnum::displayNvidiaGen()
{

}

void GenArchEnum::displayNvidiaArch()
{

}

void GenArchEnum::displayAMDGen()
{

}
void GenArchEnum::displayAMDArch()
{

}

void GenArchEnum::displayIntelGen()
{

}
void GenArchEnum::displayIntelArch()
{

}

//example Nvida GeForce40series Ada
//changes all to lower case
GenArchEnum::GenArchEnum(string storing)
{
	string brand, gen, arch;


	int status = 0;

	for (int i = 0; i < storing.length(); i++)
	{
		if (storing[i] == ' ')
			status++;
		if (status == 0)
		{
			brand += tolower(storing[i]);
		}
		if (status == 1)
		{
			gen += tolower(storing[i]);
		}
		if (status == 2)
		{
			status += tolower(storing[i]);
		}

	}

	//reusing status var
	if (brand == "Nvidia")
		status = 1;
	else if (brand == "AMD")
		status = 2;
	else if (brand == "Intel")
		status = 3;
	else
		cout << "Error encorutred, problem reading brand name in GenArchEnum\n\n";



	//this is where the fun begins
	switch (status)
	{
		case 1: //Nvidia Graphics Card
		//GeForce10series, GeForce16Series, GeForce20series, GeForce30Series, GeForce40series
		//Pascal, Turing, Ampere, Ada
		{
			//Generation
			if (gen == "geforce10series")
			{
				nvidiaGeneration storingGen = GeForce16Series;
			}
			if (gen == "geforce20series")
			{
				nvidiaGeneration storingGen = GeForce20series;
			}
			if (gen == "geforce30Series")
			{
				nvidiaGeneration storingGen = GeForce30Series;
			}
			if (gen == "geforce40series")
			{
				nvidiaGeneration storingGen = GeForce40series;
			}

			//Arch
			if (arch == "pascal")
			{
				nvidiaArchitecture storingArch = Pascal;
			}
			if (arch == "turing")
			{
				nvidiaArchitecture storingArch = Turing;
			}
			if (arch == "ampere")
			{
				nvidiaArchitecture storingArch = Ampere;
			}
			if (arch == "ada")
			{
				nvidiaArchitecture storingArch = Ada;
			}
		}
		case 2: //AMD Graphics Card
		//RadeonRX400Series, RadeonRX500Series, RadeonRX5000Series, RadeonRX6000Series, RadeonRX7000Series
		//Graphics_Core_Next_4, AMD_Graphics_Core_Next_5, RDNA1, RDNA2, RDNA3
		{
			if (gen == "radeonrx400series")
			{
				AMDGeneration storingGen = RadeonRX400Series;
			}
			if (gen == "radeonrx400series")
			{
				AMDGeneration storingGen = RadeonRX400Series;
			}
			if (gen == "radeonrx400series")
			{
				AMDGeneration storingGen = RadeonRX400Series;
			}
			if (gen == "radeonrx400series")
			{
				AMDGeneration storingGen = RadeonRX400Series;
			}

		}
		case 3: //Intel Grahpics Card
		{

		}
		default:
			cout << "Error encoutred, could not find processor brand\n\n";

	}

}