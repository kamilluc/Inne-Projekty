#include<iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

void wypelnij(int *T1,int *T2, int n)
{
	srand(time(NULL));
	for (int i = 0; i < n; i++)
	{
		T1[i] = rand() % 90 + 10;
		T2[i] = T1[i];
	}
}
void wypisz(int *T, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << T[i] << " | ";
	}
	cout << endl;
}

void heapify(int *T, int n, int heapsize, int &zamiana, int &porownanie)
{
	int l = 2 * n;
	int r = 2 * n + 1;
	int bigest;
	porownanie++;
	if (l <= heapsize && T[n - 1] < T[l - 1])
	{
		bigest = l;
	}
	else
	{
		bigest = n;
	}
	porownanie++;
	if (r <= heapsize && T[r - 1] > T[bigest - 1])
	{
		bigest = r;
	}
	porownanie++;
	if (bigest != n)
	{
		zamiana++;
		swap(T[n - 1], T[bigest - 1]);
		heapify(T, bigest, heapsize,zamiana,porownanie);
	}
}

void buildHeap(int *T, int heapsize, int &zamiana, int &porownanie)
{
	for (int i = heapsize / 2; i > 0; i--)
	{
		heapify(T, i, heapsize,zamiana,porownanie);
	}
}
void heapSort(int *T, int size, int &zamiana, int &porownanie)
{
	int heapsize = size;
	buildHeap(T, heapsize,zamiana,porownanie);
	while (heapsize > 1)
	{	zamiana++;
		swap(T[0], T[heapsize-1]);
		heapsize--;
		heapify(T, 1, heapsize,zamiana,porownanie);
	}
}
void bSort(int *T, int n, int &zamiana, int &porownanie)
{	int z;
	bool czy = true;
	for(int i = 0;i < n && czy;i++)
	{	czy = false;
		for(int j = 1;j < n;j++)
		{
			porownanie++;
			if(T[j-1] > T[j])
			{
				zamiana++;
				z = T[j-1];
				T[j-1] = T[j];
				T[j] = z;
				czy = true;
			}
		}
	}
}





int main()
{
	int Bp = 0;
	int Bz = 0;
	int Cp = 0;
	int Cz = 0;

	int n = 10;
	for(;n<10000;n=n*10)
	{
	Bp = 0;
	Bz = 0;
	Cp = 0;
	Cz = 0;
	int *T1 = new int[n];
	int *T2 = new int[n];
	wypelnij(T1,T2,n);
	bSort(T1,n,Bz,Bp);
	heapSort(T2,n,Cz,Cp);
	//wypisz(T1,n);
	//wypisz(T2,n);
	delete T1;
	delete T2;
	cout << "Dla n = " << n << endl;
	cout << "Liczba porownan dla BSort:	" << Bp << endl;
	cout << "Liczba zamian dla BSort:	" << Bz << endl;
	cout << "Liczba porownan dla HeapSort:	" << Cp << endl;
	cout << "Liczba zamian dla HeapSort:	" << Cz << endl;
	cout << endl;
	}
	



system("PAUSE");
}