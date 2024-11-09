#include <iostream>
using namespace std;

const int filas = 10;
const int columnas = 15;

const int fil = 6;
const int col = 8;
void generarDatosAleatorios(int M[filas][columnas]) {
	for (int i = 0; i < filas; i++)
	{
		for (int j = 0; j < columnas; j++)
		{
			M[i][j] = rand() % 3 + 1;
		}
	}
}

void imprimirMatriz(int M[filas][columnas]) {
	for (int i = 0; i < filas; i++)
	{
		for (int j = 0; j < columnas; j++)
		{
			cout << M[i][j] << ' ';
		}
		cout << endl;
	}
}

void determinarMayorYMenorFrecuencia(int M[filas][columnas]) {
	int cnt1, cnt2, cnt3;
	cnt1 = cnt2 = cnt3 = 0;
	for (int i = 0; i < filas; i++)
	{
		for (int j = 0; j < columnas; j++)
		{
			switch (M[i][j])
			{
			case 1: cnt1++; break;
			case 2: cnt2++; break;
			case 3: cnt3++; break;
			}
		}
	}
	cout << "Cultivos 1: " << cnt1 << '\t';
	cout << "Cultivos 2: " << cnt2 << '\t';
	cout << "Cultivos 3: " << cnt3 << '\n';
	int mayorFre, menorFre;
	mayorFre = max(cnt1, max(cnt2, cnt3));
	menorFre = min(cnt1, min(cnt2, cnt3));
	cout << "El cultivo con mayor frecuencia es ";
	if (cnt1 == mayorFre) {
		cout << "1";
	}
	else if (cnt2 == mayorFre) {
		cout << "2";
	}
	else {
		cout << "3";
	}
	cout << ", y con menor frecuencia es el ";
	if (cnt1 == menorFre) {
		cout << "1";
	}
	else if (cnt2 == menorFre) {
		cout << "2";
	}
	else {
		cout << "3";
	}
	cout << endl;

}

void buscarGuaridasTopos(int M[filas][columnas]) {
	cout << "Los puntos donde puede existir una guarida de topo son:" << endl;
	for (int i = 1; i < filas - 1; i++)
	{
		for (int j = 1; j < columnas - 1; j++)
		{
			if (M[i][j - 1] == 2 && M[i - 1][j] == 3 &&
				M[i][j + 1] == 2 && M[i + 1][j] == 1) {
				cout << "Fila: " << i + 1;
				cout << ", Columna: " << j + 1 << endl;
			}
		}
	}
}

void ejercicio_2() {
	
	int M[filas][columnas];
	generarDatosAleatorios(M);
	imprimirMatriz(M);
	determinarMayorYMenorFrecuencia(M);
	buscarGuaridasTopos(M);
}

int obtenerNValido(int limInf, int limSup) {
	int n;
	do
	{
		cout << "Ingrese size de la matriz cuadrada: ";
		cin >> n;
	} while (n < limInf || n > limSup);
	return n;
}

void generarValoresAleatorios(int** matriz, int lado) {
	for (int i = 0; i < lado; i++)
	{
		for (int j = 0; j < lado; j++)
		{
			matriz[i][j] = rand() % 5;
		}
	}
}

void imprimirMatrizCuadrada(int** matriz, int lado) {
	for (int i = 0; i < lado; i++)
	{
		for (int j = 0; j < lado; j++)
		{
			cout << matriz[i][j] << ' ';
		}
		cout << endl;
	}
}

int** obtenerMatrizVacia(int lado) {
	int** matrizResultante;
	matrizResultante = new int* [lado];
	for (int i = 0; i < lado; i++)
	{
		matrizResultante[i] = new int[lado];
	}
	for (int i = 0; i < lado; i++)
	{
		for (int j = 0; j < lado; j++)
		{
			matrizResultante[i][j] = 0;
		}
	}
	return matrizResultante;
}

void mostrarMatrizSumaTriangulos(int** matriz, int lado) {
	int** matrizResultante = obtenerMatrizVacia(lado);
	for (int i = 1; i < lado; i++)
	{
		for (int j = 0; j < i; j++)
		{
			matrizResultante[i][j] = matriz[i][j] + matriz[j][i];
		}
	}
	cout << endl << "La matriz resultante es:" << endl;
	imprimirMatrizCuadrada(matrizResultante, lado);
	for (int i = 0; i < lado; i++)
	{
		delete[] matrizResultante[i];
	}
	delete[] matrizResultante;
}

void ejercicio_4() {
	int n = obtenerNValido(2, 50);
	int** matriz;
	// filas
	matriz = new int* [n];
	for (int i = 0; i < n; i++)
	{
		// columnas
		matriz[i] = new int[n];
	}
	generarValoresAleatorios(matriz, n);
	imprimirMatrizCuadrada(matriz, n);
	mostrarMatrizSumaTriangulos(matriz, n);

	for (int i = 0; i < n; i++)
	{
		delete[] matriz[i];
	}
	delete[] matriz;
}

void generarPresenciaDeLuz(int M[fil][col]) {
	for (int i = 0; i < fil; i++)
	{
		for (int j = 0; j < col; j++)
		{
			// considerar 0 -> 11 valores mas idoneos
			M[i][j] = rand() % 12;
		}
	}
}

void imprimirRegistroDeLuz(int M[fil][col]) {
	for (int i = 0; i < fil; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cout.width(4);
			cout << M[i][j];
		}
		cout << endl;
	}
}

void mostrarEstrellas(int M[fil][col]) {
	cout << "\nReporte de estrellas\n";
	// utilizamos guiones para apreciar los vacios
	for (int i = 0; i < fil; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cout.width(4);
			if (i == 0 || i == fil - 1 || j == 0 || j == col - 1) {
				cout << "-";
				continue;
			}

			if (M[i][j] + M[i - 1][j] + M[i + 1][j] +
				M[i] [j - 1] + M[i][j + 1] > 30) {
				cout << "*";
			}
			else {
				cout << "-";
			}
		}
		cout << endl;
	}
}


void ejercicio_5() {
	int M[fil][col];
	generarPresenciaDeLuz(M);
	imprimirRegistroDeLuz(M);
	mostrarEstrellas(M);
}

int main()
{
	srand(time(nullptr));
	ejercicio_5();
	system("pause>0");
	return 0;
}