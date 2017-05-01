#include <iostream>
#include <time.h>
using namespace std;
const int n = 10;
int tab[n], p;

void bubble(int *tab, int n) {
	for (int j = n-1; j > 0; j--) {
		for (int i = 0; i < j; i++) {
			if (tab[i] > tab[i + 1] )
				swap(tab[i], tab[i + 1]);
		}
	}
}

void select(int *tab, int n) {
	int x;
	for (int j = n - 1; j > 0; j--) {
		x = j;
		for (int i = 0; i < j; i++) {
			if (tab[i] > tab[x])
				x = i;
		}
		swap(tab[x], tab[j]);
	}
}

void quick(int *tab, int lewy, int prawy)
{
	int i, j, piwot;
	i = (lewy + prawy) / 2;
	piwot = tab[i];
	tab[i] = tab[prawy];
	for (j = i = lewy; i < prawy; i++) 
	{
		if (tab[i] < piwot)
		{
			swap(tab[i], tab[j]);
			j++;
		}
	}
	tab[prawy] = tab[j];
	tab[j] = piwot;
	
	if (lewy < j - 1)
		quick(tab, lewy, j - 1);
	
	if (j + 1 < prawy)
		quick(tab, j + 1, prawy);
}

int gap(int x) {
	int a;
	if (x == 9 || x == 10)
		a = 11;
	else
		a = x / 1.3;
	return a;
	
}

void grzeb(int *tab, int n) {
	int q = gap(n);
	int i,j;

	while (q >= 1) {
		i = 0;
		while ((i + q) < n) {
			if (tab[i] > tab[i + q]) {
				j = i + q;
				swap(tab[i], tab[j]);
			};
			++i;
		}
		q = gap(q);
	}
}

int main() {
	for (int i = 0; i < n; i++)
		tab[i]=rand()%100;
	cout << "przed sortowaniem:\n";
	for (int i = 0; i < n; i++)
		cout << tab[i] << ", ";
	cout << "\n";

//sortuje babelkowo
/*	bubble(tab, n);
	cout << "po sortowaniu:\n";
	for (int i = 0; i < n; i++)
		cout << tab[i] << ", ";
	cout << "\n";
	*/

//sortuje przez wybor
/*	select(tab, n);
	cout << "po sortowaniu:\n";
	for (int i = 0; i < n; i++)
		cout << tab[i] << ", ";
	cout << "\n";
	*/

//soruje szybko
	quick(tab, 0, n-1);
	cout << "po sortowaniu:\n";
	for (int i = 0; i < n; i++)
		cout << tab[i] << ", ";
	cout << "\n";


//sortuje grzebieniowo
/*	grzeb(tab, n);
	cout << "po sortowaniu:\n";
	for (int i = 0; i < n; i++)
		cout << tab[i] << ", ";
	cout << "\n";
	*/
	system("pause");
}