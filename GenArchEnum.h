/*
Stores the generations and architectures of the 3 popular GPUs

*/
#ifndef H_GenArchEnum
#define H_GenArchEnum

#pragma once
class GenArchEnum
{
public:
	void displayNvidiaGen();
	void displayNvidiaArch();

	void displayAMDGen();
	void displayAMDArch();

	void displayAMDGen();
	void displayAMDArch();
	

	//getters TODO

	
	

private:
	//Nvidia GPUs
	enum nvidiaGeneration{
		GeForce10series, GeForce16Series, GeForce20series, GeForce30Series, GeForce40series};
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
	//past Alchemist
	enum IntelGeneration {
		Arc_Alchemist, Arc_Battlemage, Arc_Celestial, Arc_Druid
	};
	enum IntelArchitecture {
		Xe_HPG, Xe2_HPG, Xe3_HPG, Xe_Next_Architecture
	};

};
	
#endif
