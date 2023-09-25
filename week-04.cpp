#include <iostream>
using namespace std;

void ejercicio1()
{
	int num;
	cout << "Ingrese numero entero: ";
	cin >> num;
	if (num % 2 == 0)
	{
		cout << "Es un numero par\n";
	}
	else {
		cout << "Es un numero impar\n";
	}
}

float calcularPrecio(int edad)
{
	float precio;
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
	return precio;
}
void ejercicio2()
{
	int edad;
	cout << "Ingrese la edad de la persona: ";
	cin >> edad;
	if (edad <= 0) {
		cout << "No es una edad valida\n";
	}
	else {
		cout << "El precio de la entrada es: " << calcularPrecio(edad) << '\n';
	}
}

bool esTriangulo(int l1, int l2, int l3)
{
	return (l1 < l2 + l3 && l1 > abs(l2 - l3) &&
		l2 < l1 + l3 && l2 > abs(l1 - l3) &&
		l3 < l1 + l2 && l3 > abs(l1 - l2));
}
void ejercicio3()
{
	int l1, l2, l3;
	cout << "Ingrese los lados de un triangulo (A B C): ";
	cin >> l1 >> l2 >> l3;
	if (esTriangulo(l1, l2, l3))
	{
		cout << "Si es un triangulo\n";
	}
	else {
		cout << "No es un triangulo\n";
	}
}

void ejercicio4()
{
	int n1, n2;
	cout << "Ingrese dos numeros enteros (N1 N2): ";
	cin >> n1 >> n2;
	if (n1 % n2 == 0) {
		cout << n1 << " es mulitpo de " << n2 << '\n';
	}
	else {
		cout << n1 << " no es mulitpo de " << n2 << '\n';
	}
}
float calculaSueldo(int edad)
{
	float sueldo = 0;
	if (edad <= 19)
	{
		sueldo += 1500;
	}
	else if (edad <= 24)
	{
		sueldo += 3000;
	}
	else if (edad <= 30)
	{
		sueldo += 1200;
	}
	else if (edad <= 35)
	{
		sueldo += 100;
	}
	else
	{
		sueldo = 500;
	}
	return sueldo;
}
void pregunta1()
{
	int edad;
	bool esCrack;
	float sueldo = 2500;
	cout << "Es un crack? (1/0): ";
	cin >> esCrack;
	cout << "Ingrese su edad: ";
	cin >> edad;
	if (esCrack)
	{
		sueldo += 1000;
		//sueldo = sueldo + 1000;
	}
	if (edad < 15) {
		cout << "Eres muy joven...\n";
	}
	else {
		sueldo += calculaSueldo(edad);
		cout << "El sueldo es: " << sueldo << '\n';
	}
	
}

int main()
{
	pregunta1();
	system("pause>0");
	return 0;
}