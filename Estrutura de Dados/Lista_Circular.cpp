#include <iostream>
#include <cstdlib>

using namespace std;

typedef struct circulo c;

struct circulo
{
	int valor;
	c* prox;
};

//Metodo de INSERIR elemento:
c* inserir(c* cabeca, int v)
{
	c* novo = (c*) malloc(sizeof(c));
	novo->valor = v;
	if(cabeca == NULL)
	{
		novo -> prox = novo;
		return novo;
	}
	else
	{
		novo ->prox = cabeca;
		c*i = cabeca;
		do
		{
			i = i->prox;
		}
		while(i->prox != cabeca);
		i->prox = novo;
	}
	return cabeca;
}


//Imprimir Com FOR:
/*void imprimir (c* cabeca)
{	c* i;
	for(i = cabeca; i->prox != cabeca; i = i->prox)
	{
		cout << i->valor << endl;
	}
	if (i->prox==cabeca){
		cout<<i->valor <<endl;
	}
}*/

//Imprimir com DO WHILE:
void imprimir(c* cabeca)
{
	c* aux = cabeca;
	if(aux != NULL)
	{
		do
		{
			cout << aux->valor << endl;
			aux = aux ->prox;

		}
		while(aux != cabeca);
	}
}

//MAIN:
int main(int argc, char** argv)
{
	c* cabeca = NULL;
	cabeca = inserir(cabeca, 10);
	cabeca = inserir(cabeca, 20);
	cabeca = inserir(cabeca, 30);
	imprimir(cabeca);
	return 0;
}
