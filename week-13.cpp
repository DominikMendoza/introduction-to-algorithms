#include <iostream>
using namespace std;

void repaso()
{
	// estaticas
	int M[3][4];
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			M[i][j] = j;
		}
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cout << M[i][j] << ' ';
		}
		cout << '\n';
	}
	// dinamicas
	int filas, columnas;
	filas = 8, columnas = 5;
	int** matriz = new int* [filas];
	for (int i = 0; i < filas; i++)
	{
		matriz[i] = new int[columnas];
	}
	for (int i = 0; i < filas; i++)
	{
		for (int j = 0; j < columnas; j++)
		{
			matriz[i][j] = j;
		}
	}
	for (int i = 0; i < filas; i++)
	{
		for (int j = 0; j < columnas; j++)
		{
			cout << matriz[i][j] << ' ';
		}
		cout << '\n';
	}
}

void imprimirRegistroLLamadas(int matriz[][3], int filas, int columnas)
{
	cout << "Oficina\tCant,Minutos\tTipo de llamada\n";
	for (int i = 0; i < filas; i++)
	{
		for (int j = 0; j < columnas; j++)
		{
			cout << '\t' << matriz[i][j];
		}
		cout << '\n';
	}
}

void determinarMayorCantidadDeLlamadas(int matriz[][3], int filas)
{
	int cnt1, cnt2, cnt3;
	cnt1 = cnt2 = cnt3 = 0;
	for (int i = 0; i < 50; i++)
	{
		switch (matriz[i][0])
		{
		case 1: cnt1++; break;
		case 2: cnt2++; break;
		case 3: cnt3++; break;
		default:
			break;
		}
	}
	int maximo = max(cnt1, max(cnt2, cnt3));
	cout << "La(s) oficina(s): ";
	if (cnt1 == maximo) cout << "1 ";
	if (cnt2 == maximo) cout << "2 ";
	if (cnt3 == maximo) cout << "3 ";
	cout << "tiene(n) el mayor numero de llamadas\n";
}
void determinarMontoLlamada(int matriz[][3], int filas)
{
	cout << "\nMonto por cada llamada:\n";
	float tarifa = 0.0;
	for (int i = 0; i < filas; i++)
	{
		switch (matriz[i][2])
		{
		case 1: tarifa = 0.3; break;
		case 2: tarifa = 0.8; break;
		case 3: tarifa = 1.5; break;
		default:
			break;
		}
		cout << "La llamada " << i + 1 << " cuesta: ";
		cout << matriz[i][1] * tarifa << '\n';
	}
}

void determinarTiempoPromedioVentas(int matriz[][3], int filas)
{
	int cnt1, cnt2, cnt3, sumMin1, sumMin2, sumMin3;
	cnt1 = cnt2 = cnt3 = sumMin1 = sumMin2 = sumMin3 = 0;
	for (int i = 0; i < filas; i++)
	{
		// 3 es oficinas ventas
		if (matriz[i][0] == 3)
		{
			switch (matriz[i][2])
			{
			case 1: cnt1++; sumMin1 += matriz[i][1];
			case 2: cnt2++; sumMin2 += matriz[i][1];
			case 3: cnt3++; sumMin3 += matriz[i][1];
			default:
				break;
			}
		}
	}
	cout << "\nEl tiempo promedio las llamadas es el siguiente:\n";
	cout << "Llamadas tipo 1 -> " << (sumMin1 * 1.0) / cnt1 << '\n';
	cout << "Llamadas tipo 2 -> " << (sumMin2 * 1.0) / cnt2 << '\n';
	cout << "Llamadas tipo 3 -> " << (sumMin3 * 1.0) / cnt3 << '\n';
}
void ejercicio1()
{
	int registroLlamadas[50][3];
	// generar data aleatoria
	for (int i = 0; i < 50; i++)
	{
		registroLlamadas[i][0] = rand() % 3 + 1;
		registroLlamadas[i][1] = rand() % 31;
		registroLlamadas[i][2] = rand() % 3 + 1;
	}
	imprimirRegistroLLamadas(registroLlamadas, 50, 3);
	determinarMayorCantidadDeLlamadas(registroLlamadas, 50);
	determinarMontoLlamada(registroLlamadas, 50);
	determinarTiempoPromedioVentas(registroLlamadas, 50);
	
}

int obtenerNValido(int limInf, int limSup)
{
	int n;
	do
	{
		cout << "Ingrese el valor de n: ";
		cin >> n;
	} while (n < limInf || n > limSup);
	return n;
}
void generarValoresMatriz(int** M, int lado)
{
	for (int i = 0; i < lado; i++)
	{
		for (int j = 0; j < lado; j++)
		{
			M[i][j] = rand() % 3 + 1;
		}
	}
}
void imprimirMatrizCuadrada(int** M, int lado)
{
	for (int i = 0; i < lado; i++)
	{
		for (int j = 0; j < lado; j++)
		{
			cout << M[i][j] << ' ';
		}
		cout << '\n';
	}
}

void operarEImprimirMatriz(int** M, int lado)
{
	int** MResultante = new int* [lado];
	for (int i = 0; i < lado; i++)
	{
		MResultante[i] = new int[lado];
	}
	for (int i = 0; i < lado; i++)
	{
		for (int j = 0; j < lado; j++)
		{
			MResultante[i][j] = 0;
		}
	}
	for (int i = 1; i < lado; i++)
	{
		for (int j = 0; j < i; j++)
		{
			MResultante[i][j] = M[i][j] + M[j][i];
		}
	}
	cout << "\nLa matriz resultante sera:\n";
	imprimirMatrizCuadrada(MResultante, lado);
	for (int i = 0; i < lado; i++)
	{
		delete[] MResultante[i];
	}
	delete[] MResultante;
}
void ejercicio4()
{
	int n = obtenerNValido(2, 50);
	int** M = new int* [n];
	for (int i = 0; i < n; i++)
	{
		M[i] = new int[n];
	}
	generarValoresMatriz(M, n);
	imprimirMatrizCuadrada(M, n);
	operarEImprimirMatriz(M, n);
}


int main()
{
	srand(time(nullptr));
	ejercicio4();
	system("pause>0");
	return 0;
}