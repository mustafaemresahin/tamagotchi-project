#include <iostream>
#include <fstream>
using namespace std;
#ifndef PET_CPP
#define PET_CPP
class Pet {
public:
	Pet(string n) {
		name = n;
		happy = 50;
		fullness = 50;
		energy = 50;
	};
	virtual void play() = 0;
	virtual void eat() = 0;
	virtual void sleep() = 0;
	virtual void nextHour(int x) = 0;
	virtual void print() = 0;
	virtual void saveFile(string n) = 0;
	virtual void loadFile(string n) = 0;
	virtual void printStatus() = 0;
	virtual void printStatus(string message) = 0;
protected:
	string name;
	int happy;
	int fullness;
	int energy;
};
#endif