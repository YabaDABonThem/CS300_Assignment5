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
ArrayList<Type>::ArrayList()
{
	// TODO place your code in here

}

template<class Type>
ArrayList<Type>::~ArrayList()
{
	// TODO place your code in here

}

template<class Type>
int ArrayList<Type>::size() const
{
	// TODO place your code in here

	return 0;
}

template<class Type>
void ArrayList<Type>::expand()
{
	// TODO place your code in here

}

template<class Type>
void ArrayList<Type>::insert(const Type &item)
{
	// TODO place your code in here

}

template<class Type>
bool ArrayList<Type>::removeAt(int index)
{
	// TODO place your code in here

	return false;
}

template<class Type>
void ArrayList<Type>::sort()
{
	// TODO place your code in here

}

template<class Type>
Type& ArrayList<Type>::get(int index)
{
	// TODO place your code in here

	return 0;
}

template<class Type>
void ArrayList<Type>::print()
{
	for (int index = 0; index < _size; index++)
		cout << _data[index] << endl;
}

#endif /* ARRAY_LIST_CPP_ */