#include <iostream>
#include <cmath>

#include "pentagon.h"

using namespace std;


Pentagon::Pentagon(double len) : lenght(len) {
	cout << "Pentagon created:" << endl;
	this->Print();
}
Pentagon::Pentagon(std::istream &is) {
	is >> this->lenght;
}
Pentagon::Pentagon(const Pentagon &orig) {
	this->lenght = orig.lenght;
	cout << "Pentagon copy created" << std::endl;
}
double Pentagon::Square() {
	return ((sqrt(5)*(sqrt(5+(2*sqrt(5)))))/4)*pow(this->lenght,2);
}
void Pentagon::Print() {
	cout << "Side lengths: " << endl;
	cout << "A: " << this->lenght << endl;
}
Pentagon::~Pentagon() {
	cout << "Pentagon deleted" << std::endl;
}