#include <iostream>
#include "Pet.cpp"
#include <fstream>
using namespace std;
#ifndef DOG_CPP
#define DOG_CPP
class Dog : public Pet {
public:
	Dog(string n) : Pet(n) {

	};
	void play() override{
		if (happy + 40 < 100) {
			happy += 40;
		}
		else { happy = 100; }
		
		if (fullness - 10 > 0) {
			fullness -= 10;
		}
		else {
			fullness = 0;
		}
		
		if (energy - 10 > 0) {
			energy -= 10;
		}
		else { energy = 0; }
		printStatus(name + " loves running with you!");
	};
	void eat() override {
		if (fullness + 40 < 100) {
			fullness += 40;
		}
		else {
			fullness = 100;
		}
		if (happy - 10 > 0) {
			happy -= 10;
		}
		else { happy = 0; }
		printStatus(name + " loves eating beef.");
	};
	void sleep() override {
		if (energy + 40 < 100) {
			energy += 40;
		}
		else {
			energy = 100;
		}
		if (fullness - 10 > 0) {
			fullness -= 10;
		}
		else {
			fullness = 0;
		}
		if (happy - 10 > 0) {
			happy -= 10;
		}
		else { happy = 0; }
		printStatus(name + " loves sleeping.");
	};
	void nextHour(int x) override {
		x *= 2;
		if (happy - x > 0) {
			happy -= x;
		}
		else { happy = 0; }

		if (fullness - x > 0) {
			fullness -= x;
		}
		else {
			fullness = 0;
		}

		if (energy - x > 0) {
			energy -= x;
		}
		else { energy = 0; }
	};
	void print() override {
		cout << "  __      _" << endl;
		cout << "o'')}____//" << endl;
		cout << " `_/      )" << endl;
		cout << " (_(_ / -(_ /" << endl;
	};
	void saveFile(string n) override {
		ofstream fout(n);
		fout << "Dog" << endl;
		fout << name << endl;
		fout << happy << endl;
		fout << fullness << endl;
		fout << energy << endl;
	};
	void loadFile(string n) override {
		ifstream fin(n);
		string type;
		fin >> type;
		fin >> name;
		fin >> happy;
		fin >> fullness;
		fin >> energy;
	};
	void printStatus()override {
		print();
		cout << name << "'s Status: " << endl;
		cout << "Happines: " << happy << endl;
		cout << "Fullness: " << fullness << endl;
		cout << "Energy: " << energy << endl;
		if (happy < 40) {
			cout << "Attention: " << name << " is bored and wants to play with you." << endl;
		}
		if (fullness < 30) {
			cout << "Attention: " << name << " is hungry and wants to eat food." << endl;
		}
		if (energy < 30) {
			cout << "Attention: " << name << " is tired and needs some sleep." << endl;
		}
	}
	void printStatus(string message)override {
		print();
		cout << name << "'s Status: " << endl;
		cout << "Happines: " << happy << endl;
		cout << "Fullness: " << fullness << endl;
		cout << "Energy: " << energy << endl;
		cout << "Message: " << message << endl;
		if (happy < 40) {
			cout << "Attention: " << name << " is bored and wants to play with you." << endl;
		}
		if (fullness < 30) {
			cout << "Attention: " << name << " is hungry and wants to eat food." << endl;
		}
		if (energy < 30) {
			cout << "Attention: " << name << " is tired and needs some sleep." << endl;
		}
	}
};
#endif;