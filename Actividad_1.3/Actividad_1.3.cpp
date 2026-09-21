#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include "bitacora.h"
#include "utilities.h"

int main()
{
    fstream text;
    string line;
    string textS;
    vector<bitacora> bitacoras;
    vector<string> lines;
    string fecha;
    vector<string> date;
    bitacora searcher;
    vector<int> location;
    ofstream salida("bitacoras_con_filtro.txt");

    ifstream archivo("bitacora.txt");
    //text.open("bitacora.txt");
    if (!salida.is_open())
        cout << "No se ha creado el nuevo archivo" << endl;
    if (!archivo.is_open()) {
        cout << "No se abrio el archivo" << endl;
        return 1;
    }
    cout << "Archivo abierto exitosamente" << endl;
    cout << "Aplicando algoritmo de ordenamiento a la base de datos" << endl;
    while (getline(archivo, line)) {
        try {
            bitacoras.push_back(bitacora::splitBitacora(line, ' '));
        } 
        catch (const char* msg) {
            cerr << "Error de ejecución: " << msg << endl;
        }
    }
    archivo.close();
    /*for (int i = 0; i <= 20; i++) {
        cout << bitacoras[i].getMonth() << bitacoras[i].getDay() << bitacoras[i].printHour() << bitacoras[i].getIp() << bitacoras[i].getStatus() << endl;
    }*/

    //SORT
    //utilities::mergeSortBV(bitacoras, 0, bitacoras.size()-1);
    utilities::quickSortV(bitacoras, 0, bitacoras.size() - 1);

    while (true)
    {
        cout << "================================================================" << endl << "\nSistema de administracion de bitacoras" << endl;
        cout << "\nEscribe la fecha del registro que buscas en formato Mes,Dia" << "\nMes en 3 letras en ingles(Aug, Feb, Nov, Jan) con la primera mayuscula y dia en numero, separado por coma (,) "<< "Ejemplo: Jan,1" << "\nPresione e para salir" << endl;
        try {
            cin >> fecha;
            if (fecha == "e")
                return 0;

        date = utilities::split(fecha, ',');
        if (date.size() != 2)
            throw "Formato no valido";
        searcher.setMonth(date[0]);
        searcher.setDay(stoi(date[1]));
        if (searcher.getDay() > 31)
            throw "Te excediste del numero de dias posibles";
        }
        catch (const char* msg) {
            cout << msg << endl;
            continue;
        }
        catch (const exception& msg) { //exception es una clase de errores que contiene varios tipos.
            cout << "Formato no valido" << endl;
            continue;
        }
        location = utilities::busquedaSec(bitacoras, bitacoras.size(), searcher.getFecha());
        if (location.size() == 0)
            cout << "Ningun registro encontrado, revisa el formato" << endl;
        for (int i = 0; i < location.size(); i++)
        {
            cout << "La bitacora corresponiente a esa fecha exacta es:" << endl;
            cout << bitacoras[location[i]].getM() << " " << bitacoras[location[i]].getDay() << " " << bitacoras[location[i]].printHour() << " " << bitacoras[location[i]].getIp() << " " << bitacoras[location[i]].getStatus() << endl;
            
            //Grabar los resultados en el archivo txt
            salida << bitacoras[i].getM() << " "
                << bitacoras[i].getDay() << " "
                << bitacoras[i].printHour() << " "
                << bitacoras[i].getIp() << " "
                << bitacoras[i].getStatus() << endl;
        }
        salida.close();
        cout << "Se ha grabado el archivo exitosamente" << endl;

    }
   
        //string tockenizer
}
