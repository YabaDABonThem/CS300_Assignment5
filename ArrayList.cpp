/*
 * ArrayList.cpp
 *
 *  Created on: Nov 18, 2022
 *      Author: Allen Bao
 */

#ifndef ARRAY_LIST_CPP_
#define ARRAY_LIST_CPP_

#include "ArrayList.h"

template<class Type>
ArrayList<Type>::ArrayList() {
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
	for (int i = 0; i < _size; ++i) {
		newData[i] = _data[i];
	}
	delete[] _data;
	_data = newData;
}

template<class Type>
void ArrayList<Type>::insert(const Type &item) {
	// we first need to check if the array is full
	if (_size >= _capacity) {
		this->expand();
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
	
	if (_size <= 1) {
		return;
	}
	// There are at least 2 items in the array
	// NOTE: we are required to use bubble sort
	for (int i = 0; i < _size; ++i) {
		for (int j = 0; j < _size - 1; ++j) {
			if (_data[j+1] < _data[j]) {
				// swap the two items
				Type temp = _data[j];
				_data[j] = _data[j+1];
				_data[j+1] = temp;	
			}
		}
	}
	
}

template<class Type>
Type& ArrayList<Type>::get(int index) {
	// gotta check if the index is valid or not
	if (index < 0 || index >= _size) {
		throw std::logic_error("the index is out of bound");
	}
	return _data[index];
}

template<class Type>
void ArrayList<Type>::print() {
	for (int index = 0; index < _size; index++)
		cout << _data[index] << endl;
}

#endif /* ARRAY_LIST_CPP_ */