#pragma once
#include <iostream>
#include <string>
#include <windows.h>
#include <vector>
#include <fstream>
#include "item.h"
#include "cpu.h"
using namespace std;


void cpu::wypelnijVector(){
	cpu::procesory.clear();
	cpu a(1800, 2, "1150", "Pentium G3260", "Intel", 274.34);
	int i=0;
	fstream plik;
	int czes;
	int rdze;
	string soc;
	string na;
	string prod;
	double cen;
	plik.open("cpu.txt", ios::in | ios::out);
	if( plik.good() == true ){
	while(!plik.eof())
	{
	plik>>czes;
	plik>>rdze;
	plik>>soc;
	plik>>na;
	plik>>prod;
	plik>>cen;
	a.czestotliwosc=czes;
	a.iloscRdzeni=rdze;
	a.socket=soc;
	a.nazwa=na;
	a.producent=prod;
	a.cena=cen;
	cpu::procesory.push_back(a);
	i++;
	}
	plik.close();
	cout<<"Zaladowano "<<i<<" nowych elementow\n";
	}
	else
		cout<<"Nie uzyskano dostepu do pliku cpu.txt\n";
}

void cpu::zapiszVector(){
	cpu a(1800, 2, "1150", "Pentium G3260", "Intel", 274.34);
	int i=0;
	fstream plik;
	
	plik.open("cpu.txt", ios::in | ios::out);
	if( plik.good() == true ){
	while(!cpu::procesory.empty())
	{
	a=cpu::procesory.back();
	plik<<a.czestotliwosc<<" ";
	plik<<a.iloscRdzeni<<" ";
	plik<<a.socket<<" ";
	plik<<a.nazwa<<" ";
	plik<<a.producent<<" ";
	plik<<a.cena<<endl;
	cpu::procesory.pop_back();
	i++;
	}
	plik.close();
	cout<<"Zapisano "<<i<<" elementow do pliku\n";
	}
	else
		cout<<"Nie uzyskano dostepu do pliku cpu.txt\n";
}

void cpu::zmienCene(){
	double nc;
	cout<<this->producent<<" "<<this->nazwa<<" - "<<this->cena<<"zl"<<endl;
	cout<<"Nowa cena: ";
	cin>>nc;
	this->cena=nc;
	cout<<"Zmieniono\n";
}

void cpu::odczytajCpuZPliku(){
	int czes;
	int rdze;
	string soc;
	string na;
	string prod;
	double cen;

	fstream plik;
	plik.open("cpu.txt", ios::in);
	if( plik.good() == true ){
	while(!plik.eof()){
	plik>>czes;
	plik>>rdze;
	plik>>soc;
	plik>>na;
	plik>>prod;
	plik>>cen;
		cout<<"Producent: "<<prod<<endl;
		cout<<"Nazwa: "<<na<<endl;
		cout<<"Socket: "<<soc<<endl;
		cout<<"Ilosc rdzeni: "<<rdze<<endl;
		cout<<"Czestotliwosc: "<<czes<<"MHz"<<endl;
		cout<<"Cena: "<<cen<<"zl"<<endl<<endl;
	}
	plik.close();
	}
	else
		cout<<"Nie uzyskano dostepu do pliku cpu.txt\n";
}

void cpu::wypiszCpu(){
		cout<<"Producent: "<<this->producent<<endl;
		cout<<"Nazwa: "<<this->nazwa<<endl;
		cout<<"Socket: "<<this->socket<<endl;
		cout<<"Ilosc rdzeni: "<<this->iloscRdzeni<<endl;
		cout<<"Czestotliwosc: "<<this->czestotliwosc<<"MHz"<<endl;
		cout<<"Cena: "<<this->cena<<"zl"<<endl<<endl;
}

cpu::cpu(int czest, int rdzenie, string soc, string nazwa, string producent, double cena){
	czestotliwosc=czest;
	iloscRdzeni=rdzenie;
	socket=soc;
	item::nazwa=nazwa;
	item::producent=producent;
	item::cena=cena;
	item::id++;
}

cpu::cpu(){
		cout<<endl;
		cout<<"Producent: ";
		cin>>this->producent;
		cout<<"Nazwa: ";
		cin>>this->nazwa;
		cout<<"Socket: ";
		cin>>this->socket;
		cout<<"Ilosc rdzeni: ";
		cin>>this->iloscRdzeni;
		cout<<"Czestotliwosc: ";
		cin>>this->czestotliwosc;
		cout<<"Cena: ";
		cin>>this->cena;
		cout<<endl;
		item::id++;
}

cpu::~cpu(){
	//cout<<"Usunieto obiekt "<<producent<<endl;
	item::id--;
}