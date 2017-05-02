#pragma once
#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

class item{
protected:
	string nazwa;
	string producent;
	double cena;
public:
	static int id;
	virtual void zmienCene()=0;
};