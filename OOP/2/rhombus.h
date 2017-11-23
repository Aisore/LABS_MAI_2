#ifndef RHOMBUS_H
#define RHOMBUS_H

#include <cstdlib>
#include <iostream>
#include "figure.h"

class Rhombus : public Figure {
public:
	Rhombus();
	Rhombus(std::istream &is);
	Rhombus(size_t len1, size_t len2);
	Rhombus(const Rhombus &orig);
	size_t Square() override;
	void Print() override;
	virtual ~Rhombus();
private:
	size_t len1;
	size_t len2;
};
#endif /* RHOMBUS_H */