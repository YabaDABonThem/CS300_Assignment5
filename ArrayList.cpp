/*
 * ArrayList.cpp
 *
 *  Created on: Nov 8, 2022
 *      Author: varikmp
 */

#ifndef ARRAY_LIST_CPP_
#define ARRAY_LIST_CPP_

#include "ArrayList.h"

template<class Type>
ArrayList<Type>::ArrayList() {
	// _capacity = 20; // this was initialized in the .h file
	_size = 0;
	_data = new Type[_capacity];
}

template<class Type>
ArrayList<Type>::~ArrayList() {
	delete[] _data;
}

template<class Type>
int ArrayList<Type>::size() const {
	return _size;
}

template<class Type>
void ArrayList<Type>::expand() {
	// Once the array is full we need to expand it.
	// We create an array that is twice as large, and copy all of the items over. 
	_capacity *= 2;
	Type *newData = new Type[_capacity];
	for (int i = 0; i < _data.length; ++i) {
		newData[i] = _data[i];
	}
	delete[] _data;
	_data = newData;
}

template<class Type>
void ArrayList<Type>::insert(const Type &item) {
	// we first need to check if the array is full
	if (_size >= _capacity) {
		this.expand();
	}
	// we add an item to the first avilable spot
	_data[_size] = item;
	// we can only increment the size after we do the operation
	// otherwise, there is a gap in our data. 
	++_size;
}

template<class Type>
bool ArrayList<Type>::removeAt(int index) {
	// We want the list to be in the same order afterwards, just with one less item.
	if (index >= _size || index < 0) {
		return false; // return false if an invalid index is provided
	}
	// this loop should cover the edge case of size = 1
	for (int i = index; i < _size - 1; ++i) {
		_data[i] = _data[i+1];
	}
	--_size;

	return true;
}

template<class Type>
void ArrayList<Type>::sort() {
	// If the size is 1 or smaller, then the list is already sorted
	if (size <= 1) {
		return;
	}
	// There are at least 2 items in the array
	// NOTE: we are required to use bubble sort
	for (int i = 0; i < _size; ++i) {
		for (int j = 0; j < _size - 1; ++j) {
			if (_data[j+1] < _data[j]) {
				// swap the two items
				Type temp = data[j];
				data[j+1] = data[j];
				data[j] = temp;	
			}
		}
	}
	/*
	for (int i = 0; i < _size - 1; ++i) {
		// find the smallest number in the remaining numbers
		int smallest = i;
		for (int j = i + 1; j > _size; ++j) {
			if (_data[j] < _data[smallest]) {
				smallest = j;
			}
		}
		// swap the smallest you found wiht 
		Type temp = data[smallest];
		data[i] = data[smallest];
		data[smallest] = temp;		
	}
	*/
	
}

template<class Type>
Type& ArrayList<Type>::get(int index) {
	return _data[index];
}

template<class Type>
void ArrayList<Type>::print() {
	for (int index = 0; index < _size; index++)
		cout << _data[index] << endl;
}

#endif /* ARRAY_LIST_CPP_ */