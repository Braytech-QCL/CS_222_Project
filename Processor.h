/*
Catalogues the characteristics of the GPU processor and memory

*/
#ifndef H_Processor
#define H_Processor

#pragma once
#include <iostream>

using namespace std;

class Processor
{
public:
	//TODO: show info
	// 
	//Getters

	int getBaseClock() {
		return baseClock;
	}
	int getBoostClock() {
		return boostClock
	}
	string getBusInterface() {
		return busInterface;
	}
	int getDieSize() {
		return dieSize;
	}
	int getTransistors() {
		return transistors;
	}
	int getProcessorSize() {
		return processorSize;
	}
	int getMemorySize() {
		return memorySize;
	}
	int getMemoryGen() {
		return memoryGen;
	}
	int getMemoryBus() {
		return memoryBus;
	}
	int getmemoryClock() {
		return memoryClock;
	}

	//Setters
	void setbaseClock(int baseC = 0) {
		baseClock = baseC;
	}
	void setBoostClock(int boostC = 0) {
		boostClock = boostC;
	}
	void setBusInterface(string busI "") {
		busInterface = busI;
	}
	void setDieSize(int dieS = 0) {
		dieSize = diesS;
	}
	void setTransistors(int trans = 0) {
		transistors = trans;
	}
	void setProcessorSize(int processorS = 0) {
		processorSize = processorS;
	}
	void setMemorySize(int memoryS = 0) {
		memorySize = memoryS;
	}
	void setMemoryGen(int memoryG = 0) {
		memoryGen = memoryG;
	}
	void setMemoryBus(int memoryB = 0) {
		memoryBus = memoryB;
	}
	void setMemoryClock(int memoryC = 0) {
		memoryClock = memoryC;
	}
	
	Processor(int baseC = 0 , int boostC = 0, string busI = "",
		int dieS = 0, int trans = 0, int processorS = 0, int memoryS = 0,
		int memoryG = 0, int memoryB = 0, int memoryC = 0);
private:
	int baseClock; //(measured in GHz/gigahertz) GPU core clock speed on the is the speed at which your GPU processes data
	int boostClock; //(measured in GHz/gigahertz) highest processor clock can boost to with proper cooling
	string busInterface; //expansion bus standered, higher bus means more data can be transferred quickly and in larger volumes
	int dieSize; //(measured in mm^2) the square inchage of silicon the logic processor takes up
	int transistors; //(measured in millions) The amount of transistors on the GPU processor
	int processorSize; //(measured in nano meters) The smaller the distance between transistors in the processor (in nm), the more transistors can fit in a given space. 
		//Lower is better: consumes less power, consumes less heat, the battery lasts longer, the processing speed is greater

	//MEMORY
	int memorySize; //(measured in GB) 
	int memoryGen; //(preceded by GDDR#)
	int memoryBus; //(measured in bit)
	int memoryClock; //(measured in GHz) speed at which the graphics card can read and write data from its memory
};

#endif
