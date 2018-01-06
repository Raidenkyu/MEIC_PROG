#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include "FHeader.h"
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <locale.h>
#include <Windows.h>

using namespace std;

bool isHydroxidechar(char compound[])
{
	if (compound[strlen(compound) - 1] == 'H' && compound[strlen(compound) - 2] == 'O')
		return true;
	else return false;
}

bool isHydroxide(string compound)
{
	if (compound[compound.length() - 1] == 'H' && compound[compound.length() - 2] == 'O')
		return true;
	else return false;
}

int ex4dot1()
{
	system("CLS");
	string compound;
	cout << "Alinea 1" << endl << endl << "Este programa determina se o componente  introduzida acaba em OH ou nao" << endl;
	cout << "Introduza o componente: ";
	getline(cin, compound);
	cin.ignore(1, '\n');
	cin >> compound;
	if (isHydroxide(compound))
		cout << "A componente introduzida acaba em OH" << endl;
	else cout << "A componente introduzida nao acaba em OH" << endl;
	cin.get();
	cin.get();
	system("CLS");
	return 0;
}

bool sequenceSearch(string s, int nc, char c)
{
	bool existe = false;
	for (int i = 0; i < s.length() && s.length() - i - 1 >  nc; i++)
	{
		for (int j = 0; j < nc; j++)
		{
			if (s[i + j] == c)
				existe = true;
			else
			{
				existe = false;
				break;
			}
		}
	}
	return existe;
}

int ex4dot2()
{
	system("CLS");
	string s;
	int nc;
	char c;
	cout << "Alinea 2" << endl << endl << "Este programa permite verificar se numa string existe um sequencia de caracteres iguais" << endl;
	cout << "Indique a string: ";
	cin >> s;
	cout << "Indique o numero de caracteres da sequencia: ";
	cin >> nc;
	cout << "Indique o caracter: ";
	cin >> c;
	if (sequenceSearch(s, nc, c))
		cout << "A sequencia de " << nc << " caracteres " << "'" << c << "'" << " esta contida em " << s << endl;
	else cout << "A sequencia de " << nc << " caracteres " << "'" << c << "'" << " nao esta contida em " << s << endl;
	cin.get();
	cin.get();	
	system("CLS");
	return 0;
}

void decompose(string compound)
{
	cout << "O composto introduzido tem os seguintes elementos: ";
	for (int i = 0; i < compound.length(); i++)
	{
		if (compound[i] >= 'A' && compound[i] <= 'Z')
			cout << compound[i];
		else if (compound[i] >= 'a' && compound[i] <= 'z')
			cout << compound[i] << ", ";
		else if (compound[i] >= '0' && compound[i] <= '9')
			cout << ", ";
		if (i == (compound.length() - 1))
			cout << "\b\b" << "  " << endl;
	}
}

int ex4dot3()
{
	system("CLS");
	string compound;
	cout << "Alinea 3" << endl << endl;
	cout << "Este programa indica os elementos quimicos que constituem um composto quimico introduzido pelo utilizador" << endl;
	cout << "Introduza um composto: ";
	cin >> compound;
	decompose(compound);
	cin.get();
	cin.get();
	system("CLS");
	return 0;
}

string normalizeName(string name)
{
	int inicio = name.find_first_not_of(' ');
	name = name.substr(inicio);
	int fim = name.find_last_not_of(' ');
	name = name.substr(0, fim + 1);
	string Remove[] = { " DAS ", " DOS ", " DE ", " DO ", " DA ", " E " };
	for (int i = 0; i < name.length(); i++) {
		name[i] = toupper(name[i]);
	}
	for (int i = 0; i < name.length(); i++)
	{
		if (name.substr(i, 2) == "  ")
			name.erase(i, 1);

	}
	for (int i = 0; i < name.length(); i++)
	{
		for (int j = 0; j < (sizeof(Remove)/ sizeof(Remove[0])); j++)
		{
			if (name.substr(i, Remove[j].length()) == Remove[j])
				name.erase(i, Remove[j].length() - 1);
		}
	}
	return name;
}

int ex4dot4()
{
	system("CLS");
	string name;
	cout << "Alinea 4" << endl << endl;
	cout << "Este programa permite normalizar um nome" << endl;
	cout << "Introduza o seu nome: ";
	cin.ignore(INT_MAX, '\n');
	getline(cin, name);
	name = normalizeName(name);
	cout << "O seu nome normalizado: " << name;
	cin.get();
	cin.get();
	system("CLS");
	return 0;
}

struct Fraction {
	int numerator;
	int denominator;
};

Fraction readFracc()
{
		char op;
		Fraction f;
		cout << "Introduza um valor fraccionario, representado por um numerador, um traco e um denominador: ";
		cin >> f.numerator >> op >> f.denominator;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << "ERRO. A fracao nao foi representada no formato apresentado" << endl;
		}
		if (op != '/')
			cout << "ERRO. A fracao nao foi representada no formato apresentado" << endl;
		return f;
}

int gcd(unsigned a, unsigned b);

Fraction reduceFracc(Fraction f)
{
	f.numerator /= gcd(f.numerator, f.denominator);
	f.denominator /= gcd(f.numerator, f.denominator);
	return f;
}


int ex4dot5()
{
	system("CLS");
	Fraction f;
	cout << "Alinea 4" << endl << "Este programa permite trabalhar com fracoes" << endl;
	f = readFracc();
	reduceFracc(f);
	f = reduceFracc(f);
	cout << "Fracao arredondada: " << f.numerator << '/' << f.denominator << endl;
	cin.get();
	cin.get();
	system("CLS");
	return 0;

}

int MultValuesInIntArray(const int a[], int nElem, int value, int index[])
{
	bool exists = false;
	int j;
	int low = 0;
	for (int i = 0; i < nElem; i++)
	{
		if (a[i] == value)
		{
			if (exists)
			{
				index[j++] = i;
			}
			else
			{
				exists = true;
				low = i;
				index[j++] = i;
			}
			
		}
	}
	if (exists)
		return sizeof(index)/sizeof(index[0]);
	else return -1;
}

void readIntArray(int a[], int nElem)
{
	for (int i = 0; i < nElem; i++)
	{
		cout << i << "º Elemento da sequencia: ";
		cin >> a[i];
	}
}

int  ex4dot6()
{
	system("CLS");
	int a[1000];
	int nElem;
	int value;
	int index[500];
	cout << "Alinea 6" << endl << "Este programa permite guardar num array, de n elementos, numeros" << endl;
	cout << "Numero de elementos que quer guardar: ";
	cin >> nElem;
	readIntArray(a, nElem);
	cout << "Indique um valor para pesquisar no array e indicar o seu indice" << endl;
	cout << "Caso nao esteja no array, sera representado o indice: - 1" << endl;
	cout << "Valor: ";
	cin >> value;
	cout << "O array tem : " << MultValuesInIntArray(a, nElem, value, index) << " identicos ao valor " << endl;
	cin.get();
	cin.get();
	system("CLS");
	return 0;
}

void readIntVector(vector<int> &v)
{
	cout << "Coloque numeros ate decidir terminar. Para terminar Faça CTRL+Z" << endl;
	cin.clear();
	int num;
	for (int i = 0; !cin.eof(); i++)
	{
		cout << "Elemento numero " << i << ": ";
		cin >> num;
		if (cin.eof())
			break;
		v.push_back(num);
	}
	cin.clear();

}

vector<int> searchMultValuesInIntVector(const vector<int> &v, int value)
{
	vector <int> index;
	for (int i = 0; i < v.size(); i++)
	{
		if (v.at(i) == value)
		{
			index.push_back(i);
		}
	}
	return index;
}


int ex4dot7()
{
	system("CLS");
	vector <int> v;
	int value;
	cout << "Alinea 6" << endl << "Este programa permite guardar num vector tantos numeros quantos desejar" << endl;
	readIntVector(v);
	cout << "Indique um valor para pesquisar no array e indicar o seu indice" << endl;
	cout << "Caso nao esteja no array, sera representado o indice: - 1" << endl;
	cout << "Valor: ";
	cin >> value;
	vector <int> index = searchMultValuesInIntVector(v, value);
	cout << "O valor " << value << " encontra-se nas poicoes de indice: ";
	for (int i = 0; i < index.size(); i++)
	{
		cout << index.at(i) << ", ";
		if (i == index.size() - 1)
			cout << "\b\b  \n" << endl;
	}
	cin.get();
	cin.get();
	system("CLS");
	return 0;
}

void bubblesort(vector<string> &v)
{
	// nord = não ordenado
	bool nord;
	string tmp;
	do {
		nord = false;
		for (int i = 0; i <( v.size() - 1); i++)
		{
			if (v.at(i) > v.at(i + 1))
			{
				nord = true;
				tmp = v.at(i + 1);
				v.at(i + 1) = v.at(i);
				v.at(i) = tmp;
			}
		}
	} while(nord);
}

int ex4dot8()
{
	system("CLS");
	vector <string> v;
	cout << "alinea 8" << endl << "Este programa ordena vetores de numeros por ordem decrescente, usando um algoritmo bubble sort" << endl;
	cout << "Coloque numero no vectors ate decidir terminar. Para terminar Faça CTRL+Z" << endl;
	cin.clear();
	string name;
	cin.clear();
	cin.ignore(INT_MAX, '\n');
	for (int i = 0; !cin.eof(); i++)
	{
		cout << "Elemento numero " << i << ": ";
		getline(cin, name);
		if (cin.eof())
			break;
		v.push_back(name);
	}
	cin.clear();
	bubblesort(v);
	cout << "Vetor ordenado: ";
	for (int i = 0; i < v.size(); i++)
	{
		cout << v.at(i) << ", ";
		if (i == v.size() - 1)
			cout << "\b\b  \n";
	}
	return 0;
}

int binarySearch(const vector<string> &v, string value)
{
	int middle;
	int bottom = 0;
	int top = v.size() - 1;
	bool found = false;
	while (!(bottom > top) && found == false)
	{
		middle = (bottom + top) / 2;
		if (v.at(middle) == value)
			found = true;
		else if (v.at(middle) < value)
			bottom = middle + 1;
		else top = middle - 1;
	}
	if (found)
		return middle;
	else return -1;
}

int ex4dot9()
{
	system("CLS");
	string value;
	string name;
	vector<string> v;
	cout << "Alinea 9" << endl << "Este programa permite procurar num vetor de strings, o indice de uma string, usando o metodo de pesquisa binaria" << endl;
	cout << "Se o valor existir no vector, entao sera devolvido o seu indice, senao sera devolvido -1";
	cout << "Digite os numeros que constituem o vetor. Para terminar faça CTRL+Z" << endl;
	for (int i = 0; !(cin.eof()); i++)
	{
		cout << "Elemento numero " << i << ": ";
		cin >> name;
		if (cin.eof())
			break;
		v.push_back(name);
	}
	cin.clear();
	bubblesort(v);
	cout << "Digite o valor que quer procurar: ";
	cin >> value;
	cout << "Indice: " << binarySearch(v, value);
	cin.get();
	cin.get();
	system("CLS");
	return 0;
}

void removeDuplicates(vector<int> &v)
{
	for (int i = 0; i < v.size() - 1; i++)
	{
		for (int j = i + 1; j < v.size(); j++)
		{
			if (v.at(i) == v.at(j))
			{
				for (int k = j; k < v.size() - 1; k++)
				{
					v.at(k) = v.at(k + 1);
				}
				v.resize(v.size() - 1);
				i = 0;
			}
		}
	}
}

int ex4dot10()
{
	system("CLS");
	vector <int> v;
	int num;
	cout << "Alínea 10" << endl << "Este programa permite eleminar um valor de um vector" << endl;
	cout << "Quando não quiser preencher mais o vector, faça CTRL+Z" << endl;
	for (int i = 0; !cin.eof(); i++)
	{
		cout << "Elemento numero " << i << ": ";
		cin >> num;
		if (cin.eof())
			break;
		v.push_back(num);
	}
	cin.clear();
	cin.ignore(INT_MAX, '\n');
	removeDuplicates(v);
	for (int i = 0; i < v.size(); i++)
	{
		cout << "Elemento numero " << i << ": ";
		cout << v.at(i) << endl;
	}
	cin.get();
	cin.get();
	system("CLS");
	return 0;
}

void selsort(vector<int> &v)
{
	int tmp;
	for (int i = 0; i < v.size() - 1; i++)
	{
		for (int j = i + 1; j < v.size(); j++)
		{
			if (v.at(j) < v.at(i))
			{
				tmp = v.at(i);
				v.at(i) = v.at(j);
				v.at(j) = tmp;
			}
		}
	}
}

int ex4dot11()
{
	system("CLS");
	vector<int> v;
	int num;
	cout << "Alínea 11" << endl << "Este programa calcula a intersecção e a reunião de dois vetores" << endl;
	cout << "Quando não quiser preencher mais o 1º vector, faça CTRL+Z" << endl;
	for (int i = 0; !cin.eof(); i++)
	{
		cout << "Elemento numero " << i << ": ";
		cin >> num;
		if (cin.eof())
			break;
		v.push_back(num);
	}
	cin.clear();
	cin.ignore(INT_MAX, '\n');
	cout << "Quando não quiser preencher mais o 2º vector, faça CTRL+Z" << endl;
	for (int i = 0; !cin.eof(); i++)
	{
		cout << "Elemento numero " << i << ": ";
		cin >> num;
		if (cin.eof())
			break;
		v.push_back(num);
	}
	cin.clear();
	cin.ignore(INT_MAX, '\n');
	removeDuplicates(v);
	selsort(v);
	cout << "Reunião: ";
	for (int i = 0; i < v.size(); i++)
	{
		cout << v.at(i) << ", ";
	}
	cout << "\b\b  \n";
	return 0;
}

double executeOperation(string op)
{
	istringstream conta(op);
	double num1, num2, result;
	char s;
	conta >> num1 >> s >> num2;
	switch (s) {
	case '+':
		result = num1 + num2;
		break;
	case '-':
		result = num1 - num2;
		break;
	case '*':
		result = num1 * num2;
		break;
	case '/':
		result = num1 / num2;
		break;
	}
	return result;
}

int ex4dot12()
{
	string op;
	double result;
	system("CLS");
	cout << "Alinea 12" << endl << "Este programa permite realizar contas aritmetcias simples(soma, subtracao, multiplicacao e divisao)" << endl;
	cout << "Podes escrever diretamente a operacao numa so string" << endl;
	cout << "Conta: ";
	cin.clear();
	cin.ignore();
	getline(cin, op);
	result = executeOperation(op);
	cout << "Resultado: " << result << endl;
	cin.get();
	cin.get();
	system("CLS");
	return 0;
}

bool readfile(vector<string> &v)
{
	SetConsoleCP(1252); 
	SetConsoleOutputCP(1252);
	setlocale(LC_ALL, "Portuguese");
	string line;
	string name;
	cout << "Localização do ficheiro: ";
	cin.clear();
	cin.ignore(INT_MAX, '\n');
	getline(cin, name);
	ifstream myfile(name);
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			v.push_back(line);
		}
		myfile.close();
		return true;
	}
	else {
		myfile.close();
		return false;
	}
}

bool writefile(vector<string> v)
{
	SetConsoleCP(1252);
	SetConsoleOutputCP(1252);
	setlocale(LC_ALL, "Portuguese");
	string line;
	string name;
	cout << "Localização onde quer guardar: ";
	getline(cin, name);
	ofstream file(name);
	if (file.is_open())
	{
		for (int i = 0; i < v.size(); i++)
		{
			file << v.at(i) << '\n';
		}
		file.close();
		return true;
	}
	else
	{
		file.close();
		return false;
	}
}

int ex4dot13()
{
	system("CLS");
	vector<string> v;
	cout << "Alinea 13" << endl << "Este programa permite ordenar os nomes escritos em um ficheiro e posteriormente gravar noutro" << endl;
	// A variável cond irá analisar se o programa está a ser analisado como pretendido,
	//para saber se deve continuar ou mostar mensagem de erro
	bool cond = readfile(v);
	if (!cond)
	{
		cout << "Erro. O ficheiro especificado ou nao existe ou enganou-se no endereco" << endl;
		cin.get();
		cin.get();
		system("CLS");
		return 0;
	}
	bubblesort(v);
	cond = writefile(v);
	if (!cond)
	{
		cout << "Erro. O ficheiro especificado ou não existe ou enganou-se no endereco" << endl;
		cin.get();
		cin.get();
		system("CLS");
		return 0;
	}
	cout << "O ficheiro foi modificado com sucesso" << endl;
	cin.get();
	cin.get();
	system("CLS");
	return 0;
}

int menu4()
{
	cout << "Escolha uma das segintes alineas" << endl;
	cout << "1 - Exercicio 1" << endl << "2 - Exercicio 2" << endl << "3 - Exercicio 3" << endl << "4 - Exercicio 4" << endl << "5 - Exercicio 5" << endl << "6 - Exercicio 6" << endl << "7 - Exercicio 7" << endl << "8 - Exercicio 8" << endl << "9 - Exercicio 9" << endl << "10 - Exercicio 10" << endl << "11 - Exercicio 11" << endl << "12 - Exercicio 12" << endl << "13 - Exercicio 13" << endl;

	int ex;
	cout << "Numero do exercicio: ";
	cin >> ex;
	switch (ex) {
	case 1:
		ex4dot1();
		break;
	case 2:
		ex4dot2();
		break;
	case 3:
		ex4dot3();
		break;
	case 4:
		ex4dot4();
		break;
	case 5:
		ex4dot5();
		break;
	case 6:
		ex4dot6();
		break;
	case 7:
		ex4dot7();
		break;
	case 8:
		ex4dot8();
		break;
	case 9:
		ex4dot9();
		break;
	case 10:
		ex4dot10();
		break;
	case 11:
		ex4dot11();
		break;
	case 12:
		ex4dot12();
		break;
	case 13:
		ex4dot13();
		break;
	default:
		cout << "Alinea Invalida" << endl << endl;
	}
	return 0;
}