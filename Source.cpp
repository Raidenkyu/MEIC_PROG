/* File   : Exercicios de Prog
   Date   : 2017/02/17
   Author : JCM
   Program Purpose:
   - Resolucao de exercicios propostos em aula*/


#include <cmath>
#include <iostream>
#include "FHeader.h"
#include <windows.h>

using namespace std;

int ex1dot1()
{
	cout << "Alínea 1" << endl;
	cout << "Introduza um caracter para saber o seu codigo ASCII" << endl;
	char a;
	cin >> a;
	cout << (int)a << endl << endl;
	return 0;
}

int ex1dot2()
{
	float a, b, c;
	float m;
	cout << "Alínea 2" << endl;
	cout << "A?";
	cin >> a;
	cout << "B?";
	cin >> b;
	cout << "C?";
	cin >> c;
	m = (float)(a + b + c) / 3;
	cout << "media = " << m << endl;
	cout << "A-media = " << a - m << endl;
	cout << "B-media = " << b - m << endl;
	cout << "C-media = " << c - m << endl << endl;
	return 0;
}

int ex1dot3()
{
	cout << "Alinea 3" << endl;
	float m, p, r;
	float PI = 3.14;
	cout << "Densidade da esfera(Kg/m^3) = ";
	cin >> p;
	cout << "raio da esfera(m) = ";
	cin >> r;
	m = 4 / 3 * (p*r*PI);
	cout << "Massa da esfera(Kg) = " << m << endl << endl;
	return 0;
}

int ex1dot4()
{
	cout << "Alinea 4" << endl;
	float a, b, c, d, e, f;
	cout << "Para resolver o sistema de equções: a*x + b*y = c, d*x + e*y = f; introduza, respectivamente, os valores para a, b, c, d, e" << endl;
	cin >> a >> b >> c >> d >> e >> f;
	if (a*e - b*d == 0)
		cout << "A solucao do problema é impossível." << endl;
	else cout << "x = " << (c * e - b * f) / (a * e - b * d) << endl << "y = " << (a * f - c * d) / (a * e - b * d) << endl << endl;
	return 0;
}

int ex1dot5()
{
	cout << "Alinea 5" << endl;
	int d, h, m, s, d2, h2, m2, s2;
	d = 00;
	d2 = 00;
	cout << "Tempo 1 (horas minutos segundos) ?";
	cin >> h >> m >> s;
	cout << "Tempo 2 (horas minutos segundos) ?";
	cin >> h2 >> m2 >> s2;
	s += s2;
	m += m2 + (s / 60);
	h += h2 + (m / 60);
	d += d2 + (h / 24);
	s = s % 60;
	m = m % 60;
	h = h % 24;
	cout << "Soma dos tempos : ";
	cout << d;
	if (d > 1 || d == 0)
		cout << " dias, ";
	else cout << " dia, ";
	cout << h;
	if (h > 1 || h == 0)
		cout << " horas, ";
	else cout << " hora, ";
	cout << m;
	if (m > 1 || m == 0)
		cout << " minutos e ";
	else cout << " minuto e ";
	cout << s;
	if (s > 1 || s == 0)
		cout << " segundos";
	else cout << " segundo";
	cout << endl;
	return 0;
}

int ex1dot6() {
	cout << "Alinea 6" << endl;
	float x1, x2, x3, y1, y2, y3, s, a, b, c;
	cout << "Para calcular a área de um triangulo tem de se conhecer os pontos dos seus 3 vertices." << endl;
	cout << "introduza, respectivamente, as coordenadas x e y do primeiro ponto: ";
	cin >> x1 >> y1;
	cout << "introduza, respectivamente, as coordenadas x e y do segundo ponto: ";
	cin >> x2 >> y2;
	cout << "introduza, respectivamente, as coordenadas x e y do terceiro ponto: ";
	cin >> x3 >> y3;
	a = sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
	b = sqrt(pow((x2 - x3), 2) + pow((y2 - y3), 2));
	c = sqrt(pow((x1 - x3), 2) + pow((y1 - y3), 2));
	s = (a + b + c) / 2;
	cout << "Area do triangulo = " << sqrt(s * (s - a) * (s - b) * (s - c)) << endl << endl;
	return 0;
}

int menu1()
{
	int ex;
	cout << "Escolha qual alinea pretende testar" << endl;
	cout << "Exercicio 1" << endl << "Exercicio 2" << endl << "Exercicio 3" << endl << "Exercicio 4" << endl << "Exercicio 5" << endl << "Exercicio 6" << endl;
	cout << "Numero do exercicio: ";
	cin >> ex;
	cout << endl;
	switch (ex) {
	case 1 :
		ex1dot1();
		break;
	case 2:
		ex1dot2();
		break;
	case 3:
		ex1dot3();
		break;
	case 4:
		ex1dot4();
		break;
	case 5:
		ex1dot5();
		break;
	case 6:
		ex1dot6();
		break;
	default:
		cout << "Alinea Invalida" << endl;
	}
	return 0;
}

int main() {
	SetConsoleCP(1252);
	SetConsoleOutputCP(1252);
	while (!cin.eof()) {
		int ex;
		cout << "Escolha um exercicio da lista" << endl << "1 - Exercicio 1" << endl << "2 - Exercicio 2" << endl << "3 - Exercicio 3" << endl << "4 - Exercicio 4" << endl;
		cout << "Numero do exercicio: ";
		cin >> ex;
		switch (ex) {
		case 1:
			menu1();
			break;
		case 2:
			menu2();
			break;
		case 3:
			menu3();
			break;
		case 4:
			menu4();
			break;
		default:
			cout << "Exercicio Invalido" << endl;
		}
	} 
	system("CLS");
	cout << "O programa vai encerrar" << endl;
	cin.get();
	return 0;
}