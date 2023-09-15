#include <iostream>
using namespace System;
using namespace std;

void ejercicio1()
{
	int numero;
	do
	{
		cout << "Ingrese numero: ";
		cin >> numero;
	} while (numero < 1 || numero > 9);
	for (int i = 1; i <= 10; i++)
	{
		cout << numero << " x " << i << " = " << numero * i << '\n';
	}
}
void ejercicio2()
{
	int n, m, sumaPares = 0, sumaImpares = 0;
	cout << "Ingrese la cantidad de numeros pares a sumar: ";
	cin >> n;
	cout << "Ingrese la cantidad de numeros impares a sumar : ";
	cin >> m;

	cout << "Sumatoria de pares = ";
	for (int i = 1; i <= n; i++)
	{
		cout << i * 2 << "+";
		sumaPares = sumaPares + i * 2;
	}
	cout << "= " << sumaPares << '\n';

	cout << "Sumatoria de pares = ";
	for (int i = 1; i <= m; i++)
	{
		cout << i * 2 - 1 << "+";
		sumaImpares = sumaImpares + i * 2 - 1;
	}
	cout << "= " << sumaImpares << '\n';
}
int obtenerNumeroValido(int limInf, int limSup)
{
	int n;
	do
	{
		cout << "Ingrese valor de N: ";
		cin >> n;
	} while (n < limInf || n > limSup);
	return n;
}
void ejercicio13()
{
	int N = obtenerNumeroValido(1, 10);
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (i == 1 || i == N || j == 1 || j == N)
			{
				cout << "* ";
			}
			else
			{
				cout << "  ";
			}
		}
		cout << '\n';
	}
}
void ejercicio14()
{
	int N = obtenerNumeroValido(1, 10);
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (i == 1 || i == N || j == 1 || j == N || i == j)
			{
				cout << "* ";
			}
			else
			{
				cout << "  ";
			}
		}
		cout << '\n';
	}
}
void ejercicio15()
{
	int N = obtenerNumeroValido(1, 10);
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			if (i == N || j == 1 || i == j)
			{
				cout << "* ";
			}
			else
			{
				cout << "  ";
			}
		}
		cout << '\n';
	}
}
void ejercicio16_1()
{
	int N = obtenerNumeroValido(1, 10);
	int t;
	cout << "Ingrese el numero de triangulos: ";
	cin >> t;
	for (int z = 0; z < t; z++)
	{
		for (int i = 1; i <= N; i++)
		{
			Console::SetCursorPosition(z * (N + 2), i + 2);
			for (int j = 1; j <= i; j++)
			{
				if (i == N || j == 1 || i == j)
				{
					cout << "*";
				}
				else
				{
					cout << " ";
				}
			}
		}
	}
}
void ejercicio16_2()
{
	int N = obtenerNumeroValido(1, 10);
	int t;
	cout << "Ingrese el numero de triangulos: ";
	cin >> t;

	for (int i = 1; i <= N; i++)
	{
		for (int z = 1; z <= t; z++)
		{
			for (int j = 1; j <= i; j++)
			{
				if (i == N || j == 1 || i == j)
				{
					cout << "* ";
				}
				else
				{
					cout << "  ";
				}
			}
			for (int e = 1; e <= N - i + 1; e++)
			{
				cout << "  ";
			}
		}
		cout << '\n';
	}
}

void ejercicio17()
{
	int N = obtenerNumeroValido(1, 10);
	for (int i = 1; i <= N; i++)
	{
		for (int e = 1; e <= N - i; e++)
		{
			cout << "  ";
		}
		for (int j = 1; j <= 2 * i - 1; j++)
		{
			if (j <= i)
				cout << j << ' ';
			else
				cout << 2 * i - j << ' ';
		}
		cout << '\n';
	}
}
int main()
{
	// while -> repetir segun condicion no times
	// do while -> primero ejecutamos luego verificamos
	// for -> repetir con rango determinado
	ejercicio17();

	system("pause>0");
	return 0;
}