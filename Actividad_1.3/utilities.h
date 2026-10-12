#pragma once
#include <string>
#include <vector>
#include <sstream>
class bitacora; //Como hay una dependencia circular, bitacora utiliza utilities 
//y utilities utiliza bitacora, no se define bien la clase y da error. para
//evitar esto se usa "Forward declaration" que indica la existencia de su clase
//pero no utiliza ningun metodo de esta. Sin esto, hay un type error en el main
//causado porque busquedaBin en utilities utiliza getFecha() y bitacora utiliza 
//muchos metodos de utilities. Me di cuenta del error cuando implemente getFecha() 
//que es la ultima parte del código y me daba type error.

using namespace std;
class utilities
{
public:
	//Metodos para los diferentes casos de split
	

	//Split de string, devuelve un vector con los string separados
	static vector<string> split(const string& text, char delimitador);
	
	//Split que recibe string y devuelve un vector de numeros
	static vector<int> splitStoi(const string& text, char delimitador);

	//SORTS
	static void mergeSortBV(vector<bitacora>&, int, int); //Complejidad O(n log n)
	static void quickSortV(vector<bitacora>&, int, int); //Complejidad O(n^2) peor caso, O(n log n) promedio
	static void mergeSortBUint(vector<bitacora>&, int, int);

	//Busqueda
	static vector<int> busquedaSec(vector<bitacora>& lista, int n, int clave); //Complejidad:(log n)
	static vector<int> busquedaSecIp(vector<bitacora>& lista, int n, uint64_t clave);

private: //metodos que solo se usan en las funciones de arriba
	static void swap(bitacora*, bitacora*); //Complejidad O(1)
	static void mergeB(vector<bitacora>&, int, int, int); //Complejidad O(n)
	static void mergeBUint(vector<bitacora>&, int, int, int); //Complejidad O(n)
	static int partition(vector<bitacora>&, int, int); //Complejidad O(n)
};

