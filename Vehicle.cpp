/*
 * Vehicle.cpp
 *
 *  Created on: Nov 8, 2022
 *      Author: varikmp
 */

#ifndef VEHICLE_CPP_
#define VEHICLE_CPP_

#include "Vehicle.h"

Vehicle::Vehicle(string name, int arrival_time, int processing_time, int start_time)
{
	// TODO place your code in here

}

string Vehicle::get_name()
{
	// TODO place your code in here

	return _name;
}

int Vehicle::get_arrival_time()
{
	// TODO place your code in here

	return _arrival_time;
}

int Vehicle::get_processing_time()
{
	// TODO place your code in here

	return _processing_time;
}

int Vehicle::get_start_time()
{
	// TODO place your code in here

	return _start_time;
}
void Vehicle::set_start_time(int start_time)
{
	// TODO place your code in here

	_start_time = start_time;
}

bool Vehicle::operator< (const Vehicle& rhs)
{
	// TODO place your code in here

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