#include <iostream>
#define WIDTH 80
#define HEIGHT 40
using namespace System;
using namespace std;

void dibujarCuadradoHorario()
{
	int x, y;
	x = 0; y = 0;
	do
	{
		Console::SetCursorPosition(x, y);
		cout << " *";
		_sleep(10);
		x++;
	} while (x < WIDTH - 1);
	do
	{
		Console::SetCursorPosition(x, y);
		cout << " ";
		Console::SetCursorPosition(x, y + 1);
		cout << "*";
		_sleep(10);
		y++;
	} while (y < HEIGHT - 1);
	do
	{
		Console::SetCursorPosition(x, y);
		cout << "* ";
		_sleep(10);
		x--;
	} while (x > 0);
	Console::SetCursorPosition(x + 1, y);
	cout << " ";
	do
	{
		Console::SetCursorPosition(x, y - 1);
		cout << "*";
		Console::SetCursorPosition(x, y);
		cout << " ";
		_sleep(10);
		y--;
	} while (y > 0);
}
void dibujarCuadradoAntihorario()
{
	int borde = 5;
	int x, y;
	x = 4; y = 2;
	do
	{
		Console::SetCursorPosition(x, y);
		cout << " ";
		Console::SetCursorPosition(x, y + 1);
		cout << "*";
		_sleep(10);
		y++;
	} while (y < HEIGHT - (1 + borde));
	do
	{
		Console::SetCursorPosition(x, y);
		cout << " *";
		_sleep(10);
		x++;
	} while (x < WIDTH - (1 + borde));
	do
	{
		Console::SetCursorPosition(x, y - 1);
		cout << "*";
		Console::SetCursorPosition(x, y);
		cout << " ";
		_sleep(10);
		y--;
	} while (y > borde);
	Console::SetCursorPosition(x, y);
	cout << " ";
	do
	{
		Console::SetCursorPosition(x, y);
		cout << "* ";
		_sleep(10);
		x--;
	} while (x > borde);
	Console::SetCursorPosition(x + 1, y);
	cout << " ";
	
}
void ejercicio1_6A()
{
	while (true)
	{
		dibujarCuadradoHorario();
	}
}
void ejercicio2_6A()
{
	Console::SetWindowSize(WIDTH, HEIGHT);
	Console::CursorVisible = false;
	while (true)
	{
		//dibujarCuadradoHorario();
		dibujarCuadradoAntihorario();
	}
}

//void validar
int fct(int x)
{
	int facto = 1;
	for (int i = 2; i <= x; i++) {
		facto = facto * i;
	}
	return facto;
}
int validarCT()
{
	int n;
	do
	{
		cout << "Cantidad de terminos: ";
		cin >> n;
	} while (n <= 5 || n >= 10);
	return n;
}
int validarVar(char c)
{
	int n;
	do
	{
		cout << "Valor de " << c << " [2, 4] : ";
		cin >> n;
	} while (n < 2 || n > 4);
	return n;
}
void ejercicio1_6B()
{
	int n, a, b;
	n = validarCT();
	a = validarVar('a');
	b = validarVar('b');
	int x = 1;
	double suma = 0.0;
	int numerador;
	int denominador;
	for (int i = 1; i <= n; i++)
	{
		if (i % 2 == 1) {
			numerador = pow(-1, i) * pow((a + i), b);
			denominador = b + fct(x);
		}
		else {
			numerador = pow(-1, i) * pow((b - i), a);
			denominador = b + fct(x);
		}
		cout << numerador << "/" << denominador << " ; ";
		suma = suma + (numerador * 1.0)/ denominador;
		if (x % 7 == 0) x = 0;
		x++;
	}
	cout << '\n' << suma << '\n';
}

int validarN(int limInf, int limSup)
{
	int n;
	do
	{
		cout << "Ingrese un numero: ";
		cin >> n;
	} while (n < limInf || n > limSup);
	return n;
}
void ejercicio11_6C()
{
	int n = validarN(2, 6);
	for (int i = 1; i <= 2 * n - 1; i++)
	{
		for (int j = 1; j <= n; j++) {
			if (i <= n) {
				Console::SetCursorPosition(i, j + i);
			}
			else {
				Console::SetCursorPosition(i, j + i - (2 * (i - n)));
			}
			cout << char(64 + j);
		}
	}

}
void ejercicio12_6C()
{
	int n = validarN(4, 7);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n * n; j ++) {
			if (j % n == i || j % n == 0 || i == 1)
			{
				Console::SetCursorPosition(j, i);
				cout << n;

			}
		}
	}
}
void ejercicio12_6Cforma()
{
	int n = validarN(4, 7);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 2; j <= 2 * n * n; j += 2) {
			if (j / 2 % n == i || j / 2 % n == 0 || i == 1)
			{
				Console::SetCursorPosition(j, i);
				cout << n;

			}
		}
	}
}
int main()
{
	
	ejercicio12_6C();
	system("pause>0");
	return 0;
}