// FILE: AnimalNode.hpp
// AUTHOR: Rodrigo Suarez Almajano
// DATE: 04/16/2025
// PURPOSE: Definition for an AnimalNode for CS2's Project #3


#ifndef _ANIMALNODE_HPP
#define _ANIMALNODE_HPP

#include <iostream>
#include <string>
using namespace std;

#include "Animal.hpp"

class AnimalNode{

	private:
		Animal* _animal;		//Pointer to animal object
		AnimalNode* _next;	//Pointer to next animal object
		
	public: 
		AnimalNode(Animal pet) : _next(nullptr) {_animal = new Animal(); *_animal = pet;} //Constructor that creates a new node with a deep copy of animal
		
		Animal* animal() const {return _animal;}		//Getter of animal
		AnimalNode* next() const {return _next;}		//Getter of next animal
		
		
		Animal*& animal() {return _animal;}				//Reference getter of animal
		AnimalNode*& next() {return _next;}				//Reference getter of next animal
		
		
		friend ostream& operator<<(ostream &os, const AnimalNode &a);	//Friend function to overload the operator<<
};

#endif