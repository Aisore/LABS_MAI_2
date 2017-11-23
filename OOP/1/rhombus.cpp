#include <iostream>
#include <cmath>
#include "geometry.h"
#include "rhombus.h"

using namespace std;


Rhombus::Rhombus(Position in_pos, double len1, double len2) : pos(in_pos), len1(len1), len2(len2) {
	cout << "Rhombus created:" << endl;
	this->Print();
}
Rhombus::Rhombus(std::istream &is) {
	this->pos.Input(is);
	is >> this->len1;
	is >> this->len2;
}
Rhombus::Rhombus(const Rhombus &orig) {
	this->pos = orig.pos;
	this->len1 = orig.len1;
	this->len2 = orig.len2;
	cout << "Rhombus copy created" << std::endl;
}
double Rhombus::Square() {
	return (this->len1 * this->len2)/2;
}
void Rhombus::Print() {
	cout << "Position: ";
	this->pos.Print();
	cout << "Side lengths: " << endl;
	cout << "Diagonal A: " << this->len1 << endl;
	cout << "Diagonal B: " << this->len2 << endl;
	
}
Rhombus::~Rhombus() {
	cout << "Rhombus deleted" << std::endl;
}