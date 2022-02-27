#pragma once
#include "Elev.h"
#include <vector>
using namespace std;

class Clasa {
	string nume;
	int numar_elevi = 0;
	vector <Elev> elevi;
public:
	Clasa(string nume_clasa);
	string GetNume();
	void AdaugaElev(string nume_elev);
	bool StergeElev(string nume_elev);
	void SalveazaElevi(string nume_clasa);
	void AfiseazaElevi();
	void AfiseazaEleviNote(int tip);
	void Sorteaza();
	void CitesteElevi(string nume_clasa);
	void AddNota(int materie, int nota, int nr);
	void AfiseazaElev(int nr);
};
