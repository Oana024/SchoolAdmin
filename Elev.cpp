#include "Elev.h"
#include <fstream>
#include <iostream>

using namespace std;

Elev::Elev(string nume_elev) {
	nume = nume_elev;
	for (int i = 0; i <= 4; i++)
		for(int j = 0; j <= 9; j++)
			note[i][j] = 0;
}

string Elev::GetNume() {
	return nume;
}

void Elev::AdaugaNota(int mat, int nota) {
	note[mat][0]++;
	note[mat][note[mat][0]] = nota;
}

vector<int> Elev::AfisNote() {
	vector<int> v;
	int i, j;
	for (i = 1; i <= 4; i++) {
		v.push_back(note[i][0]);
		for (j = 1; j <= note[i][0]; j++)
			v.push_back(note[i][j]);
	}
	return v;
}

void Elev::AfisareNote(int tip) {
	for (int i = 1; i <= note[tip][0]; i++)
		cout << note[tip][i] << " ";
}
