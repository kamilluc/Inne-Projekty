//plan:
//1. wczytuje liczby z pliku i robi z nich liste
//2. wyswietla liste
//3. sortuje malejaco insert sortem

#include <iostream>
#include <fstream>
using namespace std;

int tab[] = { 2,4,1,4,9,5,3,8,0,5 };
struct node { int val; node *next; };
node *head = NULL;

void sortowanie(int *tab)
{
	int j, k;
	for (int i = 1;i < 10;i++)
	{
		j = i;
		k = i-1;
		while (tab[j] < tab[k] && k>=0) {
			swap(tab[j], tab[k]);
			--j;
			--k;
		};
	};
}
void add(node *&head, int x) {
	if (!head) {
		node *p = new node;
		p->val = x;
		p->next = NULL;
		head = p;
	}
	else {
		node *p = new node;
		p->val = x;
		p->next = NULL;

		node *q = new node;
		q = head;
		while (q->next) {
			q = q->next;
		};
		q->next = p;

	}
}
void show(node *&head) {
	node *p = head;
	while (p != NULL) {
		cout << p->val << " -> ";
		p = p->next;
	}
	cout <<"NULL"<< endl;
}
void sortowanielisty(node *&head, int dlugosc) {
	node *p = head;
	node *q = p;
	if (p == NULL)
		cout << "lista jest pusta";
	else if ((p->next) == NULL)
		cout << "po sortowaniu: ";
	else if ((p->next->next) == NULL) {
		q = q->next;
		if ((q->val) > (p->val)) {
			p->next = NULL;
			q->next = p;
			head->next = q;
			head = p;
		};
		cout << "po sortowaniu: ";
	};
	else{
		q = q->next;
		node *r = q->next;
		for (int i = 1; i < dlugosc;i++) {
			while ((r->val) > (q->val)) {
				p->next = r;
				q->next = r->next;
				r->next = q;	
			};

		}
	};
}

int main() 
{
	for (int i = 0; i < 10; i++)
		cout << tab[i] << " ";
	cout << endl;
	sortowanie(tab);
	for (int i = 0; i < 10; i++)
		cout << tab[i] << " ";
	cout << endl;
	cout << endl;

	fstream plik;
	plik.open("dane.txt", std::ios::in);
	int dlugosc, x;
	plik >> dlugosc;
	for (int i = 0;i < dlugosc;i++) {
		plik >> x;
		add(head, x);
	}
	plik.close();
	show(head);
	cout << endl;
	//sortowanielisty(head, dlugosc);
	show(head);
	system("pause");

}