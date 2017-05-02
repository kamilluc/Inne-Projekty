#pragma once
#include <iostream>
#include <string>
#include <windows.h>
#include <vector>
#include <fstream>
#include "item.h"
#include "gpu.h"
using namespace std;


void gpu::wypelnijVector(){
	gpu::karty_graficzne.clear();
	gpu a(1800, 2, "1150", "Pentium G3260", 274.34);
	int i=0;
	fstream plik;
	int czes;
	double rdze;
	string na;
	string prod;
	double cen;
	plik.open("gpu.txt", ios::in | ios::out);
	if( plik.good() == true ){
	while(!plik.eof())
	{
	plik>>czes;
	plik>>rdze;
	
	plik>>na;
	plik>>prod;
	plik>>cen;
	a.taktowanie_rdzenia=czes;
	a.pamiecgddr=rdze;
	
	a.nazwa=na;
	a.producent=prod;
	a.cena=cen;
	gpu::karty_graficzne.push_back(a);
	i++;
	}
	plik.close();
	cout<<"Zaladowano "<<i<<" nowych elementow\n";
	}
	else
		cout<<"Nie uzyskano dostepu do pliku gpu.txt\n";
}

void gpu::zapiszVector(){
	gpu a(1800, 2, "1150", "Pentium G3260", 274.34);
	int i=0;
	fstream plik;
	
	plik.open("gpu.txt", ios::in | ios::out);
	if( plik.good() == true ){
	while(!gpu::karty_graficzne.empty())
	{
	a=gpu::karty_graficzne.back();
	
	plik<<a.taktowanie_rdzenia<<" ";
	plik<<a.pamiecgddr<<" ";
	plik<<a.nazwa<<" ";
	plik<<a.producent<<" ";
	plik<<a.cena<<endl;
	gpu::karty_graficzne.pop_back();
	i++;
	}
	plik.close();
	cout<<"Zapisano "<<i<<" elementow do pliku\n";
	}
	else
		cout<<"Nie uzyskano dostepu do pliku gpu.txt\n";
}

void gpu::zmienCene(){
	double nc;
	cout<<this->producent<<" "<<this->nazwa<<" - "<<this->cena<<"zl"<<endl;
	cout<<"Nowa cena: ";
	cin>>nc;
	this->cena=nc;
	cout<<"Zmieniono\n";
}

void gpu::odczytajGpuZPliku(){
	int czes;
	double pamie;
	string na;
	string prod;
	double cen;
	fstream plik;
	plik.open("gpu.txt", ios::in);
	if( plik.good() == true ){
	while(!plik.eof()){
	plik>>czes;
	plik>>pamie;
	plik>>na;
	plik>>prod;
	plik>>cen;
		cout<<"Producent: "<<prod<<endl;
		cout<<"Nazwa: "<<na<<endl;
		cout<<"Pamiec GDDR: "<<pamie<<"GB"<<endl;
		cout<<"Taktowanie rdzenia: "<<czes<<"MHz"<<endl;
		cout<<"Cena: "<<cen<<"zl"<<endl<<endl;
	}
	plik.close();
	}
	else
		cout<<"Nie uzyskano dostepu do pliku gpu.txt\n";
}

void gpu::wypiszGpu(){
		cout<<"Producent: "<<this->producent<<endl;
		cout<<"Nazwa: "<<this->nazwa<<endl;
		cout<<"Pamiec GDDR: "<<this->pamiecgddr<<"GB"<<endl;
		cout<<"Taktowanie rdzenia: "<<this->taktowanie_rdzenia<<"MHz"<<endl;
		cout<<"Cena: "<<this->cena<<"zl"<<endl<<endl;
}

gpu::gpu(int takt, double  gddr, string nazwa, string producent, double cena){
	pamiecgddr=gddr;
	taktowanie_rdzenia=takt;
	item::nazwa=nazwa;
	item::producent=producent;
	item::cena=cena;
	item::id++;
}

gpu::gpu(){
		cout<<endl;
		cout<<"Producent: ";
		cin>>this->producent;
		cout<<"Nazwa: ";
		cin>>this->nazwa;
		cout<<"Pamiec GDDR (w GB): ";
		cin>>this->pamiecgddr;
		cout<<"Taktowanie rdzenia: ";
		cin>>this->taktowanie_rdzenia;
		cout<<"Cena: ";
		cin>>this->cena;
		cout<<endl;
		item::id++;
}

gpu::~gpu(){
	//cout<<"Usunieto obiekt "<<producent<<endl;
	item::id--;
}