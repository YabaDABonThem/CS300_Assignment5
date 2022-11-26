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

Simulation::Simulation(string file_name) {
	// TODO place your code in here
	current_time = -1;
	vehicles_list = new ArrayList<Vehicle>();
	vehicles_queue = new ArrayQueue<Vehicle>();
	

	// read data from the file provided
	// each line of the file has a customer's info in this format:
	// <name> <arrival time> <processing time>
	ifstream file;
	file.open(file_name, ios::in);

	std::string vehicleInfo;

	while (std::getline(file, vehicleInfo)) {
		std::istringstream iss(vehicleInfo);
		string name;
		int arrivalTime, processingTime;
		if (!(iss >> name >> arrivalTime >> processingTime)) { break; } // error

		// we are using 0 as a placeholder for the start time
		vehicles_list->insert(Vehicle(name, arrivalTime, processingTime, 0));

	}

	// Sort the list to prioritize the criteria of arrival time and processing time.
	vehicles_list->sort();
}

Simulation::~Simulation() {
	// TODO place your code in here
	// we need to clear out the ArrayList and ArrayQueue
	delete vehicles_list;
	delete vehicles_queue;
}

bool Simulation::done() {
	// The method returns true if there is no customer arriving or in queue
	// or at the drive-thru window, otherwise false
	return vehicles_list->size() == 0 && vehicles_queue->is_empty() && 
	(current_time >= current_transaction.get_start_time() + current_transaction.get_processing_time());
}

void Simulation::step() {
	// The method increases the current time by one time unit
	++current_time;
	// put the customer(s) from the list into the queue at the right time (arrival time)
	// check the current time to see if it matches up with the customer's arrival time. 
	
	// this is to avoid wrong calculations with the temp size changing 
	int tempSize = vehicles_list->size();
	for (int i = 0; i < tempSize; ++i) {
		if (vehicles_list->get(0).get_arrival_time() == current_time) {
			vehicles_queue->enqueue(vehicles_list->get(0));
			vehicles_list->removeAt(0);
		} else {
			break;
		}
	}

	// removes the customer in the front of the queue
	// place the customer into the current transaction if no customer at the drive-thru window.
	// if the current time >= start time + processing time, then you can move onto the next item.  
	if (current_time >= current_transaction.get_start_time() + current_transaction.get_processing_time()) {
		
		if (vehicles_queue->is_empty()) {
			// clear the current transaction if no more items are being processed
			current_transaction = Vehicle();
		} else {
			// pop one from the queue if there are items remaining
			vehicles_queue->peek().set_start_time(current_time);
			current_transaction = vehicles_queue->peek();
			vehicles_queue->dequeue();
		} 
	}


}

void Simulation::print() {
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