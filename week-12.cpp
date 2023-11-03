#include <iostream>
using namespace std;

struct cuadrado
{
	double lado;
};
struct triangulo
{
	double base, altura;
};

double area1(cuadrado c) {
	return c.lado* c.lado;
}

double area2(triangulo p) {
	return ((p.base * p.altura) / 2);
}

void ejercicio6()
{
	cuadrado c;
	cout << "Ingrese lado del cuadrado: ";
	cin >> c.lado;
	cout << "El area es: " << area1(c) << "u^2\n";
	triangulo t;
	cout << "Ingrese la base del triangulo: ";
	cin >> t.base;
	cout << "Ingrese la altura del triangulo: ";
	cin >> t.altura;
	cout << "El area es: " << area2(t) << "u^2\n";
}

struct puntosp
{
	double x, y, z;
};

double distancia(puntosp Pi, puntosp Pj)
{
	return sqrt(pow(Pi.x - Pj.x, 2) + pow(Pi.y - Pj.y, 2) +
		pow(Pi.z - Pj.z, 2));
}

puntosp leerPunto()
{
	puntosp punto;
	cout << "Ingrese el valor de x: "; cin >> punto.x;
	cout << "Ingrese el valor de y: "; cin >> punto.y;
	cout << "Ingrese el valor de z: "; cin >> punto.z;
	return punto;
}

void ejercicio5()
{
	puntosp P1, P2;
	P1 = leerPunto();
	P2 = leerPunto();
	cout << "La distancia es: " << distancia(P1, P2);
}

struct empleado
{
	char nombre, sexo;
	double sueldo;
};

void leerEmpleados(empleado* emp, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "\nDatos del empleado " << i + 1 << '\n';
		cout << "Ingrese inicial: ";
		cin >> emp[i].nombre;
		cout << "Ingrese sexo (M/F): ";
		cin >> emp[i].sexo;
		cout << "Ingrese sueldo: ";
		cin >> emp[i].sueldo;
	}
}
void imprimirEmpleado(empleado e)
{
	cout << "Nombre: " << e.nombre << '\n';
	cout << "Sexo: " << e.sexo << '\n';
	cout << "Sueldo: " << e.sueldo << '\n';
}
empleado obtenerMenorEmpleado(empleado* emp, int n)
{
	int menor = 0;
	for (int i = 1; i < n; i++)
	{
		if (emp[i].sueldo < emp[menor].sueldo)
		{
			menor = i;
		}
	}
	return emp[menor];
}
empleado obtenerMayorEmpleado(empleado* emp, int n)
{
	int mayor = 0;
	for (int i = 1; i < n; i++)
	{
		if (emp[i].sueldo > emp[mayor].sueldo)
		{
			mayor = i;
		}
	}
	return emp[mayor];
}
void ejercicio4()
{
	int n;
	cout << "Ingrese el valor de n: "; cin >> n;
	empleado* empleados = new empleado[n];
	leerEmpleados(empleados, n);
	cout << "El menor es:\n";
	imprimirEmpleado(obtenerMenorEmpleado(empleados, n));

	cout << "\nEl mayor es:\n";
	imprimirEmpleado(obtenerMayorEmpleado(empleados, n));
}

struct datos
{
	char nombre[40];
	char pais[25];
};

struct atleta
{
	char deporte[30];
	datos pers;
	int nmedallas;
};

void imprimirAtleta(atleta a)
{
	cout << "\nDatos del atleta:\n";
	cout << "Nombre: " << a.pers.nombre << '\n';
	cout << "Pais: " << a.pers.pais << '\n';
	cout << "Deporte: " << a.deporte << '\n';
}

void generarValores(atleta ats[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "Ingrese deporte: "; cin >> ats[i].deporte;
		cout << "Ingrese nombre: "; cin >> ats[i].pers.nombre;
		cout << "Ingrese pais: "; cin >> ats[i].pers.pais;
		cout << "Ingrese numero de medallas: "; cin >> ats[i].nmedallas;
		cout << '\n';
	}
}
void ejercicio3()
{
	int n = 3;
	atleta ats[3];
	generarValores(ats, n);
	int mayor = 0;
	for (int i = 1; i < n; i++)
	{
		if (ats[i].nmedallas > ats[mayor].nmedallas)
		{
			mayor = i;
		}
	}
	imprimirAtleta(ats[mayor]);
}

struct encuesta
{
	double monto;
	char sexo;
	int edad;
};

int obtenerNValido()
{
	int n;
	do
	{
		cout << "Ingrese el numero de encuestas: ";
		cin >> n;
	} while (n < 0 || n > 200);
	system("cls");
	return n;
}
void generarValores(encuesta* encs, int n)
{
	for (int i = 0; i < n; i++)
	{
		encs[i].monto = rand() % (500 - 25 + 1) + 25;
		int rnd = rand() % 2;
		encs[i].sexo = (rnd == 1) * 'M' + (rnd == 0) * 'F';
		encs[i].edad = rand() % (50 - 15 + 1) + 15;
	}
}
void imprimirEncuesta(encuesta e)
{
	cout << "\tMonto: " << e.monto << "  ";
	cout << "\tSexo: " << e.sexo << "  ";
	cout << "\tEdad: " << e.edad << '\n';
}
void imprimirEncuestas(encuesta* encs, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "Encuesta " << i + 1 << '\n';
		imprimirEncuesta(encs[i]);
	}
}

void interCambiarEncuestas(encuesta& a, encuesta& b)
{
	encuesta aux = a;
	a = b;
	b = aux;
}
void ordenarEncuestas(encuesta* encs, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (encs[i].sexo > encs[j].sexo)
			{
				interCambiarEncuestas(encs[i], encs[j]);
			}
			else if (encs[i].sexo == encs[j].sexo)
			{
				if (encs[i].monto > encs[j].monto)
				{
					interCambiarEncuestas(encs[i], encs[j]);
				}
			}
		}
	}
	cout << "\nLas encuestas fueron ordenadas...\n";
}

void gastoSegunGenero(encuesta* encs, int n)
{
	int cntM, cntF;
	double montoM, montoF;
	cntM = cntF = 0;
	montoM = montoF = 0.0;
	for (int i = 0; i < n; i++)
	{
		if (encs[i].sexo == 'M')
		{
			cntM++;
			montoM += encs[i].monto;
		}
		else
		{
			cntF++;
			montoF += encs[i].monto;
		}
	}
	cout << "\nEl promedio de gasto segun cada genero es:\n";
	cout << "Promedio femenino (" << cntF << "):\n";
	cout << montoF / cntF << '\n';
	cout << "Promedio masculino (" << cntM << "):\n";
	cout << montoM / cntM << '\n';
}
void ejercicio2()
{
	int n = obtenerNValido();
	encuesta* encuestas = new encuesta[n];
	generarValores(encuestas, n);
	imprimirEncuestas(encuestas, n);
	ordenarEncuestas(encuestas, n);
	imprimirEncuestas(encuestas, n);
	gastoSegunGenero(encuestas, n);
}
int main()
{
	srand(time(nullptr));
	ejercicio2();
	system("pause>0");
	return 0;
}