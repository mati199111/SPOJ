#include <iostream>
#include <iomanip>


using namespace std;
double** matrix(int wiersz, int kolumna)
{
	double** matrix;
	matrix = new double* [wiersz];
}
double** matrix_t(int wiersz, int kolumna)
{
	double** matrix;
	matrix = new double* [wiersz];
}

int main() {

	//double** macierz;
	double** transponowana;
	double* wektor;

	int ileKolumn;
	int ileWierszy;


	cin >> ileKolumn;
	cin >> ileWierszy;

	//macierz = new double* [ileWierszy];
	transponowana = new double* [ileKolumn];
	for (int i = 0; i < ileWierszy; ++i)
	{
		transponowana[i] = new double[ileKolumn];
	}
	for (int i = 0; i < ileKolumn; ++i)
	{
		transponowana[i] = new double[ileWierszy];
	}
	wektor = new double[ileWierszy] {};


	for (int i = 0; i < ileWierszy; i++) {
		for (int j = 0; j < ileKolumn; j++) {
			cin >> transponowana[i][j];
		}
		cin >> wektor[i];
	}
	for (int l = 0; l < ileKolumn; l++) {
		for (int i = 0; i < ileWierszy; i++) {
			transponowana[l][i] = transponowana[i][l];
		}
	}
	double* wyniki = new double[ileKolumn];
	double obliczenie = 0;
	for (int i = 0; i < ileKolumn; i++) {
		obliczenie = 0;
		for (int j = 0; j < ileWierszy; j++) {
			obliczenie += transponowana[i][j] * wektor[j];
		}
		wyniki[i] = obliczenie;
	}
	
	for (int m = 0; m < ileKolumn; m++) {
		cout<< wyniki[m];
		cout << " ";
	}
	
	return 0;
}