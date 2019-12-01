#include <iostream>

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main()

{

	int min = 500;
	int max = -500;
	int liczba;
	int nr = 1;
	int nrliczby = 0;
	int nrliczby1 = 0;

	while (cin >> liczba)
	{
			if (liczba < min)
			{
				min = liczba;
				nrliczby = nr;
			}

			if (liczba >= max)
			{
				max = liczba;
				nrliczby1 = nr;
			}
			nr++;

	}
	cout << min << endl << nrliczby << endl << max << endl << nrliczby1;
	return 0;

}