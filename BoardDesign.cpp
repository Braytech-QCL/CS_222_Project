#include "BoardDesign.h"

//Show info for board design, have not added measurements
void BoardDesign::showInfo()
{
	cout << "Slot width: " << slotWidth << endl;
	cout << "Thermal design power: " << TDP << endl;
	cout << "Video outputs: " << videoOutputs << endl;
	cout << "Power Connectors: " << powerConnector << endl;
	cout << "Length: " << length << endl;
	cout << "Width: " << width << endl;
	cout << "Height: " << height << endl;
}


BoardDesign::BoardDesign(double slotW, int tdp, string output,
	string powerCon, double len, double wid, double hei)
{
	slotWidth = slotW;
	TDP = tdp;
	videoOutputs = output;
	powerConnector = powerCon;
	length = len;
	width = wid;
	height = hei;
}