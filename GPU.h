/*
Main class that stores GPU information, used 3 parent classes to store specific information

*/
#ifndef H_GPU
#define H_GPU

#pragma once
#include "BoardDesign.h"
#include "Processor.h"
#include "GenArchEnum.h"

class GPU
{
public:
	//Show Info
	void showInfo();

	//Getters and Setters and Constructors



	GPU(string _name = "", string _releaseDate = "", int _MSRP = 0);

private:
	string name; //name of GPU
	string releaseDate; //the date the GPU was released for purchase
	int MSRP; //the manufacturers suggested retail price
};

#endif