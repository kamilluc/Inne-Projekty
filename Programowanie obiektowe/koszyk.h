#pragma once
#include <iostream>
#include <fstream>
#include "item.h"
#include "gpu.h"
#include "cpu.h"
#include "ram.h"
using namespace std;

class gpu;
class cpu;
class ram;
class koszyk{
public:
	static int licznik;
	void wybierzCpu();
	void wybierzGpu();
	void wybierzRam();
	friend void licznik(cpu &o1, gpu &o2, ram &o3);
	koszyk();
};