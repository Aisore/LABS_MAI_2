#include <iostream>
#include <cmath>

#include "rhombus.h"

using namespace std;

Rhombus::Rhombus() : Rhombus(0, 0) {
}

Rhombus::Rhombus(size_t len1, size_t len2) : len1(len1), len2(len2) {
	this->Print();
}
Rhombus::Rhombus(std::istream &is) {
	is >> this->len1;
	is >> this->len2;
}
Rhombus::Rhombus(const Rhombus &orig) {
	this->len1 = orig.len1;
	this->len2 = orig.len2;
	//cout << "Rhombus copy created" << std::endl;
}
size_t Rhombus::Square() {
	return (this->len1 * this->len2)/2;
}
void Rhombus::Print() {
	cout << "(" << this->len1 << ","<< this->len2 << "," << this->Square() << ")"<< endl;
	
}
Rhombus::~Rhombus() {
	//cout << "Rhombus deleted" << std::endl;
}