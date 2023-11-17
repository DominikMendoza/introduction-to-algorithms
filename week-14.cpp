#include <iostream>
#define WIDTH 80
#define HEIGHT 40
using namespace System;
using namespace std;

void generarMensaje(int* Mensaje, int longitud_mensaje)
{
	for (int i = 0; i < longitud_mensaje; i++)
	{
		Mensaje[i] = rand() % 10;
	}
}
void imprimirMensaje(int* Mensaje, int longitud_mensaje)
{
	cout << "\nMensaje:\n";
	for (int i = 0; i < longitud_mensaje; i++)
	{
		cout << Mensaje[i] << ' ';
	}
	cout << '\n';
}
bool existeCapicua(int* Mensaje, int longitud_mensaje)
{
	int n = longitud_mensaje;
	return (
		// capicua de 4
		(Mensaje[n - 1] == Mensaje[n - 4] && Mensaje[n - 2] == Mensaje[n - 3]) ||
		// capicua de 3
		(Mensaje[n - 1] == Mensaje[n - 3]) ||
		// capicua de 2
		(Mensaje[n - 1] == Mensaje[n - 2]));
}

void ejercicio1()
{
	
	int* mensaje =  new int[0];
	int n;
	int cnt = 0;
	do
	{
		n = rand() % 6 + 10;
		delete mensaje;
		mensaje = new int[n];
		generarMensaje(mensaje, n);
		imprimirMensaje(mensaje, n);
		if (existeCapicua(mensaje, n)) {
			cnt++;
		}
		if (cnt == 5) {
			cout << "Contacto!\n";
			cnt = 0;
		}
		system("pause>0");
	} while (true);
}

void generarVector(int arreglo[]) {
	for (int i = 0; i < 8; i++)
	{
		arreglo[i] = rand() % 2;
	}
}

void imprimirVector(int arreglo[]) {
	cout << "\nVector:\n";
	for (int i = 0; i < 8; i++)
	{
		cout << arreglo[i] << ' ';
	}
	cout << '\n';
}
void prendeApagaBits(int arreglo[]) {
	for (int i = 0; i < 8; i++)
	{
		arreglo[i] = abs(arreglo[i] - 1);
	}
}

void intercambiaBits(int arreglo[]) {
	for (int i = 0; i < 8; i += 2)
	{
		swap(arreglo[i], arreglo[i + 1]);
	}
}

int convertirADecimal(int arreglo[]) {
	int suma = 0;
	for (int i = 0; i < 8; i++)
	{
		suma += arreglo[i] * pow(2, 8 - i - 1);
	}
	return suma;
}
void ejercicio2()
{
	int arr[8];
	generarVector(arr);
	imprimirVector(arr);
	prendeApagaBits(arr);
	imprimirVector(arr);
	intercambiaBits(arr);
	imprimirVector(arr);
	cout << "El decimal es: " << convertirADecimal(arr);
}
struct satelite {
	int x, y, dx, dy;
};

void validarLimites(int& var, int liminf, int limSup) {
	do
	{
		cin >> var;
		if (var < liminf || var > limSup) {
			cout << "Fuera de los limites intente de nuevo: ";
		}
	} while (var < liminf || var > limSup);
}
void ingresaPosicionSatelite(satelite satelites[]) {
	cout << "Ingrese las Posiciones X de cada uno de los satelites: ";
	for (int i = 0; i < 4; i++)
	{
		validarLimites(satelites[i].x, 0, WIDTH);
	}
	Console::Clear();
	cout << "Ingrese las Posiciones Y de cada uno de los satelites: ";
	for (int i = 0; i < 4; i++)
	{
		validarLimites(satelites[i].y, 0, HEIGHT);
	}
	Console::Clear();
	cout << "Ingrese el desplazamiento en X de los satelites: ";
	for (int i = 0; i < 4; i++)
	{
		validarLimites(satelites[i].dx, -1, 1);
	}
	Console::Clear();
	cout << "Ingrese el desplazamiento en Y de los satelites: ";
	for (int i = 0; i < 4; i++)
	{
		validarLimites(satelites[i].dy, -1, 1);
	}
}

void moverSatelite(satelite& s) {

	// division en este oeste
	if (s.x < WIDTH / 2) {
		if (s.x + s.dx < 0 || s.x + s.dx > WIDTH / 2 - 1) s.dx *= -1;
	}
	else {
		if (s.x + s.dx < WIDTH / 2 || s.x + s.dx > WIDTH - 1) s.dx *= -1;
	}
	if (s.y + s.dy < 0 || s.y + s.dy > HEIGHT - 1) s.dy *= -1;
	// division norte y sur
	/*
	if (s.y < HEIGHT / 2) {
		if (s.y + s.dy < 0 || s.y + s.dy > HEIGHT / 2 - 1) s.dy *= -1;
	}
	else {
		if (s.y + s.dy < HEIGHT / 2 || s.y + s.dy > HEIGHT - 1) s.dy *= -1;
	}
	if (s.x + s.dx < 0 || s.x + s.dx > WIDTH - 1) s.dx *= -1;\
	*/

	s.x += s.dx;
	s.y += s.dy;
}
void borrarSatelite(satelite s) {
	Console::SetCursorPosition(s.x, s.y);
	cout << " ";
}
void dibujarSatelite(satelite s, int color) {
	Console::SetCursorPosition(s.x, s.y);
	Console::ForegroundColor = ConsoleColor(color);
	cout << "*";
}

void simulacion(satelite satelites[]) {
	Console::Clear();
	for (int i = 0; i < 4; i++)
	{
		borrarSatelite(satelites[i]);
		moverSatelite(satelites[i]);
		dibujarSatelite(satelites[i], 4);
	}
}

void ejercicio3()
{
	Console::SetWindowSize(WIDTH, HEIGHT);
	Console::CursorVisible = false;
	satelite satelites[4];
	ingresaPosicionSatelite(satelites);
	while (true)
	{
		simulacion(satelites);
		_sleep(150);
	}
}
int main()
{

	srand(time(nullptr));
	ejercicio3();
	system("pause>0");
	return 0;
}