#include <iostream>

void ponizej(int* tab, int index);
void powyzej(int* tab, int index);
int tab[10];
std::string sign;
int liczba;
int encounter = -1;

int main()
{
	while (std::cin >> sign)
	{
		if (sign == "+")
		{
			ponizej(tab, 10);
		}
		else if (sign == "-")
		{
			powyzej(tab, 10);
		}
	}
	return 0;
}
void ponizej(int* tab, int index)
{
	std::cin >> liczba;
	if (encounter < 9)
	{
		std::cout << ":)" << std::endl;
		encounter++;
		tab[encounter] = liczba;
	}
	else
	{
		std::cout << ":(" << std::endl;
	}
}

void powyzej(int* tab, int index)
{
	if (encounter < 0)
		std::cout << ":(" << std::endl;
	else
	{
		std::cout << tab[encounter] << std::endl;
		encounter--;
	}
}