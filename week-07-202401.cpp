#include <iostream>
#include <conio.h>
#define WIDTH 60
#define HEIGHT 20
#define UP 72
#define DOWN 80
#define RIGHT 77
#define LEFT 75
using namespace System;
using namespace std;

void dibujarTriangulo(int x, int y, int identificador)
{
	int lado = 4;
	for (int i = 1; i <= lado; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			Console::SetCursorPosition(x + j - 1, y + i - 1);
			if (i == 3 && j == 2) {
				cout << identificador; 
			}
			else {
				cout << "*";
			}
		}
	}
}
void ejercicio5_7b()
{
	int n = 4;
	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x <= y; x++)
		{
			dibujarTriangulo(4 * x, 4 * y, y + 1);
		}
	}
}
void ejercicio4_7a()
{
	const float cosVideoJuegos = 170.50, cosAccVarios = 80.90, cosTarjeVirtualRec = 50.0;
	int nClientes, cantVidejoJuegos, cantAccVarios, cantTarjVirtualRec;
	cout << "Ingrese numero de clientes: ";
	cin >> nClientes;
	/*Videojuegos S/. 170.50
	Accesorios Varios S/. 80.90
	Tarjeta virtual de recarga S/. 50.00*/
	float monto, montoFacturado, descuento;
	int cantTotalVidejoJuegos = 0, cantTotalAccVarios = 0, cantTotalTarjVirtualRec = 0;
	float montoTotalFacturado = 0.0, montoTotalDescontado = 0.0;
	for (int i = 1; i <= nClientes; i++)
	{
		monto = 0.0;
		cout << "Cliente #: " << i << endl;
		cout << "Unidades vendidas de Videojuegos: ";
		cin >> cantVidejoJuegos;
		cout << "Unidades vendidas de Accesorios: ";
		cin >> cantAccVarios;
		cout << "Unidades vendidas de Tarjetas Virtuales: ";
		cin >> cantTarjVirtualRec;
		monto = cantVidejoJuegos * cosVideoJuegos +
			cantAccVarios * cosAccVarios +
			cantTarjVirtualRec * cosTarjeVirtualRec;

		descuento = (
			cantVidejoJuegos != 0 &&
			cantAccVarios != 0 &&
			cantTarjVirtualRec != 0) * 0.2 * monto;

		montoFacturado = monto - descuento;
		cout << "Monto facturado: S/" << montoFacturado << endl;
		cout << "Descuento: S/" << descuento << endl << endl;

		/* Para reporte */
		cantTotalVidejoJuegos += cantVidejoJuegos;
		cantTotalAccVarios += cantAccVarios;
		cantTotalTarjVirtualRec += cantTarjVirtualRec;

		montoTotalFacturado += montoFacturado;
		montoTotalDescontado += descuento;
	}
	cout << "Reporte de Ventas" << endl;
	cout << "-------------------------" << endl;
	cout << "Total unidades de Videojuegos : " << cantTotalVidejoJuegos << endl;
	cout << "Total unidades de Accesorios : " << cantTotalAccVarios << endl;
	cout << "Total unidades de Tarjetas virtuales: " << cantTotalTarjVirtualRec << endl;
	cout << "Monto total facturado: S/." << montoTotalFacturado << endl;
	cout << "Monto total descontado: S/." << montoTotalDescontado << endl;

	int cantArticulosVendidos;
	float mayor = 0.0;
	float montoTotalVideojuegos = cosVideoJuegos * cantTotalVidejoJuegos;
	float montoTotalAccVarios = cosAccVarios * cantTotalAccVarios;
	float montoTotalTarjeVirtualRec = cosTarjeVirtualRec * cantTotalTarjVirtualRec;
	cantArticulosVendidos = cantTotalVidejoJuegos + cantTotalAccVarios + cantTotalTarjVirtualRec;
	if (montoTotalVideojuegos > montoTotalAccVarios && montoTotalVideojuegos > montoTotalTarjeVirtualRec) {
		cout << "VIDEOJUEGOS ";
		mayor = montoTotalVideojuegos;
	}
	if (montoTotalAccVarios > montoTotalVideojuegos && montoTotalAccVarios > montoTotalTarjeVirtualRec) {
		cout << "ACCESORIOS VARIOS ";
		mayor = montoTotalAccVarios;
	}
	if (montoTotalTarjeVirtualRec > montoTotalVideojuegos && montoTotalTarjeVirtualRec > montoTotalAccVarios) {
		cout << "TARJETAS VIRTUALES DE RECARGA ";
		mayor = montoTotalTarjeVirtualRec;
	}
	cout << "fue el producto mas vendido y representa el ";
	cout << mayor * 100.0 / montoTotalFacturado << "%";
	cout << " de monto total facturado";
}
void ejercicio3_7c()
{
	int x, y, dx, dy;
	int xproj, yproj, dxproj;
	bool isProjVisible = false;
	x = 3;
	y = rand() % HEIGHT;
	dx = 0;
	dy = 0;
	dxproj = 5;
	while (true)
	{
		Console::SetCursorPosition(x, y);
		cout << ' ';
		// projectil
		if (isProjVisible) {
			Console::SetCursorPosition(xproj, yproj);
			cout << ' ';
		}
		if (kbhit()) {
			char tecla = getch();
			switch (tecla)
			{
			case UP: dy = -1; dx = 0; break;
			case DOWN: dy = 1; dx = 0; break;
			case LEFT: dx = -1; dy = 0; break;
			case RIGHT: dx = 1; dy = 0; break;
			case 112: isProjVisible = !isProjVisible; xproj = x + 1; yproj = y; break;
			}
		}
		if (x + dx < 0 || x + dx > WIDTH) {
			dx *= -1;
		}
		if (y + dy < 0 || y + dy > HEIGHT - 1) {
			dy *= -1;
		}
		// projectil
		if (isProjVisible) {
			if (xproj + dxproj < 0 || xproj + dxproj > WIDTH) {
				dxproj *= -1;
			}
		}
		x += dx;
		y += dy;
		// projectil
		xproj += dxproj;
		Console::SetCursorPosition(x, y);
		cout << char(254);
		if (isProjVisible) {
			Console::SetCursorPosition(xproj, yproj);
			cout << '*';
		}
		_sleep(100);
	}
}
int main()
{
	srand(time(nullptr));
	Console::SetWindowSize(WIDTH, HEIGHT);
	Console::CursorVisible = false;
	ejercicio3_7c();
	system("pause>0");
	return  0;
}