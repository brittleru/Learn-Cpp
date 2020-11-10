#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <numeric>
#include <math.h>


class Animal {
private: 
	std::string name;
	double height;
	double weight;

	static int numOfAnimals;

public:
	std::string GetName() {
		return name;
	}
	void SetName(std::string name) {
		this->name = name;
	}
	double GetHeight() {
		return height;
	}
	void SetHeight(double height) {
		this->height = height;
	}
	double GetWeight() {
		return weight;
	}
	void SetWeight(double weight) {
		this->weight = weight;
	}

	void SetAll(std::string, double, double);
	
	Animal(std::string, double, double);
	Animal();
	~Animal();

	static int GetNumOfAnimals() {
		return numOfAnimals;
	}

	void ToString();
};



int Animal::numOfAnimals = 0;
void Animal::SetAll(std::string name, double height, double weight) {
	this->name = name;
	this->weight = weight;
	this->height = height;
	Animal::numOfAnimals++;
}

Animal::Animal(std::string name, double height, double weight) {
	this->name = name;
	this->weight = weight;
	this->height = height;
	Animal::numOfAnimals++;
}

Animal::Animal() {
	this->name = "";
	this->weight = 0;
	this->height = 0;
	Animal::numOfAnimals++;
}

Animal::~Animal(){
	std::cout << "Animal " << this->name << " destroyed!\n";
}

void Animal::ToString() {
	std::cout << this->name << " is " << this->height 
			  << " cms tall and " << this->weight 
			  << " kgs in weight.\n";
}

class Dog : public Animal {
private:
	std::string sound = "Woof";
public: 
	void MakeSound() {
		std::cout << "The dog " << this->GetName() << " says "
			<< this->sound << "\n";
	}
	Dog(std::string, double, double, std::string);
	Dog() : Animal() {};
	void ToString();
};

Dog::Dog(std::string name, double height, double weight, std::string sound) :
	Animal(name, height, weight) {
	this->sound = sound;
}

void Dog::ToString() {
	std::cout << this->GetName() << " is " << this->GetHeight()
			  << " cms tall and " << this->GetWeight()
			  << " kgs in weight and says " << this->sound << ".\n";
}

int main() {
    
	Animal ani;
	ani.ToString();
	ani.SetHeight(64);
	ani.SetWeight(90);
	ani.SetName("Cat");
	ani.ToString();

	Animal tom("Tom", 36, 15);
	tom.ToString();

	Dog jessica("Jessica", 120, 30, "Wooooof");
	jessica.ToString();

	std::cout << "Number of animals: " << Animal::GetNumOfAnimals() << "\n";

	return 0;

}