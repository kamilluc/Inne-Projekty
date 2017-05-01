#include <iostream>
#include <time.h>
using namespace std;
int main() {
	int a;
	srand(time(NULL)); //ta sama liczba bez tego
	a = rand() % 10 + 1; //od 1 do 10
	cout << a << "  ";
	system("pause");
}