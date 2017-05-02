#pragma once
#include <iostream>
#include <string>
#include <windows.h>
#include <vector>
#include <fstream>
#include <windows.h>
#include <conio.h>
#include "item.h"
#include "cpu.h"
#include "gpu.h"
#include "ram.h"
#include "koszyk.h"

using namespace std;
/*


	try catch pliki
	

*/

void licznik(cpu &o1, gpu &o2, ram &o3)
{
	int licz=-2;
	o1.wypelnijVector();
	o2.wypelnijVector();
	o3.wypelnijVector();
	system("cls");
	licz+=o1.procesory.size();
	licz+=o2.karty_graficzne.size();
	licz+=o3.pamieci.size();
	cout<<"Baza danych zawiera: "<<licz<<" zapisanych elementow"<<endl;
//	cout<<"Aktualnie przetwarzanych jest: "<<item::id<<" elementow";
	cout<<"Ilosc dzisiejszych zamowien: "<<koszyk::licznik<<endl;
	Sleep(2500);

}

int main(){
	
	cpu t1(1800, 2, "1150", "SprzedamOpla", "Intel", 274.34);
	gpu t2(1800, 2, "1150", "SprzedamOpla", 274.34);
	ram t3(1800, 2, 8, "1150", "Pentium G3260", "dfg", 274.34);

	//polimorfizm
	 item *wsk;

	cout<<"BAZA DANYCH SPRZETU KOMPUTEROWEGO\n";
	Sleep(1500);

	//**********
	//** MENU **
	//**********
	int wybranaopcja = 0;
	char znak;

	while (1)
	{
		system("cls");
		if (wybranaopcja == 0) cout << "[*]Procesory\n";
		else cout << "[ ]Procesory\n";

		if (wybranaopcja == 1) cout << "[*]Karty Graficzne\n";
		else cout << "[ ]Karty Graficzne\n";

		if (wybranaopcja == 2) cout << "[*]Pamieci Ram\n";
		else cout << "[ ]Pamieci Ram\n";

		if (wybranaopcja == 3) cout << "[*]Zloz zamowienie\n";
		else cout << "[ ]Zloz zamowienie\n";


		if (wybranaopcja == 4) cout << "[*]Sprawdz ilosc elementow w bazie\n";
		else cout << "[ ]Sprawdz ilosc elementow w bazie\n";

		if (wybranaopcja == 5) cout << "[*]WYJSCIE\n";
		else cout << "[ ]WYJSCIE\n";

		znak = _getch();

		switch (znak)
		{
		case 72: //strzalka w gore
			wybranaopcja--;
			break;
		case 80: //strzalka w dol
			wybranaopcja++;
			break;
		case 13: //enter
			Sleep(100);


			//Wyjscie
			if(wybranaopcja==5){
				system("cls");
			char zna;
			cout<<"Jestes pewien, ze chcesz wyjsc? y/n: ";
			cin>>zna;
			if(zna=='y'){
				Sleep(300);
				exit(0);
			}
			else{
				wybranaopcja=0;
				continue;
			}}

			//Licznik elementow
			if(wybranaopcja==4){
				system("cls");
				licznik(t1, t2, t3);
			}

			//Koszyk
			if(wybranaopcja==3){
				system("cls");
				
				koszyk nowy;
				nowy.wybierzCpu();
				nowy.wybierzGpu();
				nowy.wybierzRam();
				cout<<"\nZamowienie zostalo zlozone\n\n";
				Sleep(500);
				}
		

			//Ram
			if(wybranaopcja==2){
				system("cls");
				char opcja;
				while(1){
				cout<<"Co chcesz zrobic?\n1 - Wyswietl wszystkie pamieci ram\n2 - Dodaj nowa pamiec ram do bazy danych\n3 - Wroc"<<endl;
				cin>>opcja;
				if(opcja=='1'){
					
					t3.odczytajRamZPliku();
				}
				if(opcja=='2'){
				
					ram nowy;
					wsk=&nowy;
					cout<<endl<<"Chcesz zmienic cene? y/n: ";
					char tyt;
					cin>>tyt;
					if(tyt=='y')
						wsk->zmienCene();
					nowy.wypelnijVector();
					nowy.pamieci.push_back(nowy);
					nowy.zapiszVector();
					cout<<"Dodano nowy element do bazy danych\n";
					
				}
				if(opcja=='3')
					break;
				}}

			//Gpu
			if(wybranaopcja==1){
				system("cls");
				char opcja;
				while(1){
				cout<<"Co chcesz zrobic?\n1 - Wyswietl wszystkie karty graficzne\n2 - Dodaj nowa karte graficzna do bazy danych\n3 - Wroc"<<endl;
				cin>>opcja;
				if(opcja=='1'){
					t2.odczytajGpuZPliku();
				}
				if(opcja=='2'){
					gpu nowy;
					wsk=&nowy;
					cout<<endl<<"Chcesz zmienic cene? y/n: ";
					char tyt;
					cin>>tyt;
					if(tyt=='y')
						wsk->zmienCene();
					nowy.wypelnijVector();
					nowy.karty_graficzne.push_back(nowy);
					nowy.zapiszVector();
					cout<<"Dodano nowy element do bazy danych\n";
				}
				if(opcja=='3')
					break;
				}}

			//Cpu
			if(wybranaopcja==0){
				system("cls");
				char opcja;
				while(1){
				cout<<"Co chcesz zrobic?\n1 - Wyswietl wszystkie procesory\n2 - Dodaj nowy procesor do bazy danych\n3 - Wroc"<<endl;
				cin>>opcja;
				if(opcja=='1'){
					
					t1.odczytajCpuZPliku();
				}
				if(opcja=='2'){
					cpu nowy;
					wsk=&nowy;
					cout<<endl<<"Chcesz zmienic cene? y/n: ";
					char tyt;
					cin>>tyt;
					if(tyt=='y')
						wsk->zmienCene();
					nowy.wypelnijVector();
					nowy.procesory.push_back(nowy);
					nowy.zapiszVector();
					cout<<"Dodano nowy element do bazy danych\n";
				}
				if(opcja=='3')
					break;
				}}
		
		}
		if (wybranaopcja < 0) wybranaopcja=5;
		if (wybranaopcja > 5) wybranaopcja=0;
	}
	
}