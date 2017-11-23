#include <iostream>
#include <cmath>

#include "Hexagon.h"

#define PI 3.14159265

Hexagon::Hexagon() : Hexagon(0) {
	//std::cout << "Hexagon created: default." << std::endl;
}

Hexagon::Hexagon(int a) : side(a) {
	//std::cout << "Hexagon created: " << side << std::endl;
}

Hexagon::Hexagon(std::istream &is) {
	std::cout << "Enter a side of the Hexagon:\n";
	is >> side;
	if (side < 0) {
		std::cerr << "Error: sides should be greater than 0." << std::endl;
	}
}

Hexagon::Hexagon(const Hexagon& orig) {
	//std::cout << "Hexagon copy created." << std::endl;
	side = orig.side;
}

double Hexagon::Square() {
	return (double)(5 * side * side / (4 * (double)tan(36 * (PI / 180))));
}

void Hexagon::Print() {
	std::cout << "Sides = " << side << std::endl;
}

Hexagon::~Hexagon() {
	//std::cout << "Hexagon deleted." << std::endl;
}

