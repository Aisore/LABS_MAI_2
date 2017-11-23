#ifndef HEXAGON_H
#define HEXAGON_H

#include <iostream>

#include "Figure.h"

class Hexagon : public Figure {
public:
	Hexagon();
	Hexagon(std::istream &is);
	Hexagon(int side);
	Hexagon(const Hexagon& orig);

	friend bool operator==(const Hexagon& fst, const Hexagon& snd);
	friend std::ostream& operator<<(std::ostream& os, const Hexagon& obj);
	friend std::istream& operator>>(std::istream& is, Hexagon& obj);
	Hexagon& operator=(const Hexagon& obj);

	double Square() override;
	void Print() override;

	virtual ~Hexagon();
private:
	int side;
};

#endif /*HEXAGON_H */