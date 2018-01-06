#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include "FHeader.h"
#include <cstdlib>
#include <ctime>

using namespace std;

int ex2dot1()
{
	ex1dot4();
	return 0;
}


int ex2dot2()
{
	cout << "Alínea 2" << endl;
	int num[3], temp;
	cout << "introduza 3 numeros" << endl;
	cin >> num[0] >> num[1] >> num[2];
	for (int i = 0; i <= 1; i++)
	{
		for (int j = i + 1; j <= 2; j++)
		{
			if (num[i] > num[j])
			{
				temp = num[i];
				num[i] = num[j];
				num[j] = temp;
			}
		}
	}
	cout << "Numero maior = " << num[2] << endl;
	cout << "Numero menor = " << num[0] << endl;
	cout << "Ordenados por ordem decrescente: " << num[0] << ", " << num[1] << ", " << num[2] << endl;
	if (num[0] + num[1] < num[2])
		cout << "Os valores introduzidos permitem formar um triangulo" << endl << endl;
	else cout << "Os valores introduzidos não permitem formar um triangulo" << endl << endl;
	return 0;


}

int ex2dot3()
{
	cout << "Alinea 3" << endl;
	int a, b;
	char c;
	cout << "Digite o primeiro operando: ";
	cin >> a;
	cout << "Digite o segundo operando: ";
	cin >> b;
	cout << "Indique o sinal da operacao(+, -, *, /): ";
	cin >> c;
	switch (c) {
	case '+': 
		cout << a << ' ' << c << ' ' << b << ' ' << "= " << a + b << endl << endl;
		break;
	case '-':
		cout << a << ' ' << c << ' ' << b << ' ' << "= " << a - b << endl << endl;
		break;
	case '*':
		cout << a << ' ' << c << ' ' << b << ' ' << "= " << a * b << endl << endl;
		break;
	case '/':
		cout << a << ' ' << c << ' ' << b << ' ' << "= " << a / b << endl << endl;
		break;
	default:
		cout << "Sinal de operacao invalido" << endl << endl;
    }
	return 0;
}

int ex2dot4()
{
	float c;
	int m;
	cout << "Peso da mercadoria(g) =  ";
	cin >> m;
	int m2 = m;
	if (m < 500)
		c = 5;
	else if (m > 1000) {
		c = 12.5 + (5 * ((m - 1000) / 250));
		m -= (m % 250);
		c += (m * 5);

	}
	else {
		c = 5 + 1.5* ((m - 500) / 100);
		m -= (m % 100);
		c += (m * 1.5);
	}
	cout << "O custo do transporte de uma mercadoria de peso " << m2 << " sera de " << c << endl << endl;
	return 0;
}

int ex2dot5()
{
	float a, b, c;
	cout << "Alinea 5" << endl << "Introduza, respectivamente os coeficientes a, b, c, para resolver a equacao do tipo: a*x^2 + b*x + c = 0 " << endl;
	cout << "Introduza os coeficientes (a b c): ";
	cin >> a >> b >> c;
	cout.precision(3);
	cout << fixed;
	if (pow(b, 2) - 4 * a * c == 0)
		cout << "A equacao tem uma raiz: " << (-b) / (2 * a) << endl << endl;
	else if (pow(b, 2) - 4 * a * c > 0) {
		float r1 = (- b + sqrt(pow(b, 2) - 4 * a * c)) / (2 * a);
		float r2 = (-b - sqrt(pow(b, 2) - 4 * a * c)) / (2 * a);
		cout << "A equacao tem 2 raizes inteiras: " << r1 << " e " << r2 << endl << endl;
	}
	else if (pow(b, 2) - 4 * a * c < 0) {
		float r1 = (-b) / (2 * a);
		float d1 = sqrt(-(pow(b, 2) - 4 * a * c)) / (2 * a);
		cout << "A equacao tem 2 raizes complexas conjugadas: " << r1 << '+' << d1 << 'i' << " e " << r1 << '-' << d1 << 'i' << endl << endl;
	}

	return 0;
}

int ex2dot6()
{
	int num;
	bool primo = true;
	cout << "Digite um numero" << endl;
	cin >> num;
	while (cin.fail())
	{
		cout << "Input Invalido" << endl << "Introduza um numero inteiro" << endl;
		cin.clear();
		cin.ignore(10000, '\n');
		cin >> num;
	}
	for (int i = 2; i < num; i++)
	{
		if ( num % i == 0)
		{
			primo = false;
			break;
		}
	}
	if (primo)
		cout << "O numero " << num << " e primo" << endl;
	else 
		cout << "O numero " << num << " nao e primo" << endl;
	return 0;
}

int ex2dot7()
{
	system("CLS");
	float min, max, inc;
	cout << "ang     sen       cos       tan " << endl;
	cout << "  0  0.000000  1.000000  0.000000 " << endl;
	cout << " 15  0.258819  0.965926  0.267949 " << endl;
	cout << " 30  0.500000  0.866025  0.577350 " << endl;
	cout << " 45  0.707107  0.707107  1.000000 " << endl;
	cout << " 60  0.866025  0.500000  1.732051 " << endl;
	cout << " 75  0.965926  0.258819  3.732051 " << endl;
	cout << " 90  1.000000  0.000000  infinito " << endl;
	cin.get();
	cout << endl << "Introduza um intervalo de angulos e um incremento para construir uma nova tabela" << endl;
	cout << "Valor minimo: ";
	cin >> min;
	cout << "Valor maximo: ";
	cin >> max;
	cout << "Valor de incremento: ";
	cin >> inc;
	cout << endl << endl;
	cout << "ang         sen         cos       tan " << endl;
	cout.precision(6);
	for (float i = min; i <= max + inc; i += inc)
	{
		cout << " " << i;
		cout << fixed;
		cout << "  " << sin(i*M_PI/180) << "  " << cos(i*M_PI/180) << "  " << tan(i*M_PI/180) << "  " << endl;
		cout << defaultfloat;
	}
	cin.get();
	cin.get();
	system("CLS");
	return 0;
}

int ex2dot8()
{
	system("CLS");
	int n;
	float quantia, j;
	cout << "Quantia depositada: ";
	cin >> quantia;
	cout << "Durante quantos anos pretende amontoar dinheiro: ";
	cin >> n;
	cout << "Taxa de juro(%): ";
	cin >> j;
	for (int i = 0; i < n; i++)
	{
		quantia += quantia * (1 + (j /100));
	}
	cout << "Valor amontoado ao fim de " << n << " anos: " << quantia << endl;
	cin.get();
	cin.get();
	system("CLS");
	return 0;
}

int ex2dot9a()
{
	system("CLS");
	cout << "Introduza uma sequencia de numeros" << endl;
	int temp, n;
	float med = 0;
	int seq[1000];
	for (int i = 0; i < 1000; i++)
	{
		cout << i + 1 << " Elemento da sequencia: ";
		cin >> seq[i];
		n = i;
		if (seq[i] == 0)
			break;
	}
	for (int i = 0; i <= (n - 2); i++)
	{
		for (int j = i + 1; j <= (n - 1); j++)
		{
			if (seq[i] > seq[j])
			{
				temp = seq[i];
				seq[i] = seq[j];
				seq[j] = temp;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		med += seq[i];
	}
	med = med / n;
	cout << "Valor máximo da sequencia introduzida: " << seq[n - 1] << endl;
	cout << "Valor medio da sequencia: " << med << endl;
	cout << "Numero de elementos: " << n << endl;
	cin.get();
	cin.get();
	system("CLS");
	return 0;
}

int ex2dot9b()
{
	system("CLS");
	cout << "Introduza uma sequencia de numeros" << endl;
	cout << "Introduza a quantidade de elementos da sequencia: ";
	int temp, n;
	cin >> n;
	float med = 0;
	int seq[1000];
	for (int i = 0; i < n; i++)
	{
		cout << i + 1 << " Elemento da sequencia: ";
		cin >> seq[i];
		med += seq[i];
	}
	for (int i = 0; i <= (n - 2); i++)
	{
		for (int j = i + 1; j <= (n - 1); j++)
		{
			if (seq[i] > seq[j])
			{
				temp = seq[i];
				seq[i] = seq[j];
				seq[j] = temp;
			}
		}
	}
	med = med / n;
	cout << "Valor máximo da sequencia introduzida: " << seq[n - 1] << endl;
	cout << "Valor medio da sequencia: " << med << endl;
	cin.get();
	cin.get();
	system("CLS");
	return 0;
}

int ex2dot9c()
{
	system("CLS");
	int d;
	cout << "Introduza uma sequencia de numeros" << endl;
	int temp, n;
	float med = 0;
	int seq[1000];
	for (int i = 0; i < 1000; i++)
	{
		cout << i + 1 << " Elemento da sequencia: ";
		cin >> d;
		n = i;
		if (cin.good())
		{
			seq[i] = d;
		}
		else {
			cin.clear();
			cin.ignore(10000, '\n');
			break;
		}
		
	}
	for (int i = 0; i < (n - 1); i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (seq[i] > seq[j])
			{
				temp = seq[i];
				seq[i] = seq[j];
				seq[j] = temp;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		med += seq[i];
	}
	med = med / n;
	cout << "Valor maximo da sequencia introduzida: " << seq[n - 1] << endl;
	cout << "Valor medio da sequencia: " << med << endl;
	cout << "Numero de elementos: " << n << endl;
	cin.get();
	system("CLS");
	return 0;
}

int ex2dot9()
{
	system("CLS");
	cout << "Escolha o tipo de sequencia(a/b/c)" << endl;
	cout << "a) Sequencia com numero de elementos variavel que termine em 0 " << endl << "b) Sequencia com numero de elementos definido" << endl << "c) Sequencia com numeros variavel que termina só com end of input" << endl;
	char ex;
	cout << "Numero do exercicio: ";
	cin >> ex;
	switch (ex) {
	case 'a':
		ex2dot9a();
		break;
	case 'b':
		ex2dot9b();
		break;
	case 'c':
		ex2dot9c();
		break;
	default:
		cout << "Opcao Invalida" << endl << endl;
	}
	return 0;
}

int ex2dot10()
{
	system("CLS");
	int num, tmp, count;
	bool cap = true;
	cout << "Alinea 10" << endl << endl << "Introduza um numero para verificar se e capicua: ";
	cin >> num;
	tmp = num;
	count = 0;
	while (tmp > 0)
	{
		count += 1;
		tmp /= 10;
	}
	for (int i = 0; i <= (count / 2); i++)
	{
		if (( (int) (num / pow(10, i)) % 10) != ( (int) (num / pow(10, (count - 1 - i))) % 10))
		{
			cap = false;
			break;
		}
	}
	if (cap)
		cout << "O numero " << num << " e capicua" << endl;
	else cout << "O numero " << num << " nao e capicua" << endl;
	cin.get();
	cin.get();
	system("CLS");
	return 0;
}

int ex2dot11a()
{
	system("CLS");
	int n;
	cout << "Alinea 11" << endl << endl << "Com este programa pode calcular a serie do pi com n termos. Indique quantos termos da sequencia quer: ";
	cin >> n;
	cout << "Serie de pi de " << n << " termos:";
	for (int i = 0; i < n; i++)
	{
		if (i % 2 != 0)
			cout << " - ";
		else cout << " + ";
		cout << "4/" << i * 2 + 1 ;
	}
	cout << endl;
	cin.get();
	cin.get();
	system("CLS");
	return 0;
}

int ex2dot11b()
{
	system("CLS");
	int n;
	cout << "Alinea 11" << endl << endl << "Com este programa pode calcular a serie da constante 'e' com n termos. Indique quantos termos da sequencia quer: ";
	cin >> n;
	cout << "Serie da constante 'e' de " << n << " termos:";
	for (int i = 0; i < n; i++)
	{
		cout << " + ";
		cout << "1/" << i + 1 << "!";
	}
	cout << endl;
	cin.get();
	cin.get();
	system("CLS");
	return 0;
}

int ex2dot11c()
{
	system("CLS");
	int x, n;
	cout << "Alinea c)" << endl << endl << "Com este programa pode calcular a serie da constante 'e' com n termos. Indique quantos termos da sequencia quer: ";
	cin >> n;
	cout << "Indique um valor para x: ";
	cin >> x;
	cout << "Serie da constante 'e' de " << n << " termos:";
	for (int i = 0; i < n; i++)
	{
		if (i % 2 != 0)
			cout << " - ";
		else cout << " + ";
		cout << pow(x,i) << "/" << i + 1 << "!";
	}
	cout << endl;
	cin.get();
	cin.get();
	system("CLS");
	return 0;
}

int ex2dot11()
{
	char al;
	cout << "Alinea 11" << endl << endl << "Escolha a alinea (a/b/c)." << endl << "a) Serie do pi" << endl << "b) Serie do 'e'" << endl << "c) Serie da funcao e^-x" << endl << "alinea: ";
	cin >> al;
	switch (al)
	{
	case 'a':
		ex2dot11a();
		break;
	case 'b':
		ex2dot11b();
		break;
	case 'c':
		ex2dot11c();
		break;
	default:
		cout << "alinea invalida" << endl;
		break;

	}
	return 0;

}

int ex2dot12a()
{
	system("CLS");
	double vmax;
	cout << "Alinea a)" << endl << endl << "Com este programa pode calcular a serie do pi com n termos. Indique o valor do erro maximo: ";
	cin >> vmax;
	cout << "Serie de pi ate erro de " << vmax << ":";
	double vatual;
	double vanterior = 0.0;
	for (int i = 0; abs(vanterior - vatual) > vmax; i++)
	{
		if (i % 2 != 0)
			cout << " - ";
		else cout << " + ";
		cout << "4/" << i * 2 + 1;
		vanterior = vatual;
		vatual = 4.0 / (i * 2 + 1);
	}
	cout << endl;
	cin.get();
	cin.get();
	system("CLS");
	return 0;
}

int ex2dot12b()
{
	system("CLS");
	double vmax;
	cout << "Alinea b)" << endl << endl << "Com este programa pode calcular a serie da constante 'e' com n termos.Indique o valor do erro maximo: ";
	cin >> vmax;
	cout << "Serie da constante 'e' ate erro de " << vmax << ":";
	double vatual;
	double vanterior = 0.0;
	for (int i = 0; abs(vanterior - vatual) > vmax; i++)
	{
		cout << " + ";
		cout << "1/" << i + 1 << "!";
		vanterior = vatual;
		vatual *= 1.0 / (i + 1);
	}
	cout << endl;
	cin.get();
	cin.get();
	system("CLS");
	return 0;
}


int fatorial(int num)
{
	int factorial = 1;
	for (int a = 1; a <= num; a++)
	{
		factorial = factorial*a;
	}
	return factorial;
}

int ex2dot12c()
{
	system("CLS");
	int x;
	double vmax, vatual, vanterior;
	cout << "Alinea 11" << endl << endl << "Com este programa pode calcular a serie x^i com n termos.Indique o valor do erro maximo: ";
	cin >> vmax;
	vanterior = 0.0;
	cout << "Indique o valor de 'x': ";
	cin >> x;
	cout << "Serie x^i com erro de " << vmax << " :";
	for (int i = 0; abs(vanterior - vatual) > vmax; i++)
	{
		if (i % 2 != 0)
			cout << " - ";
		else cout << " + ";
		cout << pow(x, i) << "/" << i + 1 << "!";
		vanterior = vatual;
		vatual = (pow(x, i) / fatorial(i + 1));
	}
	cout << endl;
	cin.get();
	cin.get();
	system("CLS");
	return 0;
}

int ex2dot12()
{
	char al;
	cout << "Alinea 11" << endl << endl << "Escolha a alinea (a/b/c)." << endl << "a) Serie do pi" << endl << "b) Serie do 'e'" << endl << "c) Serie da funcao e^-x" << endl << "alinea: ";
	cin >> al;
	switch (al)
	{
	case 'a':
		ex2dot12a();
		break;
	case 'b':
		ex2dot12b();
		break;
	case 'c':
		ex2dot12c();
		break;
	default:
		cout << "alinea invalida" << endl;
		break;

	}
	return 0;

}

int ex2dot13()
{
	system("CLS");
	int num;
	int fator;
	bool primo = true;
	cout << "Alinea 13" << endl << "Indique um numero para saber a sua decomposicao em fatores primos: ";
	cin >> num;
	fator = 2;
	cout << num << " = ";
	while(num >= fator)
	{
		for (int i = 2; i < fator; i++)
		{
			if (fator % i == 0)
			{
				primo = false;
				break;
			}
		}
		if (primo && num == fator)
		{
			cout << fator << endl;
			break;
		}
		else if (primo && num != fator && num % fator == 0)
		{
			cout << fator << " x ";
			num /= fator;
		}
		else fator++;
		primo = true;
	}
	cin.get();
	cin.get();
	system("CLS");
	return 0;
}

int ex2dot14()
{
	system("CLS");
	int num, digits;
	digits = 0;
	double delta, nMaxIter, rq, rqn,rqn2, dif, tmp;
	cout << "Alinea 13" << endl << "Raiz quadrada de : ";
	cin >> num;
	cout << "Indique uma valor muito pequeno para limitar o numero de iteracoes: ";
	cin >> delta;
	tmp = delta;
	cout << "Indique o numero maximo de iteracoes: ";
	cin >> nMaxIter;
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
	while(tmp < 1)
	{
		digits += 1; 
		tmp *= 10;
	}
	cout.precision(digits);
	cout << fixed;
	cout << endl << endl << "Valor da raiz quadrada de " << num << " pelo algoritmo de Heron: " << rqn << endl;
	cout << "Valor da raiz quadrada calculada pelo computador: " << sqrt(num) << endl;
	if ((float) rqn == (float) sqrt(num))
		cout << "O valor calculado pelo algoritmo esta correcto" << endl;
	else cout << "O valor calculado pelo algoritmo esta incorreto. Serao necessarias mais iteracoes" << endl;
	cin.get();
	cin.get();
	system("CLS");
	return 0;
}

int ex2dot15()
{
	system("CLS");
	srand(time(NULL));
	int p1, p2, s, r;
	double ti, tf, delta;
	cout << "Alinea 15" << endl << endl;
	cout << "Este programa ira testar os seus conhecimentos da tabuada. Assim que pressionar Enter, tera de responder com um resultado certo, no menor tempo possivel." << endl;
	cout << "A sua avaliacao sera feita em funcao do seu tempo de resposta." << endl << "(Pressiona enter para comecar)" << endl;
	cin.get();
	cin.get();
	p1 = rand() % 8 + 2;
	p2 = rand() % 8 + 2;
	cout << p1 << " x " << p2 << " = ";
	ti = time(NULL);
	cin >> r;
	tf = time(NULL);
	cout << endl << "Nota: ";
	s = p1 * p2;
	delta = tf - ti;
	if (s == r && delta < 5)
		cout << "Muito bom" << endl << "Parabens. Conseguiu acertar a resposta em menos de " << delta << " segundos." << endl;
	else if (s == r && delta >= 5 && delta <= 10)
		cout << "Bom" << endl << "Conseguiu acertar a resposta em " << delta << " segundos. Sera que consegue ser mais rapido?" << endl;
	else if (s == r && delta > 10)
		cout << "Insuficiente" << endl << "Conseguiu acertar a resposta em " << delta << " segundos. Mas esta muito lento" << endl;
	else cout << "Muito mau" << endl << "A sua resposta estava incorreta. A Resposta certa era " << s << endl;
	cin.get();
	cin.get();
	system("CLS");
	return 0;
}

int menu2()
{
	cout << "Escolha uma das segintes alineas" << endl;
	cout << "1 - Exercicio 1" << endl << "2 - Exercicio 2" << endl << "3 - Exercicio 3" << endl << "4 - Exercicio 4" << endl << "5 - Exercicio 5" << endl << "6 - Exercicio 6" << endl << "7 - Exercicio 7" << endl << "8 - Exercicio 8" << endl << "9 - Exercicio 9" << endl << "10 - Exercicio 10" << endl << "11 - Exercicio 11" << endl << "12 - Exercicio 12" << endl << "13 - Exercicio 13" << endl << "14 - Exercicio 14" << endl << "15 - Exercicio 15" << endl;
    int ex;
	cout << "Numero do exercicio: ";
	cin >> ex;
	switch (ex) {
	case 1:
		ex2dot1();
		break;
	case 2:
		ex2dot2();
		break;
	case 3:
		ex2dot3();
		break;
	case 4:
		ex2dot4();
		break;
	case 5:
		ex2dot5();
		break;
	case 6:
		ex2dot6();
		break;
	case 7:
		ex2dot7();
		break;
	case 8:
		ex2dot8();
		break;
	case 9:
		ex2dot9();
		break;
	case 10:
		ex2dot10();
		break;
	case 11:
		ex2dot11();
		break;
	case 12:
		ex2dot12();
		break;
	case 13:
		ex2dot13();
		break;
	case 14:
		ex2dot14();
		break;
	case 15:
		ex2dot15();
		break;
	default:
		cout << "Alinea Invalida" << endl << endl;
	}
	return 0;
}