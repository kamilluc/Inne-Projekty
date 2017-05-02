#pragma once
#include <iostream>
#include <string>
#include <windows.h>
#include <vector>
#include <fstream>
#include "item.h"
#include "gpu.h"
#include "ram.h"
using namespace std;


void ram::wypelnijVector(){
	ram::pamieci.clear();
	ram a(1800, 2, 8, "1150", "Pentium G3260", "dfg", 274.34);
	int i=0;
	fstream plik;
	int czes;
	int lat;
	int poj;
	string ty;
	string na;
	string prod;
	double cen;
	plik.open("ram.txt", ios::in | ios::out);
	if( plik.good() == true ){
	while(!plik.eof())
	{
	plik>>czes;
	plik>>lat;
	plik>>poj;
	plik>>ty;
	plik>>na;
	plik>>prod;
	plik>>cen;
	a.czestotliwosc=czes;
	a.latency=lat;
	a.pojemnosc=poj;
	a.typ=ty;
	a.nazwa=na;
	a.producent=prod;
	a.cena=cen;
	ram::pamieci.push_back(a);
	i++;
	}
	plik.close();
	cout<<"Zaladowano "<<i<<" nowych elementow\n";
	}
	else
		cout<<"Nie uzyskano dostepu do pliku ram.txt\n";
}

void ram::zapiszVector(){
	ram a(1800, 2, 8, "1150", "Pentium G3260", "dfg", 274.34);
	int i=0;
	fstream plik;
	
	plik.open("ram.txt", ios::in | ios::out);
	if( plik.good() == true ){
	while(!ram::pamieci.empty())
	{
	a=ram::pamieci.back();
	
	plik<<a.czestotliwosc<<" ";
	plik<<a.latency<<" ";
	plik<<a.pojemnosc<<" ";
	plik<<a.typ<<" ";
	plik<<a.nazwa<<" ";
	plik<<a.producent<<" ";
	plik<<a.cena<<endl;
	ram::pamieci.pop_back();
	i++;
	}
	plik.close();
	cout<<"Zapisano "<<i<<" elementow do pliku\n";
	}
	else
		cout<<"Nie uzyskano dostepu do pliku ram.txt\n";
}

void ram::zmienCene(){
	double nc;
	cout<<this->producent<<" "<<this->nazwa<<" - "<<this->cena<<"zl"<<endl;
	cout<<"Nowa cena: ";
	cin>>nc;
	this->cena=nc;
	cout<<"Zmieniono\n";
}

void ram::odczytajRamZPliku(){
	int czes;
	int lat;
	int poj;
	string na;
	string prod;
	string ty;
	double cen;
	fstream plik;
	plik.open("ram.txt", ios::in);
	if( plik.good() == true ){
	while(!plik.eof()){
	plik>>czes;
	plik>>lat;
	plik>>poj;
	plik>>ty;
	plik>>na;
	plik>>prod;
	plik>>cen;
		cout<<"Producent: "<<prod<<endl;
		cout<<"Nazwa: "<<na<<endl;
		cout<<"Pojemnosc: "<<poj<<"GB"<<endl;
		cout<<"Taktowanie: "<<czes<<"MHz"<<endl;
		cout<<"Typ: "<<ty<<endl;
		cout<<"Latency: "<<lat<<"CL"<<endl;
		cout<<"Cena: "<<cen<<"zl"<<endl<<endl;
	}
	plik.close();
	}
	else
		cout<<"Nie uzyskano dostepu do pliku ram.txt\n";
}

void ram::wypiszRam(){
		cout<<"Producent: "<<this->producent<<endl;
		cout<<"Nazwa: "<<this->nazwa<<endl;
		cout<<"Pojemnosc: "<<this->pojemnosc<<"GB"<<endl;
		cout<<"Taktowanie: "<<this->czestotliwosc<<"MHz"<<endl;
		cout<<"Typ: "<<this->typ<<endl;
		cout<<"Latency: "<<this->latency<<"CL"<<endl;
		cout<<"Cena: "<<this->cena<<"zl"<<endl<<endl;
}

ram::ram(int czestotliwosc2, int latency2, int pojemnosc2, string typ2, string nazwa, string producent, double cena){
	czestotliwosc=czestotliwosc2;
	latency=latency2;
	pojemnosc=pojemnosc2;
	typ=typ2;
	item::nazwa=nazwa;
	item::producent=producent;
	item::cena=cena;
	item::id++;
}

ram::ram(){
		cout<<endl;
		cout<<"Producent: ";
		cin>>this->producent;
		cout<<"Nazwa: ";
		cin>>this->nazwa;
		cout<<"Typ: ";
		cin>>this->typ;
		cout<<"Pojemnosc (w GB): ";
		cin>>this->pojemnosc;
		cout<<"Latency (CL): ";
		cin>>this->latency;
		cout<<"Taktowanie: ";
		cin>>this->czestotliwosc;
		cout<<"Cena: ";
		cin>>this->cena;
		cout<<endl;
		item::id++;
}

ram::~ram(){
	//cout<<"Usunieto obiekt "<<producent<<endl;
	item::id--;
}