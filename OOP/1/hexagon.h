#ifndef HEXAGON_H
#define HEXAGON_H

#include <cstdlib>
#include <iostream>
#include "figure.h"


class Hexagon : public Figure {
public:
	Hexagon(std::istream &is);
	Hexagon(double len_a);
	Hexagon(const Hexagon &orig);
	double Square() override;
	void Print() override;
	virtual ~Hexagon();
private:
	double lenght;
};
#endif /* HEXAGON_H */