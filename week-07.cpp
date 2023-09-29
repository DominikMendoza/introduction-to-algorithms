#include <iostream>
#include <conio.h>
#define WIDTH 80
#define HEIGHT 40
#define ARRIBA 72
#define ABAJO 80
#define DERECHA 77
#define IZQUIERDA 75
using namespace System;
using namespace std;

void animacionBasica()
{
	int x = 0, y = 0;
	int dx = 1, dy = 1;
	while (true)
	{
		// borrar
		Console::SetCursorPosition(x, y);
		cout << ' ';
		// mover
		// rebotar en los limites
		if (x + dx >= WIDTH || x + dx < 0) {
			dx = dx * -1;
		}
		if (y + dy >= HEIGHT || y + dy < 0) {
			dy = dy * -1;
		}
		// actualizar coordenadas
		x = x + dx;
		y = y + dy;
		// dibuja
		Console::SetCursorPosition(x, y);
		cout << '*';
		_sleep(40);
	}
}
void animacionControlada()
{
	// objeto principal
	int x = 0, y = 0;
	int dx = 0, dy = 0;

	while (true)
	{
		// borrar
		Console::SetCursorPosition(x, y);
		cout << ' ';
		// mover
		// detectar teclas
		if (kbhit()) {
			char t = getch();
			switch (t)
			{
			case ABAJO: dy = 1; dx = 0; break;
			case ARRIBA: dy = -1; dx = 0; break;
			case DERECHA: dx = 1; dy = 0; break;
			case IZQUIERDA: dx = -1; dy = 0; break;
			}
		}
		// verificar que no se salga de los limities
		if (x + dx >= WIDTH || x + dx < 0) {
			dx = 0;
		}
		if (y + dy >= HEIGHT || y + dy < 0) {
			dy = 0;
		}
		x += dx;
		y += dy;
		// evitar que continue el movimento
		dx = 0;
		dy = 0;
		// dibuja
		Console::SetCursorPosition(x, y);
		cout << '*';
		_sleep(40);
	}
}
void animacionConProyectil()
{
	// objeto principal
	int x = 0, y = 0;
	int dx = 0, dy = 0;

	// proyectil
	int xp, yp, dxp = 1;
	bool esVisible = false;

	while (true)
	{
		// borrar
		Console::SetCursorPosition(x, y);
		cout << ' ';
		// proyectil
		if (esVisible) {
			Console::SetCursorPosition(xp, yp);
			cout << ' ';
		}
		// mover
		// detectar teclas
		if (kbhit()) {
			char t = getch();
			switch (t)
			{
			case ABAJO: dy = 1; dx = 0; break;
			case ARRIBA: dy = -1; dx = 0; break;
			case DERECHA: dx = 1; dy = 0; break;
			case IZQUIERDA: dx = -1; dy = 0; break;
			case 32: {
				esVisible = true;
				xp = x + 1;
				yp = y;
			}; break;
			}
		}
		// verificar que no se salga de los limities
		if (x + dx >= WIDTH || x + dx < 0) {
			dx = 0;
		}
		if (y + dy >= HEIGHT || y + dy < 0) {
			dy = 0;
		}
		x += dx;
		y += dy;

		if (esVisible) {
			xp += dxp;
		}
		if (xp + dxp >= WIDTH) {
			esVisible = false;
		}
		// evitar que continue el movimento
		//dx = 0;
		//dy = 0;
		// dibuja
		Console::SetCursorPosition(x, y);
		cout << '*';
		// proyectil
		if (esVisible) {
			Console::SetCursorPosition(xp, yp);
			cout << '-';
		}
		_sleep(40);
	}
}

void dibujar(int x, int y)
{
	Console::SetCursorPosition(x, y);
	cout << "*";
	_sleep(40);
}

void dibujarPatron(int &x, int &y, int pasos, int i)
{
	while (y + 1 < HEIGHT) {
		dibujar(x, y);
		y++;
	}
	while (x <= pasos * i) {
		dibujar(x, y);
		x++;
	}
	while (y > 0) {
		dibujar(x, y);
		y--;
	}
	while (x <= pasos * (i + 1)) {
		dibujar(x, y);
		x++;
	}
}
void ejercicio4_7C()
{
	int x = 0, y = 0;
	int pasos = 10;
	for (int i = 1; i < 5; i += 2)
	{
		dibujarPatron(x, y, pasos, i);
	}
	while (y + 1 < HEIGHT) {
		dibujar(x, y);
		y++;
	}
}
int main()
{
	Console::SetWindowSize(WIDTH, HEIGHT);
	Console::CursorVisible = false;
	ejercicio4_7C();
	system("pause>0");
	return 0;
}