#include <iostream>
#include <cstdlib>
#include <string>
#include "figure.h"
#include "pentagon.h"
#include "hexagon.h"
#include "rhombus.h"


using namespace std;

int main(int argc, char** argv) {
	cout << "Figure: Rhombus (diagonal1, diagonal2)" << endl;
	Figure *ptr = new Rhombus(std::cin);
	ptr->Print();
	cout << "Square: " << ptr->Square() << std::endl;
	delete ptr;

	cout << "Figure: Pentagon (lenght)" << endl;
	ptr = new Pentagon(std::cin);
	ptr->Print();
	cout << "Square: " << ptr->Square() << std::endl;
	delete ptr;

	cout << "Figure: Hexagon (lenght)" << endl;
	ptr = new Hexagon(std::cin);
	ptr->Print();
	cout << "Square: " << ptr->Square() << std::endl;
	delete ptr;
	system("pause");
	return 0;
}