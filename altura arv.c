#include <stdio.h>
#include <stdlib.h>


struct No {
	int data;
	struct No* esq;
	struct No* dir;
};


int maxProfundidade(struct No* no)
{
	if (no == NULL)
		return -1;
	else {
		int eProfundidade = maxProfundidade(no->esq);
		int dProfundidade = maxProfundidade(no->dir);


		if (eProfundidade > dProfundidade)
			return (eProfundidade + 1);
		else
			return (dProfundidade + 1);
	}
}

struct No* novoNo(int data)
{
	struct No* no
		= (struct No*)malloc(sizeof(struct No));
	no->data = data;
	no->esq = NULL;
	no->dir = NULL;

	return (no);
}

int main(void)
{
    struct No* raiz = novoNo(3);
	raiz->esq = novoNo(8);
	raiz->dir = novoNo(6);
	raiz->esq->dir = novoNo(7);
	raiz->esq->dir->esq = novoNo(2);
	raiz->esq->dir->dir = novoNo(12);
    raiz->dir->dir = novoNo(10);
    raiz->dir->dir->esq = novoNo(5);

	printf("a altura da arvore e %d", maxProfundidade(raiz)+1);

	getchar();
	return 0;
}

