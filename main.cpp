#include <iostream>
#include "GPU.h"

using namespace std;

int main()
{
	GPU test = GPU("RX 570", "2017 Q3", 354);
	test.showInfo();
}

void mainMenu()
{
	cout << "###---Welcome to GPU Database---###\n";
	cout << "Choose a option to contiune\n";

}