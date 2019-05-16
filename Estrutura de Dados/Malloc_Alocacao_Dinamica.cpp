#include <iostream>
#include <stdlib.h>

using namespace std;

typedef struct lista list;

struct lista
{
	int num;
	list* prox;
};

list* ler(list* lst, int valor)
{
	list* novo = (list*) malloc(sizeof(list));
	novo->num = valor;
	novo->prox = lst;
	return novo;
}

void imprimir(list* lst)
{
	for(list* i = lst; i != NULL; i = i->prox)
	{
		cout << i->num << endl;
	}
}

int main()
{
	list* lst;
	lst = NULL;
	lst = ler(lst, 10);
	lst = ler(lst, 9);
	lst = ler(lst, 30);
	imprimir(lst);
}

