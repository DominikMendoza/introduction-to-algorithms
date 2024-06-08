#include <iostream>
#include <cstring>
using namespace std;

struct Encuestado {
	int nivelDeAprobacion;
	int edad;
	char nivelSocioEconomico;
};

void generarData(Encuestado* arr, int size) {
	for (int i = 0; i < size; i++)
	{
		arr[i].nivelDeAprobacion = rand() % 5 + 1;
		arr[i].edad = rand() % 50 + 17;
		arr[i].nivelSocioEconomico = rand() % 4 + 65;
	}
}

void imprimirEncuestados(Encuestado* arr, int size) {
	for (int i = 0; i < size; i++)
	{
		cout << i + 1 << ": ";
		cout << arr[i].nivelDeAprobacion << ' ';
		cout << arr[i].edad << ' ';
		cout << arr[i].nivelSocioEconomico << ' ';
		cout << endl;
	}
	cout << endl;
}

void imprimirMayorVotacionNivelDeAprobacion(Encuestado* arr, int size) {
	int cntSize = 6;
	int* cnts = new int[cntSize];
	for (int i = 0; i < cntSize; i++)
	{
		cnts[i] = 0;
	}
	for (int i = 0; i < size; i++)
	{
		cnts[arr[i].nivelDeAprobacion]++;
	}

	int posMayor = 0;
	for (int i = 1; i < cntSize; i++)
	{
		if (cnts[i] > cnts[posMayor]) {
			posMayor = i;
		}
	}
	cout << "El nivel de aprobacion que tuvo la mayor votacion es: ";
	cout << posMayor << " con " << cnts[posMayor] << " votos" << endl;
}
void imprimirPersonasNivelSocioA(Encuestado* arr, int size) {
	int cnt = 0;
	for (int i = 0; i < size; i++)
	{
		if (arr[i].nivelSocioEconomico == 'A') {
			cnt++;
		}
	}

	cout << "Las personas del nivel socioeconomico A son: " << cnt << endl;
}

void imprimirEdadPersonaMasJoven(Encuestado* arr, int size) {
	int menorEdad = arr[0].edad;
	for (int i = 1; i < size; i++)
	{
		if (arr[i].edad < menorEdad) {
			menorEdad = arr[i].edad;
		}
	}

	cout << "La edad de la persona mas joven es: " << menorEdad << endl;
}
void ejercicio1_12() {
	int num;
	cout << "Ingrese el numero de personas: ";
	cin >> num;

	Encuestado* encuestados = new Encuestado[num];
	generarData(encuestados, num);
	imprimirEncuestados(encuestados, num);
	imprimirMayorVotacionNivelDeAprobacion(encuestados, num);
	imprimirPersonasNivelSocioA(encuestados, num);
	imprimirEdadPersonaMasJoven(encuestados, num);

}

struct Empleado {
	char nombre[50];
	char sexo;
	float sueldo;
};

void leerDatosDeTrabajadores(Empleado* arr, int size) {
	for (int i = 0; i < size; i++)
	{
		cout << "Ingrese datos para el trabajador " << i + 1 << ":\n";
		cout << "Nombre: ";  cin >> arr[i].nombre;
		cout << "Sexo: "; cin >> arr[i].sexo;
		cout << "Sueldo: "; cin >> arr[i].sueldo;
	}
}

void imprimirEmpleado(Empleado e) {
	cout << "Nombre: " << e.nombre << endl;
	cout << "Sexo: " << e.sexo << endl;
	cout << "Sueldo: " << e.sueldo << endl;
	cout << endl;
}
void imprimirEmpleadoMayoryMenorSueldo(Empleado* arr, int size) {
	int posMayor, posMenor;
	posMayor = posMenor = 0;
	for (int i = 0; i < size; i++)
	{
		if (arr[i].sueldo > arr[posMayor].sueldo) {
			posMayor = i;
		}
		if (arr[i].sueldo < arr[posMenor].sueldo) {
			posMenor = i;
		}
	}

	cout << "Datos del empleado con mayor sueldo:" << endl;
	imprimirEmpleado(arr[posMayor]);
	cout << "Datos del empleado con menor sueldo:" << endl;
	imprimirEmpleado(arr[posMenor]);
}
void ejercicio4_12() {
	int N;
	cout << "Ingrese numero de trabajadores: ";
	cin >> N;

	Empleado* arr = new Empleado[N];
	leerDatosDeTrabajadores(arr, N);
	imprimirEmpleadoMayoryMenorSueldo(arr, N);

}

struct Puntesp {
	double x, y, z;
};

double distancia(Puntesp Pi, Puntesp Pj) {
	return sqrt(
		pow(Pi.x - Pj.x, 2) +
		pow(Pi.y - Pj.y, 2) +
		pow(Pi.z - Pj.z, 2)
	);
}

void ejercicio5_12() {
	Puntesp p1, p2;
	cout << "Ingrese datos del punto 1" << endl;
	cout << "x: "; cin >> p1.x;
	cout << "y: "; cin >> p1.y;
	cout << "z: "; cin >> p1.z;

	cout << "Ingrese datos del punto 2" << endl;
	cout << "x: "; cin >> p2.x;
	cout << "y: "; cin >> p2.y;
	cout << "z: "; cin >> p2.z;

	cout << "La distancia entre los puntos es: ";
	cout << distancia(p1, p2) << endl;

}

struct Cuadrado {
	double lado;
};

struct Triangulo {
	double base, altura;
};

double area1(Cuadrado c) {
	return c.lado * c.lado;
}

double area2(Triangulo t) {
	return (t.base * t.altura) / 2;
}
void ejercicio6_12() {
	Cuadrado c;
	Triangulo t;
	cout << "Ingrese datos del cuadrado:" << endl;
	cout << "Lado: "; cin >> c.lado;

	cout << "Ingrese datos del triangulo:" << endl;
	cout << "Base: "; cin >> t.base;
	cout << "Altura: "; cin >> t.altura;

	cout << "Area del cuadrado: " << area1(c) << endl;
	cout << "Area del triangulo: " << area2(t) << endl;

}
int main()
{
	srand(time(nullptr));
	ejercicio1_12();
	system("pause>0");
	return 0;
}