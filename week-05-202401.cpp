#include <iostream>
#include <time.h>
using namespace System;
using namespace std;


int obtenerCantidadDeTerminos()
{
	int cDeTerminos;
	do
	{
		cout << "Ingrese la cantidad de terminos: ";
		cin >> cDeTerminos;
	} while (cDeTerminos < 0);
	return cDeTerminos;
}

int obtenerValorDeX()
{
	int x;
	do
	{
		cout << "Ingrese un valor de x: ";
		cin >> x;
	} while (x < 2 || x > 4);
	return x;
}

// 4! -> 4 x 3 x 2 x 1
// 2! -> 2 x 1

long long factorial(int a)
{
	long long res = 1;
	for (int i = 1; i <= a; i++)
	{
		res *= i;
	}
	return res;
}
void ejercicio3()
{
	int cDeTerminos, x;
	cDeTerminos = obtenerCantidadDeTerminos();
	x = obtenerValorDeX();
	double sumatoria = 0.0;
	float termino;
	for (int i = 1; i <= cDeTerminos; i++)
	{
		termino =  (i * pow(x, i) - i * 10) / (factorial(i) + x);
		// pow(-1, i)
		if (i % 2 == 1) {
			termino *= - 1;
		}
		sumatoria += termino;
	}
	cout << "La sumatoria es: " << sumatoria << endl;
}

void dibujarCuadrado()
{
	int lado = 4;
	for (int i = 1; i <= lado; i++)
	{
		// dibuja lineas
		for (int j = 1; j <= lado; j++)
		{
			cout << "* ";
		}
		cout << endl;
	}
	// * * * *
	// ..
	// ..
}

void dibujarTriangulo()
{
	int lado = 3;
	// cuantas lineas hare
	for (int i = 1; i <= lado; i++)
	{
		// dibuja lineas
		for (int j = 1; j <= i; j++)
		{
			cout << "* ";
		}
		cout << endl;
	}
	// n = 3
	// i = 1 * 
	// i = 2 * *
	// i = 3 * * *
}
void dibujarArbol(int lado)
{
	// cuantas lineas hare
	for (int i = 1; i <= lado; i++)
	{
		for (int z = 1; z <= lado - i; z++)
		{
			cout << " ";
		}
		for (int j = 1; j <= i; j++)
		{
			cout << "* ";
		}
		cout << endl;
	}
	// n = 4
	// i = 1  ooo* 
	// i = 2  oo* *
	// i = 3  o* * *
	// i = 4  * * * *
}

void ejercicio1_5()
{
	int x, y, n;
	float termino;
	double sumatoria = 0.0;
	for (int i = 2; i <= n; i++)
	{
		sumatoria += pow(y, 2 * x) * pow(x, y) + ((x - y) * factorial(i)) / (pow(x, i) * pow(y, i + 1));
	}
}
int main()
{
	//Console::SetCursorPosition(20, 10);
	//cout << "*********";
	dibujarArbol(12);
	system("pause>0");
	return 0;
}