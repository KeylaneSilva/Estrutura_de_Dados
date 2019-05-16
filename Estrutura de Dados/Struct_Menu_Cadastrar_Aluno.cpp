#include <windows.h>
#include <iostream>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

struct Aluno
{
	int cod, numero;
	string nome;
	float not1, not2;
};

Aluno lista[10];
int codigo, a, tm;
float media;


void Cadastrar()
{

	for(int i = 0; i < tm; i++)
	{
		srand(time(NULL));
		lista[tm].cod = rand() % 10 + 1;
	}

	lista[tm].numero = lista[tm].cod;

	cout << "Código gerado: " << lista[tm].cod << endl;
	cout << "Qual seu nome: ";
	cin >> lista[tm].nome;
	cout << "Qual sua nota 1: ";
	cin >> lista[tm].not1;
	cout << "Qual sua nota 2: ";
	cin >> lista[tm].not2;
	tm++;
	cout << "------------------------------\n" << endl;
}

void ListaAluno()
{

	for(int i = 0; i < tm; i++)
	{
		if (lista[i].cod < 0)
		{
			cout << "------------------------------\n" << endl;
			break;
		}
		cout << "Cod do Aluno : " << lista[i].cod << endl;
		cout << "Nome do Aluno: " << lista[i].nome << endl;
		cout << "Nota 01: " << lista[i].not1 << endl;
		cout << "Nota 02: " << lista[i].not2 << endl;
		cout << "------------------------------" << endl;
	}
	cout << "Total de Alunos Cadastrados: " << tm <<  endl;
	cout << "------------------------------\n" << endl;
}

void menuBusca()
{
	cout << " !!! OPÇÕES !!!" << endl;
	cout << "\n Digite 1 para EXCLUIR " << endl;
	cout << " Digite 2 para VOLTAR " << endl;
	cout << " -> ";
	cin >> a;
	cout << "-------------------------------" << endl;
	if ((a < 0) || (a > 2))
	{
		cout << "!!! OPÇÃO INVÁLIDA !!!" << endl;
	}



	switch(a)
	{
	case 1:
	{
		for(int i = 0; i < tm; i++)
		{
			(lista[i].numero) = -1;
			(lista[i].nome);
			(lista[i].not1);
			(lista[i].not2);
		}
	}

	cout << endl;

	cout << "  !!! Cadastro Exluido !!!" << endl;
	cout << "------------------------------\n" << endl;

	break;

	case 2:
	{
		break;
	}
	}
}

void busca()
{
	cout << "Digite o Código que deseja pesquisar: ";
	cin >> codigo;
	cout << "------------------------------\n" << endl;


	for(int i = 0; i < tm; i++)
	{

		if(lista[i].numero == codigo)
		{
			cout << "Nome do Aluno: " << lista[i].nome << endl;
			cout << "Nota 01: " << lista[i].not1 << endl;
			cout << "Nota 02: " << lista[i].not2 << endl;
			media = (lista[i].not1 + lista[i].not2) / 2;
			cout << "A média do " << lista[i].nome << " é: " << media << endl;
			cout << "------------------------------\n" << endl;
			menuBusca();

		}
	}
}

int main()
{


	setlocale(LC_ALL, "Portuguese");
	int sair;
	do
	{
		cout << " \n  !!! MENU DE OPÇÕES !!!\n" << endl;
		cout << "1.Cadastrar Aluno" << endl;
		cout << "2.Lista de Alunos" << endl;
		cout << "3.Buscar Aluno " << endl;
		cout << "4.Sair\n" << endl;
		cout << "------------------------------\n" << endl;
		cout << "Digite sua opção: ";
		cin >> sair;
		cout << "\n------------------------------" << endl;
		switch (sair)
		{
		case 1:
			Cadastrar();
			break;
		case 2:
			ListaAluno();
			break;
		case 3:
			busca();
			break;
		}
		if ((sair != 1) && (sair != 2) && (sair != 3) && (sair != 4))
		{
			cout << "\n   !!! OPÇÃO INVÁLIDA !!!\n" << endl;
			cout << "------------------------------\n" << endl;
		}
	}
	while(sair != 4);
	system("pause");
}
