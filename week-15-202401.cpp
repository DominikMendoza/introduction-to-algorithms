#include <iostream>
#define N_VENDEDORES 2
#define CRITERIOS 3
using namespace System;
using namespace std;
int obtenerVariableValida(int limInf, int limSup, char var) {
	int x;
	do
	{
		cout << "Ingrese el valor de " << var << ": ";
		cin >> x;
	} while (x < limInf || x > limSup);
	return x;
}

void GenerayLista_Paralelos(char* Vgripe, char* Vtos, float* Vpesos, int nAlumnos) {
	for (int i = 0; i < nAlumnos; i++)
	{
		Vgripe[i] = 'N' + (rand() % 2) * 5;
		Vtos[i] = 'N' + (rand() % 2) * 5;
		Vpesos[i] = rand() % (60 - 30 + 1) + 30;
	}

	for (int i = 0; i < nAlumnos; i++)
	{
		cout << "Alumno" << i + 1 << endl;
		cout << "Gripe: " << Vgripe[i] << endl;
		cout << "Tos: " << Vtos[i] << endl;
		cout << "Peso: " << Vpesos[i] << endl << endl;
	}
}

float Porcentaje_gripe_tos(char* Vgripe, char* Vtos, int nAlumnos) {
	int cnt = 0;
	for (int i = 0; i < nAlumnos; i++)
	{
		if (Vgripe[i] == 'S' && Vtos[i] == 'S') {
			cnt++;
		}
	}
	return (cnt * 100.0f) / nAlumnos;
}

float Promedio_pesos(char* Vgripe, char* Vtos, float* Vpesos, int nAlumnos) {
	float sumaDePesos = 0.0f;
	int cnt = 0;
	for (int i = 0; i < nAlumnos; i++)
	{
		if (Vgripe[i] == 'S' || Vtos[i] == 'S') {
			sumaDePesos += Vpesos[i];
			cnt++;
		}
	}
	if (cnt == 0) return 0;
	return (sumaDePesos / cnt);
}

void ListadoOrdenado(char* Vgripe, char* Vtos, float* Vpesos, int nAlumnos) {
	int* indices = new int[nAlumnos];
	for (int i = 0; i < nAlumnos; i++)
	{
		indices[i] = i;
	}

	for (int i = 0; i < nAlumnos - 1; i++) {
		for (int j = i + 1; j < nAlumnos; j++)
		{
			if (Vpesos[indices[j]] > Vpesos[indices[i]]) {
				swap(indices[i], indices[j]);
			}
		}
	}

	for (int i = 0; i < nAlumnos; i++)
	{
		cout << "Alumno" << indices[i] + 1 << endl;
		cout << "Gripe: " << Vgripe[indices[i]] << endl;
		cout << "Tos: " << Vtos[indices[i]] << endl;
		cout << "Peso: " << Vpesos[indices[i]] << endl << endl;
	}
	delete[] indices;
}

void ejercicio1_15() {
	char* Vgripe, * Vtos;
	float* Vpesos;
	int nAlumnos = obtenerVariableValida(1, 20, 'n');
	Vgripe = new char[nAlumnos];
	Vtos = new char[nAlumnos];
	Vpesos = new float[nAlumnos];
	GenerayLista_Paralelos(Vgripe, Vtos, Vpesos, nAlumnos);
	cout << "El porcentaje que tuvieron gripe y tos a la vez fue : ";
	cout << Porcentaje_gripe_tos(Vgripe, Vtos, nAlumnos) << "%" << endl;
	cout << "El promedio de pesos que tuvieron alguna enfermedad fue: ";
	cout << Promedio_pesos(Vgripe, Vtos, Vpesos, nAlumnos) << endl;
	ListadoOrdenado(Vgripe, Vtos, Vpesos, nAlumnos);
	delete[] Vgripe;
	delete[] Vtos;
	delete[] Vpesos;
}

int obtenerMatrizSize() {
	int size;
	do
	{
		cout << "Ingrese tamano de matriz: ";
		cin >> size;
	} while (size < 3 || size > 30);
	return size;
}

void generarDatosDeMatriz(int** matriz, int size) {
	// filas
	for (int i = 0; i < size; i++)
	{
		// columnas
		for (int j = 0; j < size; j++)
		{
			matriz[i][j] = rand() % 10;
		}
	}
}

void imprimirMatriz(int** matriz, int size) {
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cout << matriz[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl;
}

int obtenerPatronNumerico() {
	int numero;
	do
	{
		cout << "Ingrese patron numerico: ";
		cin >> numero;
	} while (numero <= 99 || numero >= 1000);
	return numero;
}

int obtenerRepeticionesDePatron(int** matriz, int size, int patron) {
	int c, d, u, cnt = 0;
	u = patron % 10;
	d = (patron / 10) % 10;
	c = patron / 100;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j <= size - 3; j++)
		{
			if (matriz[i][j] == c && matriz[i][j + 1] == d &&
				matriz[i][j + 2] == u) {
				cnt++;
			}
		}
	}
	return cnt;
}

void MostrarMatrizResaltada(int** Matriz, int N, int Patron)
{
	int p1 = Patron / 100;
	int p2 = (Patron / 10) % 10;
	int p3 = Patron % 10;

	cout << endl << "Matriz Resaltada" << endl;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (j <= N - 3 && Matriz[i][j] == p1 &&
				Matriz[i][j + 1] == p2 && Matriz[i][j + 2] == p3)
			{
				Console::BackgroundColor = ConsoleColor::Yellow;
				Console::ForegroundColor = ConsoleColor::Black;
				cout << Matriz[i][j] << ' ';
				cout << Matriz[i][j + 1] << ' ';
				cout << Matriz[i][j + 2] << ' ';
				j += 2;
				Console::ResetColor();
			}
			else
			{
				cout << Matriz[i][j] << ' ';
			}
		}
		cout << endl;
	}
}
void ejercicio2_15() {
	int N = obtenerMatrizSize();
	int** matriz = new int* [N];
	for (int i = 0; i < N; i++)
	{
		matriz[i] = new int[N];
	}
	generarDatosDeMatriz(matriz, N);
	imprimirMatriz(matriz, N);

	int patron = obtenerPatronNumerico();
	cout << "El numero de veces que se repite le patron es: ";
	cout << obtenerRepeticionesDePatron(matriz, N, patron) << endl;
	MostrarMatrizResaltada(matriz, N, patron);
	for (int i = 0; i < N; i++)
	{
		delete[] matriz[i];
	}
	delete[] matriz;
}

void poblarMatrizDeData(int matriz[][CRITERIOS]) {
	for (int i = 0; i < N_VENDEDORES; i++)
	{
		// min llam tel fijo
		matriz[i][0] = rand() % 31;
		// min llm tel cel
		matriz[i][1] = rand() % 51;
		// mensajes texto
		matriz[i][2] = rand() % 31;
	}
}

void imprimirData(int matriz[][CRITERIOS],
	int codigosVendedores[]) {
	cout << "Codigo vendedor\ttel fijo  tel cel\tmns texto" << endl;
	for (int i = 0; i < N_VENDEDORES; i++)
	{
		cout << codigosVendedores[i] << "\t\t";
		for (int j = 0; j < CRITERIOS; j++)
		{
			cout << matriz[i][j] << '\t';
		}
		cout << endl;
	}
	cout << endl;
}
void determinarVendedoresMayorMinutosCel(int matriz[][CRITERIOS],
	int codigosVendedores[]) {
	int maxi = -1;
	for (int i = 0; i < N_VENDEDORES; i++)
	{
		maxi = max(maxi, matriz[i][1]);
	}

	cout << "El/los vendedores que tiene(n) el maximo de minutos es/son: ";
	for (int i = 0; i < N_VENDEDORES; i++)
	{
		if (matriz[i][1] == maxi) {
			cout << codigosVendedores[i] << " ";
		}
	}
	cout << endl;
}

void calcularMontoDeExceso(int matriz[][CRITERIOS],
	int codigosVendedores[]) {
	int exTelFijo, exTelCel, exMensTexto;
	for (int i = 0; i < N_VENDEDORES; i++)
	{
		exTelFijo = exTelCel = exMensTexto = 0;
		if (matriz[i][0] > 20) {
			exTelFijo = matriz[i][0] - 20;
		}
		if (matriz[i][1] > 40) {
			exTelCel = matriz[i][1] - 40;
		}
		if (matriz[i][2] > 20) {
			exMensTexto = matriz[i][2] - 20;
		}
		cout << "[" << codigosVendedores[i] << "] " << "execeso a pagar: ";
		cout << exTelFijo * 0.35 + exTelCel * 0.45 + exMensTexto * 0.20 << endl;
	}
	cout << endl;
}

void tiempoPromedioDeLlamadasYMensajes(int matriz[][CRITERIOS],
	int codigosVendedores[]) {
	float sumTelFijo, sumTelCel, sumMensTexto;
	sumTelFijo = sumTelCel = sumMensTexto = 0.0f;

	for (int i = 0; i < N_VENDEDORES; i++)
	{
		sumTelFijo += matriz[i][0];
		sumTelCel += matriz[i][1];
		sumMensTexto += matriz[i][2];
	}
	cout << "El promedio de min fijo es: " << sumTelFijo/N_VENDEDORES << "\t";
	cout << "El promedio de min cel es: " << sumTelCel/N_VENDEDORES << "\t";
	cout << "El promedio de mensajes es: " << sumMensTexto/N_VENDEDORES << "\t";
	cout << endl;
}

void ejercicio3_15() {
	int codigosVendedores[N_VENDEDORES];
	int data[N_VENDEDORES][CRITERIOS];
	for (int i = 0; i < N_VENDEDORES; i++)
	{
		codigosVendedores[i] = 201 + i;
	}
	poblarMatrizDeData(data);
	imprimirData(data, codigosVendedores);
	determinarVendedoresMayorMinutosCel(data, codigosVendedores);
	calcularMontoDeExceso(data, codigosVendedores);
	tiempoPromedioDeLlamadasYMensajes(data, codigosVendedores);
}
int main()
{
	srand(time(nullptr));
	ejercicio1_15();
	system("pause>0");
	return 0;
}