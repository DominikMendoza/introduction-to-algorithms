#include <iostream>
#include <conio.h>
#define WIDTH 80
#define HEIGHT 40
using namespace System;
using namespace std;

void imprimirNivelDeSatisfaccionFrecuencia(int cntB, int cntR, int cntM) {
	int mayorFrecuencia = max(cntB, max(cntR, cntM));
	if (cntB == mayorFrecuencia) {
		cout << "Bueno" << endl;
	}
	if (cntR == mayorFrecuencia) {
		cout << "Regular" << endl;
	}
	if (cntM == mayorFrecuencia) {
		cout << "Malo" << endl;
	}
}

void imprimirMinimaEdadEstudianteNoMoodle(int edad) {
	cout << "Edad de la mujer mas joven que no usa Moodle: ";
	if (edad == 100000) {
		cout << "No hubo" << endl;
	}
	else {
		cout << edad << endl;
	}
}

int obtenerEdadValida() {
	int edad;
	do
	{
		cout << "Ingrese su edad: ";
		cin >> edad;
	} while ((edad < 17 || edad > 65) && edad != 0);
	return edad;
}

char obtenerSexoValido() {
	char sexo;
	do
	{
		cout << "Sexo (F: femenino; M: masculino): ";
		cin >> sexo;
		sexo = toupper(sexo);
	} while (sexo != 'F' && sexo != 'M');
	return sexo;
}
char obtenerPlataformaValida() {
	char plataforma;
	do
	{
		cout << "Plataforma LMS(B: B...): ";
		cin >> plataforma;
		plataforma = toupper(plataforma);
	} while (plataforma != 'B' && plataforma != 'C' && plataforma != 'M');
	return plataforma;
}

char obtenerNivelSatisfaccionValido() {
	char satisfaccion;
	do
	{
		cout << "Nivel de ...";
		cin >> satisfaccion;
		satisfaccion = toupper(satisfaccion);
	} while (satisfaccion != 'B' && satisfaccion != 'R' && satisfaccion != 'M');
	return satisfaccion;
}
void ejercicio_1_7A() {
	int edad;
	char sexo, plataforma, satisfaccion;

	int mayoresDe60 = 0;

	int estdUsanCanvas = 0;
	int sumaEdadesEstdUsanCanvas = 0;

	int cntBueno, cntRegular, cntMalo;
	cntBueno = cntRegular = cntMalo = 0;

	int minimaEdadEstdNoMoodle = 100000;
	do
	{
		edad = obtenerEdadValida();
		if (edad == 0) {
			// salimos del do -> while
			break;
		}
		sexo = obtenerSexoValido();
		plataforma = obtenerPlataformaValida();
		satisfaccion = obtenerNivelSatisfaccionValido();

		// indicadores
		if (edad >= 60) {
			mayoresDe60++;
		}

		if (plataforma == 'C') {
			estdUsanCanvas++;
			sumaEdadesEstdUsanCanvas += edad;
		}

		switch (satisfaccion)
		{
		case 'B': cntBueno++; break;
		case 'R': cntRegular++; break;
		case 'M': cntMalo++; break;
		}

		if (sexo == 'F' && plataforma != 'M') {
			minimaEdadEstdNoMoodle = min(minimaEdadEstdNoMoodle, edad);
		}

	} while (edad != 0);
	
	cout << "RESULTADOS" << endl;
	cout << "Cuantos estudiantes son adultos mayores?: " << mayoresDe60 << endl;
	cout << "El promedio de edad... Canvas: ";
	cout << float(sumaEdadesEstdUsanCanvas) / estdUsanCanvas << endl;

	imprimirNivelDeSatisfaccionFrecuencia(cntBueno, cntRegular, cntMalo);
	imprimirMinimaEdadEstudianteNoMoodle(minimaEdadEstdNoMoodle);
	
}

void dibujarTriangulo(int x, int y, int valor) {
	int size = 4;
	// 0 2 2 3
	for (int i = 1; i <= size; i++)
	{
		// 0 -> 0
		for (int j = 1; j <= i; j++)
		{
			Console::SetCursorPosition(x + j - 1, y + i - 1);
			if (j == 2 && i == 3) {
				cout << valor;
			}
			else {
				cout << "*";
			}
		}
	}
}

void ejercicio_5_7B() {
	int numero;
	cout << "Ingrese numero: ";
	cin >> numero;
	for (int i = 1; i <= numero; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			dibujarTriangulo(4 * (j - 1), 4 * (i - 1), i);
		}
	}
}

void borrar(int x, int y) {
	Console::SetCursorPosition(x, y);
	cout << " ";
}

void dibujar(int x, int y, char forma) {
	Console::SetCursorPosition(x, y);
	cout << forma;
}

int obtenerDx(int x, int dx) {
	if (x + dx < 0 || x + dx >= WIDTH) {
		dx = 0;
	}
	return dx;
}

int obtenerDy(int y, int dy) {
	if (y + dy < 0 || y + dy >= HEIGHT) {
		dy = 0;
	}
	return dy;
}

void ejercicio_8_7C() {
	int x1, y1, dx1, dy1; // asterisco
	int x2, y2, dx2, dy2; // arroba
	int x3, y3, dx3, dy3; // michi

	x1 = WIDTH / 2 - 2;
	x2 = WIDTH / 2 + 2;
	x3 = WIDTH / 2;

	y1 = y2 = HEIGHT / 2 - 1;
	y3 = HEIGHT / 2 + 1;

	dx1 = dy1 = dx2 = dy2 = dx3 = dy3 = 0;

	while (true)
	{
		borrar(x1, y1);
		borrar(x2, y2);
		borrar(x3, y3);
		// mover
		if (kbhit()) {
			char tecla = getch();
			tecla = toupper(tecla);

			if (tecla == 'S') {
				dx1 = -1;
				dy1 = -1;

				dx2 = 1;
				dy2 = -1;

				dx3 = 0;
				dy3 = 1;
			}
		}
		dx1 = obtenerDx(x1, dx1); dy1 = obtenerDy(y1, dy1);
		dx2 = obtenerDx(x2, dx2); dy2 = obtenerDy(y2, dy2);
		dx3 = obtenerDx(x3, dx3); dy3 = obtenerDy(y3, dy3);
		
		x1 += dx1; y1 += dy1;
		x2 += dx2; y2 += dy2;
		x3 += dx3; y3 += dy3;
		dibujar(x1, y1, '*');
		dibujar(x2, y2, '@');
		dibujar(x3, y3, '#');
		_sleep(40);
	}


}
int main()
{
	Console::SetWindowSize(WIDTH, HEIGHT);
	Console::CursorVisible = false;
	ejercicio_8_7C();
	system("pause>0");
	return 0;
}