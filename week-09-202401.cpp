#include <iostream>
using namespace System;
using namespace std;

void incrementarNumero(float* ptNum) {
	*ptNum = *ptNum + 5;
	cout << "El numero en la funcion es: " << *ptNum << endl;
}
void teoria() {
	int num = 5;
	cout << "El numero es: " << num << endl;
	cout << "La direccion de memoria es: " << &num << endl;
	cout << endl;
	float* ptFloat;
	ptFloat = new float;
	*ptFloat = 3.9;
	cout << "El numero es: " << *ptFloat << endl;
	cout << "La direccion de memoria es: " << ptFloat << endl;
	incrementarNumero(ptFloat);
	cout << "El numero es: " << *ptFloat << endl;
}

void Generar_numeros(int* a, int* b, int* c, int* d) {
	do
	{
		// generar los numeros
		*a = rand() % 40 + 1;
		*b = rand() % 40 + 1;
		*c = rand() % 40 + 1;
		*d = rand() % 40 + 1;
	} while (*a == *b || *a == *c || *a == *d || *b == *c || *b == *d || *c == *d);
}

void Imprimir_numeros(int* a, int* b, int* c, int* d) {
	cout << "a: " << *a << endl;
	cout << "b: " << *b << endl;
	cout << "c: " << *c << endl;
	cout << "d: " << *d << endl;
}

int Hallar_mayor(int* a, int* b, int* c, int* d) {
	// max(int n1, int n2) -> mayor
	// max(a, max(b, max(c, d)))
	if (*a > *b && *a > *c && *a > *d) {
		return *a;
	}
	if (*b > *a && *b > *c && *b > *d) {
		return *b;
	}
	if (*c > *a && *c > *b && *c > *d) {
		return *c;
	}
	return *d;
}

int Hallar_menor(int* a, int* b, int* c, int* d) {
	if (*a < *b && *a < *c && *a < *d) {
		return *a;
	}
	if (*b < *a && *b < *c && *b < *d) {
		return *b;
	}
	if (*c < *a && *c < *b && *c < *d) {
		return *c;
	}
	return *d;
}

void intercambiar(int* n1, int* n2) {
	int* aux;
	aux = new int;
	*aux = *n1;
	*n1 = *n2;
	*n2 = *aux;
	delete aux;
}

void ordenar(int* a, int* b, int* c, int* d) {
	// comparaciones del a
	if (*b < *a) intercambiar(a, b);
	if (*c < *a) intercambiar(a, c);
	if (*d < *a) intercambiar(a, d);
	// comparaciones del b
	if (*c < *b) intercambiar(b, c);
	if (*d < *b) intercambiar(b, d);
	// comparaciones del c
	if (*d < *c) intercambiar(c, d);
}

int Hallar_Anterior_Mayor(int* a, int* b, int* c, int* d) {
	ordenar(a, b, c, d);
	return *c;
}

void dibujarEscalon(int* num, int* alt) {
	// si tiene 2 cifras
	if (*num > 9) {
		Console::SetCursorPosition(78 - *num, *alt);
	}
	// si tiene una cifra
	else {
		Console::SetCursorPosition(79 - *num, *alt);
	}
	cout << *num;
	for (int i = 0; i < *num; i++)
	{
		cout << '*';
	}
	*alt = *alt + 1;
}
void Graficar(int* a, int* b, int* c, int* d) {
	int* ptAlt;
	ptAlt = new int;
	*ptAlt = 2;
	dibujarEscalon(a, ptAlt);
	dibujarEscalon(b, ptAlt);
	dibujarEscalon(c, ptAlt);
	dibujarEscalon(d, ptAlt);
}

void ejercicio_1() {
	int* a, * b, * c, * d;
	a = new int;
	b = new int;
	c = new int;
	d = new int;
	Generar_numeros(a, b, c, d);
	Imprimir_numeros(a, b, c, d);
	cout << "El mayor es: " << Hallar_mayor(a, b, c, d) << endl;
	cout << "El menor es: " << Hallar_menor(a, b, c, d) << endl;
	cout << "El anterior a mayor es: " << Hallar_Anterior_Mayor(a, b, c, d) << endl;
	ordenar(a, b, c, d);
	cout << "Los numeros fueron ordenados\n";
	Imprimir_numeros(a, b, c, d);
	Graficar(a, b, c, d);
	delete a;
	delete b;
	delete c;
	delete d;
}

void imprimirNumeroComplejo(float* pr, float* pi) {
	cout << "(" << *pr << "+";
	if (*pi != 1) cout << *pi;
	cout << "i)";
}

void sumarComplejos(float* pr1, float* pi1, float* pr2, float* pi2) {
	float* prResultado, * piResultado;
	prResultado = new float;
	piResultado = new float;
	imprimirNumeroComplejo(pr1, pi1);
	cout << " + ";
	imprimirNumeroComplejo(pr2, pi2);
	cout << " = ";
	*prResultado = *pr1 + *pr2;
	*piResultado = *pi1 + *pi2;
	imprimirNumeroComplejo(prResultado, piResultado);
	cout << endl;
	delete prResultado;
	delete piResultado;
}

void restarComplejos(float* pr1, float* pi1, float* pr2, float* pi2) {
	float* prResultado, * piResultado;
	prResultado = new float;
	piResultado = new float;
	imprimirNumeroComplejo(pr1, pi1);
	cout << " - ";
	imprimirNumeroComplejo(pr2, pi2);
	cout << " = ";
	*prResultado = *pr1 - *pr2;
	*piResultado = *pi1 - *pi2;
	imprimirNumeroComplejo(prResultado, piResultado);
	cout << endl;
	delete prResultado;
	delete piResultado;
}

void ejercicio_2() {
	float* pr1, * pi1;
	float* pr2, * pi2;
	pr1 = new float;
	pi1 = new float;
	pr2 = new float;
	pi2 = new float;
	cout << "Numero 1\n";
	cout << "Parte real: ";
	cin >> *pr1;
	cout << "Parte imaginaria: ";
	cin >> *pi1;
	cout << "Numero 2\n";
	cout << "Parte real: ";
	cin >> *pr2;
	cout << "Parte imaginaria: ";
	cin >> *pi2;
	sumarComplejos(pr1, pi1, pr2, pi2);
	restarComplejos(pr1, pi1, pr2, pi2);
}
void ejercicio_3() {
	int n = 15;
	for (int i = 1; i <=  2 * n - 1; i++)
	{
		for (int e = 1; e <= abs(n - i); e++)
		{
			cout << "  ";
		}
		int limite;
		if (i > 5) {
			limite = 2 * n - 1 - (2 * (i - n));
		}
		else {
			limite = 2 * i - 1;
		}
		for (int j = 1; j <= limite; j++)
		{
			cout << j;
			if (j < 9) cout << ' ';
		}
		cout << endl;
	}
}
void rombo() {
	int n = 15;
	for (int i = 1; i <= n; i++)
	{
		for (int e = 1; e <= abs(n - i); e++)
		{
			cout << "  ";
		}
		for (int j = 1; j <= i * 2 - 1; j++)
		{
			cout << j;
			if (j < 9) cout << ' ';
		}
		cout << endl;
	}
	for (int i = 1; i <= n - 1; i++)
	{
		for (int e = 1; e <= i; e++)
		{
			cout << "  ";
		}
		for (int j = 1; j <= (n - i) * 2 - 1; j++)
		{
			cout << j;
			if (j < 9) cout << ' ';
		}
		cout << endl;
	}
}

long long calcularFactorial(long long facto) {
	long long factorial = 1;
	for (int i = 2; i <= facto; i++)
	{
		//factorial = factorial * i;
		factorial *= i;
	}
	return factorial;
}
double ea(double k, double a) {
	double sumatoria = 0.0;
	for (int i = 0; i <= k; i++)
	{
		sumatoria += pow(a, i) / calcularFactorial(i);
	}
	return sumatoria;
}
int main()
{
	srand(time(nullptr));
	cout << ea(2, 2);
	system("pause>0");
	return 0;
}