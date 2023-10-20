#include <iostream>
#include <conio.h>
#define WIDTH 80
#define HEIGHT 40
using namespace System;
using namespace std;
void ejercicio1_10()
{
	int n = 6;
	int* arr = new int[n];
	cout << "Ingrese las notas: ";
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	int suma = 0;
	int mini = arr[0];
	for (int i = 0; i < n; i++)
	{
		suma += arr[i];
		if (arr[i] < mini) {
			mini = arr[i];
		}
	}
	suma -= mini;
	cout << "La nota que no se considera en el promedio seria: " << mini << '\n';
	cout << "El promedio es: " << suma * 1.0 / (n - 1) << '\n';
}
void ejercicio2_10()
{
	int n;
	cout << "Ingrese el valor de n: ";
	cin >> n;
	float* pesos = new float[n];
	cout << "Ingrese los pesos: ";
	for (int i = 0; i < n; i++)
	{
		cin >> pesos[i];
	}

	float suma = 0.0f;
	float maxi = pesos[0];
	int cntDelg, cntMed, cntGrue;
	cntDelg = cntMed = cntGrue = 0;
	for (int i = 0; i < n; i++)
	{
		suma += pesos[i];
		if (pesos[i] > maxi) {
			maxi = pesos[i];
		}
		if (pesos[i] < 53) {
			cntDelg++;
		} else if (pesos[i] <= 60) {
			cntMed++;
		} else {
			cntGrue++;
		}
	}
	cout << "El peso promedio es: " << suma / n << '\n';
	cout << "La persona mas pesada pesa: " << maxi << '\n';
	cout << "El num de per delgadas: " << cntDelg << '\n';
	cout << "El num de per medianas: " << cntMed << '\n';
	cout << "El num de per gruesas: " << cntGrue << '\n';
}
void draw(int* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		Console::ForegroundColor = ConsoleColor(arr[i]);
		cout << '*';
	}
}
void clean(int n)
{
	for (int i = 0; i < n; i++)
	{
		Console::ForegroundColor = ConsoleColor::Black;
		cout << ' ';
	}
}
void ejercicio1_10A()
{
	Console::CursorVisible = false;
	int n = 60;
	int* arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 16;
	}
	for (int i = 1; i < 30; i++)
	{
		Console::SetCursorPosition(5, i - 1);
		clean(n);
		Console::SetCursorPosition(5, i);
		draw(arr, n);
		_sleep(100);
	}
}

void asignarValores(int* cx, int* cy, int* dx, int* dy, int* size, int* color, int num)
{
	for (int i = 0; i < num; i++)
	{
		size[i] = rand() % (5 - 2 + 1) + 2;
		cx[i] = rand() % (WIDTH - size[i]);
		cy[i] = rand() % HEIGHT;
		int arr[] = {-1, 1};
		dx[i] = arr[rand() % 1];
		dy[i] = arr[rand() % 1];
		color[i] = rand() % 16;
	}
}
void borrar(int* cx, int* cy, int* size, int num)
{
	Console::ForegroundColor = ConsoleColor::Black;
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < size[i]; j++)
		{
			Console::SetCursorPosition(cx[i] + j, cy[i]);
			cout << ' ';
		}
	}
}
void mover(int* cx, int* cy, int* dx, int* dy, int* size, int num)
{
	for (int i = 0; i < num; i++)
	{
		if (cx[i] + dx[i] < 0 || cx[i] + size[i] + dx[i] >= WIDTH)
			dx[i] *= -1;
		if (cy[i] + dy[i] < 0 || cy[i] + dy[i] >= HEIGHT)
			dy[i] *= -1;
		cx[i] += dx[i];
		cy[i] += dy[i];
	}
}
void dibujar(int* cx, int* cy, int* size, int* color, int num)
{
	for (int i = 0; i < num; i++)
	{
		Console::ForegroundColor = ConsoleColor(color[i]);
		for (int j = 0; j < size[i]; j++)
		{
			Console::SetCursorPosition(cx[i] + j, cy[i]);
			cout << '*';
		}
	}
}
void verificarColisiones(int* cx, int* cy, int* size, int* color, int num)
{
	for (int i = 0; i < num - 1; i++)
	{
		for (int j = i + 1; j < num; j++)
		{
			for (int s = 0; s < size[i]; s++)
			{
				for (int s2 = 0; s2 < size[j]; s2++)
				{
					if (cx[i] + s == cx[i] + s2 &&
						cy[i] == cy[j] && color[i] != 0 && color[j] != 0)
					{
						color[i] = 0;
						color[j] = 0;
						return;
					}
				}
			}
		}
	}
}
void ejercicio2_10A()
{
	int num = rand() % (10 - 5 + 1) + 5;
	int* cx = new int[num];
	int* cy = new int[num];
	int* dx = new int[num];
	int* dy = new int[num];
	int* size = new int[num];
	int* color = new int[num];
	asignarValores(cx, cy, dx, dy, size, color, num);
	while (true)
	{
		borrar(cx, cy, size, num);
		mover(cx, cy, dx, dy, size, num);
		dibujar(cx, cy, size, color, num);
		verificarColisiones(cx, cy, size, color, num);
		_sleep(100);
	}
}
void borrar3(int* coorY, int n)
{
	for (int i = 0; i < n; i++)
	{
		Console::SetCursorPosition(i, coorY[i]);
		cout << ' ';
	}
}
void dibujar3(int* colores, char* characteres, int* coorY, int n)
{
	for (int i = 0; i < n; i++)
	{
		Console::ForegroundColor = ConsoleColor(colores[i]);
		Console::SetCursorPosition(i, coorY[i]);
		cout << characteres[i];
	}
}
void mover3(int* coorY, int* velocidades, int n)
{
	for (int i = 0; i < n; i++)
	{
		if (coorY[i] + velocidades[i] > HEIGHT)
		{
			velocidades[i] = 0;
			coorY[i] = HEIGHT;
		}
		coorY[i] += velocidades[i];
	}
}
void ejercicio3_10A()
{
	Console::CursorVisible = false;
	int n = 60;
	int* colores = new int[n];
	char* caracteres = new char[n];
	int* velocidades = new int[n];
	int* coorY = new int[n];
	for (int i = 0; i < n; i++)
	{
		colores[i] = rand() % 16;
		caracteres[i] = rand() % (90 - 65 + 1) + 65;
		velocidades[i] = rand() % (3 - 1 + 1) + 1;
		coorY[i] = 1;
	}
	while (true)
	{
		borrar3(coorY, n);
		mover3(coorY, velocidades, n);
		dibujar3(colores, caracteres, coorY, n);
		_sleep(100);
	}
}

// extra
//funciones
void genera_datos(int* numeros, int t)
{
	for (int i = 0; i < t; i++)
	{
		do {
			numeros[i] = 0 + rand() % 6;
		} while (numeros[i] != 2 && numeros[i] != 5 && numeros[i] != 0);
	}
}

void imprime_datos(int* numeros, int t)
{
	cout << endl << "DATOS DEL ARREGLO" << endl;
	for (int i = 0; i < t; i++)
	{
		cout << " " << numeros[i];
	}
}

bool frio(int* numeros, int t)
{
	if (numeros[0] == 2 && numeros[1] == 5 && numeros[2] == 2)
	{
		cout << endl << "Tienen frio";
		return true;
	}
	return false;
}
bool calor(int* numeros, int t)
{
	for (int i = 0; i < t - 5 ; i++)
	{
		if (numeros[i] == 2 && numeros[i + 2] == 0 && numeros[i + 4] == 2)
		{
			cout << endl << "Tienen calor";
			return true;
		}
	}
	return false;
}
bool hambre(int* numeros, int t)
{
	if (numeros[t - 3] == 5 && numeros[t - 2] == 0 && numeros[t - 1] == 2)
	{
		cout << endl << "Tienen hambre";
		return true;
	}
	return false;
}

void peligro(int* numeros, int t)
{
	for (int i = 0; i < t - 3; i++)
	{
		if (numeros[i] == 0 && numeros[i + 1] == 0 && numeros[i + 2] == 0)
			cout << endl << "PELIGRO!";
	}
}

// In process...
void ejercicioExtra()
{
	int* numeros;
	int mensajes_procesados = 0;
	int t;
	int opcion;
	int cntAbrigo, cntAgua, cntAlimento;
	cntAbrigo = cntAgua = cntAlimento = 0;
	do
	{
		Console::Clear();
		//entrada
		cout << endl << "Ingrese tam del arreglo: "; cin >> t;
		//crea el arreglo
		numeros = new int[t];
		genera_datos(numeros, t);
		imprime_datos(numeros, t);
		if (frio(numeros, t)) cntAbrigo++;
		if (calor(numeros, t)) cntAgua++;
		if (hambre(numeros, t)) cntAlimento++;
		peligro(numeros, t);
		delete[]numeros;
		cout << endl << "...presiona una tecla para un nuevo arreglo..";
		system("pause>0");
		mensajes_procesados++;
	} while (opcion != 'T');
	cout << "\t===== REPORTE =====";
	cout << "\tCantidad de mensajes procesados: " << mensajes_procesados << endl;
	cout << "\tCantidad de veces que se ha solicitado abrigo: " << cntAbrigo << endl;
	cout << "\tCantidad de veces que se ha solicitado agua: " << cntAgua << endl;
	cout << "\tCantidad de veces que se ha solicitado alimento " << cntAlimento << endl;
}


int main()
{
	Console::SetWindowSize(WIDTH, HEIGHT);
	Console::CursorVisible = false;
	srand(time(NULL));
	ejercicio2_10A();
	system("pause>0");
	return 0;
}