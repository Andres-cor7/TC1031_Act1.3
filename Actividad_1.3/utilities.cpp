#include "utilities.h"
#include "bitacora.h"



vector<string> utilities::split(const string& text, char delimitador)
{
    vector<string> resultado;
    stringstream ss(text);
    string token;
	int cont = 0;

    while (getline(ss, token, delimitador)) {	
        resultado.push_back(token);
		cont++;
    }
    return resultado;
}
vector<int> utilities::splitStoi(const string& text, char delimitador)
{
    vector<int> resultado;
    stringstream ss(text);
    string token;

    while (getline(ss, token, delimitador)) {
        resultado.push_back(stoi(token));
    }
    return resultado;
}


void utilities::mergeSortBV(vector<bitacora>& v, int const begin, int const end)
{
	if (begin >= end)
		return;

	auto mid = begin + (end - begin) / 2;
	utilities::mergeSortBV(v, begin, mid);
	utilities::mergeSortBV(v, mid + 1, end);
	utilities::mergeB(v, begin, mid, end);
}

//Complejidad: O(n)
void utilities::mergeB(vector<bitacora>& v, int const left, int const mid, int const right)
{
	auto const subArrayOne = mid - left + 1;
	auto const subArrayTwo = right - mid;

	// Create temp arrays
	auto* leftArray = new bitacora[subArrayOne],
		* rightArray = new bitacora[subArrayTwo];

	// Copy data to temp arrays leftArray[] 
	// and rightArray[]
	for (auto i = 0; i < subArrayOne; i++)
		leftArray[i] = v[left + i];
	for (auto j = 0; j < subArrayTwo; j++)
		rightArray[j] = v[mid + 1 + j];

	// Initial index of first sub-array
	// Initial index of second sub-array
	auto indexOfSubArrayOne = 0,
		indexOfSubArrayTwo = 0;

	// Initial index of merged array
	int indexOfMergedArray = left;

	// Merge the temp arrays back into 
	// array[left..right]
	while (indexOfSubArrayOne < subArrayOne &&
		indexOfSubArrayTwo < subArrayTwo)
	{
		if (leftArray[indexOfSubArrayOne].getFecha() <=
			rightArray[indexOfSubArrayTwo].getFecha())
		{
			v[indexOfMergedArray] =
				leftArray[indexOfSubArrayOne];
			indexOfSubArrayOne++;
		}
		else
		{
			v[indexOfMergedArray] =
				rightArray[indexOfSubArrayTwo];
			indexOfSubArrayTwo++;
		}
		indexOfMergedArray++;
	}

	// Copy the remaining elements of
	// left[], if there are any
	while (indexOfSubArrayOne < subArrayOne)
	{
		v[indexOfMergedArray] =
			leftArray[indexOfSubArrayOne];
		indexOfSubArrayOne++;
		indexOfMergedArray++;
	}

	// Copy the remaining elements of
	// right[], if there are any
	while (indexOfSubArrayTwo < subArrayTwo)
	{
		v[indexOfMergedArray] =
			rightArray[indexOfSubArrayTwo];
		indexOfSubArrayTwo++;
		indexOfMergedArray++;
	}

	delete[]leftArray;
	delete[]rightArray;
}
//Complejidad: O(n^2) en peor caso
void utilities::quickSortV(vector<bitacora>& arr, int low, int high)
{
	if (low < high)
	{
		/* pi is partitioning index, arr[p] is now
		   at right place */
		int pi = partition(arr, low, high);

		// Separately sort elements before 
		// partition and after partition 
		quickSortV(arr, low, pi - 1);
		quickSortV(arr, pi + 1, high);
	}
}

//Complejidad: O(n)
int utilities::partition(vector<bitacora>& arr, int low, int high)
{
	int pivot = arr[high].getFecha();    // pivot 
	int i = (low - 1);  // Index of smaller element 

	for (int j = low; j <= high - 1; j++)
	{
		// If current element is smaller than or 
		// equal to pivot 
		if (arr[j].getFecha() <= pivot)
		{
			i++;    // increment index of smaller element 
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}
void utilities::swap(bitacora* val1, bitacora* val2)
{
	bitacora temp = *val1;
	*val1 = *val2;
	*val2 = temp;
}

//Busqueda Binaria
vector<int> utilities::busquedaSec(vector<bitacora>& lista, int n, int clave)
{
	vector<int> resultado;
	for (int i = 0; i < n; i++) {
		if (lista[i].getFecha() == clave)
			resultado.push_back(i);
	}
	return resultado;
}