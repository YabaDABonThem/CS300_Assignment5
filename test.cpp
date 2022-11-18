/*
 * test.cpp
 *
 *  Created on: Nov 8, 2022
 *      Author: varikmp
 */

#include <iostream>
#include "Simulation.h"
using namespace std;

int main()
{
	Simulation *simulation = new Simulation("data.txt");
	while (!simulation->done())
	{
		simulation->step();
		simulation->print();
		cout << "====================================================" << endl;
	}

	delete simulation;
	return 0;
}