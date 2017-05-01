#include <iostream>
#include <time.h>
using namespace std;
const int n = 20;
int tab[n];
void sortuj(int *tab, int n) {
	int k, j;
	for (int i = n - 2;i >= 0;--i) {
		k = i;
		j = i + 1;
		while (tab[k] > tab[j] && j<=n-1) {
			swap(tab[k], tab[j]);
			++k;
			++j;
		};
	};
}
int main() {
	srand(time(NULL));
	for (int i = 0;i < n;i++)
		tab[i] = rand() % 100 + 1;
	for (int i = 0;i < n;i++)
		cout << tab[i] << " ";
	cout << endl << endl;
	sortuj(tab, n);
	for (int i = 0;i < n;i++)
		cout << tab[i] << " ";
	cout << endl << endl;
	system("pause");
}