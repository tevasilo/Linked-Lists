// FILE: AnimalShelter.cpp
// AUTHOR: Rodrigo Suarez Almajano
// DATE: 04/16/2025
// PURPOSE: Implementation of an AnimalShelter for CS2's Project #3


#include "AnimalNode.hpp"
#include "AnimalShelter.hpp"
using namespace std;

AnimalShelter::AnimalShelter() : _front(nullptr) {}		//Default constructor

AnimalShelter::AnimalShelter(istream &is){				  //Input constructor
	_front = nullptr;		//Start with empty list
	
	Animal animal_input;
	is >> animal_input;
	
	while(is){		//Read animals from input to list
		AnimalNode *newNode = new AnimalNode(animal_input);	//Create a node for animal
		*this += animal_input;				//Add animal using operator+=
		newNode = newNode->next();			//Go to next animal
		is >> animal_input;					//Read next animal
	}
}

int AnimalShelter::size() const{				//Returns the number of animals in the shelter
	
	AnimalNode* position = _front;
	int capacity = 0;
	
	while(position != nullptr){
		capacity++;
		position = position->next();	
	}
	return capacity;
}

void AnimalShelter::adoptAll(){			//Deletes all animals from the shelter
	
	AnimalNode* position = _front;
	
	while(position != nullptr){
	
		AnimalNode* temp = position->next();
		delete position;
		position = temp;	
	}
	_front = nullptr;
}

Animal* AnimalShelter::find(const Animal &animal){			//Searches for an animal in the shelter
  AnimalNode* curr = _front;
  
  while(curr != nullptr) {

    if(*(curr->animal()) == animal)
      return (curr->animal());

    curr = curr->next();
  }
  return nullptr;
}

AnimalShelter& AnimalShelter::adopt(const Animal &animal){	//Removes given animal from the list
	
	Animal* animalToRemove = find(animal);
  
	// If the animal is not on the list
	if(animalToRemove == nullptr)
		return *this;
  
	//If the given animal is on the front of the list
	if(*(_front->animal()) == animal){
		_front = _front->next();
		return *this;
	}
  
	//For whatever else
	AnimalNode* prev = _front; 

	while (prev != nullptr && *(prev->next()->animal()) != animal){
		prev = prev->next(); 
	}
  
	prev->next() = prev->next()->next();  //Remove animal by going over it
	
	return *this;
}

Animal* AnimalShelter::celebrateBirthday(const Animal &animal){		//Finds an animal, and increments its age by 1

	bool found = false;
	Animal* animal_birthday = find(animal);
	if(find(animal)){
		found = true;
	}
	
	if(found){
		++*(animal_birthday);	
		return animal_birthday;	
	}
	else{
	return nullptr;
	}	
}

AnimalShelter& AnimalShelter::operator=(const AnimalShelter &new_shelter){		//Operator= to copy elements of shelters

	
	adoptAll();	//Cleans the current shelter
	AnimalNode* curr = new_shelter._front;
	
	while(curr != nullptr){
		*this += *(curr->animal()); //Copy each animal
		curr = curr->next();		
	}
	return *this;
}

AnimalShelter& AnimalShelter::operator+=(const Animal &new_animal){			//Adds an animal to the shelter, after checking that it is not already present

	bool repeated = false;
	AnimalNode* curr = _front;
	// Iterate over list
	while(curr != nullptr) {
		// Output current node
		if(*(curr->animal()) == new_animal){
			repeated = true;
		}
		curr = curr->next();
	}
	
	if(repeated){
		repeated = false;
		return *this;
	}
	else{
		if(_front == nullptr){
			AnimalNode* newNode = new AnimalNode(new_animal); 
  			newNode->next() = _front; 
  			_front = newNode; 
  			return *this;
		}
		else{
			AnimalNode* newNode = new AnimalNode(new_animal); 

  			AnimalNode *last = _front; 
  			while(last->next() != nullptr){ 
    			last = last->next(); 
			}

  			last->next() =  newNode;		
		}
	}					
	return *this;
}

AnimalShelter& AnimalShelter::operator+=(const AnimalShelter &new_shelter){		//Adds all animals from another shelter, if one of the animals is repeated, it is not added

	AnimalNode* curr = new_shelter._front;
	while(curr != nullptr){
		*this += *(curr->animal());
		curr = curr->next();	
	}
	return *this;
}

AnimalShelter AnimalShelter::operator+(const AnimalShelter &new_shelter) const{ //Adds two shelters and returns a shelter with all the animals in the two shelters
	
	AnimalShelter *addedShelter = new AnimalShelter();
	AnimalNode* curr = _front;
	while(curr != nullptr){
		
		*addedShelter += *(curr->animal());
		curr = curr->next();	
	}
	AnimalNode* curr2 = new_shelter._front;
	while(curr2 != nullptr){
		
		*addedShelter += *(curr2->animal());
		curr2 = curr2->next();	
	}
	return *addedShelter;
}	

istream& operator>>(istream &is, AnimalShelter &a){ //Operator>> to read into shelter
	Animal temporary;
	while(is >> temporary){
		a+=temporary;
	}
   return is;
}	


ostream& AnimalShelter::print(ostream &os) const{		//Prints all animals in the shelter
	AnimalNode* curr = _front;

	while(curr != nullptr) {
		os << *(curr->animal()) << endl;
 		curr = curr->next();
  }
	return os;
}


ostream& operator<<(ostream &os, const AnimalShelter &l){ //Operator<< to output shelter
	return l.print(os);
}