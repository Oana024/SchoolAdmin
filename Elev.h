#pragma once
#include <string>
#include <vector>

using namespace std;

class Elev {
	string nume;
	int note[10][10];//1 - mate / 2 - istorie / 3 - fizica / 4 - geografie
public:
	Elev(string nume_elev);
	string GetNume();
	void AdaugaNota(int mat, int nota);
	vector <int> AfisNote();
	void AfisareNote(int tip);
};
