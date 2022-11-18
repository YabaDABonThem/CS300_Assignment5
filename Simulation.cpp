/*
 * Pharmacy.cpp
 *
 *  Created on: Nov 8, 2022
 *      Author: varikmp
 */

#ifndef SIMULATION_CPP_
#define SIMULATION_CPP_

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Vehicle.h"
#include "ArrayList.h"
#include "ArrayQueue.h"
#include "Simulation.h"
using namespace std;

Simulation::Simulation(string file_name)
{
	// TODO place your code in here

}

Simulation::~Simulation()
{
	// TODO place your code in here

}

bool Simulation::done()
{
	// TODO place your code in here

	return true;
}

void Simulation::step()
{
	// TODO place your code in here

}

void Simulation::print()
{
	cout << "Time: " << current_time << endl;

	cout << "Queue:" << endl;
	if (!vehicles_queue->is_empty())
		vehicles_queue->print();
	else cout << "EMPTY" << endl;

	cout << "Transaction:" << endl;
	if (current_transaction.get_name() != "")
		cout << current_transaction << endl;
	else cout << "EMPTY" << endl;
}

#endif /* SIMULATION_CPP_ */