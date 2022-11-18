/*
 * Vehicle.h
 *
 *  Created on: Nov 8, 2022
 *      Author: varikmp
 */

#ifndef VEHICLE_H_
#define VEHICLE_H_

#include <iostream>
#include <string>
using namespace std;

class Vehicle
{
    private:
		string _name;
        int _arrival_time;
        int _processing_time;
        int _start_time;

    public:
        Vehicle(string name = "", int arrival_time = 0, int processing_time = 0, int start_time = 0);
        string get_name();
        int get_arrival_time();
        int get_processing_time();
        int get_start_time();
        void set_start_time(int start_time);

        bool operator< (const Vehicle& rhs);
        friend ostream &operator<<(ostream &out, const Vehicle &that);
};

#endif /* VEHICLE_H_ */