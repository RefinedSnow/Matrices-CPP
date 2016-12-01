#ifndef C_MATRICE
#define C_MATRICE

#include <iostream>
#include <ostream>

class Matrice{
	private:
	double **mat;
	int nbCol;
	int nbLin;

	public:
	Matrice();
	Matrice(int nbLin, int nbCol);
	Matrice(const Matrice & matrice);
	Matrice& operator=(const Matrice& matrice);
	~Matrice();

	void allocation();
	void deallocation();

	int getNbLin();
	int getNbCol();

	double& getCase(int numLine, int numCol); // en remplacement de l'opérateur []
	double* operator[](int numLine); //ne peux pas fonctionner en ami

	double determinant(int l, int c);
	Matrice transpose(const Matrice & matrice);

	friend Matrice operator+(Matrice & a, Matrice & b);
	friend Matrice operator-(Matrice & a, Matrice & b);
	friend Matrice operator-(Matrice & a);
	friend std::istream& operator>>(std::istream & istrm, Matrice & a);
	friend std::ostream& operator<<(std::ostream & ostrm, Matrice & a);
};

#endif