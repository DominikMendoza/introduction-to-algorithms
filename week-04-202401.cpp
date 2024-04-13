#include <iostream>
using namespace std;

void ejercicio1()
{
	int num;
	cout << "Ingrese numero: ";
	cin >> num;
	if (num % 2 == 0)
	{
		cout << "Es un numero par" << endl;
	}
	else
	{
		cout << "Es un numero impar" << endl;
	}

	// si es multipo de 5 o no
}

int determinarPrecioEntradaCine(int edad)
{
	if (edad < 18) {
		return 7;
	}
	if (edad <= 50) {
		return 15;
	}
	return 5;
	/*
	if (edad < 18) {
		return 7;
	}
	// mi else involucra todos los mayores o igual a 18
	else {
		if (edad <= 50) {
			// los de 18 hasta 50
			return 15;
		}
		else {
			// abarca los de 50 a mas
			return 5;
		}
	}
	*/
}

void ejercicio2()
{
	int edad;
	float entradaCine;
	cout << "Ingrese su edad: ";
	cin >> edad;
	// valido
	if (edad <= 0) {
		cout << "La edad es menor a 0" << endl;
		system("pause>0");
		return;
	}
	// ejecuto con normalidad
	cout << "La entrada del cine costara: ";
	cout << determinarPrecioEntradaCine(edad) << endl;
	// lower camel case
}

void ejercicio4()
{
	int n1, n2;
	cout << "Ingrese 2 numeros enteros (N1|N2): ";
	cin >> n1 >> n2;
	// si al dividirlo la division es exacta entonces es multiplo
	if (n1 % n2 == 0) {
		cout << n1 << " es multiplo de " << n2;
	}
	else {
		cout << n1 << " no es multiplo de " << n2;
	}
	/* Advanced
	cout << endl;

	cout << n1;
	if (n1 % n2 != 0) {
		cout << " no";
	}
	cout << " es multiplo de " << n2;
	cout << endl;
	*/
}

void imprimirMensajeAdicional(int valor1, int valor2)
{
	if (valor1 == valor2) {
		switch (valor1)
		{;
		case 1: cout << "PAR DE ASES" << endl; break;
		case 3: cout << "PAR DE TRIOS" << endl; break;
		case 13: cout << "REYES" << endl; break;
		}
	}
}

void imprimirCarta1(char c)
{
	cout << endl;
	cout << "  " << c << "  " << endl;
	cout << endl;
	cout << endl;
}

void imprimirCarta7(char c)
{
	cout << c << "   " << c << endl;
	cout << "  " << c << "  " << endl;
	cout << c << "   " << c << endl;
	cout << c << "   " << c << endl;
}

void imprimirCartaSegunValor(int valor, char palo)
{
	switch (valor)
	{
	case 1: imprimirCarta1(palo); break;
	case 7: imprimirCarta7(palo); break;
	default:
		break;
	}
}
void evaluarCartas(int carta1, int carta2, char palo) {
	imprimirCartaSegunValor(carta1, palo);
	imprimirCartaSegunValor(carta2, palo);
	imprimirMensajeAdicional(carta1, carta2);
}

void menu()
{
	cout << "Escoja el palo de barajas" << endl;
	cout << "Mostrar las opciones" << endl;
}

char determinarFiguraDePalo(char paloAJugar)
{
	char paloFigura;
	switch (paloAJugar)
	{
	case 'c': paloFigura = 3; break;
	case 'd': paloFigura = 4; break;
	case 'A': paloFigura = 'A'; break;
	default:
		break;
	}
	return paloFigura;
}
void ejercicio14()
{
	int carta1, carta2;
	char paloAJugar, paloFigura;
	menu();
	cout << "Elija el palo a jugar: ";
	cin >> paloAJugar;
	paloFigura = determinarFiguraDePalo(paloAJugar);
	
	cout << "Ingrese carta 1: ";
	cin >> carta1;
	cout << "Ingrese carta 2: ";
	cin >> carta2;
	evaluarCartas(carta1, carta2, paloFigura);
}
int main()
{
	ejercicio14();
	system("pause>0");
	return 0;
}