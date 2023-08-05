#include <iostream>
#include <fstream>
#include <string>
#include "Pet.cpp"
#include "Dog.cpp"
#include "Cat.cpp"
#include "Bird.cpp"
#include <time.h>
using namespace std;
void printMenu() {
	cout << "1- Load a pet" << endl;
	cout << "2- Create a pet" << endl;
	cout << "3- Exit" << endl;
	cout << "Please make a selection: ";
}
void printActionMenu(string name) {
	cout << "What do you want to do with " << name << "?" << endl;
	cout << "1- Play with " << name << "." << endl;
	cout << "2- Feed " << name << "." << endl;
	cout << "3- Make " << name << " go to sleep." << endl;
	cout << "4- Exit" << endl;
}
void printInvalidAction(string name) {
	cout << "Invalid Action" << endl;
	cout << "What do you want to do with " << name << "?" << endl;
	cout << "1- Play with " << name << "." << endl;
	cout << "2- Feed " << name << "." << endl;
	cout << "3- Make " << name << " go to sleep." << endl;
	cout << "4- Exit" << endl;
}
void printInvalid() {
	cout << "Invalid Selection" << endl;
	cout << "1- Load a pet" << endl;
	cout << "2- Create a pet" << endl;
	cout << "3- Exit" << endl;
	cout << "Please make a selection: ";
}
void Format(string &str) {
	string result = "";
	result += char(toupper(str[0]));
	for (int i = 1; i < str.length(); i++) {
		result += char(tolower(str[i]));
	}
	str = result;
}
int main() {
	printMenu();
	int selection, start, end, total;
	string type;
	string name = "";
	int action = 0;
	cin >> selection;
	while (selection != 1 && selection != 2 && selection != 3){
		printInvalid();
		cin >> selection;
	}
	while (selection != 3) {
		if (selection == 1) {
			cout << "What is your pet's type?" << endl;
			cin >> type;
			Format(type);
			cout << "What is your " << type << "'s name?" << endl;
			cin >> name;
			Format(name);
			ifstream fin(type + name + ".txt");
			while (!fin.is_open()) {
				int ans;
				cout << "There is no such pet." << endl;
				cout << "1 - Load another file" << endl;
				cout << "2 - Create this pet" << endl;
				cin >> ans;
				while (ans > 2 || ans < 1) {
					cout << "Invalid Action" << endl;
					cout << "There is no such pet." << endl;
					cout << "1 - Load another file" << endl;
					cout << "2 - Create this pet" << endl;
					cin >> ans;
				}
				if (ans == 1) {
					cout << "What is your pet's type?" << endl;
					cin >> type;
					Format(type);
					cout << "What is your " << type << "'s name?" << endl;
					cin >> name;
					Format(name);
					ifstream fin(type + name + ".txt");
				}
				else if(ans == 2) {
					cout << "New pet created" << endl;
					selection = 2;
					break;
				}
			}
			Pet* pet{};
			if (type == "Dog") {
				pet = new Dog(name);
			}
			else if (type == "Cat") {
				pet = new Cat(name);
			}
			else if(type == "Bird") {
				pet = new Bird(name);
			}
			fin >> type;
			Format(name);
			pet->loadFile(type + name + ".txt");
			pet->printStatus();
			while (action != 4) {
				printActionMenu(name);
				total = 0;
				start = time(NULL);
				cin >> action;
				end = time(NULL);
				total = end - start;
				pet->nextHour(total);
				string fileName = type + name + ".txt";
				while (action < 1 || action > 4) {
					printInvalidAction(name);
					total = 0;
					start = time(NULL);
					cin >> action;
					end = time(NULL);
					total = end - start;
					pet->nextHour(total);
				}
				if (action == 1) {
					pet->play();
					pet->saveFile(fileName);
				}
				else if (action == 2) {
					pet->eat();
					pet->saveFile(fileName);
				}
				else if (action == 3) {
					pet->sleep();
					pet->saveFile(fileName);
				}
			}
			action = 0;
			delete pet;
		}
		else if (selection == 2) {
			string type;
			cout << "What type of pet do you want?(Dog, Cat, or Bird)" << endl;
			cin >> type;
			Format(type);
			while (type != "Dog" && type != "Cat" && type != "Bird") {
				cout << "Invalid pet type." << endl;
				cout << "What type of pet do you want?(Dog, Cat, or Bird)" << endl;
				cin >> type;
				Format(type);
			}
			cout << "What is your " << type << "'s name?" << endl;
			cin >> name;
			Format(name);
			ifstream fin(type + name + ".txt");
			int x;
			if (fin.is_open()) {
				while (fin.is_open()) {
					cout << "Pet already exists." << endl;
					cout << "1 - Load the pet" << endl;
					cout << "2 - Create another one" << endl;
					cin >> x;
					while (x < 1 || x > 2) {
						cout << "Invalid Action" << endl;
						cout << "Pet already exists." << endl;
						cout << "1 - Load the pet" << endl;
						cout << "2 - Create another one" << endl;
						cin >> x;
					}
					if (x == 2) {
						cout << "What type of pet do you want?(Dog, Cat, or Bird)" << endl;
						cin >> type;
						Format(type);
						while (type != "Dog" && type != "Cat" && type != "Bird") {
							cout << "Invalid pet type." << endl;
							cout << "What type of pet do you want?(Dog, Cat, or Bird)" << endl;
							cin >> type;
							Format(type);
						}
						cout << "What is your " << type << "'s name?" << endl;
						cin >> name;
						Format(name);
						ifstream fin(type + name + ".txt");
					}
					else if(x == 1) {
						Pet* pet{};
						if (type == "Dog") {
							pet = new Dog(name);
						}
						else if (type == "Cat") {
							pet = new Cat(name);
						}
						else if (type == "Bird") {
							pet = new Bird(name);
						}
						pet->loadFile(type + name + ".txt");
						pet->printStatus();
						while (action != 4) {
							printActionMenu(name);
							total = 0;
							start = time(NULL);
							cin >> action;
							end = time(NULL);
							total = end - start;
							pet->nextHour(total);
							string fileName = type + name + ".txt";
							while (action < 1 || action > 4) {
								printInvalidAction(name);
								total = 0;
								start = time(NULL);
								cin >> action;
								end = time(NULL);
								total = end - start;
								pet->nextHour(total);
							}
							if (action == 1) {
								pet->play();
								pet->saveFile(fileName);
							}
							else if (action == 2) {
								pet->eat();
								pet->saveFile(fileName);
							}
							else if (action == 3) {
								pet->sleep();
								pet->saveFile(fileName);
							}
						}
						action = 0;
						delete pet;
						break;
					}
				}
			}
			else {
				Pet* pet{};
				if (type == "Dog") {
					pet = new Dog(name);
				}
				else if (type == "Cat") {
					pet = new Cat(name);
				}
				else if (type == "Bird") {
					pet = new Bird(name);
				}
				pet->loadFile(type + name + ".txt");
				pet->printStatus();
				while (action != 4) {
					printActionMenu(name);
					total = 0;
					start = time(NULL);
					cin >> action;
					end = time(NULL);
					total = end - start;
					pet->nextHour(total);
					string fileName = type + name + ".txt";
					while (action < 1 || action > 4) {
						printInvalidAction(name);
						total = 0;
						start = time(NULL);
						cin >> action;
						end = time(NULL);
						total = end - start;
						pet->nextHour(total);
					}
					if (action == 1) {
						pet->play();
						pet->saveFile(fileName);
					}
					else if (action == 2) {
						pet->eat();
						pet->saveFile(fileName);
					}
					else if (action == 3) {
						pet->sleep();
						pet->saveFile(fileName);
					}
				}
				delete pet;
				action = 0;
			}
		}
		printMenu();
		cin >> selection;
		while (selection != 1 && selection != 2 && selection != 3) {
			printInvalid();
			cin >> selection;
		}
	}
	cout << "Goodbye!" << endl;
	return 0;
}