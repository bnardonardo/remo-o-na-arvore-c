#include <limits.h>
#include <stdio.h>
#include <stdlib.h>


struct No {
	int data;
	struct No *esq, *dir;
};


struct No* novoNo(int data)
{
	struct No* no
		= (struct No*)malloc(sizeof(struct No));
	no->data = data;
	no->esq = no->dir = NULL;
	return (no);
}

int AchaMaior(struct No* raiz)
{

	if (raiz == NULL)
		return INT_MIN;


	int res = raiz->data;
	int eres = AchaMaior(raiz->esq);
	int dres = AchaMaior(raiz->dir);
	if (eres > res)
		res = eres;
	if (dres > res)
		res = dres;
	return res;
}

int AchaMenor(struct No* raiz)
{

	if (raiz == NULL)
	return INT_MAX;


	int res = raiz->data;
	int eres = AchaMenor(raiz->esq);
	int dres = AchaMenor(raiz->dir);
	if (eres < res)
	res = eres;
	if (dres < res)
	res = dres;
	return res;
}



int main(void)
{
	struct No* NovaRaiz = NULL;
	struct No* raiz = novoNo(3);
	raiz->esq = novoNo(8);
	raiz->dir = novoNo(6);
	raiz->esq->dir = novoNo(7);
	raiz->esq->dir->esq = novoNo(2);
	raiz->esq->dir->dir = novoNo(12);
    raiz->dir->dir = novoNo(10);
    raiz->dir->dir->esq = novoNo(5);


	printf("Maior elemento e %d \n", AchaMaior(raiz));
	printf("Menor elemento e %d \n", AchaMenor(raiz));

	return 0;
}
