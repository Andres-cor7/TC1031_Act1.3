#include "bitacora.h"
#include <map>

bitacora::bitacora()
{
    month = 0;
    day = 0;
    status = "";
    strHour = "";
    hour = {};
}
bitacora::bitacora(string m, int d, string h, string s, int f)
{
    this->m = m;
    map<string, int> dic = {
        {"Jan", 1},
        {"Feb", 2},
        {"Mar", 3},
        {"Apr", 4},
        {"May", 5},
        {"Jun", 6},
        {"Jul", 7},
        {"Aug", 8},
        {"Sep", 9},
        {"Oct", 10},
        {"Nov", 11},
        {"Dec", 12} };
    month = dic[m];
    status = s;
    day = d;
    strHour = h;
    hour = utilities::splitStoi(h,':');
    fecha = f;
}

int bitacora::getMonth()
{
    return month;
}

string bitacora::getM()
{
    return m;
}

vector<int> bitacora::getHour() const
{
    return hour;
}

int bitacora::getDay()
{
    return day;
}

string bitacora::getIp()
{
    return ip;
}

string bitacora::getStatus()
{
    return status;
}

int bitacora::getFecha()
{
    int mes = month - 1;
    int fecha = 0;
    map<int, int> diasPorMes = {
    {1, 31},
    {2, 28},
    {3, 31},
    {4, 30},
    {5, 31},
    {6, 30},
    {7, 31},
    {8, 31},
    {9, 30},
    {10, 31},
    {11, 30},
    {12, 31}
    };
    while (mes > 0) {
        fecha += diasPorMes[mes];
        mes--;
    }
    fecha += day;
    return fecha;
}

void bitacora::setMonth(string m)
{
    //map se puede usar para hacer diccionarios, es un contenedor
    //que guarda pares key-value como en python
    this->m = m;
    map<string, int> dic = {
        {"Jan", 1},
        {"Feb", 2},
        {"Mar", 3},
        {"Apr", 4},
        {"May", 5},
        {"Jun", 6},
        {"Jul", 7},
        {"Aug", 8},
        {"Sep", 9},
        {"Oct", 10},
        {"Nov", 11},
        {"Dec", 12} };
    month = dic[m];
}

void bitacora::setHour(string h)
{
    strHour = h;
    hour = utilities::splitStoi(h,':');
}

void bitacora::setStatus(string s)
{
    status = s;
}

void bitacora::setDay(int d)
{
    day = d;
}

void bitacora::setIp(string s)
{
    ip = s;
}

string bitacora::printHour()
{
    return strHour;
}

bitacora bitacora::splitBitacora(const string& text, char delimitador)
{
    vector<string> resultado;
    stringstream ss(text);
    string token;
    bitacora b;
    int cont = 0;

    while (getline(ss, token, delimitador)) {
        if (cont >= 4) {
            string rest;
            getline(ss, rest);
            token += " " + rest;
        }
        if (cont == 0)
            b.setMonth(token);
        else if (cont == 1)
            b.setDay(stoi(token));
        else if (cont == 2)
            b.setHour(token);
        else if (cont == 3)
            b.setIp(token);
        else if (cont == 4)
            b.setStatus(token);
        else
            throw "Formato de bitacora no permitido";
        cont++;
    }
    return b;
}