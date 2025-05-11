// FILE: AnimalShelter.hpp
// AUTHOR: Rodrigo Suarez Almajano
// DATE: 04/16/2025
// PURPOSE: Definition for an AnimalShelter for CS2's Project #3


#ifndef _ANIMALSHELTER_HPP_
#define _ANIMALSHELTER_HPP_

#include <iostream>
#include <string>
#include "Animal.hpp"
#include "AnimalNode.hpp"
using namespace std;


class AnimalShelter{

	private:
		AnimalNode* _front; //Pointer to the front of the linked list
		
	public:
	
		AnimalShelter(); //Default constructor
		
		AnimalShelter(istream &is);	//Input constructor - Builds a shelter by reading animals from a string
		
		int size() const;		//Returns the number of animals in the shelter
		
		void adoptAll();		//Deletes all animals in the shelter
		
		Animal* find(const Animal &animal);		//Looks for an animal in the shelter
		
		AnimalShelter& adopt(const Animal &animal);		//Removes a given animal from the shelter
		
		Animal* celebrateBirthday(const Animal &animal);	//Finds a given animal and increments its age by 1
		

		
		AnimalShelter& operator=(const AnimalShelter &new_shelter); 					//Overload the operator=, copies the contents of a shelter to another
		AnimalShelter& operator+=(const Animal &new_animal);								//Overload the operator+= for another animal, adds the given animal to the shelter
		AnimalShelter& operator+=(const AnimalShelter &new_shelter);					//Overload the operator+= for another shelter, adds the given shelter to the shelter
		AnimalShelter operator+(const AnimalShelter &new_shelter) const;				//Overload the operator+, creates a new shelter with the addition of both animals
		friend istream& operator>>(istream &is, AnimalShelter &a);						//Overloaded '>>' for input 
		ostream& print(ostream &os) const;														//Prints the animals of the shelter

};

ostream& operator<<(ostream &os, const AnimalShelter &l);								//Overload the '<<' for output

#endif