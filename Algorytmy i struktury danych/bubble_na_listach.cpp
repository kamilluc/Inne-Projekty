#include <iostream>
#include <time.h>
using namespace std;

struct node {
	int val;
	node *next;};
node *head = NULL;

int const n = 4;
int liczba;

void dodaj(node *&head, int x) {
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
	while (p) {
		cout << p -> val << ", ";
		p = p->next;
	};
}

void bubble(node *&head) {
	bool z;
	node *p = new node;
	node *r = new node;
	node *q = new node;
	for (int i = n-1;i > 0;i--) {
		z = false;
		p = head->next;
		r = head;
		q = p->next;
		if (q == NULL)
			break;
	
		
		for (int j = 0; j < i; j++) {

			if ((p->val) > (q->val)) {
				
				p->next = q->next;
				q->next = p;
				r->next = q;
				z = true;
				r = r->next;
				q = p->next;
			}
			else {
				p = p->next;
				r = r->next;
				q = q->next;
			}
			if (q == NULL)
			break;
		};
		if (z == false)
			break;
	};
}
int main() {
	srand(time(NULL));
	for (int i = 0; i < n; i++) {
		liczba = rand() % 100+1;
		dodaj(head, liczba);
	};
	show(head);
	cout << endl << endl;
	bubble(head);
	show(head);

	cout << endl;
	system("pause");
}