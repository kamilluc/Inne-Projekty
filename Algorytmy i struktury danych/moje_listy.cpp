#include <iostream>
using namespace std;

struct node {
	int val;
	node *next;
};
node *head = NULL;

//wyswietla liste
void show(node *&head) {
	if (head == NULL)
		cout << "lista jest pusta\n";
	else
	{
		node *p = head;
		while (p != NULL){
			cout << (p->val) << ", ";
			p = p->next;
		}
	}
}

//dodaj na poczatek listy
void insert(node *&head, int x) {
node *p = new node;
	p->val = x;
	p->next = head;
	head = p;
}

//dodaj na koniec listy
void insert2(node *&head, int x) {
	node *p = new node;
	p->val = x;
	p->next = NULL;
	if (head == NULL)
		head = p;
	else{
		node *end = head;
		while (end->next != NULL) {
			end = end->next;
		}
		end->next = p;
		}
	}

//dodaj ele x za ele y
void insert3(node *&head, int x, int y) {
	if (head == NULL){
		cout << "\nlista pusta, wstawiam " << x << " na pierwsza pozycje\n";
		insert(head, x);
		}
	else {

		node *licznik = head;
		while (licznik != NULL && (licznik->val) != y)
			licznik = licznik->next;
		node *p = new node;
		p->val = x;
		p->next = licznik->next;
		licznik->next = p;
		}
}

//usuwa element o wartosci x
void del(node *&head, int x) {
	if (head == NULL)
		cout << "lista jest pusta nie ma co usuwac";
	else
	{
		node *p = head;
		node *re_p = head;
		while ((p->next) != NULL && (p->val) != x)
			p = p->next;
		if ((p->val) == x){	
			while (re_p->next != p)
				re_p = re_p->next;
			re_p->next = p->next;
			delete p;	
		}
		else
			cout << "nie znaleziono elementu " << x;
	}
}

//x kopii elementow x
void cp(node *&head) {
	node *p = head;
	
	while (p != NULL) {
		for (int i = 0;i < (p->val);i++) {
			node *tmp = new node;
			tmp->val = p->val;
			tmp->next = p->next;
			p->next = tmp;
			p = tmp;
		};
		p = p->next;
	}
}

int main() {
//	insert(head, 12);
//	insert(head, 35);
//	insert(head, 5);
//	show(head);
//	cout << "\n";
//	insert(head, 1);
//  insert2(head, 7);
//	show(head);
//	cout << "\n";
//  insert3(head, 0, 35);
//	show(head);
//	cout << "\n";
/*
	node *head2 = NULL;
	insert(head2, 12);
	insert(head2, 11);
	insert(head2, 11);
	insert(head2, 16);
	show(head2);
	cout << "\n";
	del(head2, 12);
	cout << "\n";
	show(head2);
	*/

	node *head3 = NULL;
	insert2(head3, 2);
	insert2(head3, 3);
	insert2(head3, 1);
	insert2(head3, 5);
	show(head3);
	cp(head3);
	cout << endl;
	show(head3);

	system("pause");
}