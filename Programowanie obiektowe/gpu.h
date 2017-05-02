#pragma once
#include <iostream>
#include <string>
#include <windows.h>
#include <vector>
#include <fstream>
#include "item.h"
#include "cpu.h"
#include "ram.h"
using namespace std;

class cpu;
class gpu;
class gpu: public item{
private:
	int taktowanie_rdzenia;
	double pamiecgddr;
	
public:
	vector <gpu> karty_graficzne;
	friend void licznik(cpu &o1, gpu &o2, ram &o3);
	void wypelnijVector();
	void zapiszVector();
	void zmienCene();
	void odczytajGpuZPliku();
	void wypiszGpu();
	gpu(int taktowanie_rdzenia, double pamiecgddr, string nazwa, string producent, double cena);
	gpu();
	~gpu();
};