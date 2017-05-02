#pragma once
#include <iostream>
#include <string>
#include <windows.h>
#include <vector>
#include <fstream>
#include "item.h"
#include "gpu.h"
#include "cpu.h"
using namespace std;

class gpu;
class cpu;
class ram: public item{
private:
	int czestotliwosc;
	int latency;
	int pojemnosc;
	string typ;

public:
	vector <ram> pamieci;
	friend void licznik(cpu &o1, gpu &o2, ram &o3);
	void wypelnijVector();
	void zapiszVector();
	void zmienCene();
	void odczytajRamZPliku();
	void wypiszRam();
	ram(int czestotliwosc, int latency, int pojemnosc, string typ, string nazwa, string producent, double cena);
	ram();
	~ram();
};