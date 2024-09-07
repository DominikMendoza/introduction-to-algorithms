#include <iostream>
using namespace std;

void ejercicio_1() {
	int num;
	cout << "Ingrese numero nuevo: ";
	cin >> num;

	// cout << "Es numero " << (num % 2 ? "impar" : "par");
	if (num % 2 == 0) {
		cout << "Es numero par" << endl;
	}
	else {
		cout << "Es numero impar" << endl;
	}
}

void ejercicio_2() {
	int edad;
	float precio;
	cout << "Ingrese edad de la persona: ";
	cin >> edad;

	if (edad < 18) {
		precio = 7;
	}
	else {
		if (edad <= 50) {
			precio = 15;
		}
		else {
			precio = 5;
		}
	}

	cout << "El precio de la entrada es " << precio << " soles";
}

void ejercicio_4() {
	int num1, num2;
	cout << "Ingrese dos numeros enteros (N1 N2): ";
	cin >> num1 >> num2;
	if (num1 % num2 == 0) {
		cout << num1 << " es multiplo de " << num2 << endl;
	}
	else {
		cout << num1 << " no es multiplo de " << num2 << endl;
	}
}

void ejercicio_6() {
	int caramt1, caramt2, caramt3;
	float propina, montoCompra;

	cout << "Ingrese la cantidad de caramelos que va a comprar por el Tipo 1: ";
	cin >> caramt1;
	cout << "Ingrese la cantidad de caramelos que va a comprar por el Tipo 2: ";
	cin >> caramt2;
	cout << "Ingrese la cantidad de caramelos que va a comprar por el Tipo 3: ";
	cin >> caramt3;
	cout << "Ingrese monto de la propina: ";
	cin >> propina;

	montoCompra = caramt1 * 0.75 + caramt2 * 1.15 + caramt3 * 0.65;
	cout << "El monto total de la compra es: " << montoCompra << endl;

	if (propina < montoCompra) {
		cout << "LA PROPINA NO FUE SUFICIENTE PARA PAGAR POR LOS CARAMELOS" << endl;
	}
	else {
		cout << "PEDRO COMERA DULCES";
	}

}
void dibujarCartaA(char c) {
	cout << "     " << endl;
	cout << "     " << endl;
	cout << "  " << c << "  " << endl;
	cout << "     " << endl;
	cout << "     " << endl;
}

void dibujarCartaValor3(char c) {
	cout << "  " << c << "  " << endl;
	cout << "     " << endl;
	cout << "  " << c << "  " << endl;
	cout << "     " << endl;
	cout << "  " << c << "  " << endl;
}

void dibujarCartaValor7(char c) {
	cout << c << "   "<< c << endl;
	cout << "  "<< c << "  " << endl;
	cout << c << "   "<< c << endl;
	cout << "     " << endl;
	cout << c << "   "<< c << endl;
}

void dibujarCartaValor8(char c) {
	cout << c << "   "<< c << endl;
	cout << "  "<< c << "  " << endl;
	cout << c << "   "<< c << endl;
	cout << "  "<< c << "  " << endl;
	cout << c << "   "<< c <<  endl;
}

void dibujarCartaRey(char c) {
	cout << "K    " << endl;
	cout << c << "    " << endl;
	cout << "     " << endl;
	cout << "     " << endl;
	cout << "   " << c << "K" << endl;
}

void menuDePalos() {
	cout << "Elija el palo de barajas\n";
	cout << "------------------------\n";
	cout << "< C > Corazones\n";
	cout << "< D > Diamantes\n";
	cout << "< T > Treboles\n";
	cout << "< E > Espadas\n";
	cout << "Elija el palo a jugar :> ";
}

void imprimirMensajeSegunValores(int valorPrimeraCarta, int valorSegundaCarta) {
	if (valorPrimeraCarta != valorSegundaCarta) {
		return;
	}
	switch (valorPrimeraCarta)
	{
	case 1: cout << "PAR DE ASES!\n\n"; break;
	case 3: cout << "PAR DE TRIOS!\n\n"; break;
	case 13: cout << "PAR DE REYES!\n\n"; break;
	}
}

int obtenerValorAscii(char palo) {
	int valorAscii;
	palo = toupper(palo);
	switch (palo)
	{
	case 'C': valorAscii = 3; break;
	case 'D': valorAscii = 4; break;
	case 'T': valorAscii = 5; break;
	case 'E': valorAscii = 6; break;
	default: valorAscii = -1;
	}
	return valorAscii;
}

void dibujarCarta(int valorCarta, int valorAscii) {
	switch (valorCarta)
	{
	case 1: dibujarCartaA(valorAscii); break;
	case 3: dibujarCartaValor3(valorAscii); break;
	case 7: dibujarCartaValor7(valorAscii); break;
	case 8: dibujarCartaValor8(valorAscii); break;
	case 13: dibujarCartaRey(valorAscii); break;
	default: dibujarCartaValor7(valorAscii);
	}
	cout << "\n\n";
}

void ejercicio_14() {
	char palo;
	int valorPrimeraCarta, valorSegundaCarta;
	menuDePalos();
	cin >> palo;
	int valorAscii = obtenerValorAscii(palo);
	if (valorAscii == -1) {
		cout << "Palo no valido...";
		return;
	}

	cout << "Muestre la Primera Carta :> ";
	cin >> valorPrimeraCarta;
	if (valorPrimeraCarta < 1 || valorPrimeraCarta > 13) {
		cout << "Valor de carta fuera de rango...";
		return;
	}

	cout << "Muestre la Segnda Carta :> ";
	cin >> valorSegundaCarta;
	if (valorSegundaCarta < 1 || valorSegundaCarta > 13) {
		cout << "Valor de carta fuera de rango...";
		return;
	}
	imprimirMensajeSegunValores(valorPrimeraCarta, valorSegundaCarta);
	
	dibujarCarta(valorPrimeraCarta, valorAscii);
	dibujarCarta(valorSegundaCarta, valorAscii);
}
int main()
{
	ejercicio_14();
	system("pause>0");
	return 0;
}