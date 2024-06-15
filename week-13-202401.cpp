#include <iostream>
using namespace std;
const int meses = 12;
const int agencias = 5;

const int filas = 6;
const int columnas = 8;

void leerVentasDeAgencias(int M[][agencias]) {
	for (int i = 0; i < meses; i++)
	{
		for (int j = 0; j < agencias; j++)
		{
			cout << "Ingrese datos de la agencia " << j + 1;
			cout << " en el mes " << i + 1 << ": ";
			cin >> M[i][j];
		}
	}
}

void generarVentasDeFormaAleatoria(int M[][agencias]) {
	for (int i = 0; i < meses; i++)
	{
		for (int j = 0; j < agencias; j++)
		{
			M[i][j] = rand() % 10;
		}
	}
}
void mostrarMatrizDeVentas(int M[][agencias]) {
	for (int i = 0; i < meses; i++)
	{
		for (int j = 0; j < agencias; j++)
		{
			cout << M[i][j] << ' ';
		}
		cout << endl;
	}
}

void mostrarResumenDeVentasPorAgencias(int M[][agencias]) {
	int tmp = 0;
	for (int i = 0; i < agencias; i++)
	{
		for (int j = 0; j < meses; j++)
		{
			tmp += M[j][i];
		}
		cout << "Las ventas totales para la agencia " << i + 1;
		cout << " fueron: " << tmp << endl;
		tmp = 0;
	}
	cout << endl;
}

void mostrarTotalDeVentasAgencia3(int M[][agencias]) {
	// La agencia 3 esta en la columna 2
	int agencia3 = 2;
	int suma = 0;
	for (int i = 0; i < meses; i++)
	{
		suma += M[i][agencia3];
	}

	cout << "Las ventas totales de la agencia 3 fueron: ";
	cout << suma << endl << endl;
}

void mostrarPromedioDeVentasDiciembre(int M[][agencias]) {
	// El mes de diciembre esta en la fila 3
	int diciembre = 11;
	int suma = 0;
	for (int i = 0; i < agencias; i++)
	{
		suma += M[diciembre][i];
	}
	cout << "El promedio de ventas para el mes de diciembre fue: ";
	cout << float(suma) / agencias << endl << endl;
}

void mostrarAgenciaConMayorVentasEnMayo(int M[][agencias]) {
	// El mes de mayo esta en la fila 4
	int mayo = 4;
	int mayorVenta = M[mayo][0];
	for (int i = 1; i < agencias; i++)
	{
		mayorVenta = max(mayorVenta, M[mayo][i]);
	}

	for (int i = 1; i < agencias; i++)
	{
		if (M[mayo][i] == mayorVenta) {
			cout << "La agencia " << i + 1 << " tuvo la mayor venta" << endl;
			//break;
		}
	}
	cout << endl;
}

void mostrarMenoresVentas(int M[][agencias]) {
	int tmp = 0;
	int menorVenta = 900000000;
	for (int i = 0; i < meses; i++)
	{
		tmp = 0;
		for (int j = 0; j < agencias; j++)
		{
			tmp += M[i][j];
		}
		menorVenta = min(menorVenta, tmp);
	}

	for (int i = 0; i < meses; i++)
	{
		tmp = 0;
		for (int j = 0; j < agencias; j++)
		{
			tmp += M[i][j];
		}

		if (tmp == menorVenta) {
			cout << "El mes con la menor venta fue el: " << i + 1 << endl;
			// break;
		}
	}
	cout << endl;
}
void ejercicio_3_13() {
	
	int M[meses][agencias];
	//leerVentasDeAgencias(M);
	generarVentasDeFormaAleatoria(M);
	mostrarMatrizDeVentas(M);
	mostrarResumenDeVentasPorAgencias(M);
	mostrarTotalDeVentasAgencia3(M);
	mostrarPromedioDeVentasDiciembre(M);
	mostrarAgenciaConMayorVentasEnMayo(M);
	mostrarMenoresVentas(M);
}

int obtenerNValido(int limInf, int limSup) {
	int n;
	do
	{
		cout << "Ingrese valor de n: ";
		cin >> n;
	} while (n < limInf || n > limSup);
	system("cls");
	cout << "Ingrese valor de n: " << n << endl;
	return n;
}

void generarValoresMatrizCuadrada(int** M, int lado) {
	for (int i = 0; i < lado; i++)
	{
		for (int j = 0; j < lado; j++)
		{
			M[i][j] = rand() % 21;
		}
	}
}

void inicializarMatrizEnCeros(int** MR, int lado) {
	for (int i = 0; i < lado; i++)
	{
		for (int j = 0; j < lado; j++)
		{
			MR[i][j] = 0;
		}
	}
}

void imprimirMatrizCuadrada(int** M, int lado) {
	for (int i = 0; i < lado; i++)
	{
		for (int j = 0; j < lado; j++)
		{
			cout << M[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl;
}
void calcularMatrizResultante(int** M, int** MR, int lado) {
	for (int i = 1; i < lado; i++)
	{
		for (int j = 0; j < i; j++)
		{
			MR[i][j] = M[i][j] + M[j][i];
		}
	}
}
void ejercicio_4_13() {
	int n = obtenerNValido(2, 50);

	int** M, ** MR;
	M = new int* [n];
	MR = new int* [n];
	for (int i = 0; i < n; i++)
	{
		M[i] = new int[n];
		MR[i] = new int[n];
	}
	generarValoresMatrizCuadrada(M, n);
	imprimirMatrizCuadrada(M, n);
	inicializarMatrizEnCeros(MR, n);
	calcularMatrizResultante(M, MR, n);
	imprimirMatrizCuadrada(MR, n);
}

void generarLuminosidadTablaA(int A[][columnas]) {
	for (int i = 0; i < filas; i++)
	{
		for (int j = 0; j < columnas; j++)
		{
			A[i][j] = rand() % 11;
		}
	}
}

void imprimirTablaA(int A[][columnas]) {
	for (int i = 0; i < filas; i++)
	{
		for (int j = 0; j < columnas; j++)
		{
			cout << A[i][j] << '\t';
		}
		cout << endl;
	}
	cout << endl;
}

void analizarTablas(int A[][columnas], int B[][columnas]) {
	int suma;
	// llenamos la tabla B de '0'
	for (int i = 0; i < filas; i++)
	{
		for (int j = 0; j < columnas; j++)
		{
			B[i][j] = 0;
		}
	}
	//  Analizamos la tabla A
	for (int i = 1; i < filas - 1; i++)
	{

		for (int j = 1; j < columnas - 1; j++)
		{
			suma = A[i][j] + A[i - 1][j] + A[i + 1][j] +
				A[i][j - 1] + A[i][j + 1];
			/*
			if (suma > 30) {
				B[i][j] = 1;
			}
			else {
				B[i][j] = 0;
			}
			*/
			B[i][j] = (suma > 30 ? 1 : 0);
		}
	}
}

void imprimirTablaB(int B[][columnas]) {
	for (int i = 0; i < filas; i++)
	{
		for (int j = 0; j < columnas; j++)
		{
			/*
			if (B[i][j]) {
				cout << "* ";
			}
			else {
				cout << "- ";
			}
			*/
			cout << (B[i][j] ? "*\t" : "-\t");
		}
		cout << endl;
	}
	cout << endl;
}
void ejercicio_5_13() {
	int A[filas][columnas];
	int B[filas][columnas];
	generarLuminosidadTablaA(A);
	imprimirTablaA(A);
	analizarTablas(A, B);
	imprimirTablaB(B);
}
int main()
{
	srand(time(nullptr));
	ejercicio_4_13();
	system("pause>0");
	return 0;
}