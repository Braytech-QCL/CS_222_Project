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
	void showInfoGPU();

	//Setters
	void setName(string _name = "")
	{
		name = _name;
	}

	void setReleaseDate(string _releaseDate = "")
	{
		releaseDate = _releaseDate;
	}

	void setMSRP(int _MSRP = 0)
	{
		MSRP = _MSRP;
	}
	
	//Getters

	string getName()
	{
		return name;
	}

	string getReleaseDate()
	{
		return releaseDate;
	}

	int getMSRP()
	{
		return MSRP;
	}





	GPU(string _name = "", string _releaseDate = "", int _MSRP = 0, double slotW = 0, int tdp = 0, string output = "",
		string powerCon = "", double len = 0, double wid = 0, double hei = 0);

private:
	string name; //name of GPU
	string releaseDate; //the date the GPU was released for purchase
	int MSRP; //the manufacturers suggested retail price

	BoardDesign test; //used to call Board Design's show info. Yes it needs to be cleaned up...
};

#endif