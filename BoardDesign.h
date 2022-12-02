/*
Catalogues the physical characteristics of a GPU board


*/
#ifndef H_BoardDesign
#define H_BoardDesign

#pragma once
#include <iostream>

using namespace std;

class BoardDesign
{
public:
	//show info
	void showInfo();



	//getters and setters

	double getSlotWidth() {
		return slotWidth;
	}

	int getTDP() {
		return TDP;
	}

	string getVideoOutputs() {
		return videoOutputs;
	}

	string getPowerConnector() {
		return powerConnector;
	}

	double getLength() {
		return length;
	}

	double getWidth() {
		return width;
	}

	double getHeight() {
		return height;
	}

	//Setters

	void setSlotWidth(double slotW = 0) {
		slotWidth = slotW;
	}
	void setTDP(int tdp = 0) {
		TDP = tdp;
	}

	void setVideoOutputs(string output = "") {
		videoOutputs = output;
	}
	void setPowerConnector(string powerCon = "") {
		powerConnector = powerCon;
	}

	void setLength(double len = 0) {
		length = len;
	}

	void setWidth(double wid = 0) {
		width = wid;
	}

	void setHeight(double hei = 0) {
		height = hei;
	}

	BoardDesign(double slotW = 0, int tdp = 0, string output = "", 
                string powerCon = "", double len = 0, double wid = 0, double hei = 0);


private:
	double slotWidth; //how many slots a gpu card takes up
	int TDP; //Thermal Design Power, maximum power that a subsystem is allowed to draw for a ‘real world’ application
	string videoOutputs; //the output ports on the GPU that can be connected to monitors, usally hdmi, display port, and vga/dvi
	string powerConnector; //the power conenctor used to plug in the gpu. lower end gpus might not need one if tdp if under 75
	double length, width, height; //the actual size measurements of the GPU
};

#endif
