#include <iostream>
#include <cstdlib>
using namespace std;

typedef struct pilha
{
	int num;
	pilha* prox;
} pilha;

pilha* push(pilha* topo, int valor)
{
	pilha* novo = (pilha*) malloc(sizeof(pilha));
	novo -> num = valor;
	novo -> prox = topo;

	return novo;
}

pilha* pop(pilha* topo)
{
	if (topo != NULL)
	{
		pilha* aux = topo;
		topo = topo -> prox;
		free(aux);
	}
	else
	{
		cout << "Pilha vazia" << endl;
	}

	return topo;
}

void listar(pilha* topo)
{
	for (pilha* i = topo; i != NULL; i = i -> prox)
	{
		cout << i -> num << endl;
	}
}

int main()
{
	pilha* topo = NULL;
	topo = push(topo, 5);
	topo = push(topo, 25);
	topo = push(topo, 15);
	listar(topo);
	topo = pop(topo);
	cout << endl;
	listar(topo);
	return 0;
}
