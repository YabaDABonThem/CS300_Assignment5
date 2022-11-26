/*
 * Vehicle.cpp
 *
 *  Created on: Nov 8, 2022
 *      Author: varikmp
 */
// Edited by ALlen Bao

#ifndef VEHICLE_CPP_
#define VEHICLE_CPP_

#include "Vehicle.h"

Vehicle::Vehicle(string name, int arrival_time, int processing_time, int start_time) {
	// Assign field values
	// We need to throw invalid argument exception when we input a negative number 
	// We have three different error mesaages for debugging purposes. 
	if (arrival_time < 0) {
		throw std::invalid_argument("the arrival time must be non-negative");
	} else if (processing_time < 0) {
		throw std::invalid_argument("the processing time must be non-negative");
	} else if (start_time < 0) {
		throw std::invalid_argument("the start time must be non-negative");
	}
	_name = name;
	_arrival_time = arrival_time;
	_processing_time = processing_time;
	_start_time = start_time;
}

string Vehicle::get_name() {
	return _name;
}

int Vehicle::get_arrival_time() {
	return _arrival_time;
}

int Vehicle::get_processing_time() {
	return _processing_time;
}

int Vehicle::get_start_time() {
	return _start_time;
}
void Vehicle::set_start_time(int start_time) {
	_start_time = start_time;
}

bool Vehicle::operator< (const Vehicle& rhs) {
	// compare their processing times when their arrival times are the same
	if (this->_arrival_time == rhs._arrival_time) {
		return this->_processing_time < rhs._processing_time;
	}
	return this->_arrival_time < rhs._arrival_time;
}

ostream &operator<<(ostream &out, const Vehicle &that)
{
	out << "vehicle: { ";
	out << "name: " << that._name << ", ";
	out << "arrival_time: " << that._arrival_time << ", ";
	out << "processing_time: " << that._processing_time << ", ";
	out << "start_time: " << that._start_time << " }";

	return out;
}

#endif /* VEHICLE_CPP_ */