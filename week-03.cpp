#include <iostream>
using namespace std;

void ejercicio2a()
{
	int codigoDeSalida;
	cout << "Ingrese un codigo de salida: ";
	cin >> codigoDeSalida;

	int ddep, hora, dparadas;
	ddep = codigoDeSalida / 1000;
	hora = (codigoDeSalida % 1000) / 10;
	dparadas = codigoDeSalida % 10;

	char departamento, paradas;
	departamento = (ddep == 1) * 'T' + (ddep == 2) * 'A' + (ddep == 3) * 'P';
	paradas = (dparadas == 1) * 'S' + (dparadas == 2) * 'N';

	cout << "Departamento de destino: " << departamento << '\n';
	cout << "Hora de salida: " << hora << '\n';
	cout << "Realizan paradas: " << paradas << '\n';
}

void ejercicio3a()
{
	char marca, categoria;
	cout << "Ingrese Marca (B: Best; M: Monark; O: Oxford): ";
	cin >> marca;
	marca = toupper(marca);
	cout << "Ingrese Categoria(P: Paseo; M: Montaniera) : ";
	cin >> categoria;
	categoria = toupper(categoria);

	float precio = 0;
	precio = (marca == 'B' && categoria == 'P') * 1300 + (marca == 'B' && categoria == 'M') * 1000 +
		(marca == 'M' && categoria == 'P') * 1350 + (marca == 'M' && categoria == 'M') * 2500 +
		(marca == 'O' && categoria == 'P') * 900 + (marca == 'O' && categoria == 'M') * 3200;

	cout << "El monto a pagar es: " << precio << '\n';
}

void compararNumeros(int R, int C, int M)
{
	int mayor, intermedio, menor;
	mayor = (R >= C && R >= M) * R + (C >= R && C >= M) * C + (M >= R && M >= C) * M;
	menor = (R <= C && R <= M) * R + (C <= R && C <= M) * C + (M <= R && M <= C) * M;
	intermedio = (R != menor && R != mayor) * R +
		(C != menor && C != mayor) * C + (M != menor && M != mayor) * M;

	cout << "Mayor: " << mayor << '\n';
	cout << "Menor: " << menor << '\n';
	cout << "Intermedio: " << intermedio << '\n';
}
void ejercicio2b()
{
	long long numero;
	cout << "Ingresando el numero: ";
	cin >> numero;
	long long P, R, C;
	P = numero / 100000000;
	R = (numero % 100000000) / 10000;
	C = numero % 10000;
	cout << "P es: " << P << '\n';
	cout << "R es: " << R << '\n';
	cout << "C es: " << C << '\n';
	compararNumeros(P, R, C);

}


void ejercicio3b()
{
	long long codigoAlumno;
	codigoAlumno = 20170666721;
	int anio, mesIngreso, dma, dfacultad, dbc;
	anio = codigoAlumno / 10000000;
	mesIngreso = (codigoAlumno % 10000000) / 100000;
	dma = (codigoAlumno % 100000) / 1000;
	dfacultad = (codigoAlumno % 1000) / 10;
	dbc = codigoAlumno % 10;

	char modalidad, facultad;
	modalidad = (dma == 66) * 'E' + (dma == 77) * 'I';
	facultad = (dfacultad == 70) * 'C' + (dfacultad == 72) * 'H';

	cout << "Anio de ingreso: " << anio << '\n';
	cout << "Mes de ingreso: " << mesIngreso << '\n';
	cout << "Modalidad de admision: " << modalidad << '\n';
	cout << "Categoria: " << facultad << '\n';
	cout << "Es becado? (0: No; 1; Si): " << dbc << '\n';
}

void ejercicio4b()
{
	char marca;
	int color, almacenamiento;
	cout << "Ingrese Marca (N: Nokia; S: Sansumg): ";
	cin >> marca;
	marca = toupper(marca);

	cout << "Ingrese el color: ";
	cin >> color;

	cout << "Ingrese la capacidad de almacenamiento(8: 8GB; 16: 16GB) : ";
	cin >> almacenamiento;

	float precio;
	precio = (marca == 'N' && color == 0 && almacenamiento == 8) * 1800 +
		(marca == 'N' && color == 0 && almacenamiento == 16) * 2650 +
		(marca == 'N' && color == 1 && almacenamiento == 16) * 2780 +
		(marca == 'S' && color == 0 && almacenamiento == 8) * 1700 +
		(marca == 'S' && color == 0 && almacenamiento == 16) * 2500 +
		(marca == 'S' && color == 1 && almacenamiento == 16) * 2900 * 0.94;


	cout << "Usted pagara: " << precio << " soles" << '\n';
}
int main()
{
	ejercicio4b();
	system("pause>0");
	return 0;
}