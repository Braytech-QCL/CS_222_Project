/*
Main class that stores GPU information, used 3 parent classes to store specific information

*/
#ifndef H_GPU
#define H_GPU

#pragma once
#include "BoardDesign.h"
#include "Processor.h"

class GPU
{
public:
	//Show Info
	void showInfo();

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

	void setBrand(string b) 
	{
		brand = b;
	}

	void setGeneration(string g) 
	{
		generation = g;
	}

	void setArchitecture(string a) 
	{
		architecture = a;
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

	string getBrand() 
	{
		return brand;
	}

	string getGeneration() 
	{
		return generation;
	}

	string getArchitecture() 
	{
		return architecture;
	}




	GPU(string _name = "", int _releaseDate = "", int _MSRP = 0, double slotW = 0, int tdp = 0, string output = "",
		string powerCon = "", double len = 0, double wid = 0, double hei = 0, int baseC = 0, int boostC = 0, string busI = "",
		int dieS = 0, int trans = 0, int processorS = 0, int memoryS = 0,
		int memoryG = 0, int memoryB = 0, int memoryC = 0, string b = "", string g = "", string a = "");

private:
	string name; //name of GPU
	int releaseDate; //the date the GPU was released for purchase
	int MSRP; //the manufacturers suggested retail price
	string brand; //company that produced GPU, either Nvdia, AMD, or Intel
	string generation; //The generation of GPU
	string architecture; //architecture that GPU is build on

    Processor processorVar; //Calls processor info
};

#endif

/*
	//Nvidia GPUs
	enum nvidiaGeneration{
		GeForce10series, GeForce16Series, GeForce20series, GeForce30Series, GeForce40series };
	enum nvidiaArchitecture{Pascal, Turing, Ampere, Ada};

	//AMD GPUs
	enum AMDGeneration {
		RadeonRX400Series, RadeonRX500Series, RadeonRX5000Series, RadeonRX6000Series, RadeonRX7000Series
	};
	enum AMDArchitecture {
		Graphics_Core_Next_4, AMD_Graphics_Core_Next_5, RDNA1, RDNA2, RDNA3
	};

	//Intel GPUs
	//Intel is very new into the dedicated GPU market, they have not actually released anything
	//past Alchemist.
	enum IntelGeneration {
		Arc_Alchemist, Arc_Battlemage, Arc_Celestial, Arc_Druid
	};
	enum IntelArchitecture {
		Xe_HPG, Xe2_HPG, Xe3_HPG, Xe_Next_Architecture
*/