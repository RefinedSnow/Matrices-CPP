#include <iostream>
#include <ostream>
#include "Matrice.h"

int main(){
	int lin=0, col=0;

	std::cout << std::endl << "Entrer le nombre de lignes de la matrice a" << std::endl;
	std::cin >> lin;
	std::cout << std::endl << "Entrer le nombre de colonnes de la matrice a" << std::endl;
	std::cin >> col;
	Matrice a(lin,col);

	std::cin >> a;
	std::cout << a;

	std::cout << std::endl << "Entrer le nombre de lignes de la matrice b" << std::endl;
	std::cin >> lin;
	std::cout << std::endl << "Entrer le nombre de colonnes de la matrice b" << std::endl;
	std::cin >> col;
	Matrice b(lin,col);

	std::cin >> b;
	std::cout << b;

	//Addition
	std::cout << std::endl << "A + B = " << std::endl;
	Matrice c(lin,col);
	c = a+b;
	std::cout << c;

	//Soustraction
	std::cout << std::endl << "A - B = " << std::endl;
	Matrice d(lin,col);
	d = a-b;
	std::cout << d;

	//negation
	std::cout << std::endl << "-A = " << std::endl;
	Matrice e(lin,col);
	e = -a;
	std::cout << e;

	//transposition
	std::cout << std::endl << "A^t = " << std::endl;
	Matrice f = a.transpose(a);
	std::cout << f;
	return 0;
}