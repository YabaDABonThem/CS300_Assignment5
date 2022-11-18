/*
 * ArrayList.h
 *
 *  Created on: Oct 1, 2022
 *      Author: varikmp
 */

#ifndef ARRAY_LIST_H_
#define ARRAY_LIST_H_

#include <iostream>
using namespace std;

template<class Type>
class ArrayList
{
	private:
		int _capacity = 20;
		int _size;
		Type *_data;
		void expand();

	public:
		ArrayList();
		~ArrayList();
		int size() const;
		void insert(const Type &item);
		bool removeAt(int index);
		Type& get(int index);
		void sort();
		void print();
};

#include "ArrayList.cpp"

#endif /* ARRAY_LIST_H_ */