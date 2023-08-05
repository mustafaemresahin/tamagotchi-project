#include <iostream>
#include "Pet.cpp"
using namespace std;
#ifndef CAT_CPP
#define CAT_CPP
class Cat : public Pet {
public:
	Cat(string n) : Pet(n) {

	};
	void play() override {
		if (happy + 30 < 100) {
			happy += 30;
		}
		else { happy = 100; }

		if (fullness - 5 > 0) {
			fullness -= 5;
		}
		else {
			fullness = 0;
		}

		if (energy - 5 > 0) {
			energy -= 5;
		}
		else { energy = 0; }
		printStatus(name + " loves playing with you!");
	};
	void eat() override {
		if (fullness + 30 < 100) {
			fullness += 30;
		}
		else {
			fullness = 100;
		}
		if (happy - 5 > 0) {
			happy -= 5;
		}
		else { happy = 0; }
		printStatus(name + " loves eating fish.");
	};
	void sleep() override {
		if (energy + 30 < 100) {
			energy += 30;
		}
		else {
			energy = 100;
		}
		if (fullness - 5 > 0) {
			fullness -= 5;
		}
		else {
			fullness = 0;
		}
		if (happy - 5 > 0) {
			happy -= 5;
		}
		else { happy = 0; }
		printStatus(name + " loves resting.");
	};
	void nextHour(int x) override {
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
		cout << "  ^  _ ^" << endl;
		cout << " (  o.o  )" << endl;
		cout << "   > ^ < " << endl;
	};
	void saveFile(string n) override {
		ofstream fout(n);
		fout << "Cat" << endl;
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
			cout << "Attention: " << name << " is bored and wants to jump with you." << endl;
		}
		if (fullness < 30) {
			cout << "Attention: " << name << " is hungry and wants to eat fish." << endl;
		}
		if (energy < 30) {
			cout << "Attention: " << name << " is sleepy and needs to take a nap." << endl;
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