// FILE: AnimalNode.cpp
// AUTHOR: Rodrigo Suarez Almajano
// DATE: 04/16/2025
// PURPOSE: Implementation of an AnimalNode for CS2's Project #3


#include <iostream>
#include <string>
#include "AnimalNode.hpp"
using namespace std;

ostream& operator<<(ostream& os, const AnimalNode &a){		//Overloaded operator<< to output the animal stored in specified node

	os << *a.animal();		//Dereferences the pointer to get the animal
	
	return os;		
}