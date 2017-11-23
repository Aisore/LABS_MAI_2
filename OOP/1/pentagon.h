#ifndef PENTAGON_H
#define PENTAGON_H

#include <cstdlib>
#include <iostream>
#include "figure.h"

class Pentagon : public Figure {
public:
	Pentagon(std::istream &is);
	Pentagon(double len_a);
	Pentagon(const Pentagon &orig);
	double Square() override;
	void Print() override;
	virtual ~Pentagon();
private:
	double lenght;
};
#endif /* PENTAGON_H */