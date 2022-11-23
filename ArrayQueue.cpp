/*
 * ArrayList.cpp
 *
 *  Created on: Oct 30, 2022
 *      Author: varikmp
 */

#ifndef ARRAY_QUEUE_CPP_
#define ARRAY_QUEUE_CPP_

#include "ArrayQueue.h"

template<class Type>
ArrayQueue<Type>::ArrayQueue(int capacity)
{
	// we need to create en empty ArrayQueue with the specified capacity
	_capacity = capacity;
	_size = 0;
	// What do we do with the Type data?
	Type[] 
	
}

template<class Type>
ArrayQueue<Type>::~ArrayQueue()
{
	// TODO place your code in here

}

template<class Type>
bool ArrayQueue<Type>::is_full() const
{
	// TODO place your code in here
	return _size >= _capacity;
	// return false;
}

template<class Type>
bool ArrayQueue<Type>::is_empty() const
{
	// TODO place your code in here
	return _size <= 0;
	//return false;
}

template<class Type>
Type &ArrayQueue<Type>::peek() const
{
	// TODO place your code in here

	return 0;
}

template<class Type>
bool ArrayQueue<Type>::enqueue(const Type &item)
{
	// TODO place your code in here

	return false;
}

template<class Type>
bool ArrayQueue<Type>::dequeue()
{
	// TODO place your code in here

	return false;
}

template<class Type>
void ArrayQueue<Type>::print()
{
	for (int index = 0; index < _size; index++)
		cout << _data[index] << endl;
}

#endif /* ARRAY_QUEUE_CPP_ */