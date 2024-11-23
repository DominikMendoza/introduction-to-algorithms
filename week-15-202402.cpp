#include <iostream>
#define N_LLAMADAS 30
#define COL 3
using namespace std;

int obtenerNValido() {
	int n;
	do
	{
		cout << "Ingrese el numero de alumnos: ";
		cin >> n;
	} while (n < 1 || n > 20);
	return n;
}

void GenerayLista_Paralelos(char* Vgripe, char* Vtos, float* Vpesos, int nAlumnos) {
	for (int i = 0; i < nAlumnos; i++)
	{
		Vgripe[i] = 'N' + (rand() % 2) * 5;
		Vtos[i] = 'N' + (rand() % 2) * 5;
		Vpesos[i] = rand() % (60 - 30 + 1) + 30;
	}
}

void imprimirAlumnos(char* Vgripe, char* Vtos, float* Vpesos, int nAlumnos) {
	for (int i = 0; i < nAlumnos; i++)
	{
		cout << "Alumno " << i + 1 << endl;
		cout << "Gripe: " << Vgripe[i] << endl;
		cout << "Tos: " << Vtos[i] << endl;
		cout << "Peso: " << Vpesos[i] << endl << endl;
	}
}

void Porcentaje_gripe_tos(char* Vgripe, char* Vtos, int nAlumnos) {
	int gripeYTos = 0;
	for (int i = 0; i < nAlumnos; i++)
	{
		if (Vgripe[i] == 'S' && Vtos[i] == 'S') {
			gripeYTos++;
		}
	}

	cout << "El promedio de alumons que tuvieron gripe y tos es: ";
	cout << gripeYTos * 100.0f / nAlumnos << "%" << endl << endl;
}

void Promedio_pesos(char* Vgripe, char* Vtos, float* Vpesos, int nAlumnos) {
	float sumaPesos = 0.0f;
	int cnt = 0;
	for (int i = 0; i < nAlumnos; i++)
	{
		if (Vgripe[i] == 'S' || Vtos[i] == 'S') {
			sumaPesos += Vpesos[i];
			cnt++;
		}
	}

	cout << "El promedio de peso para los que tuvieron gripe o tos es: ";
	cout << sumaPesos / cnt << endl << endl;
}

void Listado_ordenado(char* Vgripe, char* Vtos, float* Vpesos, int nAlumnos) {
	for (int i = 0; i < nAlumnos - 1; i++)
	{
		for (int j = i + 1; j < nAlumnos; j++)
		{
			if (Vpesos[j] > Vpesos[i]) {
				swap(Vpesos[i], Vpesos[j]);
				swap(Vgripe[i], Vgripe[j]);
				swap(Vtos[i], Vtos[j]);
			}
		}
	}

	imprimirAlumnos(Vgripe, Vtos, Vpesos, nAlumnos);
}

void ejercicio_1() {
	char* Vgripe, * Vtos;
	float *Vpesos;
	int N = obtenerNValido();
	Vgripe = new char[N];
	Vtos = new char[N];
	Vpesos = new float[N];
	GenerayLista_Paralelos(Vgripe, Vtos, Vpesos, N);
	imprimirAlumnos(Vgripe, Vtos, Vpesos, N);
	Porcentaje_gripe_tos(Vgripe, Vtos, N);
	Promedio_pesos(Vgripe, Vtos, Vpesos, N);
	Listado_ordenado(Vgripe, Vtos, Vpesos, N);
}

void generarCodigos(int* codigos) {
	for (int i = 0; i < N_LLAMADAS; i++)
	{
		codigos[i] = 201 + i;
	}
}

void generarDatosDeMatriz(int M[N_LLAMADAS][COL]) {
	for (int i = 0; i < N_LLAMADAS; i++)
	{
		M[i][0] = rand() % 31;
		M[i][1] = rand() % 61;
		M[i][2] = rand() % 31;
	}
}

void imprimirDatos(int* codigos, int M[N_LLAMADAS][COL]) {
	cout << "Codigo\tMin Tel Fijo\tMin Tel Celular\tSMS\n";
	for (int i = 0; i < N_LLAMADAS; i++)
	{
		cout << codigos[i] << "\t\t";
		cout << M[i][0] << "\t" << M[i][1] << "\t\t" << M[i][2] << endl;
	}
}

void determinarCodigosMayorMinCelulares(int* codigos, int M[N_LLAMADAS][COL]) {
	// Columna min celular -> 1
	int colMinCelular = 1;
	int maxMin = -1;
	for (int i = 0; i < N_LLAMADAS; i++)
	{
		maxMin = max(maxMin, M[i][colMinCelular]);
	}

	cout << "El(los) codigo(s) mayor cantidad min celular son: ";
	for (int i = 0; i < N_LLAMADAS; i++)
	{
		if (M[i][colMinCelular] == maxMin) {
			cout << codigos[i] << " ";
		}
	}
	cout << endl;
}

void determinarExcesos(int* codigos, int M[N_LLAMADAS][COL]) {
	float costoPorExceso;
	cout << "\nCosto asociado por llamada a cada vendedor\n";
	for (int i = 0; i < N_LLAMADAS; i++)
	{
		costoPorExceso = 0.0f;
		cout << codigos[i] << "\tcosto por exceso: ";
		// tel fijo
		if (M[i][0] > 20) {
			costoPorExceso += (M[i][0] - 20) * 0.35;

		}
		// tel celular
		if (M[i][1] > 40) {
			costoPorExceso += (M[i][1] - 40) * 0.45;
		}
		// mensajes texto
		if (M[i][2] > 20) {
			costoPorExceso += (M[i][2] - 20) * 0.20;
		}
		cout << costoPorExceso << endl;
	}
}

void calcularPromedios(int M[N_LLAMADAS][COL]) {
	int sumMinutosTelFijo, sumMinutosTelCelular, sumMensajesTexto;
	sumMinutosTelFijo = sumMinutosTelCelular = sumMensajesTexto = 0;
	for (int i = 0; i < N_LLAMADAS; i++)
	{
		sumMinutosTelFijo += M[i][0];
		sumMinutosTelCelular += M[i][1];
		sumMensajesTexto += M[i][2];
	}
	cout << "El promedio de minutos para tel fijo es: ";
	cout << (float)sumMinutosTelFijo / N_LLAMADAS << endl;
	cout << "El promedio de minutos para tel celular es: ";
	cout << (float)sumMinutosTelCelular / N_LLAMADAS << endl;
	cout << "El promedio de minutos para mensajes de texto: ";
	cout << (float)sumMensajesTexto / N_LLAMADAS << endl << endl;
}
void ejercicio_3() {
	int* codigos = new int[N_LLAMADAS];
	int M[N_LLAMADAS][COL];
	generarCodigos(codigos);
	generarDatosDeMatriz(M);
	imprimirDatos(codigos, M);
	determinarCodigosMayorMinCelulares(codigos, M);
	determinarExcesos(codigos, M);
	calcularPromedios(M);
}
int main()
{
	srand(time(nullptr));
	ejercicio_3();
	system("pause>0");
	return 0;
}