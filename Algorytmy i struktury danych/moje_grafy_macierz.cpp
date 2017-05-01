#include <iostream>
#include <fstream>
using namespace std;

struct ls {
	int val;
	int odl;
	ls *next;
};
const int wieszcholki = 5;
int ms[wieszcholki][wieszcholki];
ls *lista[wieszcholki];
int x, y; 
struct lk {
	int od;
	int dokad;
	int waga;
	lk *next;
};
lk *headlk = NULL;

void DodajDoLk(lk *&headlk, int od, int srednia, ls *&headls) {
	ls *p = headls;
	
	while (p!=NULL) {
		if ((p->odl) > srednia) {
			lk *q = new lk;
			q->od = od;
			q->dokad = p->val;
			q->waga = p->odl;
			q->next = NULL;
			if (!headlk)
				headlk = q;
			else{
				lk *r = headlk;
				while (r->next)
					r = r->next;
				r->next = q;	
			};	
		};
		p = p->next;


	};
}
void WypiszLk(lk *&head) {
	lk *p = head;
	if (p) {
		while (p) {
			cout << p->od << "|" << p->dokad << "|" << p->waga << " -> ";
			p = p->next;
		};
	}
	else
		cout << "Lista krawedzi jest pusta";
	cout << endl;
}
void WypiszMacierz() {
	for (int i = 0;i < wieszcholki;i++) {
		for (int j = 0;j < wieszcholki;j++)
			cout << ms[i][j] << " ";
		cout << endl;
	};
	cout << endl << endl;
}
void WypiszLs(ls *&head) {
	if (head == NULL)
		cout << "lista jest pusta";
	else {
		ls *p = head;
		while (p) {
			cout << p->val << "|" << p->odl << " -> ";
			p = p->next;
		};
		
	};
}
void DodajDoLs(ls *&head, int x, int y) {
	
	ls *p = new ls;
	p->next = NULL;
	p->val = x;
	p->odl = y;

	if (!head)
		head = p;
	else {
		ls *q = new ls;
		q = head;
		while (q->next)
			q = q->next;
		q->next = p;
	};

}

int main() {
	fstream plik;
	plik.open("macierz.txt", std::ios::in);
	for (int i = 0;i < wieszcholki;i++) {
		for (int j = 0;j < wieszcholki;j++)
			plik >> ms[i][j];
	};
	plik.close();

	WypiszMacierz();

	for (int i = 0;i < wieszcholki;i++) {
		
		for (int j = 0;j < wieszcholki;j++) {
			if (ms[i][j] != 0) {
				DodajDoLs(lista[i], j+1, ms[i][j]);
			};
		};
	};

	for (int i = 0;i < wieszcholki;i++) {
		cout << "W" << i + 1 << ":  ";
		WypiszLs(lista[i]);
		cout << endl;
	};

	int LicznikWartosci = 0;
	int IloscWartosci = 0;
	for (int i = 0;i < wieszcholki;i++) {
		for (int j = 0;j < wieszcholki;j++) {
			if (ms[i][j]>0) {
				LicznikWartosci += ms[i][j];
				IloscWartosci++;
			};
		};
	};

	int srednia;
	srednia = LicznikWartosci / IloscWartosci;
	cout << endl << endl << "Srednia waga krawedzi: " << srednia << endl<<"Lista krawedzi, schemat od|do|waga np. 1|3|2:"<<endl;
	for (int i = 0;i < wieszcholki;i++)
		DodajDoLk(headlk, i + 1, srednia, lista[i]);
	WypiszLk(headlk);
	cout << endl;
	system("pause");
}