#include <iostream>
#include <iomanip>
int main()
{
	int k;
	std::cin >> k;
	int w;
	std::cin >> w;
	// =====================tworzenie trablicy==============================
	double* wector = new double[w];
	double** matrix = new double* [w];
	for (int i = 0; i < w; i++)
	{
		matrix[i] = new double[k];
	}
	for (int s = 0; s < w; s++)
	{
		for (int x = 0; x < k; x++)
		{
			std::cin >> matrix[s][x];
		}
		std::cin >> wector[s];
	}
	// =====================tranponowanie tablicy==============================
	double** trans_matrix = new double* [k];
	for (int i = 0; i < k; i++)
	{
		trans_matrix[i] = new double[w];
	}
	for (int y = 0; y < w; y++)
	{
		for (int x = 0; x < k; x++)
		{
			trans_matrix[x][y] = matrix[y][x];
		}
	}
	// =====================mnozenie macierzy przez wektor==============================
	double* multiplty_matrix = new double[k] {};
	for (int x = 0; x < k; x++)
	{
		for (int y = 0; y < w; y++)
		{
			multiplty_matrix[x] += trans_matrix[x][y] * wector[y];
		}
		//dodana biblioteka iomanip / setprecision 6 miejsc po przecinku
		std::cout <<std::setprecision(12)<< multiplty_matrix[x]<<" ";
	}
	// =====================lkasowanie tablic==============================
	for (int i = 0; i < w; i++)
	{
		delete[] matrix[i];
	}
	for (int i = 0; i < k; i++)
	{
		delete[] trans_matrix[i];
	}
	delete[] matrix;
	delete[] trans_matrix;
	delete[] multiplty_matrix;
	delete[] wector;

	return 0;
}