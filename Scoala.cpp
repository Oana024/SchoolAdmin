#define _CRT_SECURE_NO_WARNINGS
#include "Scoala.h"
#include <iostream>
#include <fstream>
#include <Windows.h>
#include <conio.h>
#include <stdio.h>
using namespace std;

int materie = 0;

void Wait() {
	cout << "\n\nApasati ENTER pentru a continua...";

	while (1) {

		if (_kbhit()) {

			char ch = _getch();

			if (int(ch) == 13)
				break;
		}
	}
}

void Actualizeaza(vector<Clasa> Clasee) {
	ofstream AddClase("Clase.txt");
	for (unsigned int i = 0; i < Clasee.size(); i++) {
		AddClase << Clasee[i].GetNume() << '\n';

		Clasee[i].SalveazaElevi(Clasee[i].GetNume());
		
	}
	AddClase.close();
}

void Scoala::Restore() {
	ifstream RestoreClase("Clase.txt");
	string nume_clasa, nume_elev;

	while (RestoreClase >> nume_clasa) {
		Clasa clasa_noua(nume_clasa);
		clase.push_back(clasa_noua);

		clase[clase.size() - 1].CitesteElevi(nume_clasa);
	}
	RestoreClase.close();

	Actualizeaza(clase);
}

Scoala::Scoala() {
	Restore();
	int tip;
	cout << "                                          |-------------------------------|                          \n";
	cout << "                                          |          SCHOOL NAME          |                          \n";
	cout << "                                          |-------------------------------|                          \n";
	cout << "                                                                                                     \n";
	cout << "                                                                                                     \n";
	cout << "                                                                                                     \n";
	cout << "                                                                                                     \n";
	cout << "                                                    1. Admin                                         \n";
	cout << "                                                    2. Profesor                                      \n";
	cout << "                                                    3. Elev                                          \n";
	cout << "                                                                                                     \n";
	cout << "                                                                                                     \n";
	cout << "                                                                                                     \n";
	cout << "                                                                                                     \n";
	cout << "Selectati tipul de Acees: ";
	cin >> tip;
	if (tip == 1) {
		MeniuAdmin();
	}
	else
		if (tip == 2) {
			MeniuSelectProfesor();
		}
		else {
			MeniuElev();
		}
}

void Scoala::MeniuAdmin() {
	int x;
	system("CLS");
	cout << "                                          |-------------------------------|                        \n";
	cout << "                                          |              ADMIN            |                        \n";
	cout << "                                          |-------------------------------|                        \n";
	cout << "                                                                                                   \n";
	cout << "                                                                                                   \n";
	cout << "                                                                                                   \n";
	cout << "                                                                                                   \n";
	cout << "                                                                                                   \n";
	cout << "                                                     1. Adauga Clasa                               \n";
	cout << "                                                     2. Sterge Clasa                               \n";
	cout << "                                                     3. Adauga Elevi In Clasa                      \n";
	cout << "                                                     4. Sterge Elevi Din Clasa                     \n";
	cout << "                                                     5. Afiseaza Clase                             \n";
	cout << "                                                     6. Close                                      \n";
	cout << "                                                                                                   \n";
	cout << "                                                                                                   \n";
	cout << "                                                                                                   \n";
	cout << "Alegeti actiunea: ";
	cin >> x;
	cout << '\n';
	switch (x)
	{
	case 1:
		AdaugaClasa();
		break;
	case 2:
		StergeClasa();
		break;
	case 3:
		AdaugaEleviInClasa();
		break;
	case 4:
		StergeEleviDinClasa();
		break;
	case 5:
		AfiseazaClase(1);
	case 6:
		Close();
	}
}

void Scoala::MeniuSelectProfesor() {
	system("CLS");
	cout << "                                          |-------------------------------|                        \n";
	cout << "                                          |           PROFESOR            |                        \n";
	cout << "                                          |-------------------------------|                        \n";
	cout << "                                                                                                   \n";
	cout << "                                                                                                   \n";
	cout << "                                                                                                   \n";
	cout << "                                                                                                   \n";
	cout << "                                                                                                   \n";
	cout << "                                          Materie Predata:                                         \n";
	cout << "                                               1. Mate                                             \n";
	cout << "                                               2. Istorie                                          \n";
	cout << "                                               3. Fizica                                           \n";
	cout << "                                               4. Geografie                                        \n";
	cout << "                                                                                                   \n";
	cout << "                                                                                                   \n";
	cout << "                                                                                                   \n";
	cout << "Alegeti materie: ";
	cin >> materie;
	MeniuProfesor(materie);
}

void Scoala::MeniuProfesor(int tip) {
	int x;
	system("CLS");
	cout << "                                          |-------------------------------|                        \n";
	cout << "                                          |           PROFESOR            |                        \n";
	cout << "                                          |-------------------------------|                        \n";
	cout << "                                                                                                   \n";
	cout << "                                                                                                   \n";
	cout << "                                                                                                   \n";
	cout << "                                                                                                   \n";
	cout << "                                                                                                   \n";
	cout << "                                                     1. Afiseaza Clase                             \n";
	cout << "                                                     2. Afiseaza Elevi + Note                      \n";
	cout << "                                                     3. Adauga Nota                                \n";
	cout << "                                                     4. Close                                      \n";
	cout << "                                                                                                   \n";
	cout << "                                                                                                   \n";
	cout << "                                                                                                   \n";
	cout << "Alegeti actiunea: ";
	cin >> x;
	cout << '\n';
	switch (x)
	{
	case 1:
		AfiseazaClase(2);
		break;
	case 2:
		AfiseazaElevi(tip);
		break;
	case 3:
		AdaugaNota();
		break;
	case 4:
		Close();
	}
}

void Scoala::MeniuElev() {
	int x;
	system("CLS");
	cout << "                                          |-------------------------------|                        \n";
	cout << "                                          |              ELEV             |                        \n";
	cout << "                                          |-------------------------------|                        \n";
	cout << "                                                                                                   \n";
	cout << "                                                                                                   \n";
	cout << "                                                                                                   \n";
	cout << "                                                                                                   \n";
	cout << "                                                                                                   \n";
	cout << "                                                     1. Afiseaza Note                              \n";
	cout << "                                                     2. Close                                      \n";
	cout << "                                                                                                   \n";
	cout << "                                                                                                   \n";
	cout << "                                                                                                   \n";
	cout << "Alegeti actiunea: ";
	cin >> x;

	if (x == 1) {
		AfiseazaNoteElev();
	}
	else {
		Close();
	}
}

void Scoala::AdaugaClasa() {
	string nume_clasa;
	bool ok = true;

	system("CLS");
	cout << "                                          |-------------------------------|                        \n";
	cout << "                                          |          ADAUGA CLASA         |                        \n";
	cout << "                                          |-------------------------------|                        \n";
	cout << "                                                                                                   \n";
	cout << "                                                                                                   \n";
	cout << "                                                                                                   \n";
	cout << "                                                                                                   \n";
	cout << "Nume Clasa: ";
	cin >> nume_clasa;
	cout << '\n';

	for (unsigned int i = 0; i < clase.size(); i++)
		if (clase[i].GetNume() == nume_clasa) {
			cout << "Nu se poate adauga: Clasa exista deja" << '\n';
			ok = false;
		}

	if (ok) {

		Clasa clasa_noua(nume_clasa);
		clase.push_back(clasa_noua);

		Actualizeaza(clase);
		cout << "Clasa a fost adaugata cu succes\n";
	}

	Wait();
	MeniuAdmin();
}

void Scoala::StergeClasa() {
	string nume_clasa;
	bool ok = false;
	int c = -1;

	system("CLS");
	cout << "                                          |-------------------------------|                        \n";
	cout << "                                          |          STERGE CLASA         |                        \n";
	cout << "                                          |-------------------------------|                        \n";
	cout << "                                                                                                   \n";
	cout << "                                                                                                   \n";
	cout << "                                                                                                   \n";
	cout << "                                                                                                   \n";
	cout << "Introduceti numele clasei: ";
	cin >> nume_clasa;
	cout << '\n';

	for (unsigned int i = 0; i < clase.size(); i++)
		if (clase[i].GetNume() == nume_clasa) {
			ok = true;
			c = i;
		}

	if (ok == false) {
		cout << "Nu se poate sterge clasa: " << nume_clasa << " nu exista\n";
	}
	else {
		char* string2char = new char[nume_clasa.length() + 1];
		strcpy(string2char, nume_clasa.c_str());
		strcat(string2char, ".txt");

		char* fisier = new char[strlen(string2char) + 10];
		strcpy(fisier, "Clase\\");
		strcat(fisier, string2char);
		remove(fisier);
		clase.erase(clase.begin() + c);
		Actualizeaza(clase);
		cout << "Clasa a fost stearsa cu succes\n";
	}
	Wait();
	MeniuAdmin();
}

void Scoala::AdaugaEleviInClasa() {
	string nume_clasa, nume_elev;
	int k = -1, numar_elevi;
	system("CLS");
	cout << "                                          |-------------------------------|                        \n";
	cout << "                                          |          ADAUGA ELEVI         |                        \n";
	cout << "                                          |-------------------------------|                        \n";
	cout << "                                                                                                   \n";
	cout << "                                                                                                   \n";
	cout << "                                                                                                   \n";
	cout << "                                                                                                   \n";
	cout << "Introduceti numele clasei: ";
	cin >> nume_clasa;
	cout << '\n';

	for (unsigned int i = 0; i < clase.size(); i++)
		if (clase[i].GetNume() == nume_clasa)
			k = i;

	if (k == -1) {
		cout << "Nu exista clasa " << nume_clasa << '\n';
	}
	else {
		cout << "Introduceti numarul de elevi: ";
		cin >> numar_elevi;
		cout << '\n';

		ofstream AddElev("Clasa\\" + nume_clasa + ".txt");
		for (int i = 0; i < numar_elevi; i++) {
			cout << "Introduceti numele elevului: ";
			cin >> nume_elev;
			cout << '\n';
			clase[k].AdaugaElev(nume_elev);
			AddElev << nume_elev << '\n';
		}
		AddElev.close();
		clase[k].Sorteaza();
		clase[k].SalveazaElevi(clase[k].GetNume());
		cout << numar_elevi << " elevi au fost adaugati cu succes!\n";
	}
	
	Wait();
	MeniuAdmin();
}

void Scoala::StergeEleviDinClasa() {
	string nume_clasa, nume_elev;
	int k = -1;
	system("CLS");
	cout << "                                          |-------------------------------|                        \n";
	cout << "                                          |          STERGE ELEVI         |                        \n";
	cout << "                                          |-------------------------------|                        \n";
	cout << "                                                                                                   \n";
	cout << "                                                                                                   \n";
	cout << "                                                                                                   \n";
	cout << "                                                                                                   \n";
	cout << "Introduceti numele clasei: ";
	cin >> nume_clasa;
	cout << '\n';

	for (unsigned int i = 0; i < clase.size(); i++)
		if (clase[i].GetNume() == nume_clasa)
			k = i;

	if (k == -1) {
		cout << "Nu se poate executa actiunea: Nu exista clasa " << nume_clasa << '\n';
	}
	else {
		cout << "Introduceti numele elevului: ";
		cin >> nume_elev;
		cout << '\n';
		if (clase[k].StergeElev(nume_elev) == true)
			cout << "Elev sters cu succes\n";
		else
			cout << "Nu se poate sterge: Elevul " << nume_elev << " nu exista\n";
		clase[k].Sorteaza();
		Actualizeaza(clase);
	}

	Wait();
	MeniuAdmin();
}

void Scoala::AfiseazaClase(int tip) {
	system("CLS");
	cout << "Clase Disponibile: \n";
	for (unsigned int i = 0; i < clase.size(); i++) {
		cout << "\n-----" << clase[i].GetNume() << "-----\n\n";
		clase[i].AfiseazaElevi();
		cout << '\n';
	}
	
	Wait();

	if (tip == 1) {
		MeniuAdmin();
	}
	else {
		MeniuProfesor(materie);
	}
}

void Scoala::AfiseazaElevi(int tip) {
	system("CLS");
	string nume_clasa;
	int k = -1;
	cout << "Introduceti numele clasei: ";
	cin >> nume_clasa;
	cout << '\n';

	for (unsigned int i = 0; i < clase.size(); i++)
		if (clase[i].GetNume() == nume_clasa)
			k = i;

	if (k == -1) {
		cout << "Nu exista clasa " << nume_clasa << '\n';
	}
	else {
		cout << "Clasa " << nume_clasa << " + " << "note ";
		switch (tip)
		{
		case 1:
			cout << "mate:\n\n";
			break;
		case 2:
			cout << "istorie:\n\n";
			break;
		case 3:
			cout << "fizica:\n\n";
			break;
		case 4:
			cout << "geografie:\n\n";
			break;
		}

		clase[k].AfiseazaEleviNote(tip);
	}


	Wait();
	MeniuProfesor(materie);
}

void Scoala::AdaugaNota() {
	string nume_clasa;
	int k = -1, nr, nota;
	system("CLS");
	cout << "                                          |-------------------------------|                        \n";
	cout << "                                          |           ADAUGA NOTA         |                        \n";
	cout << "                                          |-------------------------------|                        \n";
	cout << "                                                                                                   \n";
	cout << "                                                                                                   \n";
	cout << "                                                                                                   \n";
	cout << "                                                                                                   \n";
	cout << "Nume Clasa: ";
	cin >> nume_clasa;
	cout << '\n';

	for (unsigned int i = 0; i < clase.size(); i++)
		if (clase[i].GetNume() == nume_clasa)
			k = i;

	if (k == -1) {
		cout << "Nu exista clasa " << nume_clasa << '\n';
	}
	else {
		cout << "Clasa " << nume_clasa << " + " << "note ";
		switch (materie)
		{
		case 1:
			cout << "mate:\n\n";
			break;
		case 2:
			cout << "istorie:\n\n";
			break;
		case 3:
			cout << "fizica:\n\n";
			break;
		case 4:
			cout << "geografie:\n\n";
			break;
		}

		clase[k].AfiseazaEleviNote(materie);

		cout << "\nAlege Elevul(numar): ";
		cin >> nr;
		cout << "\nNota: ";
		cin >> nota;

		clase[k].AddNota(materie, nota, nr);
		Actualizeaza(clase);
	}

	Wait();
	MeniuProfesor(materie);
}

int Scoala::Close() {
	system("CLS");
	return 0;
}

void Scoala::AfiseazaNoteElev() {
	string nume_clasa;
	int k = -1, nr;
	system("CLS");
	cout << "Introduceti numele clasei: ";
	cin >> nume_clasa;

	for (unsigned int i = 0; i < clase.size(); i++)
		if (clase[i].GetNume() == nume_clasa)
			k = i;

	if (k == -1) {
		cout << "Nu exista clasa " << nume_clasa << '\n';
	}
	else {
		cout << '\n';
		cout <<"======"<<nume_clasa << "======\n\n";
		clase[k].AfiseazaElevi();
		cout << "\nAlegeti elevul: ";
		cin >> nr;
		system("CLS");
		clase[k].AfiseazaElev(nr);
	}

	Wait();
	MeniuElev();
}