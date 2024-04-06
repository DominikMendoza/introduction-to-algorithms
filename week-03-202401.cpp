#include <iostream>
using namespace std;

int calcularMayorDe3(int num1, int num2, int num3)
{
	int mayor = 0;
	mayor = (num1 >= num2 && num1 >= num3) * num1 +
		(num2 >= num1 && num2 >= num3) * num2 +
		(num3 >= num1 && num3 >= num2) * num3;
	return mayor;
}

float calcularCubo(float numero)
{
	return numero * numero * numero;
	//return pow(numero, 3);
}

float convertirKilometrosAMetros(float distancia)
{
	return distancia * 1000;
}

int calcularMenor(int num1, int num2)
{
	int menor = 0;
	menor = (num1 < num2 && num2 != num1) * num1 + (num2 <= num1) * num2;
	return menor;
}


int calcularResultado(int AQI, int pm2)
{
	int resultado = 0;
	resultado += (AQI >= 0 && AQI <= 50 && pm2 >= 0 && pm2 <= 12.0) * 1;
	resultado += (AQI >= 51 && AQI <= 100 && pm2 >= 12.1 && pm2 <= 35.4) * 2;
	resultado += (AQI >= 101 && AQI <= 150 && pm2 >= 35.5 && pm2 <= 55.4) * 3;
	// completar casos
	return resultado;
}
void ejercicio11()
{
	int AQI;
	float pm2;
	// Generacion de valores
	// rand() % (mayorV - menorV + 1) + menorV
	AQI = rand() % (500);
	pm2 = (rand() % (2700)) / 10.0;

	// Ingreso de datos
	cout << "Ingrese el indice de calidad del aire (AQI): ";
	cin >> AQI;

	cout << "Ingrese el PM2.5: ";
	cin >> pm2;

	int resultado;
	resultado = calcularResultado(AQI, pm2);
	
	// completar el resto de casos

	cout << (
		(resultado == 1) ? "Air quality is sa..." : 
		(resultado == 2) ? "Sensitive indivudual....":
		(resultado == 3) ? "General public...." : "No cumple"
		);

	
}

float calcularPrecioBicicleta(char marca, char categoria)
{
	float precio = 0.0;
	precio += (marca == 'B' && categoria == 'P') * 1300;
	precio += (marca == 'B' && categoria == 'M') * 1000;
	precio += (marca == 'M' && categoria == 'P') * 1350;
	precio += (marca == 'M' && categoria == 'M') * 2500;
	precio += (marca == 'O' && categoria == 'P') * 900;
	precio += (marca == 'O' && categoria == 'M') * 3200;
	return precio;
}
void ejercicio13()
{
	char marca, categoria;
	cout << "Ingrese marca: ";
	cin >> marca;

	cout << "Ingrese categoria: ";
	cin >> categoria;

	cout << "El monto a pagar es: ";
	cout << calcularPrecioBicicleta(marca, categoria) << endl;
}
int main()
{
	srand(time(nullptr));
	ejercicio13();
	system("pause>0");
	return 0;
}