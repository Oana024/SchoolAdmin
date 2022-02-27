#pragma once
#include "Clasa.h"
#include <vector>
using namespace std;

class Scoala {
	vector <Clasa> clase;
public:
	Scoala();
	void Restore();
	void AdaugaClasa();
	void StergeClasa();
	void AdaugaEleviInClasa();
	void StergeEleviDinClasa();
	void AfiseazaClase(int tip);
	void AfiseazaElevi(int tip);
	void AfiseazaNoteElev();
	void AdaugaNota();
	void MeniuAdmin();
	void MeniuProfesor(int tip);
	void MeniuSelectProfesor();
	void MeniuElev();
	int Close();
};
