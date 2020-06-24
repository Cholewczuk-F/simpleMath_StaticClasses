#include <iostream>
#include <math.h>
#include <vector>
#include <time.h>
#include <cstdlib>
#include <algorithm>

using namespace std;

class operacje
{
public:
	static vector<int> liczby;

	static int maksimum()
	{
		int max;
		max = liczby[0];
		for (int i = 1; i < liczby.size(); i++)
		{
			if (max < liczby[i])
				max = liczby[i];
		}
		return max;
	}

	static int minimum()
	{
		int min;
		min = liczby[0];
		for (int i = 1; i < liczby.size(); i++)
		{
			if (min > liczby[i])
				min = liczby[i];
		}
		return min;
	}

	static double srednia()
	{
		double suma = 0;
		for (int i = 0; i < liczby.size(); i++)
		{
			suma += liczby[i];
		}
		suma = suma / liczby.size();
		return suma;
	}

	static double mediana()
	{
		int srodek;
		double i;
		sort(liczby.begin(), liczby.end());

		if (liczby.size() % 2 == 0)
		{
			srodek = liczby.size() / 2;
			i = ((double)(liczby[srodek - 1] + liczby[srodek]) / 2);
		}
		else
		{
			srodek = liczby.size() / 2;
			i = liczby[srodek];
		}

		for(int liczba : liczby)
		{
			cout << liczba << " ";
		}
		cout << endl;
		return i;
	}

	static pair<int, int> dominanta()
	{
		pair<int, int> dominanta;
		int wystapien = 0, wartosc = 0; 
		int spr, sprWyst;

		for (int i = 0; i < liczby.size(); i++)
		{
			spr = liczby[i];
			sprWyst = 0;
			for (int j = 0; j < liczby.size(); j++)
			{
				if (spr == liczby[j])
				{
					sprWyst++;
				}
			}
			if (sprWyst > wystapien)
			{
				wystapien = sprWyst;
				wartosc = spr;
			}
		}
		dominanta.first = wartosc; dominanta.second = wystapien;
		return dominanta;
	}

};


vector<int> operacje::liczby;
int main()
{
	srand(time(0));
	int i, x;
	cout << "Ile liczb: ";
	cin >> x;
	for (i = 0; i < x; i++)
	{
		operacje::liczby.push_back(rand() % 10);
		cout << operacje::liczby[i] << " ";
	}
	cout << endl;
	cout << "Najwieksza: " << operacje::maksimum() << endl << endl;
	cout << "Najmniejsza: " << operacje::minimum() << endl << endl;
	cout << "Srednia: " << operacje::srednia() << endl << endl;
	cout << "Mediana: " << operacje::mediana() << endl << endl;

	pair<int, int> dominanta = operacje::dominanta();
	cout << "Dominanta: Liczba " << dominanta.first << " wystepuje " << dominanta.second << " razy.\n\n";

	return 0;
}
