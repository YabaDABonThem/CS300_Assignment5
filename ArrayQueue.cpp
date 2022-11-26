/*
 * ArrayList.cpp
 *
 *  Created on: Nov 18, 2022
 *      Author: Allen Bao
 */

#ifndef ARRAY_QUEUE_CPP_
#define ARRAY_QUEUE_CPP_

#include "ArrayQueue.h"

template<class Type>
ArrayQueue<Type>::ArrayQueue(int capacity) {
	// we need to create en empty ArrayQueue with the specified capacity
	_capacity = capacity;
	_size = 0;
	_data = new Type[_capacity];
	
}

template<class Type>
ArrayQueue<Type>::~ArrayQueue() {
	delete[] _data;
}

template<class Type>
bool ArrayQueue<Type>::is_full() const {
	return _size >= _capacity;
}

template<class Type>
bool ArrayQueue<Type>::is_empty() const {
	return _size <= 0;
}

template<class Type>
Type &ArrayQueue<Type>::peek() const {
	if (is_empty()) {
		throw std::logic_error("the queue is empty");
	}
	return _data[0];
}

template<class Type>
bool ArrayQueue<Type>::enqueue(const Type &item) {
	// place an item into the back of the queue
	// note that this queue shouldn't be able to grow 
	if (_size >= _capacity) {
		return false;
	}
	_data[_size] = item;
	++_size;
	return true;
}

template<class Type>
bool ArrayQueue<Type>::dequeue() {
	// remove the item from the front of the queue
	if (_size <= 0) {
		return false; // return false if it's empty
	}
	// this loop should cover the edge case of size = 1
	for (int i = 0; i < _size - 1; ++i) {
		_data[i] = _data[i+1];
	}
	--_size;
	
	return true;
}

template<class Type>
void ArrayQueue<Type>::print() {
	for (int index = 0; index < _size; index++)
		cout << _data[index] << endl;
}

#endif /* ARRAY_QUEUE_CPP_ */