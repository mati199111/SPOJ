#include <iostream>
#include <string>
#include <vector>

using namespace std;
int** create_empty_matrix(int m, int n);
int** create_realtion_matrix(vector <pair<int, int>> relation);
int get_max(vector <pair<int, int>> relation);
vector<pair<int, int>> read_relation();
bool feedback_r(int** matrix, int k);
bool reverse_r(int** matrix, int k);
bool symmetrical_r(int** matrix, int k);
bool antisymmetric_r(int** matrix, int k);
bool transitive_r(int** matrix, int k);
bool coherent_r(int** matrix, int k);
void display_matrix(int** matrix, int m, int n);

int main() {

	auto relation = read_relation();
	int** relation_matrix = create_realtion_matrix(relation);
	int max = get_max(relation);
	display_matrix(relation_matrix, max, max);

	

	return 0;
}
int** create_empty_matrix(int m, int n) {
	int** A = new int* [m];
	for (int i = 0; i < m; i++)
	{
		A[i] = new int[n];
	}
	return A;
}
vector <pair<int, int>> read_relation() {
	int a, b;
	vector <pair<int, int>> relation;
	while (cin >> a >> b)
	{
		pair<int, int> pair = make_pair(a, b);
		relation.push_back(pair);
	}
	return relation;
}
int** create_realtion_matrix(vector <pair<int, int>> relation) {
	int max = get_max(relation);
	int** r = create_empty_matrix(max, max);
	for (int i = 0; i < max; i++)
	{
		for (int j = 0; j < max; j++)
		{
			r[i][j] = 0;
		}
	}
	for (int i = 0; i < relation.size(); i++) //rozmiar tablicy relation
	{
		r[relation[i].first - 1][relation[i].second - 1] = 1; //tablica pierwszy elemnt [0]
	}
	return r;
}
int get_max(vector <pair<int, int>> relation) {
	int pom = 0;
	for (int i = 0; i < relation.size(); i++) //rozmiar tablicy relation
	{
		if (relation[i].first > pom)
		{
			pom = relation[i].first;
		}
		if (relation[i].second > pom)
		{
			pom = relation[i].second;
		}
	}
	return pom;
}
void display_matrix(int** matrix, int m, int n) {
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

bool feedback_r(int** matrix, int k) {

	for (int i = 0; i < k; i++)
	{
		if (matrix[i][i] == 0)
		{
			return false;
		}
	}

	return true;
}
bool reverse_r(int** matrix, int k) {
	for (int i = 0; i < k; i++)
	{
		if (matrix[i][i])
		{
			return false;
		}
	}

	return true;
}
bool symmetrical_r(int** matrix, int k) {

	for (int i = 0; i < k; i++)
	{
		for (int j = i + 1; j < k; j++)
		{
			if (matrix[i][j] != matrix[j][i])
			{
				return false;
			}
		}
	}
	return true;
}
bool antisymmetric_r(int** matrix, int k) {

	for (int i = 0; i < k - 1; i++)
	{
		for (int j = i + 1; j < k; j++)
		{
			if (i != j)
			{
				if (matrix[i][j] && matrix[j][i])
				{
					return false;
				}
			}
		}
	}
	return true;
}
bool transitive_r(int** matrix, int k) {
	int** matrix_2 = create_empty_matrix(k, k);

	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < k; j++)
		{
			matrix_2[i][j] = 0;
			for (int s = 0; s < k; s++)
			{
				matrix_2[i][j] = matrix_2[i][j] || (matrix[i][s] && matrix[s][j]);
			}
		}
	}
	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < k; j++)
		{
			if (matrix[i][j] < matrix_2[i][j])
			{
				return false;
			}
		}
	}
	return true;
}
bool coherent_r(int** matrix, int k) {
	for (int i = 0; i < k - 1; i++)
	{
		for (int j = i + 1; j < k; j++)
		{
			if (!(matrix[i][j] || matrix[j][i]))
			{
				return false;
			}
		}
	}
	return true;
}