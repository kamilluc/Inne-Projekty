#include<iostream>

using namespace std;

struct lista
{
	lista *next;
	int value;
};
void pushL(lista *&H, int x)	// dodaj z lewej
{
	lista *p = new lista;
	p->value = x;
	p->next = H;
	H = p;
}
void pushR(lista *&H, int x)	// dodaj z prawej
{
	lista *p = new lista;
	lista *q = new lista;
	q->next = NULL;
	p = H;
	if (H != NULL)
	{
		while (p->next != NULL)
		{
			p = p->next;
		}
		q->value = x;
		p->next = q;
	}
	else
	{
		q->value = x;
		q->next = H;
		H = q;
	}
}
void kopiuj(lista *H, lista *&Tc, int l, int r)
{
	lista *p = new lista;
	p = H;
	for (int i = 0; i < l; i++)
	{
		p = p->next;
	}
	for (int i = 0; i <= r - l; i++)
	{
		pushR(Tc, p->value);
		p = p->next;
	}
}


void merge(lista *&H, int l, int i, int r)
{
	lista *Hl = NULL;
	lista *Hr = NULL;
	kopiuj(H, Hl, l, i);
	kopiuj(H, Hr, i + 1, r);
	H = NULL;
	int p = 0;
	int k = 0;
	while (p <= i - l && k <= r - i - 1)
	{
		if (Hl->value < Hr->value)
		{
			pushR(H, Hl->value);
			Hl = Hl->next;
			p++;
		}
		else
		{
			pushR(H, Hr->value);
			Hr = Hr->next;
			k++;
		}
	}
	while (p <= i - l)
	{
		pushR(H, Hl->value);
		Hl = Hl->next;
		p++;
	}
	while (k <= r - i - 1)
	{
		pushR(H, Hr->value);
		Hr = Hr->next;
		k++;
	}
}
void wypisz(lista *H)
{
	lista *p = new lista;
	p = H;
	cout << "[H]->";
	while (p != NULL)
	{
		cout << "[ " << p->value << " ]->";
		p = p->next;
	}
	cout << "[NULL]";
}

void mergeSort(lista *H, int n)
{

}

int main()
{
	lista *H;
	H = NULL;

	pushR(H, 5);
	pushR(H, 6);
	pushR(H, 7);
	pushR(H, 3);
	pushR(H, 4);
	pushR(H, 5);
	pushL(H, 32);
	wypisz(H);
	cout << endl;
	merge(H, 0, 2, 5);
	wypisz(H);


	system("PAUSE");
}