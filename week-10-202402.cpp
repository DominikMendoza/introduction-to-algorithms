#include <iostream>
#define MAX_SIZE 22
#define WIDTH 80
#define HEIGHT 40

using namespace System;
using namespace std;

void criba() {
	bool esPrimo[MAX_SIZE];
	for (int i = 0; i < MAX_SIZE; i++)
	{
		esPrimo[i] = true;
	}
	esPrimo[0] = false;
	esPrimo[1] = false;

	for (int p = 2; p * p < MAX_SIZE; p++)
	{
		if (esPrimo[p]) {
			for (int i = p * p; i < MAX_SIZE; i += p)
			{
				esPrimo[i] = false;
			}
		}
	}

	for (int i = 2; i < MAX_SIZE; i++)
	{
		if (esPrimo[i]) {
			cout << i << " ";
		}
		else {
			cout << "-1 ";
		}
	}
	cout << endl;
}

void dibujarFiguras(int* sizes, int* colores, int* coordX, int* coordY, int nFiguras) {
	for (int i = 0; i < nFiguras; i++)
	{
		Console::SetCursorPosition(coordX[i], coordY[i]);
		Console::ForegroundColor = ConsoleColor(colores[i]);
		for (int j = 0; j < sizes[i]; j++)
		{
			cout << "*";
		}
	}
}

void borrarFiguras(int* sizes, int* coordX, int* coordY, int nFiguras) {
	for (int i = 0; i < nFiguras; i++)
	{
		Console::SetCursorPosition(coordX[i], coordY[i]);
		for (int j = 0; j < sizes[i]; j++)
		{
			cout << " ";
		}
	}
}

void moverFiguras(int* sizes, int* coordX, int* coordY, int* deltaX, int* deltaY, int nFiguras) {
	for (int i = 0; i < nFiguras; i++)
	{
		if (coordX[i] + deltaX[i] < 0 || coordX[i] + deltaX[i] + sizes[i] >= WIDTH) {
			deltaX[i] *= -1;
		}
		if (coordY[i] + deltaY[i] < 0 || coordY[i] + deltaY[i] >= HEIGHT) {
			deltaY[i] *= -1;
		}
		coordX[i] += deltaX[i];
		coordY[i] += deltaY[i];
	}
}

void ejercicio_2_10A() {
	int numeroFiguras = 4;
	int* sizes = new int[numeroFiguras];
	int* colores = new int[numeroFiguras];
	int* coordX = new int[numeroFiguras];
	int* coordY = new int[numeroFiguras];
	int* deltaX = new int[numeroFiguras];
	int* deltaY = new int[numeroFiguras];
	for (int i = 0; i < numeroFiguras; i++)
	{
		sizes[i] = rand() % 3 + 2;
		colores[i] = rand() % 15 + 1;
		coordX[i] = rand() % (WIDTH - 1 - sizes[i]);
		coordY[i] = rand() % (HEIGHT - 2);
		deltaX[i] = rand() % 3 - 1;
		deltaY[i] = rand() % 3 - 1;
	}
	while (true)
	{
		borrarFiguras(sizes, coordX, coordY, numeroFiguras);
		moverFiguras(sizes, coordX, coordY, deltaX, deltaY, numeroFiguras);
		dibujarFiguras(sizes, colores, coordX, coordY, numeroFiguras);
		_sleep(90);
	}
}
int main()
{
	Console::SetWindowSize(WIDTH, HEIGHT);
	Console::CursorVisible = false;
	srand(time(nullptr));
	ejercicio_2_10A();
	system("pause>0");
	return 0;
}
