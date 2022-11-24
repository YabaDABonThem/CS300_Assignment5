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
	// read data from the file provided
	// each line of the file has a customer's info in this format:
	// <name> <arrival time> <processing time>
	constexpr char path[] = "C:\\Users\\allen\\Documents\\cs300\\HW5\\data.txt";
	ifstream file;
	file.open(path, ios::in);

	std::string vehicleInfo;
	// does start time start from zero?
	// arrival time supports zero so I assume it does
	int startTime = 0;
	while (std::getline(file, vehicleInfo))
	{
		std::istringstream iss(vehicleInfo);
		string name;
		int arrivalTime, processingTime;
		if (!(iss >> name >> arrivalTime >> processingTime)) { break; } // error

		vehicles_list->insert(*(new Vehicle(name, arrivalTime, processingTime, startTime)));

		++startTime;
	}
}

Simulation::~Simulation()
{
	// TODO place your code in here
	// we need to clear out the ArrayList and ArrayQueue
	vehicles_list->~ArrayList();
	vehicles_queue->~ArrayQueue();
}

bool Simulation::done()
{
	// The method returns true if there is no customer arriving or in queue
	// or at the drive-thru window, otherwise false
	return vehicles_list->size() == 0 && vehicles_queue->is_empty();
}

void Simulation::step()
{
	// 	The method increases the current time by one time unit
	++current_time;
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