#include <iostream>
using namespace std;
struct Encuestado {
	char sexo;
	int edad;
	float monto;
};

int obtenerNValido() {
	int n;
	do
	{
		cout << "Ingresar n: ";
		cin >> n;
	} while (n < 0 || n > 200);
	return n;
}

void generarDatosAleatorios(Encuestado* encuestados, int size) {
	for (int i = 0; i < size; i++)
	{
		// rand de MenorValor -> MayorValor
		// rand () % (MayorValor - MenorValor + 1) + MenorValor;
		encuestados[i].edad = rand() % (50 - 15 + 1) + 15;
		encuestados[i].sexo = 70 + (rand() % 2) * 7;
		encuestados[i].monto = rand() % (500 - 25 + 1) + 25;
	}
}

void imprimirDatos(Encuestado* encuestados, int size) {
	for (int i = 0; i < size; i++)
	{
		cout << "Datos del encuestado " << i + 1 << ":" << endl;
		cout << "Edad: " << encuestados[i].edad << endl;
		cout << "Sexo: " << encuestados[i].sexo << endl;
		cout << "Monto: " << encuestados[i].monto << endl << endl;
	}
}

void promedioGastoSegunGenero(Encuestado* encuestados, int size) {
	float sumaMontoMasculino, sumaMontoFemenino;
	int cntMasculinos, cntFemeninas;
	sumaMontoFemenino = sumaMontoMasculino = 0.0f;
	cntFemeninas = cntMasculinos = 0;
	for (int i = 0; i < size; i++)
	{
		if (encuestados[i].sexo == 'F') {
			cntFemeninas++;
			sumaMontoFemenino += encuestados[i].monto;
		}
		else {
			cntMasculinos++;
			sumaMontoMasculino += encuestados[i].monto;
		}
	}
	cout << "\nPROMEDIO DE GASTOS SEGUN SEXO:\n";
	cout << "El promedio de gasto masculino es: ";
	if (cntMasculinos > 0) {
		cout << sumaMontoMasculino / cntMasculinos << endl;
	}
	else {
		cout << 0 << endl;
	}
	cout << "El promedio de gasto femenino es: ";
	cout << (cntFemeninas > 0 ? sumaMontoFemenino / cntFemeninas : 0) << endl;
	/*
	if (cntFemeninas > 0) {
		cout << sumaMontoFemenino / cntFemeninas << endl;
	}
	else {
		cout << 0 << endl;
	}
	*/
}

void promedioGastosSegunGrupoEdad(Encuestado* encuestados, int size) {
	float mnt15_30, mnt30_45, mnt45_50;
	int cnt15_30, cnt30_45, cnt45_50;
	mnt15_30 = mnt30_45 = mnt45_50 = 0;
	cnt15_30 = cnt30_45 = cnt45_50 = 0;
	for (int i = 0; i < size; i++)
	{
		if (encuestados[i].edad < 30) {
			cnt15_30++;
			mnt15_30 += encuestados[i].monto;
		}
		else if (encuestados[i].edad < 45) {
			cnt30_45++;
			mnt30_45 += encuestados[i].monto;
		}
		else {
			cnt45_50++;
			mnt45_50 += encuestados[i].monto;
		}
	}
	cout << "\nPROMEDIO DE GASTOS SEGUN GRUPO DE EDADES\n";
	cout << "El promedio de gasto de 15 a 30 es: ";
	cout << (cnt15_30 > 0 ? mnt15_30 / cnt15_30 : 0) << endl;
	cout << "El promedio de gasto de 30 a 45 es: ";
	cout << (cnt30_45 > 0 ? mnt30_45 / cnt30_45 : 0) << endl;
	cout << "El promedio de gasto de 45 a 50 es: ";
	cout << (cnt45_50 > 0 ? mnt45_50 / cnt45_50 : 0) << endl;
}

void intercambiar(Encuestado& e1, Encuestado& e2) {
	Encuestado x = e1;
	e1 = e2;
	e2 = x;
}

void ordenarSegunGeneroYMonto(Encuestado* encuestados, int size) {
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (encuestados[j].sexo == encuestados[i].sexo) {
				if (encuestados[j].monto < encuestados[i].monto) {
					intercambiar(encuestados[j], encuestados[i]);
				}
			}
			else {
				if (encuestados[j].sexo < encuestados[i].sexo) {
					intercambiar(encuestados[j], encuestados[i]);
				}
			}
		}
	}
}
void ejercicio_2() {
	int N = obtenerNValido();
	Encuestado* encuestados = new Encuestado[N];
	generarDatosAleatorios(encuestados, N);
	imprimirDatos(encuestados, N);
	promedioGastoSegunGenero(encuestados, N);
	promedioGastosSegunGrupoEdad(encuestados, N);
	ordenarSegunGeneroYMonto(encuestados, N);
	imprimirDatos(encuestados, N);
}


struct Datos {
	char nombre[40];
	char pais[25];
};

struct Atleta {
	char deporte[30];
	Datos datosPersonales;
	int medallas;
};

Atleta leerAtleta() {
	Atleta a;
	cout << "Ingrese deporte: "; cin >> a.deporte;
	cout << "Ingrese nombre: "; cin >> a.datosPersonales.nombre;
	cout << "Ingrese pais: "; cin >> a.datosPersonales.pais;
	cout << "Ingrese n de medallas: "; cin >> a.medallas;
	return a;
}

void leerDatosDeAtletas(Atleta* atletas, int size) {
	for (int i = 0; i < size; i++)
	{
		atletas[i] = leerAtleta();
	}
}

void imprimirDatos(Atleta* atletas, int size) {
	for (int i = 0; i < size; i++)
	{
		cout << "Atleta " << i + 1 << ":" << endl;
		cout << "Deporte: " << atletas[i].deporte << endl;
		cout << "Nombre: " << atletas[i].datosPersonales.nombre << endl;
		cout << "Pais: " << atletas[i].datosPersonales.pais << endl;
		cout << "N de medallas: " << atletas[i].medallas << endl << endl;
	}
}

void ejercicio_3() {
	int n = obtenerNValido();
	Atleta* atletas = new Atleta[n];
	leerDatosDeAtletas(atletas, n);
	imprimirDatos(atletas, n);
}

struct Empleado {
	string nombre;
	char sexo;
	float sueldo;
};

Empleado leerEmpleado() {
	Empleado e;
	cout << "Ingrese el nombre: "; cin >> e.nombre;
	cout << "Ingrese su sexo (F/M): "; cin >> e.sexo;
	cout << "Ingrese su sueldo: "; cin >> e.sueldo;
	return e;
}

void imprimirEmpleado(Empleado e) {
	cout << "Nombre: " << e.nombre << endl;
	cout << "Sexo: " << e.sexo << endl;
	cout << "Sueldo: " << e.sueldo << endl;
	cout << endl;
}

void imprimirEmpleadoMayorSueldo(Empleado* empleados, int size) {
	int mayorPos = 0;
	for (int i = 1; i < size; i++)
	{
		if (empleados[i].sueldo > empleados[mayorPos].sueldo) {
			mayorPos = i;
		}
	}
	cout << "\nEl empleado con mayor sueldo es:\n";
	imprimirEmpleado(empleados[mayorPos]);
}

void imprimirEmpleadoMenorSueldo(Empleado* empleados, int size) {
	int menorPos = 0;
	for (int i = 1; i < size; i++)
	{
		if (empleados[i].sueldo < empleados[menorPos].sueldo) {
			menorPos = i;
		}
	}
	cout << "\nEl empleado con menor sueldo es:\n";
	imprimirEmpleado(empleados[menorPos]);
}

void ejercicio_4() {
	int N;
	cout << "Ingrese el numero de empleados: ";
	cin >> N;
	Empleado* empleados = new Empleado[N];
	for (int i = 0; i < N; i++)
	{
		empleados[i] = leerEmpleado();
	}
	cout << "\nLos empleados son...\n";
	for (int i = 0; i < N; i++)
	{
		imprimirEmpleado(empleados[i]);
	}
	imprimirEmpleadoMayorSueldo(empleados, N);
	imprimirEmpleadoMenorSueldo(empleados, N);
}
int main()
{
	srand(time(nullptr));
	ejercicio_3();
	system("pause>0");
	return 0;
}