#ifndef RHOMBUS_H
#define RHOMBUS_H

#include <cstdlib>
#include <iostream>
#include "figure.h"

class Rhombus : public Figure {
public:
	Rhombus(std::istream &is);
	Rhombus(double len1, double len2);
	Rhombus(const Rhombus &orig);
	double Square() override;
	void Print() override;
	virtual ~Rhombus();
private:
	double len1;
	double len2;
};
#endif /* RHOMBUS_H */