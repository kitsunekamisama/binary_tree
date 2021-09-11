#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bstree.h"

int cmp(void *elm, void *key);
void visit(void *item);

typedef struct{
    char placa[8];
    char modelo[20];
    int ano;
    float valor;
}Carro;

int main()
{
    TNode *t = NULL;
    Carro *carro;
    void *data;
    int opcao;

    do{
        printf("1 - Inserir\n");
        printf("2 - Buscar\n");
        printf("3 - Remover\n");
        printf("4 - Listar\n");
        printf("5 - Sair\n");
        scanf("%d", &opcao);
        switch(opcao){
            case 1:// Inserir elemento
                carro=(Carro *)malloc(sizeof(Carro));
                printf("Digite a placa:\n");
                fflush(stdin);
                fgets(carro->placa,8,stdin);
                printf("Digite o modelo: \n");
                fflush(stdin);
                fgets(carro->modelo,20,stdin);
                printf("Digite o ano: \n");
                scanf("%d", &carro->ano);
                printf("Digite o valor: \n");
                scanf("%f", &carro->valor);

                if(t==NULL){
                    t = treeInsert(NULL, carro, cmp);
                    if(t){
                        printf("Elemento inserido!\n");
                    }else{
                        printf("Elemento nao inserido\n");
                    }
                }else{
                    if(treeInsert(t, carro, cmp)){
                        printf("Elemento inserido!\n");
                    }else{
                        printf("Elemento nao inserido\n");
                    }
                }
                break;
            case 2:
                carro=(Carro *)malloc(sizeof(Carro));
                printf("Digite a placa do carro:\n");
                fflush(stdin);
                fgets(carro->placa,8,stdin);
                carro=treeQuery(t,(void *)&carro->placa,cmp);
                //Se o retorno não for nulo, então informa o carro encontrado
                if(carro!=NULL){
                    printf("\tCARRO\n");
                    printf("\nPlaca: %s\n",carro->placa);
                    printf("Modelo: %s",carro->modelo);
                    printf("Ano: %d\n",carro->ano);
                    printf("Valor: %2.f\n\n",carro->valor);
                }else{
                    printf("\nElemento nao encontrado!!!\n\n");
                }
                break;
            case 3: // Remover elemento
                carro=(Carro *)malloc(sizeof(Carro));
                printf("Digite a placa do carro:\n");
                fflush(stdin);
                fgets(carro->placa,8,stdin);

                treeRemove(t, (void *)&carro->placa, cmp, &data);

                //Se o retorno não for nulo, então informa o carro removido
                if(data!=NULL){
                    carro=(Carro *)data;
                    printf("\nPlaca: %s",carro->placa);
                    printf("Modelo: %s",carro->modelo);
                    printf("Ano: %d\n",carro->ano);
                    printf("Valor: %2.f\n",carro->valor);
                    printf("Elemento removido!\n\n");
                }else{
                    printf("\nElemento nao removido\n\n");
                }
                break;
            case 4:
                    printf("CARRO(S)\n");
                    simetrico(t, visit);
                break;
            case 5:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida!!!\n");
                break;
        }
    }while(opcao!=5);

    return 0;
}

//Função de comparação
int cmp(void *elm, void *key){
    char *pelm = (char *)elm;
    Carro *pkey = (Carro *)key;
    return strcmp(pelm, pkey->placa);
}

//Função de exibição do item
void visit(void *item){
    Carro *carro = (Carro *)item;// Atribui à variável carro cada elemento da árvore
    printf("\nPlaca: %s\n",carro->placa);
    printf("Modelo: %s",carro->modelo);
    printf("Ano: %d\n",carro->ano);
    printf("Valor: %.2f RS\n",carro->valor);
}
