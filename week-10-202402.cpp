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

void dibujarFiguras(int* sizes, int* colores, int* coordX, int* coordY, bool* visibles, int nFiguras) {
	for (int i = 0; i < nFiguras; i++)
	{
		if (!visibles[i]) continue;
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


bool colisionarObjetos(int x1, int y1, int size1, int x2, int y2, int size2) {
	if (y1 != y2) {
		return false;
	}
	for (int i = 0; i < size1; i++)
	{
		for (int j = 0; j < size2; j++)
		{
			if (x1 + i == x2 + j) {
				return true;
			}
		}
	}
	return false;
	//return (x1 <= x2 + size2 && x2 < x1 + size1);
}

void verificarColisiones(int* sizes, int* coordX, int* coordY, bool* visibles, int nFiguras) {
	for (int i = 0; i < nFiguras; i++)
	{
		if (!visibles[i]) continue;
		for (int j = 0; j < nFiguras; j++)
		{
			if (i == j || !visibles[j]) continue;
			if (colisionarObjetos(coordX[i], coordY[i], sizes[i], coordX[j], coordY[j], sizes[j])) {
				visibles[i] = visibles[j] = false;
				return;
			}
		}
	}
}

void moverFiguras(int* sizes, int* coordX, int* coordY, int* deltaX, int* deltaY, bool* visibles, int nFiguras) {
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
		verificarColisiones(sizes, coordX, coordY, visibles, nFiguras);
	}
}

void ejercicio_2_10A() {
	int numeroFiguras = rand() % 11 + 5;
	int* sizes = new int[numeroFiguras];
	int* colores = new int[numeroFiguras];
	int* coordX = new int[numeroFiguras];
	int* coordY = new int[numeroFiguras];
	int* deltaX = new int[numeroFiguras];
	int* deltaY = new int[numeroFiguras];
	bool* visibles = new bool[numeroFiguras];
	for (int i = 0; i < numeroFiguras; i++)
	{
		sizes[i] = rand() % 4 + 5;
		colores[i] = rand() % 15 + 1;
		coordX[i] = rand() % (WIDTH - 1 - sizes[i]);
		coordY[i] = rand() % (HEIGHT - 2);
		visibles[i] = true;
		do
		{
			deltaX[i] = rand() % 3 - 1;
			deltaY[i] = rand() % 3 - 1;
		} while (deltaX[i] == 0 || deltaY[i] == 0);
	}
	while (true)
	{
		borrarFiguras(sizes, coordX, coordY, numeroFiguras);
		moverFiguras(sizes, coordX, coordY, deltaX, deltaY, visibles, numeroFiguras);
		//verificarColisiones(sizes, coordX, coordY, visibles, numeroFiguras);
		dibujarFiguras(sizes, colores, coordX, coordY, visibles, numeroFiguras);
		_sleep(90);
	}
}

void ejercicio_5_10() {
	int n;
	cout << "Ingrese el tamano del arreglo: ";
	cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 55;
		cout << arr[i] << ' ';
	}
	cout << endl << endl;

	for (int i = 0; i < n - 1; i++)
	{
		cout << arr[i];
		if (arr[i] > arr[i + 1]) {
			cout << endl;
		}
		else {
			cout << ' ';
		}
	}
	// size = 5 -> 0 1 2 3 4
	cout << arr[n - 1];
}
int main()
{
	Console::SetWindowSize(WIDTH, HEIGHT);
	Console::CursorVisible = false;
	srand(time(nullptr));
	ejercicio_5_10();
	system("pause>0");
	return 0;
}
