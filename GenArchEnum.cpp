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
			brand += storing[i];
		}
		if (status == 1)
		{
			gen += storing[i];
		}
		if (status == 2)
		{
			status += storing[i];
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
		{
			nvidiaGeneration storingGen = gen;
		}
		case 2: //AMD Graphics Card
		{

		}
		case 3: //Intel Grahpics Card
		{

		}
		default:
			cout << "Error encoutred, could not find processor brand\n\n";

	}

}