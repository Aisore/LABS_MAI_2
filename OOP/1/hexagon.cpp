#include <iostream>
#include <cmath>

#include "hexagon.h"

using namespace std;


Hexagon::Hexagon(double len_a) : lenght(len_a) {
	cout << "Hexagon created:" << endl;
	this->Print();
}
Hexagon::Hexagon(std::istream &is) {
	is >> this->lenght;
}
Hexagon::Hexagon(const Hexagon &orig) {
	this->lenght = orig.lenght;
	cout << "Hexagon copy created" << std::endl;
}
double Hexagon::Square() {
	return ((3*sqrt(3))/2)*pow(this->lenght,2);
}
void Hexagon::Print() {
	cout << "Side lengths: " << endl;
	cout << "A: " << this->lenght << endl;
}
Hexagon::~Hexagon() {
	cout << "Hexagon deleted" << std::endl;
}