#include <iostream>
#include <conio.h>
#define WIDTH 40
#define HEIGHT 40
#define N_SATELITES 4
#define MATRIX_SIZE 40
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
using namespace System;
using namespace std;

void Generar_Vector(int arr[]) {
	for (int i = 0; i < 8; i++)
	{
		arr[i] = rand() % 2;
	}
}

void imprimirByte(int arr[]) {
	for (int i = 0; i < 8; i++)
	{
		cout << arr[i] << ' ';
	}
	cout << endl;
}
void prende_apaga_bits(int arr[]) {
	for (int i = 0; i < 8; i++)
	{
		arr[i] = abs(arr[i] - 1);
	}
}

void intercambia_bits(int arr[]) {
	for (int i = 0; i < 8; i += 2)
	{
		swap(arr[i], arr[i + 1]);
	}
}

int convertir_a_decimal(int arr[]) {
	int resultado = 0;
	for (int i = 0; i < 8; i++)
	{
		resultado += pow(2, 7 - i) * arr[i];
	}
	return resultado;
}

void ejercicio_2() {
	int arr[8];
	Generar_Vector(arr);
	imprimirByte(arr);
	prende_apaga_bits(arr);
	imprimirByte(arr);
	intercambia_bits(arr);
	imprimirByte(arr);
	cout << "El numero decimal es: " << convertir_a_decimal(arr) << endl;
}

void validarPosicionesX(int PosicionXsatelite[]) {
	cout << "Ingrese las posicion X de cada uno de los satelites: ";
	for (int i = 0; i < N_SATELITES; i++)
	{
		cin >> PosicionXsatelite[i];
		if (PosicionXsatelite[i] < 0 || PosicionXsatelite[i] >= WIDTH) {
			cout << "\nDato invalido, ingresar uno en el rango (0, 79)\n";
			i--;
		}
	}
}

void validarPosicionesY(int PosicionYsatelite[]) {
	cout << "Ingrese las posicion Y de cada uno de los satelites: ";
	for (int i = 0; i < N_SATELITES; i++)
	{
		cin >> PosicionYsatelite[i];
		if (PosicionYsatelite[i] < 0 || PosicionYsatelite[i] >= WIDTH) {
			cout << "\nDato invalido, ingresar uno en el rango (0, 39)\n";
			i--;
		}
	}
}

void validarDX(int dXsatelite[]) {
	cout << "Ingrese desplazamiento en X de los satelites: ";
	for (int i = 0; i < N_SATELITES; i++)
	{
		cin >> dXsatelite[i];
		if (dXsatelite[i] < -1 || dXsatelite[i] > 1) {
			cout << "\nDato invalido, ingresar uno en el rango (-1, 1)\n";
			i--;
		}
	}
}

void validarDY(int dYsatelite[]) {
	cout << "Ingrese desplazamiento en Y de los satelites: ";
	for (int i = 0; i < N_SATELITES; i++)
	{
		cin >> dYsatelite[i];
		if (dYsatelite[i] < -1 || dYsatelite[i] > 1) {
			cout << "\nDato invalido, ingresar uno en el rango (-1, 1)\n";
			i--;
		}
	}
}

void Ingresa_Posicion_Satelites(int PosicionXsatelite[], int PosicionYsatelite[],
	int dXsatelite[], int dYsatelite[]) {
	validarPosicionesX(PosicionXsatelite);
	validarPosicionesY(PosicionYsatelite);
	validarDX(dXsatelite);
	validarDY(dYsatelite);
	Console::Clear();
}

void generarColores(int colores[]) {
	for (int i = 0; i < N_SATELITES; i++)
	{
		colores[i] = rand() % 15 + 1;
	}
}
void borrar(int x, int y) {
	Console::SetCursorPosition(x, y);
	cout << ' ';
}

void mover(int& x, int& y, int& dx, int& dy) {
	// lado izquierdo
	if (x < WIDTH / 2) {
		if (x + dx < 0 || x + dx >= WIDTH / 2) {
			dx *= -1;
		}
	}
	// derecha
	else {
		if (x + dx <= WIDTH / 2 || x + dx >= WIDTH) {
			dx *= -1;
		}
	}
	if (y + dy < 0 || y + dy >= HEIGHT) {
		dy *= -1;
	}
	x += dx;
	y += dy;
}

void dibujar(int x, int y, int color) {
	Console::SetCursorPosition(x, y);
	Console::ForegroundColor = ConsoleColor(color);
	cout << char(219);
}

void simulacion(int PosicionXsatelite[], int PosicionYsatelite[],
	int dXsatelite[], int dYsatelite[], int colores[]) {
	for (int i = 0; i < N_SATELITES; i++)
	{
		borrar(PosicionXsatelite[i], PosicionYsatelite[i]);
		mover(PosicionXsatelite[i], PosicionYsatelite[i], dXsatelite[i], dYsatelite[i]);
		dibujar(PosicionXsatelite[i], PosicionYsatelite[i], colores[i]);
	}
}

void ejercicio_3() {
	int PosicionXsatelite[N_SATELITES], PosicionYsatelite[N_SATELITES],
		dXsatelite[N_SATELITES], dYsatelite[N_SATELITES], colores[N_SATELITES];
	Ingresa_Posicion_Satelites(PosicionXsatelite, PosicionYsatelite, dXsatelite, dYsatelite);
	generarColores(colores);
	while (true)
	{
		simulacion(PosicionXsatelite, PosicionYsatelite, dXsatelite, dYsatelite, colores);
		_sleep(100);
	}
}

void generarMatriz(int matriz[][MATRIX_SIZE]) {
	for (int i = 0; i < MATRIX_SIZE; i++) {
		for (int j = 0; j < MATRIX_SIZE; j++) {
			if (i == 0 || i == MATRIX_SIZE - 1 || j == 0 || j == MATRIX_SIZE - 1 || i == 23) {
				matriz[i][j] = 1;
			}
			else {
				matriz[i][j] = 0;
			}
		}
	}
	matriz[23][9] = matriz[23][10] = matriz[23][32] = matriz[23][33] = 0;
}

void imprimirMatriz(int matriz[][MATRIX_SIZE]) {
	for (int i = 0; i < MATRIX_SIZE; i++) {
		for (int j = 0; j < MATRIX_SIZE; j++) {
			Console::SetCursorPosition(j, i);
			Console::ForegroundColor = ConsoleColor::Blue;
			if (matriz[i][j] == 1) {
				cout << char(219);
			}
			else {
				cout << ' ';
			}
		}
	}
}

void borrarObjeto(int x, int y) {
	Console::SetCursorPosition(x, y);
	Console::BackgroundColor = ConsoleColor::Yellow;
	Console::ForegroundColor = ConsoleColor::Red;
	cout << 2;
	Console::ResetColor();
}
void dibujarObjeto(int x, int y) {
	Console::SetCursorPosition(x, y);
	Console::ForegroundColor = ConsoleColor::Green;
	cout << char(219);
}

void moverObjeto(int& x, int& y, int& dx, int& dy, int matriz[][MATRIX_SIZE]) {
	
	if (kbhit()) {
		char t = _getch();
		t = toupper(t);
		switch (t)
		{
		case UP: dy = -1; dx = 0; break;
		case DOWN: dy = 1; dx = 0; break;
		case LEFT: dx = -1; dy = 0; break;
		case RIGHT: dx = 1; dy = 0; break;
		}
	}
	if (matriz[y][x + dx] == 1 || matriz[y][x + dx] == 2) {
		dx = 0;
	}
	if (matriz[y + dy][x] == 1 || matriz[y + dy][x] == 2) {
		dy = 0;
	}
	x += dx;
	y += dy;
	matriz[y][x] = 2;
}


void ejercicio_4() {
	int x, y, dx, dy;
	x = y = 5;
	dx = dy = 0;
	int matriz[MATRIX_SIZE][MATRIX_SIZE];
	generarMatriz(matriz);
	imprimirMatriz(matriz);
	while (true)
	{
		borrarObjeto(x, y);
		moverObjeto(x, y, dx, dy, matriz);
		dibujarObjeto(x, y);
		_sleep(50);
	}
}
int main()
{
	Console::SetWindowSize(WIDTH, HEIGHT);
	Console::CursorVisible = false;
	srand(time(nullptr));
	ejercicio_4();
	system("pause>0");
	return 0;
}