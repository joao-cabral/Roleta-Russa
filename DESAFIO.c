#include<stdio.h>
#include<stdlib.h>

typedef struct Lista{
    int numero;
    char nome[20];
    struct Lista *prox;
}lista;

lista* inserir(lista *cabeca){
    lista *newNodo = (lista*)malloc(sizeof(lista));
    int numero;

    printf("\nInforme um nome:\n");
    scanf("%s", newNodo->nome);
    printf("Informe um numero:\n");
    scanf("%d", &numero);

    newNodo->numero = numero;

    if(cabeca == NULL){
        cabeca = newNodo;
        newNodo->prox = cabeca;
    }else{
        lista *aux = cabeca;

        while(aux->prox != cabeca){
            aux = aux->prox;
        }

        newNodo->prox = cabeca;
        aux->prox = newNodo;

    }

return cabeca;
}

lista* jogar(lista *cabeca){
    int n, cont=0, i;
    lista *aux1, *ant;

    printf("Informe um numero:\n");
    scanf("%d", &n);

    if(cabeca == NULL){
        printf("Lista vazia!");
        printf("Recomece o programa!");
        //getch();
        system("PAUSE");
        return 0;
    }else if(n == 0){
        printf("\nNUMERO INFORMADO INVALIDO!\n");
        return 0;
    }else{
        while(cabeca->prox != cabeca){
        	if(n == 1){
        		ant = cabeca;
		        while(ant->prox != cabeca){
		        	ant = ant->prox;
		        }
				aux1 = cabeca;
				printf("\nMorto: %s", cabeca->nome);
				n = cabeca->numero;
            	ant->prox = cabeca->prox;
            	cabeca = cabeca->prox; 
            	free(aux1);	
			}else{
				for(i=1; i<n; i++){
            	ant = cabeca;
                cabeca = cabeca->prox;
            }
            printf("\nMorto: %s", cabeca->nome);
            
			aux1 = cabeca;
			n = cabeca->numero;
            ant->prox = cabeca->prox;
            cabeca = ant->prox;
            free(aux1);
        }
    }
    printf("\nUltimo:\n%s\n%d", cabeca->nome, cabeca->numero);
    }
    
return cabeca;
}

void imprimir(lista *cabeca){
    lista *aux = cabeca;
    lista *auxAux;

    do{
        printf("\nNOME: %s", aux->nome);
        printf("\nVALOR: %d\n", aux->numero);
        printf("-------------");
        aux = aux->prox;
        //auxAux = aux;
    }while(aux != cabeca);
}

int main(){
    lista *LISTA = NULL;
    int op;

    do{
        printf("\n(1) Para inserir\n(2)Imprimir na tela\n(3) Para jogar\n(4)Para sair\n");
        scanf("%d", &op);

        switch(op){
        case 1:
            LISTA = inserir(LISTA);
            system("cls");
            break;
        case 2:
            imprimir(LISTA);
            break;
        case 3:
            LISTA = jogar(LISTA);
            }
    }while(op != 4);

free(LISTA);
return 0;
}
