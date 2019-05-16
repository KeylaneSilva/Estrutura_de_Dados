#include <iostream>
#include <cstdlib>
#include <locale.h>

using namespace std;

typedef struct Lista list;
struct Lista
{
	double n;
	list* prox;
	list* ant;
};

list* inserir(list* inicio, double valor)
{
	list* novo = (list*)malloc(sizeof(list));
	novo->n = valor;
	if(inicio == NULL)
	{
		novo->prox = NULL;
		novo->ant = NULL;
	}
	else if(valor < inicio->n)
	{
		novo->ant = NULL;
		novo->prox = inicio;
		inicio->ant = novo;
	}
	else
	{
		list* aux = inicio;
		bool sair = false;
		while(!sair)
		{
			if(aux->prox != NULL)
			{
				list* aux2 = aux->prox;
				if(valor < (aux2->n))
				{
					novo->ant = aux;
					aux->prox = novo;
					novo->prox = aux2;
					aux2->ant = novo;
					sair = true;
				}
			}
			else
			{
				novo->prox = NULL;
				novo->ant = aux;
				aux->prox = novo;
				sair = true;
			}
			aux = aux->prox;
		}
		return inicio;
	}
	return novo;
}
void imprimir(list* inicio)
{
	for(list* i = inicio; i != NULL; i = i->prox)
	{
		cout << i->n << endl;
	}

}

void buscar(list* inicio, double c)
{
	for(list* i = inicio; i != NULL; i = i->ant)
	{
		if(i->n == c)
		{
			cout << "TEM NA LISTA" << endl;
			break;
		}
		else
		{
			cout << "NAO TEM NA LISTA" << endl;
			break;
		}
	}
}

list* excluir(list* inicio, double n)
{
	list* posAnt = NULL;
	list* posProx;
	for(list* i = inicio; i != NULL; i = i->prox)
	{
		if(n == i->n)
		{
			//cout << "Existe" << endl;
			list* aux = i;

			if(posAnt != NULL && posProx != NULL)
			{
				posProx = i ->prox;
				posAnt = i->ant;
				posProx ->ant = posAnt;
				posAnt ->prox = posProx;
				free(aux);
				return inicio;
			}
			else if(posProx == NULL)
			{
				posAnt = i->ant;
				posAnt -> prox = NULL;
				free(aux);
				return inicio;
			}
			else if(posAnt == NULL)
			{
				posProx = i ->prox;
				posProx ->ant = NULL;
				free(aux);
				return posProx;
			}
		}
		else
		{
			posAnt = i;
			posProx = i -> prox->prox;

		}
	}
	return inicio;
}


int main(int argc, char** argv)
{
	setlocale(LC_ALL, "Portuguese");
	list* inicio = NULL;
	double x, y, c;
	string z, a;
	cout << "\n========== DIGITE '0' PARA ENCERRAR O LOOP ==========\n" << endl;

	do
	{
		cout << "Digite um número para ser armazenado." << endl;
		cout << "-> ";
		cin >> x;
		inicio = inserir(inicio, x);
	}
	while(x > 0);
volta1:
	cout << "================ NÚMEROS ARMAZENADOS ================" << endl;
	imprimir(inicio);
	cout << "QUAL NUMERO QUE VC QUE BUSCAR" << endl;
	cin >> c;
	buscar(inicio, c);
volta2:
	cout << "=====================================================" << endl;
	cout << "Você deseja excluir algum número?" << endl;
	cout << "Y/N" << endl;
	cout << "-> ";
	cin >> z;
	if((z != "y") && (z != "Y") && (z != "n") && (z != "N"))
	{
		cout << "=====================================================" << endl;
		cout << "\n!!! Opção Inválida !!!\n" << endl;
		goto volta2;
	}
	else
	{
		if ((z == "y") || (z == "Y"))
		{
			cout << "=====================================================" << endl;
			cout << "Qual número você deseja excluir?" << endl;
			cout << "-> ";
			cin >> y;
			inicio = excluir(inicio, y);
			cout << "================= NÚMERO " << y << " EXCLUIDO =================" << endl;
			imprimir(inicio);
		}
		else if ((z == "n") || (z == "N"))
		{
		}
	}
volta3:
	cout << "=====================================================" << endl;
	cout << "Deseja Adicionar mais um número?" << endl;
	cout << "Y/N" << endl;
	cout << "->";
	cin >> a;
	if((a != "y") && (a != "Y") && (a != "n") && (a != "N"))
	{
		cout << "=====================================================" << endl;
		cout << "\n!!! Opção Inválida !!!\n" << endl;
		goto volta3;
	}
	else
	{


		if ((a == "y") || (a == "Y"))
		{
			double b;
			cout << "Qual número você deseja adicionar?" << endl;
			cout << "->";
			cin >> b;
			inicio = inserir(inicio, b);
			goto volta1;

		}
		else if ((a == "n") || (a == "N"))
		{
			cout << "\nAté a Proxima...\n";
		}
		return 0;
	}
}
