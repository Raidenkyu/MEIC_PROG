#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include "FHeader.h"

using namespace std;


int area(double x1, double y1, double x2, double y2, double x3, double y3)
{
	double a, b, c, s;
	a = sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
	b = sqrt(pow((x2 - x3), 2) + pow((y2 - y3), 2));
	c = sqrt(pow((x1 - x3), 2) + pow((y1 - y3), 2));
	s = (a + b + c) / 2;
	cout << "Area do triangulo = " << sqrt(s * (s - a) * (s - b) * (s - c)) << endl << endl;
	return 0;
}

int distance(double x1, double y1, double x2, double y2)
{
	double d;
	d = sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
	cout << "Distancia entre os pontos indicados: " << d << endl;
	return 0;
}

int ex3dot1()
{
	system("CLS");
	int ex;
	double x1, x2, x3, y1, y2, y3;
	cout << "Alinea 1" << endl << "Este programa pode: " << endl;
	cout << "1 - Calcular a area de um triangulo, apartir das coordenadas dos seus vertices" << endl;
	cout << "2 - Calcular a distancia entre dois pontos, cujas coordenadas são conhecidas" << endl;
	cout << "Escolha a sua opcao: ";
	cin >> ex;
	switch (ex)
	{
	case 1:
		cout << "Para calcular a area de um triangulo tem de se conhecer os pontos dos seus 3 vertices." << endl;
		cout << "introduza, respectivamente, as coordenadas x e y do primeiro ponto: ";
		cin >> x1 >> y1;
		cout << "introduza, respectivamente, as coordenadas x e y do segundo ponto: ";
		cin >> x2 >> y2;
		cout << "introduza, respectivamente, as coordenadas x e y do terceiro ponto: ";
		cin >> x3 >> y3;
		area(x1, y1, x2, y2, x3, y3);
		break;
	case 2:
		cout << "Para calcular a distancia entre dois pontos, tem de se conhecer as suas repectivas coordenadas." << endl;
		cout << "introduza, respectivamente, as coordenadas x e y do primeiro ponto: ";
		cin >> x1 >> y1;
		cout << "introduza, respectivamente, as coordenadas x e y do segundo ponto: ";
		cin >> x2 >> y2;
		distance(x1, y1, x2, y2);
		break;
	default: 
		cout << "Funvao inexistente" << endl;
	}
	cin.get();
	cin.get();
	system("CLS");
	return 0;
}


int IsPrime(int num)
{
	bool primo = true;
	for (int i = 2; i < num; i++)
	{
		if (num % i == 0)
		{
			primo = false;
			break;
		}
	}
	return primo;
}

int ex3dot2()
{
	system("CLS");
	int num;
	cout << "Alinea 2" << endl << "Introzua um numero para saber se e primo: ";
	cin >> num;
	if (IsPrime(num))
		cout << "O numero introduzido e primo" << endl;
	else cout << "O numero introduzido nao e primo" << endl;
	cin.get();
	cin.get();
	system("CLS");
	return 0;
}

int solucao(int num, double rqn)
{
	bool sol;
	if ((float)rqn == (float)sqrt(num))
		sol = true;
	else sol = false;

	return sol;
}

int raizq(double delta, double nMaxIter)
{
	double rq, rqn, rqn2, dif, tmp;
	int num, digits;
	tmp = delta;
	bool sol;
	digits = 0;
	cout << "Raiz quadrada de : ";
	cin >> num;
	rq = 1;
	rqn = (rq + num / rq) / 2;
	rqn2 = pow(rqn, 2);
	dif = num - rqn2;
	cout << "rq\trqn\trqn^2\tdif" << endl;
	for (int i = 0; i <= nMaxIter && abs(dif) >= delta; i++)
	{
		cout << rq << '\t' << rqn << '\t' << rqn2 << '\t' << dif << endl;
		rq = rqn;
		rqn = (rq + num / rq) / 2;
		rqn2 = pow(rqn, 2);
		dif = num - rqn2;
	}
	while (tmp < 1)
	{
		digits += 1;
		tmp *= 10;
	}
	cout.precision(digits);
	cout << fixed;
	cout << endl << endl << "Valor da raiz quadrada de " << num << " pelo algoritmo de Heron: " << rqn << endl;
	sol = solucao(num, rqn);
	if (sol)
		cout << "O valor esta correto" << endl;
	else cout << "O valor esta incorreto, porque o numero de iteracoes foi insuficiente" << endl;
	return rqn;
}

int ex3dot3()
{
	system("CLS");
	double delta, nMaxIter, rqn;
	int num, digits;
	digits = 0;
	cout << "Alinea 3" << endl << "Este exercicio permite calcular a raiaz quadrada" << endl << endl;
	cout << "Indique uma valor muito pequeno para limitar o numero de iteracoes: ";
	cin >> delta;
	cout << "Indique o numero maximo de iteracoes: ";
	cin >> nMaxIter;
	raizq(delta, nMaxIter);
	cin.get();
	cin.get();
	system("CLS");
	return 0;
}

double round(double x, unsigned n)
{
	double y = floor(x*pow(10, n) + 0.5) / pow(10, n);
	return y;
}

int ex3dot4()
{
	system("CLS");
	double x, y;
	int n;
	cout << "Alinea 4" << endl << endl << "Função arredondamento" << endl << "Introduza um numero para arredondar: ";
	cin >> x;
	cout << "Introduza com quantas casas decimais quer arredondar: ";
	cin >> n;
	y = round(x, n);
	cout << "Valor arredondado de " << x << " com " << n << " casas decimais: " << y << endl;
	cin.get();
	cin.get();
	system("CLS");
	return 0;
}

bool readFracc(int &numerator, int &denominator)
{
	char op;
	cout << "Introduza um valor fraccionario, representado por um numerador, um traco e um denominador: ";
	cin >> numerator >> op >> denominator;
	if (cin.fail())
	{
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		return false;
	}
	if (op != '/') {
	return false;

}
	return true;
}

int gcd(unsigned a, unsigned b)
{
	if (a < b)
	{
		a += b;
		b = a - b;
		a -= b;
	}

	if (b == 0) return a;

	while (a % b != 0)
	{
		a += b;
		b = a - b;
		a -= b;
		b %= a;
	}
	return b;
}

void reduceFracc(int &numerator, int &denominator)
{
	numerator /= gcd(numerator, denominator);
	denominator /= gcd(numerator, denominator);
}

void writeFracc(int numerator, int denominator)
{
	cout << "Fracao: " << numerator << '/' << denominator << endl;
}

int ex3dot5()
{
	system("CLS");
	int num1, den1, num2, den2;
	char op;
	cout << "Alinea 5" << endl << endl << "Este programa permite calcular com fraccoes" << endl;
	cout << endl << "Indique o sinal da operacao: ";
	cin >> op;
	bool frac = readFracc(num1, den1); 
	if (!frac)
	{
		cout << "Nao foi introduzida uma fracao. Input invalido" << endl;
		cout << "O prgrama vai encerrar" << endl;
		cin.get();
		cin.get();
		system("CLS");
		return 0;
	}
	else
	{
		cout << "Primeira fracao: ";
		reduceFracc(num1, den1);
		writeFracc(num1, den1);
	}
	cout << endl;
	frac = readFracc(num2, den2);
	if (!frac)
	{
		cout << "Nao foi introduzida uma fracao. Input invalido" << endl;
		cout << "O programa vai encerrar" << endl;
		cin.get();
		cin.get();
		system("CLS");
		return 0;
	}
	else
	{
		cout << "Segunda Fracao: ";
		reduceFracc(num2, den2);
		writeFracc(num2, den2);
	}
	cout << endl << "Resultado: ";
	int num, den;
	switch (op)
	{
	case '+':
		num = (num1 * den2) + ( num2 * den1);
		den = den1 * den2;
		break;
	case '-':
		num = num1 * den2 - num2*den1;
		den = den1*den2;
	case '*':
		num = num1 *  num2;
		den = den1 * den2;
		break;
	case '/':
		num = num1 * den2;
		den = den1 * num2;
		break;
	default:
		cout << "Sinal invalido. O programa vai terminar." << endl;
		return 0;
	}
	reduceFracc(num, den);
	writeFracc(num, den);
	cin.get();
	cin.get();
	system("CLS");
	return 0;
}


bool bissexto(int ano)
{
	if (ano % 4 == 0 && ano % 100 != 0 || ano % 400 == 0)
		return true;
	else return false;
}

int diasDoMes(int mes, int ano)
{
	int dias;
	bool tipo = bissexto(ano);
	switch (mes)
	{
	case 1:
		dias = 31;
		break;
	case 2:
		if (tipo)
			dias = 29;
		else dias = 28;
		break;
	case 3:
		dias = 31;
		break;
	case 4:
		dias = 30;
		break;
	case 5:
		dias = 31;
		break;
	case 6:
		dias = 30;
		break;
	case 7:
		dias = 31;
		break;
	case 8:
		dias = 31;
		break;
	case 9:
		dias = 30;
		break;
	case 10:
		dias = 31;
		break;
	case 11:
		dias = 30;
		break;
	case 12:
		dias = 31;
		break;
	default: cout << "Mes invalido" << endl;
	}
	return dias;
}


int ex3dot6()
{
	system("CLS");
	int ano;
	int mes;
	cout << "Alinea 6" << endl << endl << "Indique o ano: ";
	cin >> ano;
	cout << "Indique o mes(valor numerico): ";
	cin >> mes;
	int dias = diasDoMes(mes, ano);
	cout << "O mes numero " << mes << " do ano de " << ano;
	bool tipo = bissexto(ano);
	if (tipo)
		cout << " e bissexto";
	else cout << " nao e bissexto";
	cout << " e tem " << dias << " dias" << endl;
	cin.get();
	cin.get();
	system("CLS");
	return 0;
}

int menu3()
{
	cout << "Escolha uma das segintes alineas" << endl;
	cout << "1 - Exercicio 1" << endl << "2 - Exercicio 2" << endl << "3 - Exercicio 3" << endl << "4 - Exercicio 4" << endl << "5 - Exercicio 5" << endl << "6 - Exercicio 6" << endl << "7 - Exercicio 7" << endl << "8 - Exercicio 8" << endl << "9 - Exercicio 9" << endl;
	int ex;
	cout << "Numero do exercicio: ";
	cin >> ex;
	switch (ex) {
	case 1:
		ex3dot1();
		break;
	case 2:
		ex3dot2();
		break;
	case 3:
		ex3dot3();
		break;
	case 4:
		ex3dot4();
		break;
	case 5:
		ex3dot5();
		break;
	case 6:
		ex3dot6();
		break;
	default:
		cout << "Alinea Invalida" << endl << endl;
	}
	return 0;
}