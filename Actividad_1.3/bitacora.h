#pragma once
#include <string>
#include <vector>
#include "utilities.h"
using namespace std;
class bitacora
{
private:
	int month;
	string m;
	int day;
	string strHour;
	vector<int> hour;
	string ip;
	string status;
	int fecha;
public:
	bitacora();
	bitacora(string m, int d, string h, string s, int f);
	int getMonth();
	string getM();
	vector<int> getHour() const;
	int getDay();
	string getIp();
	string getStatus();
	int getFecha();
	
	void setMonth(string);
	void setHour(string);
	void setStatus(string);
	void setDay(int);
	void setIp(string);
	string printHour();
	//Lee bitacora y la devuelve con sus setters correspondientes
	static bitacora splitBitacora(const string& text, char delimitador);
};

