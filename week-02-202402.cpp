#include <iostream>
#include <cmath>
using namespace std;

void ejercicio_1() {
	int k, m5, m2, m1;
	cout << "Ingrese cantidad a repartir (k): ";
	cin >> k;

	m5 = k / 5;
	k = k % 5;

	m2 = k / 2;
	k = k % 2;

	m1 = k;

	cout << "Monedas de 5: " << m5 << endl;
	cout << "Monedas de 2: " << m2 << "\n";
	cout << "Monedas de 1: " << m1 << endl;
}
void ejercicio_2() {
	double x1, y1, x2, y2;
	double distancia, angulo;
	cout << "Ingrese las coordenadas x1, y1: ";
	cin >> x1 >> y1;
	cout << "Ingrese las coordenadas x2, y2: ";
	cin >> x2 >> y2;

	distancia = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
	angulo = atan((y2 - y1) / (x2 - x1)) * 180 / 3.1416;
	cout << "La distancia es: " << distancia << endl;
	cout << "El angulo es: " << angulo << endl;
}

void ejercicio_6() {
	int l1, l2, l3;
	bool esEquilatero, esIsoceles, esEscaleno;
	cout << "Ingrese los 3 lados del triangulo: ";
	cin >> l1 >> l2 >> l3;

	esEquilatero = (l1 == l2) && (l2 == l3);
	esEscaleno = (l1 != l2) && (l2 != l3) && (l1 != l3);
	esIsoceles = (!esEquilatero && !esEscaleno);

	cout << "Es equilatero: ";
	cout << (esEquilatero ? "V" : "F") << endl;
	cout << "Es isoceles: ";
	cout << (esIsoceles ? "V" : "F") << endl;
	cout << "Es escaleno: ";
	cout << (esEscaleno ? "V" : "F") << endl;
}

void ejercicio_7() {
	float x, y;
	bool esPc, esSc, esTc, esCc;
	int numeroCuadrante;

	cout << "Ingrese la coordenada X: ";
	cin >> x;

	cout << "Ingrese la coordenada Y: ";
	cin >> y;

	esPc = (x > 0) && (y > 0);
	esSc = (x < 0) && (y > 0);
	esTc = (x < 0) && (y < 0);
	esCc = (x > 0) && (y < 0);

	numeroCuadrante = 0;
	numeroCuadrante = numeroCuadrante + (esPc) * 1;
	numeroCuadrante = numeroCuadrante + (esSc) * 2;
	numeroCuadrante = numeroCuadrante + (esTc == 1) * 3;
	numeroCuadrante = numeroCuadrante + (esCc == 1) * 4;

	cout << "El punto se encuentra en el cuadrante " << numeroCuadrante << endl;
}

int main()
{
	system("pause>0");
	return 0;
}