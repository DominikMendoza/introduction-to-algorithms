#include <iostream>
#define WIDTH 80
#define HEIGHT 40
using namespace System;
using namespace std;

void Generar_numeros(int* n1, int* n2, int* n3, int* n4) {
	do
	{
		*n1 = rand() % (40) + 1;
		*n2 = rand() % (40) + 1;
		*n3 = rand() % (40) + 1;
		*n4 = rand() % (40) + 1;
	} while (*n1 == *n2 || *n1 == *n3 || *n1 == *n4 ||
		*n2 == *n3 || *n2 == *n4 || *n3 == *n4);
}

void imprimirNumeros(int* n1, int* n2, int* n3, int* n4) {
	cout << *n1 << ' ' << *n2 << ' ' << *n3 << ' ' << *n4 << endl;
}

void Hallar_mayor(int* n1, int* n2, int* n3, int* n4) {
	int valorMayor = *n1;
	if (*n2 > valorMayor) {
		valorMayor = *n2;
	}
	if (*n3 > valorMayor) {
		valorMayor = *n3;
	}
	if (*n4 > valorMayor) {
		valorMayor = *n4;
	}
	cout << "El mayor valor es: " << valorMayor << endl;
}

void Hallar_menor(int* n1, int* n2, int* n3, int* n4) {
	int valorMenor = *n1;
	if (*n2 < valorMenor) {
		valorMenor = *n2;
	}
	if (*n3 < valorMenor) {
		valorMenor = *n3;
	}
	if (*n4 < valorMenor) {
		valorMenor = *n4;
	}
	cout << "El menor valor es: " << valorMenor << endl;
}


void inter(int* p1, int* p2) {
	int* pAux = new int;
	*pAux = *p1;
	*p1 = *p2;
	*p2 = *pAux;
	delete pAux;
}

void Hallar_anterior_mayor(int* n1, int* n2, int* n3, int* n4) {
	if (*n2 < *n1) {
		swap(*n1, *n2);
	}
	if (*n3 < *n1) {
		inter(n1, n3);
	}
	if (*n4 < *n1) {
		inter(n1, n4);
	}

	if (*n3 < *n2) {
		inter(n2, n3);
	}
	if (*n4 < *n2) {
		inter(n2, n4);
	}

	if (*n4 < *n3) {
		inter(n3, n4);
	}

	cout << "El anterior a mayor es: " << *n3 << endl;
}

void dibujarEscalon(int* p, int altura) {
	if (*p < 10) {
		Console::SetCursorPosition(WIDTH - 2 - *p, altura);
	}
	else {
		// *valor del puntero - 1
		Console::SetCursorPosition(WIDTH - 2 - *p - 1, altura);
	}
	cout << *p;
	for (int i = 1; i <= *p; i++)
	{
		cout << "*";
	}
}
void Graficar(int* n1, int* n2, int* n3, int* n4) {
	dibujarEscalon(n1, 2);
	dibujarEscalon(n2, 3);
	dibujarEscalon(n3, 4);
	dibujarEscalon(n4, 5);
}

void ejercicio_1() {
	int* n1, * n2, * n3, * n4;
	n1 = new int;
	n2 = new int;
	n3 = new int;
	n4 = new int;
	imprimirNumeros(n1, n2, n3, n4);
	Generar_numeros(n1, n2, n3, n4);
	imprimirNumeros(n1, n2, n3, n4);
	Hallar_mayor(n1, n2, n3, n4);
	Hallar_menor(n1, n2, n3, n4);
	Hallar_anterior_mayor(n1, n2, n3, n4);
	imprimirNumeros(n1, n2, n3, n4);
	Graficar(n1, n2, n3, n4);
	delete n1, n2, n3, n4;
}

long long factorial(int x) {
	long long facto = 1;
	for (int i = 2; i <= x; i++)
	{
		facto *= i;
	}
	return facto;
}

void validarNumero(int* x, int limInf, int limSup, char forma) {
	do
	{
		cout << "Ingrese el valor de " << forma << ": ";
		cin >> *x;
	} while (*x < limInf || *x > limSup);
}
void dibujarRombo() {

	int* n = new int;
	validarNumero(n, 1, 11, 'n');
	int columnas;
	for (int i = 1; i <= 2 * *n - 1; i++) {
		for (int e = 1; e <= abs(*n - i); e++)
		{
			cout << "  ";
		}
		if (i <= *n) {
			columnas = 2 * i - 1;
		}
		else {
			columnas = 2 * (2 * *n - i) - 1;
		}
		for (int j = 1; j <= columnas; j++)
		{
			if (j <= 9)
				cout << j << ' ';
			else
				cout << j;
		}
		cout << endl;
	}
	delete n;
}
void exponencial() {
	int* k, * a;
	k = new int;
	validarNumero(k, 1, 20, 'k');
	a = new int;
	validarNumero(a, 2, 5, 'a');
	double* sumatoria = new double;
	*sumatoria = 1;
	for (int i = 1; i <= *k; i++)
	{
		*sumatoria += pow(*a, i) / factorial(i);
	}
	cout << "La suma es: " << *sumatoria << endl;
	delete k, a, sumatoria;
}

void ejercicio_2() {
	int opc;
	do
	{
		Console::Clear();
		cout << "MENU PRINCIPAL\n";
		cout << "1) Determinar factorial...\n";
		cout << "2) Calcular el valo de ea\n";
		cout << "3) Imprime rombo\n";
		cout << "4) Fin\n";
		cin >> opc;
		switch (opc)
		{
		case 1: int x; cout << "Ingrese el valor de numero: ";
			cin >> x; cout << "El factorial es: " << factorial(x); break;
		case 2: exponencial(); break;
		case 3: dibujarRombo(); break;
		}
		system("pause>0");
	} while (opc != 4);
	
}
int main()
{
	Console::SetWindowSize(WIDTH, HEIGHT);
	srand(time(nullptr));
	ejercicio_2();
	system("pause>0");
	return 0;
}