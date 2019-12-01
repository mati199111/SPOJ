#include <iostream>

using namespace std;

int main()
{
	int x, minL, minP, z;
	cin >> x;
	z = minP = 1;
	minL = x;
	do {
		cin >> x;
		z++;
		if (x <= minL) {
			minL = x;
			minP = z;
		}
	} while (x != 0);
	cout << minL << endl;
	cout << minP << endl;

	return 0;
}
/*Wskazówka 1: zerknij na warunek sprawdzaj¹cy czy dana liczba jest mniejsza od Twojej zmiennej pomocniczej
Zmienna pomocnicza - zmienna, w której trzymasz najmniejsz¹ liczbê*/