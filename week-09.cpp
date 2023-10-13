#include <iostream>
#define WIDTH 80
#define HEIGHT 40
using namespace System;
using namespace std;

void Generar_numeros(int* a, int* b, int* c, int* d)
{
	do
	{
		*a = rand() % 40 + 1;
		*b = rand() % 40 + 1;
		*c = rand() % 40 + 1;
		*d = rand() % 40 + 1;
	} while (*a == *b || *a == *c || *a == *d || *b == *c ||
		*b == *d || *c == *d);
}
void imprimirNumeros(int* a, int* b, int* c, int* d)
{
	cout << "a: " << *a << ", " << "b: " << *b << ", ";
	cout << "c: " << *c << ", " << "d: " << *d << '\n';
}
int Hallar_mayor(int* a, int* b, int* c, int* d)
{
	int mayor = *a;
	if (*b > mayor) mayor = *b;
	if (*c > mayor) mayor = *c;
	if (*d > mayor) mayor = *d;
	return mayor;
}
int Hallar_menor(int* a, int* b, int* c, int* d)
{
	int menor = *a;
	if (*b < menor) menor = *b;
	if (*c < menor) menor = *c;
	if (*d < menor) menor = *d;
	return menor;
}
void intercambiar(int* n1, int* n2)
{
	int aux = *n1;
	*n1 = *n2;
	*n2 = aux;
}
void ordenar(int* a, int* b, int* c, int* d)
{
	if (*a > *b) intercambiar(a, b);
	if (*a > *c) intercambiar(a, c);
	if (*a > *d) intercambiar(a, d);

	if (*b > *c) intercambiar(b, c);
	if (*b > *d) intercambiar(b, d);

	if (*c > *d) intercambiar(c, d);
}
int Hallar_anterior_mayor(int* a, int* b, int* c, int* d)
{
	ordenar(a, b, c, d);
	return *c;
}
void escalon(int* n, int y)
{
	if (*n > 9) Console::SetCursorPosition(WIDTH - (*n + 2), y);
	else Console::SetCursorPosition(WIDTH - (*n + 1), y);
	cout << *n;
	for (int i = 0; i < *n; i++)
	{
		cout << "*";
	}
}
void dibujar(int* a, int* b, int* c, int* d)
{
	ordenar(a, b, c, d);
	escalon(a, 1);
	escalon(b, 2);
	escalon(c, 3);
	escalon(d, 4);
}
void ejercicio1()
{
	int* a, * b, * c, * d;
	a = new int; b = new int; c = new int; d = new int;
	Generar_numeros(a, b, c, d);
	imprimirNumeros(a, b, c, d);
	cout << "El mayor es: " << Hallar_mayor(a, b, c, d) << '\n';
	cout << "El menor es: " << Hallar_menor(a, b, c, d) << '\n';
	cout << "El anterior a mayor es: " << Hallar_anterior_mayor(a, b, c, d) << '\n';
	ordenar(a, b, c, d);
	imprimirNumeros(a, b, c, d);
	dibujar(a, b, c, d);
}

void menu()
{
	cout << "\tMENU PRINCIPAL\n";
	cout << "1) Determinar el factorial de un numero\n";
	cout << "2) Calcular el valor de ea\n";
	cout << "3) Imprime rombo\n";
	cout << "4) Fin\n";
	cout << "Ingrese su opcion: ";
}
long long factorial(int n)
{
	long long fct = 1;
	for (int i = n; i > 1; i--)
	{
		fct *= i;
	}
	return fct;
}
void caso1()
{
	int n;
	cout << "Ingrese el valor de n: "; 
	cin >> n;
	cout << "El factorial de " << n << " es: " << factorial(n);
}
double ea(int k, int a)
{
	if (k == 0) return 0.0;
	if (k == 1) return 1.0;
	if (k == 2) return 1 + a;
	double ea = 1 + a;
	for (int i = 2; i <= k; i++)
	{
		ea -= pow(a, i) / factorial(i);
		// Adaptacion para intercalar signos
		/*if (i % 2 == 0) ea -= pow(a, i) / factorial(i);
		else ea += pow(a, i) / factorial(i);
		*/
	}
	return ea;
}
void caso2()
{
	int k, a;
	do
	{
		cout << "Ingrese el valor de k: "; cin >> k;
	} while (k > 20);
	cout << "Ingrese el valor de a: "; cin >> a;
	cout << "El volar de ea es: " << ea(k, a);
}
int obtenerN(int limInf, int limSup)
{
	int n;
	do
	{
		cout << "Ingrese el valor de n: ";
		cin >> n;
	} while (n < limInf || n > limSup);
	return n;
}
void caso3()
{
	int n = obtenerN(1, 10);
	for (int i = 1; i <= 2 * n - 1; i++)
	{
		for (int e = 0; e < abs(n - i); e++)
		{
			cout << "  ";
		}
		int lim;
		if (i <= n) lim = 2 * i - 1;
		else lim = 2 * (2 * n - 1) - (2 * i - 1);
		for (int j = 1; j <= lim; j++)
		{
			cout << j << ' ';
		}
		cout << '\n';
	}
}
void ejercicio2()
{
	int opc;
	do
	{
		Console::Clear();
		menu();
		cin >> opc;
		switch (opc)
		{
		case 1: caso1(); break;
		case 2: caso2(); break;
		case 3: caso3(); break;
		case 4: cout << "Programa terminado..."; break;
		default: cout << "Opcion invalida"; break;
		}
		getchar();
		getchar();
	} while (opc != 4);
}

void imprimirNumComplejo(double pReal, double pImg)
{
	cout << "(" << pReal << "+" << pImg << "i)";
}
void sumarComplejos(double* n1pr, double* n1pi, double* n2pr, double* n2pi)
{
	imprimirNumComplejo(*n1pr, *n1pi);
	cout << " + ";
	imprimirNumComplejo(*n2pr, *n2pi);
	cout << " = ";
	imprimirNumComplejo(*n1pr + *n2pr, *n1pi + *n2pi);
}
void restarComplejos(double* n1pr, double* n1pi, double* n2pr, double* n2pi)
{
	imprimirNumComplejo(*n1pr, *n1pi);
	cout << " - ";
	imprimirNumComplejo(*n2pr, *n2pi);
	cout << " = ";
	imprimirNumComplejo(*n1pr - *n2pr, *n1pi - *n2pi);
}
void ejercicio3()
{
	double* n1pr, * n1pi, * n2pr, * n2pi;
	n1pr = new double; n1pi = new double; n2pr = new double; n2pi = new double;
	cout << "Numero 1\n";
	cout << "Parte Real: "; cin >> *n1pr;
	cout << "Parte Imaginaria: "; cin >> *n1pi;

	cout << "Numero 2\n";
	cout << "Parte Real: "; cin >> *n2pr;
	cout << "Parte Imaginaria: "; cin >> *n2pi;
	sumarComplejos(n1pr, n1pi, n2pr, n2pi);
	restarComplejos(n1pr, n1pi, n2pr, n2pi);
}
int main()
{
	srand(time(NULL));
	Console::SetWindowSize(WIDTH, HEIGHT);
	ejercicio3();
	system("pause>0");
	return 0;
}