/*
Catalogues the physical characteristics of a GPU board


*/
#pragma once
class BoardDesign
{
public:

private:
	double slotWidth //how many slots a gpu card takes up
	int TDP //Thermal Design Power, maximum power that a subsystem is allowed to draw for a ‘real world’ application
	string videoOutputs //the output ports on the GPU that can be connected to monitors, usally hdmi, display port, and vga/dvi
	string powerConnector //the power conenctor used to plug in the gpu. lower end gpus might not need one if tdp if under 75
	double length, width, height //the actual size measurements of the GPU
};

