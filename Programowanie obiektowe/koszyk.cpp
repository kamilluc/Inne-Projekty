#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "koszyk.h"
using namespace std;

koszyk::koszyk(){licznik++;};

int koszyk::licznik=0;

void koszyk::wybierzCpu(){
fstream plik;
string linia;
int i=0;
plik.open("cpu.txt", ios::in | ios::out);
while(!plik.eof()){
	getline(plik, linia);
	i++;
	cout<<i<<" - "<<linia<<endl;
}
plik.close();
cout<<endl<<"Wybieram procesor nr: ";
cin>>i;
plik.open("cpu.txt", ios::in | ios::out);
for(int j=0;j<i;j++){
		getline(plik, linia);
}
plik.close();
plik.open("koszyk.txt", ios::app);
plik<<"Zamowienie numer: "<<koszyk::licznik<<endl<<linia<<endl;
plik.close();
}

void koszyk::wybierzGpu(){
fstream plik;
string linia;
int i=0;
plik.open("gpu.txt", ios::in | ios::out);
while(!plik.eof()){
	getline(plik, linia);
	i++;
	cout<<i<<" - "<<linia<<endl;
}
plik.close();
cout<<endl<<"Wybieram karte graficzna nr: ";
cin>>i;
plik.open("gpu.txt", ios::in | ios::out);
for(int j=0;j<i;j++){
		getline(plik, linia);
}
plik.close();
plik.open("koszyk.txt", ios::app);
plik<<linia<<endl;
plik.close();
}

void koszyk::wybierzRam(){
fstream plik;
string linia;
int i=0;
plik.open("ram.txt", ios::in | ios::out);
while(!plik.eof()){
	getline(plik, linia);
	i++;
	cout<<i<<" - "<<linia<<endl;
}
plik.close();
cout<<endl<<"Wybieram pamiec RAM nr: ";
cin>>i;
plik.open("ram.txt", ios::in | ios::out);
for(int j=0;j<i;j++){
		getline(plik, linia);
}
plik.close();
plik.open("koszyk.txt", ios::app);
plik<<linia<<endl<<endl;
plik.close();
}