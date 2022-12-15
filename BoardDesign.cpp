#include "BoardDesign.h"

/**

	This function sets information for a BoardDesign object.

	Preconditions:
		'boardDesign' is a valid BoardDesign object
	Postconditions:
		the 'slotWidth', 'TDP', 'videoOutputs', 'powerConnector', 'length',
	'width', and 'height' fields of the BoardDesign object are set to the
	corresponding input arguments

	@param slotW The width of the slot that the Processor occupies on a motherboard
	@param tdp The thermal design power of the Processor
	@param output The video output options of the Processor
	@param powerCon The power connector type of the Processor
	@param len The length of the Processor
	@param wid The width of the Processor
	@param hei The height of the Processor
	*/
void BoardDesign::setInfo(double slotW, int tdp, string output,
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


/**

	This function prints information about a BoardDesign object to the console.

	Preconditions:
		'boardDesign' is a valid BoardDesign object
	Postconditions:
		the information of the BoardDesign object is printed to the console
*/
void BoardDesign::showInfo()
{
	cout << "###Board Design###" << endl;
	cout << "Slot width: " << slotWidth << endl;
	cout << "Thermal design power: " << TDP << endl;
	cout << "Video outputs: " << videoOutputs << endl;
	cout << "Power Connectors: " << powerConnector << endl;
	cout << "Length: " << length << endl;
	cout << "Width: " << width << endl;
	cout << "Height: " << height << endl;
}

/**

	This is the constructor for the BoardDesign class. It initializes a new
	BoardDesign object with the given information.
	Preconditions:
		'boardDesign' is a valid BoardDesign object
	Postconditions:
		a new BoardDesign object is created with the given information
	@param slotW The width of the slot that the Processor occupies on a motherboard
	@param tdp The thermal design power of the Processor
	@param output The video output options of the Processor
	@param powerCon The power connector type of the Processor
	@param len The length of the Processor
	@param wid The width of the Processor
	@param hei The height of the Processor
	*/
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