#include <iostream>
using namespace std;

int obtenerNValido(int limInf, int limSup) {
	int n;
	do
	{
		cout << "Ingrese numero de alumnos: ";
		cin >> n;
	} while (n < limInf || n > limSup);
	return n;
}

struct Alumno {
	char gripe, tos;
	float peso;
};

void generarListaParalelos(Alumno* alumnos, int n) {
	for (int i = 0; i < n; i++)
	{
		int aux = rand() % 2;
		alumnos[i].gripe = (aux == 0) * 'S' + (aux) * 'N';
		aux = rand() % 2;
		alumnos[i].tos = (aux == 0) * 'S' + (aux) * 'N';
		alumnos[i].peso = rand() % 31 + 30;
	}

	for (int i = 0; i < n; i++)
	{
		cout << "Alumno " << i + 1 << "\n";
		cout << "Gripe: " << alumnos[i].gripe << '\n';
		cout << "Tos: " << alumnos[i].tos << '\n';
		cout << "Peso: " << alumnos[i].peso << "\n\n";
	}
}

void porcentajeGripeTos(Alumno* alumnos, int n) {
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		if (alumnos[i].gripe == 'S' && alumnos[i].tos == 'S') {
			cnt++;
		}
	}
	cout << "El porcentaje de los que tuvieron tos y gripe es: ";
	cout << (cnt * 100.0) / n << " %\n\n";
}

void promedioPesos(Alumno* alumnos, int n) {
	float suma = 0.0;
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		if (alumnos[i].gripe == 'S' || alumnos[i].tos == 'S') {
			suma += alumnos[i].peso;
			cnt++;
		}
	}
	cout << "El peso promedio de los que estuvieron enfermos es: ";
	cout << suma / cnt << "\n\n";
}

void listadoOrdenado(Alumno* alumnos, int n) {
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j ++)
		{
			if (alumnos[i].peso < alumnos[j].peso) {
				swap(alumnos[i], alumnos[j]);
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		cout << "Alumno " << i + 1 << "\n";
		cout << "Gripe: " << alumnos[i].gripe << '\n';
		cout << "Tos: " << alumnos[i].tos << '\n';
		cout << "Peso: " << alumnos[i].peso << "\n\n";
	}
}
void ejercicio1()
{
	int n = obtenerNValido(0, 20);
	Alumno* alumnos = new Alumno[n];
	generarListaParalelos(alumnos, n);
	porcentajeGripeTos(alumnos, n);
	promedioPesos(alumnos, n);
	listadoOrdenado(alumnos, n);
}

int obtenerTamanioValido(int limInf, int limSup) {
	int n;
	do
	{
		cout << "Ingrese el tamanio de la matriz: ";
		cin >> n;
	} while (n < limInf || n > limSup);
	return n;
}

int obtenerPatronValido() {
	int n;
	do
	{
		cout << "Ingrese patron a buscar: ";
		cin >> n;
	} while (n < 99 || n > 1000);
	return n;
}
void generarValoresMatriz(int** M, int n) {
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			M[i][j] = rand() % 10;
		}
	}
}
void imprimirMatriz(int** M, int n) {
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << M[i][j] << ' ';
		}
		cout << '\n';
	}
}

void buscarPatron(int** M, int n, int patron) {
	int C, D, U;
	C = patron / 100;
	D = (patron % 100) / 10;
	U = patron % 10;
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - 3; j++)
		{
			if (M[i][j] == C && M[i][j + 1] == D && M[i][j + 2] == U) {
				cnt++;
			}
		}
	}
	cout << "El numero de veces que se repito el patron es: " << cnt << '\n';
}
void ejercicio2()
{
	int n = obtenerTamanioValido(3, 30);
	int** matriz = new int* [n];
	for (int i = 0; i < n; i++)
	{
		matriz[i] = new int[n];
	}

	generarValoresMatriz(matriz, n);
	imprimirMatriz(matriz, n);

	int patron = obtenerPatronValido();
	buscarPatron(matriz, n, patron);

}
int main()
{
	srand(time(nullptr));
	ejercicio2();
	system("pause>0");
	return 0;
}