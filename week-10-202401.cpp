#include <iostream>
#include <conio.h>
#define WIDTH 80
#define HEIGHT 40
using namespace System;
using namespace std;

void ejercicio_1() {
	int* notas = new int[6];
	int sumaTotal = 0;
	cout << "Ingrese sus notas: ";
	for (int i = 0; i < 6; i++)
	{
		cin >> notas[i];
		sumaTotal += notas[i];
	}
	int minimaNota;
	minimaNota = notas[0];
	for (int i = 1; i < 6; i++)
	{
		minimaNota = min(minimaNota, notas[i]);
	}

	sumaTotal -= minimaNota;

	cout << "La nota que no se considera en el promedio seria: " << minimaNota << endl;
	cout << "El promedio es: " << sumaTotal / 5.0 << endl;

}

void ejercicio_3() {
	int n;
	cout << "Ingrese el numero de personas: ";
	cin >> n;
	int* personas = new int[n];
	int personasEntre30y50 = 0;
	int indiceMenor = 0;
	for (int i = 0; i < n; i++)
	{
		personas[i] = rand() % 101;
	}

	// Imprimir
	for (int i = 0; i < n; i++)
	{
		cout << personas[i] << ' ';
	}
	cout << endl;

	// Menor
	for (int i = 1; i < n; i++)
	{
		if (personas[i] < personas[indiceMenor]) {
			indiceMenor = i;
		}
	}
	cout << "El menor valor es: " << personas[indiceMenor];
	cout << " y su posicion es: " << indiceMenor + 1 << endl;

	// Personas entre 30 y 50
	for (int i = 0; i < n; i++)
	{
		if (personas[i] >= 30 && personas[i] <= 50) {
			personasEntre30y50++;
		}
	}
	cout << "Las personas entre 30 y 50 son: " << personasEntre30y50 << endl;
	// Buscar una edad
	int edadABuscar;
	cout << "Ingrese una edad a buscar: ";
	cin >> edadABuscar;
	for (int i = 0; i < n; i++)
	{
		if (edadABuscar == personas[i]) {
			cout << "Se encontro a la persona en esta posicion: " << i + 1 << endl;
			break;
		}
	}
}

void ejercicio_6() {
	int size = 20;
	bool* primos = new bool[size];
	for (int i = 0; i < size; i++)
	{
		primos[i] = 1;
	}

	// No llega a 5
	for (int i = 2; i * i <= size; i++)
	{
		if (primos[i]) {
			for (int j = i * i; j <= size; j += i)
			{
				primos[j] = 0;
			}
			// impresion
			for (int i = 2; i <= size; i++)
			{
				if (primos[i]) {
					cout << i << ' ';
				}
				else {
					cout << "-1 ";
				}
			}
			cout << endl;
		}
	}
	
}


void borrar(int x, int y, int ancho) {
	for (int i = 0; i < ancho; i++)
	{
		Console::SetCursorPosition(x + i, y);
		cout << ' ';
	}
}
void dibujar(int x, int y, int ancho) {
	for (int i = 0; i < ancho; i++)
	{
		Console::SetCursorPosition(x + i, y);
		cout << '*';
	}
}
void mover(int& x, int& y, int& dx, int& dy, int ancho) {
	if (x + dx < 0 || x + ancho + dx >= WIDTH) {
		dx *= -1;
	}
	if (y + dy < 0 || y + dy >= HEIGHT) {
		dy *= -1;
	}
	x += dx;
	y += dy;
}

bool colisionar(int xc, int yc, int x2, int y2, int ancho2) {
	for (int i = 0; i < ancho2; i++) {
		if (yc == y2 && xc == x2 + i) {
			return true;
		}
	}
	return false;
}
// x1 < x2 + ancho2 &&  x2 < x1 + ancho1 && y1 < y2 + alto2 && y2 < y1 + alto1
void ejercicio_6_animaciones() {
	int xc, yc, dxc, dyc;
	// arr figuras
	int numFiguras = rand() % 6 + 3;
	int* arrx, * arry, * arrdx, * arrdy, * arrAnchos;
	arrx = new int[numFiguras];
	arry = new int[numFiguras];
	arrdx = new int[numFiguras];
	arrdy = new int[numFiguras];
	arrAnchos  = new int[numFiguras];
	// asignamos valores
	xc = 0;
	yc = HEIGHT - 1;
	dxc = 1;
	dyc = 0;
	for (int i = 0; i < numFiguras; i++)
	{
		arrx[i] = rand() % WIDTH;
		arry[i] = rand() % HEIGHT;
		arrdx[i] = rand() % 2;
		arrdy[i] = rand() % 2;
		arrAnchos[i] = rand() % 3 + 2;
	}
	arrx[0] = WIDTH - 15;
	arry[0] = HEIGHT - 1;
	arrdx[0] = -1;
	arrdy[0] = 0;
	arrAnchos[0] = 9;
	while (true)
	{
		Console::SetCursorPosition(xc, yc);
		cout << ' ';
		for (int i = 0; i < numFiguras; i++)
		{
			borrar(arrx[i], arry[i], arrAnchos[i]);
		}
		mover(xc, yc, dxc, dyc, 1);
		for (int i = 0; i < numFiguras; i++)
		{
			mover(arrx[i], arry[i], arrdx[i], arrdy[i], arrAnchos[i]);
		}
		// comprobamos colision
		for (int i = 0; i < numFiguras; i++)
		{
			if (colisionar(xc, yc, arrx[i], arry[i], arrAnchos[i])) {
				Console::Clear();
				cout << "Colisionaron...";
				system("pause>0");
			}
		}
		Console::SetCursorPosition(xc, yc);
		cout << 'o';
		for (int i = 0; i < numFiguras; i++)
		{
			dibujar(arrx[i], arry[i], arrAnchos[i]);
		}
		_sleep(40);
	}
}
int main()
{
	Console::SetWindowSize(WIDTH, HEIGHT);
	Console::CursorVisible = false;
	srand(time(nullptr));
	ejercicio_6_animaciones();
	system("pause>0");
	return 0;
}