#include <iostream>
#include <vector>

using namespace std;
float** create_empty_matrix(int m, int n);
void display_matrix(float** matrix, int m, int n);
void read_matrix(float** matrix, int m, int n);
float** transpone_matrix(float** matrix, int m, int n);
float** multiply_matrix(float** matrix_a, int m, int n, float** matrix_b);
void delete_matrix(float** matrix, int m);

int main() {
	//stworzenie macierzy
	int m, n;
	cin >> m;
	cin >> n;
	float** k = create_empty_matrix(m, n);
	//wyswietlanie macierzy X
	//display_matrix(k,m,n);
	//cout << endl;
	//uzupelnienie danymi macierz
	read_matrix(k, m, n);
	//display_matrix(k, m, n);
	//cout << endl;
	//transponowanie macierzy
	float** t = transpone_matrix(k, m, n);
	//wyswietlanie macierzy X^T
	//display_matrix(t, n, m);
	//cout << endl;
	//mnozenie macierzy
	float** mt = multiply_matrix(k, m, n, t);
	//wyswietlanie macierzy X^T*X
	display_matrix(mt, n, n);
	//usuniecie macierzy
	delete_matrix(k, m);
	delete_matrix(t, n);
	delete_matrix(mt, n);
	return 0;
}
float** create_empty_matrix(int m, int n) {
	float** A = new float* [m];
	for (int i = 0; i < m; i++)
	{
		A[i] = new float[n];
	}
	return A;
}
void display_matrix(float** matrix, int m, int n) {
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}
void read_matrix(float** matrix, int m, int n) {
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> matrix[i][j];
		}

	}
}
float** transpone_matrix(float** matrix, int m, int n) {
	float** t = create_empty_matrix(n, m);
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			t[j][i] = matrix[i][j];
		}
	}
	return t;
}
float** multiply_matrix(float** matrix_a, int m, int n, float** matrix_b) {
	float** mt = create_empty_matrix(n, n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			mt[i][j] = 0;
			for (int k = 0; k < m; k++)
			{
				mt[i][j] += matrix_a[k][i] * matrix_b[j][k];
			}
		}
	}
	return mt;
}
void delete_matrix(float** matrix, int m) {
	for (int i = 0; i < m; i++)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
}