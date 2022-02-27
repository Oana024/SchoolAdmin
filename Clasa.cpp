#include "Clasa.h"
#include <iostream>
#include <fstream>
using namespace std;

Clasa::Clasa(string nume_clasa) {
	nume = nume_clasa;
	numar_elevi = 0;
}

void Clasa::AdaugaElev(string nume_elev) {
	Elev copil(nume_elev);
	elevi.push_back(copil);
}

string Clasa::GetNume() {
	return nume;
}

bool Clasa::StergeElev(string nume_elev) {
	int k = -1;
	for (unsigned int i = 0; i < elevi.size(); i++)
		if (elevi[i].GetNume() == nume_elev)
			k = i;

	if (k != -1) {
		elevi.erase(elevi.begin() + k);
		return true;
	}
	return false;
}

void Clasa::AfiseazaElevi() {
	for (unsigned int i = 0; i < elevi.size(); i++)
		cout << i + 1 << ". " << elevi[i].GetNume() << '\n';
}

void Clasa::AfiseazaEleviNote(int tip) {
	for (unsigned int i = 0; i < elevi.size(); i++) {
		cout << i + 1 << ". " << elevi[i].GetNume() << " ";
		elevi[i].AfisareNote(tip);
		cout << "\n\n";
	}
}

void Clasa::Sorteaza() {
	unsigned int i, j;

	for (i = 0; i < elevi.size(); i++)
		for (j = i + 1; j < elevi.size(); j++)
			if (elevi[i].GetNume() > elevi[j].GetNume())
				swap(elevi[i], elevi[j]);

}

void Clasa::CitesteElevi(string nume_clasa) {
	int i, j, nr, n;
	string nume_elev;

	ifstream addelevi("Clase\\" + nume_clasa + ".txt");
	while (addelevi >> nume_elev) {
		AdaugaElev(nume_elev);
		for (i = 1; i <= 4; i++) {
			addelevi >> nr;
			for (j = 0; j < nr; j++) {
				addelevi >> n;
				elevi[elevi.size() - 1].AdaugaNota(i, n);
			}
		}
	}
	Sorteaza();
	addelevi.close();
}

void Clasa::SalveazaElevi(string nume_clasa) {
	ofstream afis("Clase\\" + nume_clasa + ".txt");
	for (unsigned int i = 0; i < elevi.size(); i++) {
		afis << elevi[i].GetNume() << " ";
		vector <int> note = elevi[i].AfisNote();
		for (unsigned int j = 0; j < note.size(); j++)
			afis << note[j] << " ";
		afis << '\n';
	}
	afis.close();
}

void Clasa::AddNota(int materie, int nota,int nr) {
	elevi[nr - 1].AdaugaNota(materie, nota);
}

void Clasa::AfiseazaElev(int nr) {
	cout << "                                   ==================================================\n";
	cout <<"                                                        "<<elevi[nr - 1].GetNume() <<"    \n";
	cout << "                                   ==================================================\n\n";
	cout << "Note Mate: ";
	elevi[nr - 1].AfisareNote(1);

	cout << "\n\nNote Istorie: ";
	elevi[nr - 1].AfisareNote(2);

	cout << "\n\nNote Fizica: ";
	elevi[nr - 1].AfisareNote(3);

	cout << "\n\nNote Geografie: ";
	elevi[nr - 1].AfisareNote(4);
}