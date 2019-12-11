#include <iostream>

int part(int tab[], int right, int left);
void quicksort(int tab[], int right, int left);

int main() {
	int tab[100000];
	int zmienna, counter = 0;
	while (std::cin >> zmienna)
	{
		tab[counter] = zmienna;
		counter++;
	}
	quicksort(tab, 0, (counter - 1));
	for (int i = 0; i < counter; i++)
	{
		std::cout << tab[i] << " " << std::endl;
	}
	std::cout << "\n";

	return 0;
}
int part(int tab[], int right, int left)
{
	int x = tab[right];
	int i = right;
	int j = left, w;
	while (true)
	{
		while (tab[j] > x)
		{
			j--;
		}
		while (tab[i] < x)
		{
			i++;
		}
		if (i < j)
		{
			w = tab[i];
			tab[i] = tab[j];
			tab[j] = w;
			i++;
			j--;
		}
		else
		{
			return j;
		}
	}
}
void quicksort(int tab[], int right, int left)
{
	int a;
	if (right < left)
	{
		a = part(tab, right, left);
		quicksort(tab, right, a);
		quicksort(tab, a + 1, left);
	}
}