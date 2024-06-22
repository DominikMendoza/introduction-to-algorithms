#include <iostream>
#define BYTE_SIZE 8
#define N_SATELITES 4
#define WIDTH 80
#define HEIGHT 40
using namespace System;
using namespace std;

void generarMensaje(int* mensaje, int size) {
	for (int i = 0; i < size; i++)
	{
		mensaje[i] = rand() % 10;
	}
}

void imprimirMensaje(int* mensaje, int size) {
	for (int i = 0; i < size; i++)
	{
		cout << mensaje[i] << ' ';
	}
	cout << endl;
}

bool existeCapicua4(int* mensaje, int size) {
	return (mensaje[size - 1] == mensaje[size - 4] &&
		mensaje[size - 3] == mensaje[size - 2]);
}

bool existeCapicua3(int* mensaje, int size) {
	return (mensaje[size - 1] == mensaje[size - 3]);
}

void ejercicio1_14() {
	int cnt = 0;
	while (true) {
		int size = rand() % (15 - 10 + 1) + 10;
		int* arr = new int[size];
		generarMensaje(arr, size);
		imprimirMensaje(arr, size);
		if (existeCapicua3(arr, size) || existeCapicua4(arr, size)) {
			cout << "Se encontro capicua...\n\n";
			cnt++;
		}
		if (cnt == 5) {
			cout << "CONTACTO!";
			break;
		}
		delete arr;
		//system("pause");
	}
}

void generarVector(int arr[]) {
	for (int i = 0; i < BYTE_SIZE; i++)
	{
		arr[i] = rand() % 2;
	}
}

void imprimirByte(int arr[]) {
	for (int i = 0; i < BYTE_SIZE; i++)
	{
		cout << arr[i] << ' ';
	}
	cout << '\n';
}
void prendeApagaBits(int arr[]) {
	for (int i = 0; i < BYTE_SIZE; i++)
	{
		arr[i] = abs(arr[i] - 1);
	}
}

void intercambiarBits(int arr[]) {
	for (int i = 0; i < BYTE_SIZE; i += 2)
	{
		swap(arr[i], arr[i + 1]);
	}
}

int convertirADecimal(int arr[]) {
	int resultado = 0;
	for (int i = 0; i < BYTE_SIZE; i++)
	{
		resultado += arr[i] * pow(2, 7 - i);
	}
	return resultado;
}

void ejercicio2_14() {
	int arr[BYTE_SIZE];
	generarVector(arr);
	imprimirByte(arr);
	prendeApagaBits(arr);
	imprimirByte(arr);
	intercambiarBits(arr);
	imprimirByte(arr);
	cout << "El numero es: " << convertirADecimal(arr) << endl;
}

void validarLimites(int& num, int limInf, int limSup) {
	do
	{
		cin >> num;
		if (num < limInf || num > limSup) {
			cout << "Fuera de los limites, intente de nuevo: ";
		}
	} while (num < limInf || num > limSup);
}

void ingresaPosicionSatelites(int posicionXSatelite[], int posicionYSatelite[], int dXSatelite[], int dYSatelite[]) {
	cout << "Ingrese las Posiciones X de cada uno de los satélites: ";
	for (int i = 0; i < N_SATELITES; i++)
	{
		validarLimites(posicionXSatelite[i], 0, WIDTH);
	}

	cout << "Ingrese las Posiciones Y de cada uno de los satélites: ";
	for (int i = 0; i < N_SATELITES; i++)
	{
		validarLimites(posicionYSatelite[i], 0, HEIGHT);
	}

	cout << "Ingrese el desplazamiento en X de los satélites: ";
	for (int i = 0; i < N_SATELITES; i++)
	{
		validarLimites(dXSatelite[i], -1, 1);
	}

	cout << "Ingrese el desplazamiento en Y de los satélites: ";
	for (int i = 0; i < N_SATELITES; i++)
	{
		validarLimites(dYSatelite[i], -1, 1);
	}
}

void borrarSatelites(int posicionXSatelite[], int posicionYSatelite[]) {
	for (int i = 0; i < N_SATELITES; i++)
	{
		Console::SetCursorPosition(posicionXSatelite[i], posicionYSatelite[i]);
		cout << ' ';
	}
}

void dibujarSatelites(int posicionXSatelite[], int posicionYSatelite[], char formaSatelite[], int colorSatelite[]) {
	/*
	Console::ForegroundColor = ConsoleColor::Green;
	Console::SetCursorPosition(posicionXSatelite[0], posicionYSatelite[0]);
	cout << '0';

	Console::ForegroundColor = ConsoleColor::Red;
	Console::SetCursorPosition(posicionXSatelite[1], posicionYSatelite[1]);
	cout << '1';

	Console::ForegroundColor = ConsoleColor::Yellow;
	Console::SetCursorPosition(posicionXSatelite[2], posicionYSatelite[2]);
	cout << '2';

	Console::ForegroundColor = ConsoleColor::White;
	Console::SetCursorPosition(posicionXSatelite[3], posicionYSatelite[3]);
	cout << '3';
	*/
	for (int i = 0; i < N_SATELITES; i++)
	{
		Console::ForegroundColor = ConsoleColor(colorSatelite[i]);
		Console::SetCursorPosition(posicionXSatelite[i], posicionYSatelite[i]);
		cout << formaSatelite[i];
	}
}

void simulacionDeMovimiento(int posicionXSatelite[], int posicionYSatelite[], int dXSatelite[], int dYSatelite[]) {
	for (int i = 0; i < N_SATELITES; i++)
	{
		// Evaluamos si esta a la izquierda o derecha
		if (posicionXSatelite[i] < WIDTH / 2) {
			// rebote de 0 a la mitad
			if (posicionXSatelite[i] + dXSatelite[i] < 0 || posicionXSatelite[i] + dXSatelite[i] >= WIDTH / 2) {
				dXSatelite[i] *= -1;
			}
		}
		else {
			if (posicionXSatelite[i] + dXSatelite[i] <= WIDTH / 2 || posicionXSatelite[i] + dXSatelite[i] >= WIDTH) {
				dXSatelite[i] *= -1;
			}
			// rebote de mitad a el total
		}

		// Rebotamos arriba o abajo
		if (posicionYSatelite[i] + dYSatelite[i] < 0 || posicionYSatelite[i] + dYSatelite[i] >= HEIGHT) {
			dYSatelite[i] *= -1;
		}

		posicionXSatelite[i] += dXSatelite[i];
		posicionYSatelite[i] += dYSatelite[i];
	}
}

void ejercicio3_14() {
	int posicionXSatelite[N_SATELITES];
	int posicionYSatelite[N_SATELITES];
	int dXSatelite[N_SATELITES];
	int dYSatelite[N_SATELITES];
	// Adicional
	char formaSatelite[N_SATELITES];
	int colorSatelite[N_SATELITES];

	for (int i = 0; i < N_SATELITES; i++)
	{
		formaSatelite[i] = rand() % (47 - 33 + 1) + 33;
		colorSatelite[i] = rand() % (15 - 11 + 1) + 11;
	}

	ingresaPosicionSatelites(posicionXSatelite, posicionYSatelite, dXSatelite, dYSatelite);
	Console::Clear();
	while (true)
	{
		borrarSatelites(posicionXSatelite, posicionYSatelite);
		simulacionDeMovimiento(posicionXSatelite, posicionYSatelite, dXSatelite, dYSatelite);
		dibujarSatelites(posicionXSatelite, posicionYSatelite, formaSatelite, colorSatelite);
		_sleep(120);
	}
}

int main()
{
	Console::SetWindowSize(WIDTH, HEIGHT);
	Console::CursorVisible = false;
	srand(time(nullptr));
	ejercicio3_14();
	system("pause>0");
	return 0;
}