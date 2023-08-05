#include <iostream>
#include "Pet.cpp"
using namespace std;
#ifndef BIRD_CPP
#define BIRD_CPP
class Bird : public Pet {
public:
	Bird(string n) : Pet(n) {

	};
	void play() override {
		if (happy + 50 < 100) {
			happy += 50;
		}
		else { happy = 100; }

		if (fullness - 20 > 0) {
			fullness -= 20;
		}
		else {
			fullness = 0;
		}

		if (energy - 20 > 0) {
			energy -= 20;
		}
		else { energy = 0; }
		printStatus(name + " loves singing with you!");
	};
	void eat() override {
		if (fullness + 50 < 100) {
			fullness += 50;
		}
		else {
			fullness = 100;
		}
		if (happy - 20 > 0) {
			happy -= 20;
		}
		else { happy = 0; }
		printStatus(name + " loves eating seeds.");
	};
	void sleep() override {
		if (energy + 50 < 100) {
			energy += 50;
		}
		else {
			energy = 100;
		}
		if (fullness - 20 > 0) {
			fullness -= 20;
		}
		else {
			fullness = 0;
		}
		if (happy - 20 > 0) {
			happy -= 20;
		}
		else { happy = 0; }
		printStatus(name + " loves napping.");
	};
	void nextHour(int x) override {
		x /= 2;
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
		    cout << "    \\ " << endl;
			cout << "    (o>" << endl;
			cout << "\\_//)" << endl;
			cout << " \_/_)" << endl;
			cout << "   _|_" << endl;
	};
	void saveFile(string n) override {
		ofstream fout(n);
		fout << "Bird" << endl;
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
			cout << "Attention: " << name << " is not happy and wants to sing with you." << endl;
		}
		if (fullness < 30) {
			cout << "Attention: " << name << " is starving and wants to eat nuts." << endl;
		}
		if (energy < 30) {
			cout << "Attention: " << name << " is tired and needs to some rest." << endl;
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
#endif