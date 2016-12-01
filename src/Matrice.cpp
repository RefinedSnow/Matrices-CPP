#include <iostream>
#include <ostream>

#include "Matrice.h"

Matrice::Matrice()
{
    nbCol = 0;
    nbLin = 0;
    std::cout << "+++Matrice() @" << this << std::endl;
}

Matrice::Matrice(int l, int c)
{
    nbLin = l;
    nbCol = c;
    allocation();
    std::cout << "+++Matrice(" << nbLin << "," << nbCol << ") @" << this << std::endl;
}

Matrice::Matrice(const Matrice& matrice) : Matrice(matrice.nbLin,matrice.nbCol)
{
    for (int i = 0; i < nbLin; i++) {
        memcpy(&mat[i], &matrice.mat[i], sizeof(double) * nbCol);
    }
    std::cout << "rrrMatrice(" << nbLin << "," << nbCol << ") @" << this << std::endl;
}
Matrice::~Matrice()
{
    deallocation();
    std::cout << "---Matrice(" << nbLin << "," << nbCol << ") @" << this << std::endl;
}

Matrice& Matrice::operator=(const Matrice &matrice)
{
    if(nbLin != matrice.nbLin || nbCol != matrice.nbCol)
    {
        //desalouer
        std::cout << "desaloc operateur affect" <<std::endl;
        deallocation();
        //realouer
        nbLin = matrice.nbLin;
        nbCol = matrice.nbCol;
        allocation();
    }
    //memcpy    
     for (int i = 0; i < nbLin; i++) {
        memcpy(&mat[i], &matrice.mat[i], sizeof(double) * nbCol);
    }
    std::cout << "affect : Matrice(" << nbLin << "," << nbCol << ") @" << this << std::endl;
	return *this;
}


int Matrice::getNbLin()
{
    return nbLin;
}
int Matrice::getNbCol()
{
    return nbCol;
}

void Matrice::allocation()
{
    mat = new double *[nbLin];
    for (int i = 0; i < nbLin; ++i)
    {
		mat[i] = new double[nbCol]();
    }

    std::cout << "alloc : Matrice[" << nbLin << "," << nbCol << "] @" << this << std::endl;
}
void Matrice::deallocation()
{
    for (int i = 0; i < nbLin; ++i)
    {
		delete[] mat[i];
    }
    delete[] mat;
    std::cout << "dealloc : Matrice[" << nbLin << "," << nbCol << "] @" << this << std::endl;
}

double& Matrice::getCase(int numLine, int numCol)
{
    if (numLine <= 0 || numCol <= 0)
    {
		throw "Debordement de taille : les indices commencent à 1";
    }
    else if (numLine >= nbLin + 1 || numCol >= nbCol + 1)
    {
		throw "Debordement  : les indices dépassent la taille de la matrice : > " + nbCol;
    }
    return mat[numLine - 1][numCol - 1];
}

Matrice operator+(Matrice & a, Matrice &b)
{
    if(a.nbCol != b.nbCol || a.nbLin != b.nbLin){
        throw "Tailles incompatibles";
    }
    
    Matrice sum(a.nbLin,a.nbCol);
    for (int i = 0; i < a.nbLin; ++i)
    {
		for (int j = 0; j < a.nbCol; ++j)
		{
			sum.mat[i][j] = a.mat[i][j] + b.mat[i][j];
		}
    }
	return sum;
}
Matrice operator-(Matrice & a, Matrice &b)
{
    if(a.nbCol != b.nbCol || a.nbLin != b.nbLin){
        throw "Tailles incompatibles";
    }

    Matrice sum(a.nbLin,a.nbCol);
    for (int i = 0; i < a.nbLin; ++i)
    {
		for (int j = 0; j < a.nbCol; ++j)
		{
			sum.mat[i][j] = a.mat[i][j] - b.mat[i][j];
		}
    }
	return sum;
}

Matrice operator-(Matrice & a)
{

    Matrice neg(a.nbLin,a.nbCol);
    for (int i = 0; i < a.nbLin; ++i)
    {
		for (int j = 0; j < a.nbCol; ++j)
		{
			neg.mat[i][j] = a.mat[i][j] * (-1);
		}
    }
	return neg;
}

double* Matrice::operator[](int numLine)
{
    if (numLine < 0 || numLine >= nbLin + 1)
    {
		throw "Debordement d'indices' : < 0 ou >= " + nbLin;
    }
    return mat[numLine];
}

//Remplissage de la matrice
std::istream & operator>>(std::istream &istrm, Matrice & a)
{
	std::cout << std::endl << "Entrer les coefficients de la matrice " << std::endl;
    for(int i = 1; i < a.getNbLin() +1; ++i)
       for(int j = 1; j < a.getNbCol() +1; ++j)
       {
           std::cout << "Entrer le coefficient a[" << i  << "][" << j  << "] : ";
           istrm >> a.getCase(i,j);
       }
	return istrm;
}
//Affichage de la matrice
std::ostream & operator<<(std::ostream &ostrm, Matrice & a)
{
	ostrm << std::endl << "Affichage de la matrice: " << std::endl;
    for(int i = 1; i < a.getNbLin() + 1; ++i)
	{
        for(int j = 1; j < a.getNbCol() + 1; ++j)
        {
            ostrm << a.getCase(i,j) << ",  ";
            if(j == a.getNbCol())
			{
                ostrm << std::endl;
			}
        }
	}
	return ostrm;
}

Matrice Matrice::transpose(const Matrice & matrice){
    Matrice t(matrice.nbCol,matrice.nbLin);
    for(int i = 0; i < matrice.nbLin; ++i)
    {
        for(int j = 0; j < matrice.nbCol; ++j)
        {
            t.mat[j][i]=matrice.mat[i][j];
        }
    }
    return t;
}

double Matrice::determinant(int l, int c){
    double det = 0;
    if(l != c){
        throw "Matrice non carrée";
    }

    return det;
}