#ifndef FIGURE_H
#define FIGURE_H

class Figure {
public:
	virtual size_t Square() = 0;
	virtual void Print() = 0;
	virtual ~Figure() {};
};


#endif /* FIGURE_H */