#include <iostream>
using namespace std;

void generarDatosAleatorios(int* arr, int size, int limInf, int limSup) {
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % (limSup - limInf + 1) + limInf;
	}
}

void imprimirDatosDelArreglo(int* arr, int size) {
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << ' ';
	}
	cout << endl;
}

void buscarMayorYPosicion(int* arr, int size) {
	int mayorPos = 0;
	for (int i = 1; i < size; i++)
	{
		if (arr[i] > arr[mayorPos]) {
			mayorPos = i;
		}
	}

	cout << "El mayor elemento es: " << arr[mayorPos];
	cout << " y su posicion es: " << mayorPos + 1 << endl;
}

void buscarMenorYPosicion(int* arr, int size) {
	int menorPos = 0;
	for (int i = 1; i < size; i++)
	{
		if (arr[i] < arr[menorPos]) {
			menorPos = i;
		}
	}

	cout << "El menor elemento es: " << arr[menorPos];
	cout << " y su posicion es: " << menorPos + 1 << endl;
}

void ordenarArregloDescendenteYMostrarlo(int* arr, int size) {
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (arr[j] > arr[i]) {
				int aux = arr[i];
				arr[i] = arr[j];
				arr[j] = aux;
				//swap(arr[i], arr[j]);
			}
		}
	}
	imprimirDatosDelArreglo(arr, size);
}
void ejercicio_1() {
	int size = 10;
	int* arr = new int[size];
	generarDatosAleatorios(arr, size, 1, 9);
	imprimirDatosDelArreglo(arr, size);
	buscarMayorYPosicion(arr, size);
	buscarMenorYPosicion(arr, size);
	ordenarArregloDescendenteYMostrarlo(arr, size);
}

void ordenarArregloAscendente(int* arr, int size) {
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (arr[j] < arr[i]) {
				int aux = arr[i];
				arr[i] = arr[j];
				arr[j] = aux;
				//swap(arr[i], arr[j]);
			}
		}
	}
	//imprimirDatosDelArreglo(arr, size);
}

void imprimirRepeticionesDeNumeros(int* arr, int size) {
	int cnt = 1;
	for (int i = 0; i < size - 1; i++)
	{
		if (arr[i + 1] == arr[i]) {
			cnt++;
		}
		else {
			cout << arr[i] << " se repite " << cnt << " veces" << endl;
			cnt = 1;
		}
	}
	cout << arr[size - 1] << " se repite " << cnt << " veces" << endl;
}

void imprimirElementosUnicos(int* arr, int size) {
	for (int i = 0; i < size - 1; i++)
	{
		if (arr[i + 1] != arr[i]) {
			cout << arr[i] << ' ';
		}
	}
	cout << arr[size - 1] << endl;
}

void eliminarElementoEnPosicion(int*& arr, int &size, int pos) {
	int* tmp = new int[size - 1];
	int j = 0;
	for (int i = 0; i < size; i++)
	{
		if (pos != i) {
			tmp[j] = arr[i];
			j++;
		}
	}

	delete[] arr;
	arr = tmp;
	size--;
}

void eliminarRepetidos(int*& arr, int& size) {
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == arr[i + 1]) {
			eliminarElementoEnPosicion(arr, size, i + 1);
			i--;
		}
	}
	imprimirDatosDelArreglo(arr, size);
}

void ejercicio_3() {
	int size = 10;
	int* arr = new int[size];
	generarDatosAleatorios(arr, size, 1, 10);
	imprimirDatosDelArreglo(arr, size);
	ordenarArregloAscendente(arr, size);
	imprimirDatosDelArreglo(arr, size);
	eliminarElementoEnPosicion(arr, size, 1);
	imprimirDatosDelArreglo(arr, size);
	imprimirRepeticionesDeNumeros(arr, size);
	imprimirElementosUnicos(arr, size);
	eliminarRepetidos(arr, size);

}

int obtenerNValido(int limInf, int limSup) {
	int n;
	do
	{
		cout << "Ingrese el valor de n: ";
		cin >> n;
	} while (n < limInf || n > limSup);
	return n;
}

void imprimirArregloConIndices(int* arr, int size) {
	for (int i = 0; i < size; i++)
	{
		cout << "| " << i;
		if (i < 10) {
			cout << ' ';
		}
		cout << "|";
	}
	cout << endl;
	for (int i = 0; i < size; i++)
	{
		cout << "| ";
		cout << arr[i];
		if (arr[i] < 10) {
			cout << ' ';
		}
		cout << "|";
	}
	cout << endl << endl;
}

void eliminarMultiplosDe3(int*& arr, int& size) {
	for (int i = 0; i < size; i++)
	{
		if (arr[i] % 3 == 0) {
			eliminarElementoEnPosicion(arr, size, i);
			i--;
		}
	}
}

void agregarElementoArreglo(int*& arr, int& size, int elemento) {
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

void leerEInsertarOrdenado(int*& arr, int& size) {
	int elemento;
	cout << "Ingrese nuevo elemento: ";
	cin >> elemento;

	agregarElementoArreglo(arr, size, elemento);
	ordenarArregloAscendente(arr, size);
}
void ejercicio_4() {
	int n = obtenerNValido(10, 15);
	int* arr = new int[n];
	generarDatosAleatorios(arr, n, 1, 50);
	imprimirArregloConIndices(arr, n);
	eliminarMultiplosDe3(arr, n);
	imprimirArregloConIndices(arr, n);
	ordenarArregloAscendente(arr, n);
	imprimirArregloConIndices(arr, n);
	leerEInsertarOrdenado(arr, n);
	imprimirArregloConIndices(arr, n);

}
int main()
{
	srand(time(nullptr));
	ejercicio_4();
	system("pause>0");
	return 0;
}