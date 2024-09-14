#include <iostream>
#define WIDTH 50
#define HEIGHT 20
using namespace System;
using namespace std;

long long factorial(int num) {
	long long facto = 1;
	for (int i = 2; i <= num; i++)
	{
		facto *= i; // facto = facto * i
	}
	return facto;
}

int validarNumero(char letra, int limInf, int limSup) {
	int num;
	do
	{
		cout << "Ingrese el valor de ";
		cout << letra << ": ";
		cin >> num;
	} while (num < limInf || num > limSup);
	return num;
}

void ejercicio_5A() {
	int n, x, y;
	n = validarNumero('n', 1, 20);
	x = validarNumero('x', 2, 10);
	y = validarNumero('y', 2, 5);

	double sumatoria = 0.0;

	for (int i = 1; i <= n; i++)
	{
		double primerTermino = pow(y, (2 * x)) * pow(x, y);
		double segundoTermino = ((x - y) * factorial(i)) / (pow(x, i) * pow(y, i + 1));
		sumatoria += primerTermino + segundoTermino;
	}

	cout << "La suma es: " << sumatoria << endl;
}

void dibujarCuadradoRelleno() {
	int n = 5;
	// dibujo n lineas
	for (int i = 1; i <= n; i++)
	{
		// dibujo linea
		for (int j = 1; j <= n; j++)
		{
			cout << "* ";
		}
		cout << endl;
	}
}

void dibujarTriangulo() {
	int n = 5;
	// dibujo n lineas
	for (int i = 1; i <= n; i++)
	{
		// dibujo i asteriscsos
		for (int j = 1; j <= i; j++)
		{
			cout << "* ";
		}
		cout << endl;
	}
}

void dibujarTrianguloCentrado() {
	int n = 8;
	// dibujo n lineas
	for (int i = 1; i <= n; i++)
	{
		// dibujo n - i espacios en blanco
		for (int e = 1; e <= n - i; e++)
		{
			cout << " ";
		}
		// dibujo i asteriscsos
		for (int j = 1; j <= i; j++)
		{
			cout << "* ";
		}
		cout << endl;
	}
}

void animacion() {
	Console::SetWindowSize(WIDTH, HEIGHT);
	Console::CursorVisible = false;
	
	int x, y, dx, dy;
	x = 5, y = 8;
	dx = 0;
	dy = 1;

	while (true)
	{
		// borrar
		Console::SetCursorPosition(x, y);
		cout << " ";

		// mover
		if (x + dx < 0 || x + dx >= WIDTH) {
			dx *= -1;
		}
		if (y + dy < 0 || y + dy >= HEIGHT) {
			dy *= -1;
		}
		x += dx;
		y += dy;

		// dibujar
		Console::SetCursorPosition(x, y);
		cout << "*";
		_sleep(40);
	}
}
int main()
{
	animacion();
	system("pause>0");
	return 0;
}