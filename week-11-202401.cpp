#include <iostream>
using namespace std;

void generarValores(int* arr, int size, int valorMin, int valorMax) {
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % (valorMax - valorMin + 1) + valorMin;
	}
}

void imprimirValores(int* arr, int size) {
	for (int i = 0; i < size; i++)
	{
		cout << i << ' ';
	}
	cout << endl;
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << ' ';
	}
	cout << endl << endl;
}

void buscarMayorYUbicacion(int* arr, int size) {
	// Asumimos que el primer elemento es el mayor
	int posMayor = 0;
	for (int i = 1; i < size; i++)
	{
		if (arr[i] > arr[posMayor]) {
			posMayor = i;
		}
	}
	cout << "El mayor elemento es: " << arr[posMayor];
	// Sumamos 1, porque el usuario cuenta desde 1 no desde 0
	cout << " y su posicion es: " << posMayor + 1 << endl;
}

void buscarMenorYUbicacion(int* arr, int size) {
	// Asumimos que el primer elemento es el mayor
	int posMenor = 0;
	for (int i = 1; i < size; i++)
	{
		if (arr[i] < arr[posMenor]) {
			posMenor = i;
		}
	}
	cout << "El menor elemento es: " << arr[posMenor];
	// Sumamos 1, porque el usuario cuenta desde 1 no desde 0
	cout << " y su posicion es: " << posMenor + 1 << endl;
}

void intercambiar(int &a, int &b) {
	int aux = a;
	a = b;
	b = aux;
}
void ordenarArreglo(int* arr, int size, bool ascendente) {
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			// si cambiamos > por < cambiamos el orden
			if (ascendente) {
				if (arr[j] < arr[i]) {
					//swap(arr[i], arr[j]);
					intercambiar(arr[i], arr[j]);
				}
			}
			else {
				if (arr[j] > arr[i]) {
					//swap(arr[i], arr[j]);
					intercambiar(arr[i], arr[j]);
				}
			}
		}
	}
	imprimirValores(arr, size);
}

void ejercicio_1() {
	int size = 5;
	int* arr = new int[size];
	generarValores(arr, size, 1, 100);
	imprimirValores(arr, size);
	buscarMayorYUbicacion(arr, size);
	buscarMenorYUbicacion(arr, size);
	ordenarArreglo(arr, size, false);
}

int leerN() {
	int n;
	do
	{
		cout << "Ingrese el valor de N ([10; 30]): ";
		cin >> n;
	} while (n < 10 || n > 30);
	return n;
}

int leerR() {
	int r;
	do
	{
		cout << "Ingrese valor de R ([2; 5]): ";
		cin >> r;
	} while (r < 2 || r > 5);
	return r;
}

void agregarElemento(int*& arr, int& size, int elemento) {
	int* tmp = new int[size + 1];
	for (int i = 0; i < size; i++)
	{
		tmp[i] = arr[i];
	}
	tmp[size] = elemento;
	delete[] arr;
	arr = tmp;
	size++;
}
void modificarSegunR(int*& arr, int& size, int R) {
	int sizeTmp = 0;
	int* tmp = new int[sizeTmp];
	for (int i = 0; i < size - 1; i++)
	{
		if (arr[i] != arr[i + 1]) {
			for (int j = 0; j < R; j++)
			{
				agregarElemento(tmp, sizeTmp, arr[i]);
			}
		}
	}
	for (int j = 0; j < R; j++)
	{
		agregarElemento(tmp, sizeTmp, arr[size - 1]);
	}
	delete[] arr;
	arr = tmp;
	size = sizeTmp;
}
void ejercicio_5() {
	int N = leerN();
	int* arr = new int[N];
	generarValores(arr, N, 1, 4);
	imprimirValores(arr, N);
	ordenarArreglo(arr, N, true);
	int R = leerR();
	modificarSegunR(arr, N, R);
	imprimirValores(arr, N);
}

void imprimirRepeticiones(int* arr, int size) {
	int cnt = 1;
	for (int i = 0; i < size - 1; i++)
	{
		if (arr[i] == arr[i + 1]) {
			cnt++;
		}
		else {
			cout << arr[i] << " se repite " << cnt << " veces" << endl;
			cnt = 1;
		}
	}
	cout << arr[size - 1] << " se repite " << cnt << " veces" << endl << endl;
}

void eliminarRepetidos(int*& arr, int& size) {
	int sizeTmp = 0;
	int* tmp = new int[sizeTmp];
	for (int i = 0; i < size - 1; i++)
	{
		if (arr[i] != arr[i + 1]) {
			agregarElemento(tmp, sizeTmp, arr[i]);
		}
	}
	agregarElemento(tmp, sizeTmp, arr[size - 1]);

	delete[] arr;
	arr = tmp;
	size = sizeTmp;
}
void ejercicio_3() {
	int size = 10;
	int* arr = new int[size];
	generarValores(arr, size, 1, 10);
	imprimirValores(arr, size);
	ordenarArreglo(arr, size, true);
	imprimirRepeticiones(arr, size);
	eliminarRepetidos(arr, size);
	imprimirValores(arr, size);
}
int main() {
	srand(time(nullptr));
	ejercicio_3();
	system("pause>0");
	return 0;
}