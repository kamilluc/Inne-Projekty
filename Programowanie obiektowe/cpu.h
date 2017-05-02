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

class gpu;
class ram;
class cpu: public item{
private:
	int czestotliwosc;
	int iloscRdzeni;
	string socket;
	
public:
	vector <cpu> procesory;
	friend void licznik(cpu &o1, gpu &o2, ram &o3);
	void wypelnijVector();
	void zapiszVector();
	void zmienCene();
	void odczytajCpuZPliku();
	void wypiszCpu();
	cpu(int czestotliwosc, int rdzenie, string socket, string nazwa, string producent, double cena);
	cpu();
	~cpu();
};