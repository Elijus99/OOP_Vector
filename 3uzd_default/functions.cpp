#include "functions.h"
#include "libraries.h"
#include "student.h"
#include <limits>
#include <random>
#include <algorithm>
#include <cfloat>
#include <fstream>

void ivedimas(string &GType, std::vector<StudentDerived> &ls, int &VSize, int &PSize, std::chrono::duration<double> &diff1)
{
	bool valid_input = false;
	int N;
	string choice;
	do {
		cout << "Ka norite naudoti galutinio balo skaiciavimui: vidurki ar mediana? (Iveskite 'v' arba 'm')" << endl;
		cin >> GType;
		if (GType == "v" || GType == "V" || GType == "M" || GType == "m") {
			break;
		}
		else {
			cout << "That input is invalid!" << endl;
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	} while (GType != "v" || GType != "V" || GType != "M" || GType != "m");
	string choose;
	int chooseN;
	do {
		cout << "Ar norite sugeneruoti studentu saraso faila ? (y/n)" << endl;
		cin >> choose;
		if (choose == "y" || choose == "Y" || choose == "N" || choose == "n") {
			break;
		}
		else {
			cout << "That input is invalid!" << endl;
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	} while (choose != "y" || choose != "Y" || choose != "N" || choose != "n");
	if (choose == "y" || choose == "Y") {
		do {
			cout << "Kiek irasu faile norite generuoti? " << endl;
			cin >> chooseN;
			if (!(valid_input = cin.good())) {
				cout << "That input is invalid!" << endl;
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
		} while (!valid_input);
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		string name = "StudentList" + std::to_string(chooseN) + ".txt";
		auto start = std::chrono::high_resolution_clock::now();
		generate(chooseN, name, GType, ls);
		auto end = std::chrono::high_resolution_clock::now();
		diff1 = end - start;
	}

	do {
		cout << "Ar norite nuskaityti duomenis is failo 'kursiokai.txt'? (y/n)" << endl;
		cin >> choice;
		if (choice == "y" || choice == "Y" || choice == "N" || choice == "n") {
			break;
		}
		else {
			cout << "That input is invalid!" << endl;
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	} while (choice != "y" || choice != "Y" || choice != "N" || choice != "n");
	string fileName = "kursiokai.txt";
	if (choice == "y" || choice == "Y") {
		InputFromFiles(fileName, VSize, PSize, ls, GType);
	}
	do {
		cout << "Keliu studentu duomenis norite irasyti?" << endl;
		cin >> N;
		if (!(valid_input = cin.good())) {
			cout << "That input is invalid!" << endl;
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	} while (!valid_input);
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	int egzaminas;
	int j, temp;
	int SIZE = ls.size();
	for (int i = SIZE; i < (N + SIZE); i++)
	{
		StudentDerived x(GType, cin);
		if (VSize < x.vardas().size()) { VSize = x.vardas().size(); }
		if (PSize < x.pavarde().size()) { PSize = x.pavarde().size(); }
		ls.push_back(x);
	}
}

void isvedimas(std::vector<StudentDerived> ls, std::vector<StudentDerived> vargs, int VSize, int PSize, string GType)
{
	cout << "Vardas";
	for (int i = 0; i < VSize; i++)
	{
		cout << " ";
	}
	cout << "Pavarde";
	for (int i = 0; i < PSize; i++)
	{
		cout << " ";
	}
	if (GType == "V" || GType == "v") {
		cout << "Galutinis (Vid.)" << endl;
	}
	else {
		cout << "Galutinis (Med.)" << endl;
	}
	for (int i = 0; i < PSize + VSize + 29; i++)
	{
		cout << "-";
	}
	cout << endl;
	for (int i = 0; i < ls.size(); i++)
	{
		cout << std::left << setw(VSize + 6) << ls[i].vardas()<< setw(PSize + 7) << ls[i].pavarde() << std::fixed << setprecision(2) << ls[i].galutinis() << endl;
	}
	for (int i = 0; i < vargs.size(); i++)
	{
		cout << std::left << setw(VSize + 6) << vargs[i].vardas() << setw(PSize + 7) << vargs[i].pavarde() << std::fixed << setprecision(2) << vargs[i].galutinis() << endl;
	}
}
bool exist(string fileName)
{
	std::ifstream infile(fileName);
	return infile.good();
};
double division(int a, int b)
{
	if (b == 0) {
		return 0;
	}
	return ((double)a / b);
}
int RandomNumber()
{
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution <int> gen(1, std::nextafter(10, DBL_MAX));
	return gen(mt);
}

void generate(int n, string OutputFileName, string GType, std::vector<StudentDerived> &ls)
{
	double egzaminas;
	StudentDerived student;
	std::ofstream out(OutputFileName);
	if (GType == "V" || GType == "v") {
		out << "Vardas          " << "Pavarde          " << "ND1   " << "ND2   " << "ND3   " << "ND4   " << "ND5   " << "Egzaminas   " << "Galutinis (Vid.)" << endl;
	}
	else {
		out << "Vardas          " << "Pavarde          " << "ND1   " << "ND2   " << "ND3   " << "ND4   " << "ND5   " << "Egzaminas   " << "Galutinis (Med.)" << endl;
	}
	out << endl;
	for (int i = 0; i < n; i++)
	{
		student.setVardas("Vardas" + std::to_string(i + 1));
		student.setPav("Pavarde" + std::to_string(i + 1));
		vector<int> nd;
		nd.clear();
		for (int j = 0; j < 5; j++)
		{
			nd.push_back(RandomNumber());
		}
		student.setNd(nd);
		egzaminas = RandomNumber();
		student.setEgz(egzaminas);
		student.setGal(student.galBalas(GType));
		ls.push_back(student);
		out << std::left << setw(16) << student.vardas() << std::left << setw(17) << student.pavarde() << std::left << setw(6) << nd[0] << std::left << setw(6) << nd[1] << std::left << setw(6) << nd[2] << std::left << setw(6) << nd[3] << std::left << setw(6) << nd[4] << std::left << setw(12) << std::defaultfloat << egzaminas << std::fixed << setprecision(2) << student.galutinis() << endl;
		student.clearNd();
	}
}
void SortToGroups(std::vector<StudentDerived> &ls, std::vector<StudentDerived> &vargs)
{
	for (int i = 0; i < ls.size(); i++)
	{
		if (ls[i].galutinis() < 5.0) {
			vargs.push_back(ls[i]);
		}
	}
	ls.erase(std::remove_if(
		ls.begin(), ls.end(),
		[](StudentDerived x) {
		return x.galutinis() < 5.0;
	}), ls.end());
}
void InputFromFiles(string fileName, int &VSize, int &PSize, std::vector<StudentDerived> &ls, string GType)
{
	if (exist(fileName)) {
		std::ifstream in(fileName);
		in.ignore(10000, '\n');
		StudentDerived X;
		string vard, pav;
		std::vector<int> nd;
		double egzaminas, gal;
		int n = 5, j = 0;
		int temp;
		while (in >> vard >> pav) {
			if (VSize < vard.size()) {
				VSize = vard.size();
			}
			if (PSize < pav.size()) {
				PSize = pav.size();
			}
			X.setVardas(vard);
			X.setPav(pav);
			nd.clear();
			for (int i = 0; i < n; i++)
			{
				in >> temp;
				nd.push_back(temp);
			}
			in >> egzaminas;
			X.setNd(nd);
			X.setEgz(egzaminas);
			X.setGal(X.galBalas(GType));
			ls.push_back(X);
		}
		cout << "---Duomenys nuskaityti!---" << endl;
	}
	else {
		cout << "---Failas 'kursiokai.txt' nebuvo rastas---" << endl;
	}
}
void OutputToFiles(std::vector<StudentDerived> &ls,std::vector<StudentDerived> vargs, string GType, int VSize, int PSize)
{
	std::ofstream outToK("kietiakai.txt");
	std::ofstream outToV("vargsiukai.txt");
	outToK << "Vardas";
	outToV << "Vardas";
	for (int i = 0; i < VSize; i++)
	{
		outToK << " ";
		outToV << " ";
	}
	outToK << "Pavarde";
	outToV << "Pavarde";
	for (int i = 0; i < PSize; i++)
	{
		outToK << " ";
		outToV << " ";
	}
	if (GType == "V" || GType == "v") {
		outToK << "Galutinis (Vid.)" << endl;
		outToV << "Galutinis (Vid.)" << endl;
	}
	else {
		outToK << "Galutinis (Med.)" << endl;
		outToV << "Galutinis (Med.)" << endl;
	}
	for (int i = 0; i < PSize + VSize + 29; i++)
	{
		outToK << "-";
		outToV << "-";
	}
	outToK << endl;
	outToV << endl;
	for (int i = 0; i < vargs.size(); i++)
	{
		outToV << std::left << setw(VSize + 6) << vargs[i].vardas() << setw(PSize + 7) << vargs[i].pavarde() << std::fixed << setprecision(2) << vargs[i].galutinis() << endl;
	}
	for (int i = 0; i < ls.size(); i++)
	{
		outToK << std::left << setw(VSize + 6) << ls[i].vardas() << setw(PSize + 7) << ls[i].pavarde() << std::fixed << setprecision(2) << ls[i].galutinis() << endl;
	}
}