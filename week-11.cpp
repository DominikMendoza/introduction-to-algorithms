#include <iostream>
using namespace std;
void valor_arreglo(int* arreglo, int t)
{
	for (int i = 0; i < t; i++)
	{
		arreglo[i] = 1 + rand() % (50 + 1 - 1);
	}
}
void imprime_arreglo(int* arreglo, int t)
{
	for (int i = 0; i < t; i++)
	{
		cout << "indice: " << i << " entero: " << arreglo[i] << endl;
	}
}
void ordena_arreglo(int* arreglo, int t) {
	for (int i = 0; i < t - 1; i++) {
		for (int j = 0; j < t - i - 1; j++) {
			if (arreglo[j] > arreglo[j + 1]) {
				swap(arreglo[j], arreglo[j + 1]);
			}
		}
	}
}

void agregarElementoPos(int*& arr, int& n, int pos, int elemento)
{
	if (pos < 0 || pos > n - 1) {
		cout << "Fuera de rango\n";
		return;
	}
	int* aux = new int[n + 1];
	for (int i = 0; i < n; i++)
	{
		if (i < pos) aux[i] = arr[i];
		else aux[i + 1] = arr[i];
	}
	aux[pos] = elemento;
	delete[] arr;
	arr = aux;
	n++;
}
void agregarAlFinal(int*& arr, int& n, int elemento)
{
	int* aux = new int[n + 1];
	for (int i = 0; i < n; i++)
	{
		aux[i] = arr[i];
	}
	aux[n] = elemento;
	delete[] arr;
	arr = aux;
	n++;
}
void eliminarEnPos(int*& arr, int& n, int pos)
{
	if (pos < 0 || pos > n - 1) {
		cout << "Fuera de rango\n";
		return;
	}
	int* aux = new int[n - 1];
	for (int i = 0; i < n; i++)
	{
		if (i < pos) aux[i] = arr[i];
		if (i > pos) aux[i - 1] = arr[i];
	}
	delete[] arr;
	arr = aux;
	n--;
}
void modificarArregloR(int*& arr, int &n, int r)
{
	int ntam = 0;
	int* aux = new int[ntam];
	for (int j = 0; j < r; j++)
	{
		agregarAlFinal(aux, ntam, arr[0]);
		//agregarElementoPos(aux, ntam, ntam - 1, arr[0]);
	}
	for (int i = 1; i < n; i++)
	{
		if (arr[i] != arr[i - 1])
		{
			for (int j = 0; j < r; j++)
			{
				//agregarElementoPos(aux, ntam, ntam - 1, arr[i]);
				agregarAlFinal(aux, ntam, arr[i]);
			}
		}
	}
	delete[] arr;
	n = ntam;
	arr = aux;
}
void ejercicio5_sem11()
{
	int t;
	int* arreglo;
	int r;
	do
	{
		cout << "ingrese n: "; cin >> t;
	} while (t > 30 || t < 10);
	arreglo = new int[t];
	valor_arreglo(arreglo, t);
	imprime_arreglo(arreglo, t);
	ordena_arreglo(arreglo, t);
	cout << endl << "arreglo ordenado" << endl;
	imprime_arreglo(arreglo, t);
	cout << endl;
	do
	{
		cout << "ingrese R: "; cin >> r;
	} while (r < 2 || r>5);
	modificarArregloR(arreglo, t, r);
	imprime_arreglo(arreglo, t);
}
int main()
{
    ejercicio5_sem11();
    return 0;
}