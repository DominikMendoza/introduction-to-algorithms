#include <iostream>
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
	// 0 1 2 3
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
int main()
{
	ejercicio_5_7B();
	system("pause>0");
	return 0;
}