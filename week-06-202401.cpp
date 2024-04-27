#include <iostream>
#define WIDTH 40
#define HEIGHT 20
using namespace System;
using namespace std;

int leer_n() {
	int n;
	// solicito el numero si no esta fuera de mi rango ]3, 10]
	do
	{
		cout << "Ingrese un numero: ";
		cin >> n;
	} while (n < 3 || n > 10);
	return n;
}
void dibujar_triangulo(int identificador, int espacios)
{
	int lado = 4;
	// aqui indico cuantas lineas dibujo
	for (int i = 1; i <= lado; i++)
	{
		// aqui dibujo mis espacios
		for (int k = 1; k <= espacios; k++)
		{
			cout << "  ";
		}
		// aqui dibujo mis lineas
		for (int j = 1; j <= i; j++)
		{
			if (i == 3 && j == 2) {
				cout << identificador << " ";
			}
			else {
				cout << "* ";
			}
		}
		cout << endl;
	}
}
void ejercicio1() {
	int n = leer_n();
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			dibujar_triangulo(i, 4 * (j - 1));
		}
		cout << endl;
	}
}
int main()
{
	Console::SetWindowSize(WIDTH, HEIGHT);
	Console::CursorVisible = false;
	long long timeSleep = 50;
	while (true)
	{
		for (int i = 0; i < WIDTH - 1; i++)
		{
			Console::SetCursorPosition(i, 0);
			cout << " *";
			_sleep(timeSleep);
		}
		for (int i = 0; i < HEIGHT - 1; i++)
		{
			Console::SetCursorPosition(WIDTH - 1, i);
			cout << " ";
			Console::SetCursorPosition(WIDTH - 1, i + 1);
			cout << "*";
			_sleep(timeSleep);
		}
		for (int i = WIDTH - 1; i >= 0; i--)
		{
			Console::SetCursorPosition(i, HEIGHT - 1);
			cout << "* ";
			_sleep(timeSleep);
		}
		for (int i = HEIGHT - 1; i >= 1; i--)
		{
			Console::SetCursorPosition(0, i - 1);
			cout << "*";
			Console::SetCursorPosition(0, i);
			cout << " ";
			_sleep(timeSleep);
		}
	}
	system("pause>0");
	return 0;
}