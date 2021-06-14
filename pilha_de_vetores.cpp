#include <stdio.h>
#include <stdlib.h>

#define MAXTAM 100

typedef struct pilha {
	/* 
	Na pilha, só será possível
	adicionar ou remover inteiros.
	*/ 
	int item[MAXTAM];
	
	/*  
	Indica a posição do vetor
	que está o topo da pilha.
	*/
	int topo;
}t_pilha;

void t_pilha_inicia(t_pilha *p) {
	/*
	Inicia o topo da pilha com -1,
	pois não há valor empilhado (pilha vazia).
	*/
	p->topo = -1;
}

int t_pilha_vazia(t_pilha *p) {
	if(p->topo == -1){
		return 1;
	}else{
		return 0;
	}
}

int t_pilha_cheia(t_pilha *p) {
	/*
	Se o topo do índice do vetor for
	igual a 99 (0 - 99), significa que
	todas as 100 posições do vetor foram
	preenchidas com algum valor.
	*/
	if(p->topo == MAXTAM-1){
		return 1;	
	}else{
		return 0;
	}
}

void t_pilha_insere(t_pilha *p, int x) {
	if(t_pilha_cheia(p) == 1){
		printf("ERRO!\nPilha cheia!\n");
	}else{
		p->topo++;
		// Armazena em item o valor de x. 
		p->item[p->topo] = x;
	}
}

int t_pilha_remove(t_pilha *p) {
	int aux;
	
	if(t_pilha_vazia(p) == 1){
		printf("ERRO!\nPilha vazia!\n");
	}else{
		aux = p->item[p->topo];
		p->topo--;
		return aux;
	}
}

int main() {
	int valor;
	int resp;
	int aux;
	
	// Aloca na memória.
	t_pilha *p = (t_pilha *)malloc(sizeof(t_pilha));
	
	t_pilha_inicia(p);
	
	while(1){
		printf("\nDigite um valor: ");
		scanf("%d", &valor);
		
		t_pilha_insere(p, valor);
		
		printf("\nDeseja continuar? <1> SIM <outro valor> NAO:");
		scanf("%d", &resp);
		
		if(resp != 1)
			break;
	}	
	
	while(1){
		printf("\nDeseja remover o ultimo valor da pilha? <1> SIM <outro valor> NAO:");
		scanf("%d", &resp);	
		
		if(resp == 1){
			aux = t_pilha_remove(p);
			printf("\nValor removido: %d", aux);
		}else{
			break;
		}
	}
	
	return 0;
}
