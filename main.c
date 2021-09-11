#ifndef _main_c_
#define _main_c_

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "bstree.h"
#define TRUE 1
#define FALSE 0

/*------------------------------------------------------------------------------
Implementa��o das opera��es na main:
------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
Estrutura _livro_: Declara��o de tipo que cont�m as vari�veis que comp�em o LIVRO.
Vari�veis: char    nome[30]: Vetor de String com o nome da nome do LIVRO
           int     qpaginas:  A qpaginas do LIVRO em tipo inteiro
           int     nexemplares:   O numero de exemplares do LIVRO em tipo inteiro
           float   preco:     O preco do LIVRO em tipo float
           long    codigo:     O numero da codigo do LIVRO em tipo long(int)
------------------------------------------------------------------------------*/
//Estrutura Livro
typedef struct _livro_{
    char    nome[30];
    int     qpaginas;
    int     nexemplares;
    float   preco;
    long    codigo;
}Livro;

/*------------------------------------------------------------------------------
Fun��o comCodigo: Compara a codigo de um livro
Parametro: Ponteiro para um elemento k a ser comparado com os elementos dentro da Lista
Retorno: TRUE(1) -  caso o elemento for igual ao do TAD Lista;
         FALSE(0) - Caso contr�rio
------------------------------------------------------------------------------*/
//Fun��o de compara��o por codigo do livro
int comCodigo(void *k, void *elm){
    long *icodigo = (long*)k;
    Livro *Celm = (Livro*)elm;
    long *codigo = (long*)Celm ->codigo;

    if(icodigo == codigo ){
        return TRUE;
    }
    else{
        return FALSE;
    }
}

/*------------------------------------------------------------------------------
Fun��o comNome: Compara a Nome de um livro
Parametro: Ponteiro para um elemento k a ser comparado com os elementos dentro da Lista
Retorno: TRUE(1) -  caso o elemento for igual ao do TAD Lista;
         FALSE(0) - Caso contr�rio
------------------------------------------------------------------------------*/
//Fun��o de compara��o por nome do livro
int comNome(void *key,void *elm){
	char strkey[30];
	char strelm[30];
	Livro *l = (Livro *)elm;
	strcpy(strkey,(char *)key);

    strcpy(strelm, (char*)l->nome);
    if( strcmp(strkey,l->nome) == 0){
	//if( strcmp(strkey,strelm) == 0){
		return TRUE;
	}
	else{
        return FALSE;
	}
}

/*------------------------------------------------------------------------------
Fun��o comPaginas: Compara a Preco de um livro
Parametro: Ponteiro para um elemento k a ser comparado com os elementos dentro da Lista
Retorno: TRUE(1) -  caso o elemento for igual ao do TAD Lista;
         FALSE(0) - Caso contr�rio
------------------------------------------------------------------------------*/
//Fun��o de compara��o por preco do livro
int comPaginas(void *k, void *elm){
    int *ipagina = (int*)k;
    Livro *Pag = (Livro*)elm;
    int *qpaginas = (int*)Pag ->qpaginas;


    if(ipagina == qpaginas ){
        return TRUE;
    }
    else{
        return FALSE;
    }
}


/*Vari�vel |op| � para as opcoes do menu principal
 *Vari�vel |op2| � para a opc�es de busca e remo��o por CODIGO ou NOME
 *Vari�vel |tam| � para o tamanho da Lista a ser criado
 *Variavel |destroi| usada para auxiliar na detruicao do Lista
 *Variavel |inseriu| verifica se foi inserido um elemento do tipo livro na Lista ou n�o
 *Variavel |cont| usada pra delimitar a quantidade de livros INSERIDOS e REMOVIDOS da Lista
 *
 *
*/


int main(){

    int op, op2, tam, destroi, inseriu, cont = 0;
    long codigo;
    int qpaginas;
    char nome[30];
    TNode *l = NULL;
    Livro *liv, *busca, *removeu;

    do{
        do{

        printf("\n\n\n");
       printf("\n\t\t\t     Sistema de biblioteca\n\n");
       printf("\n\t\t     ( 1 ) Criar a Arvore\n");
       printf("\t\t     ( 2 ) Destruir a Arvore\n");
       printf("\t\t     ( 3 ) Cadastrar Livros\n");
       printf("\t\t     ( 4 ) Visualizar livros cadastrados\n");
       printf("\t\t     ( 5 ) Consultar livros cadastrados\n");
       printf("\t\t     ( 6 ) Remover livros cadastrados\n");
       printf("\t\t     ( 7 ) Sair do programa\n");
       printf("\nOpcao Desejada: ");

       scanf("%d",&op);
            if(op<1 || op>7){
                system("cls");
                printf("\nOpcao invalida!!\n");
            }
        }while(op<1 || op>7);
        system("cls");

        switch(op){
            case 1:
                if(l==NULL){
                    l = abpCreate();
                    //liv = (Livro*)malloc(sizeof(Livro));
                    if(l!=NULL){
                        printf("\nArvore criada com SUCESSO!!\n");
                        liv = NULL;
                        break;
                        system("cls");
                    }
                    else{
                        printf("\nFalha na criacao do Arvore\n");
                        break;
                        system("cls");
                    }
                }
                else{
                    printf("\nArvore ja esta criada!!!\n");
                    break;
                    system("cls");
                }
                break;
            case 2:
                if(l!=NULL){
                    destroi = sllDestroy(l);
                    if(destroi == TRUE){
                        printf("\nArvore Destruida com SUCESSO!!\n");
                        l = NULL;
                        break;
                        system("pause");
                    }
                    else{
                        destroi = sllRemoveAll (l);
                        destroi = sllDestroy(l);
                        printf("\nArvore nao foi Destruida com SUCESSO!!\n");
                        l = NULL;
                        break;
                        system("pause");
                    }
                }else{
                    printf("\nIMPOSSIVEL DESTRUIR, Arvore ainda nao Criada!!\n");
                    break;
                    system("cls");
                }
                break;
            case 3:
                if(l!=NULL){
                        cont = 0;
                        liv = (Livro*)malloc(sizeof(Livro));

                        if(liv!=NULL){
                            printf("\nInsira os dados dos livros na Arvore?\n");
                            printf("\nInsira o nome do livro:\n");
                            fflush(stdin);
                            fgets(liv ->nome, 30, stdin);
                            printf("\nInsira a quantidade de paginas do livro:\n");
                            scanf("%d",&(liv ->qpaginas));
                            printf("\nInsira o numero de exemplares do livro:\n");
                            scanf("%d",&(liv ->nexemplares));
                            printf("\nInsira o preco do livro:\n");
                            scanf("%f",&(liv ->preco));
                            printf("\nInsira a codigo do livro:\n");
                            scanf("%ld",&(liv ->codigo));
                            inseriu = abpInsert(l,(void*)liv);
                            system("cls");
                            if(inseriu == TRUE){
                                printf("\nLivro inserido com sucesso!!\n");
                                cont ++;
                                break;
                                system("cls");
                            }
                            if(inseriu == FALSE){
                                printf("\nNao ha mais espaco para inserir livros na Arvore!!\n");
                                break;
                                system("cls");
                            }
                        }



                }
                else{
                    printf("\nIMPOSSIVEL INSERIR DADOS, Arvore ainda nao Criada!!\n");
                    break;
                    system("cls");
                }
                break;
            case 4:
                if(l!=NULL){
                    if(liv!=NULL){
                        int i =0;
                        liv = (Livro*)sllGetFirst(l);
                        //l->cur = l->first;
                        if(liv!=NULL){
                            printf("\nOs livros que estao na Arvore:\n");
                        }else{
                            printf("\nSem elementos ainda na Arvore!!\n");
                        }
                        while(liv!=NULL){
                            printf("\n\t*** Livro %d: ***\n",i);
                            printf("\nNome:\t %s\n",liv ->nome);
                            printf("\nQuantidade de paginas:\t %d\n",liv ->qpaginas);
                            printf("\nNumero de exemplares:\t %d\n",liv ->nexemplares);
                            printf("\nPreco:\t %.2f\n",liv ->preco);
                            printf("\nCodigo:\t %ld\n",liv ->codigo);
                            printf("\n");
                            liv = (Livro*)sllGetNext(l);
                            i++;
                        }
                        liv = (Livro*)sllGetFirst(l);
                        break;
                        system("cls");
                    }
                    else{
                        printf("\nSem elementos ainda na Arvore!!\n");
                        break;
                        system("cls");
                    }
                }
                else{
                    printf("\nIMPOSSIVEL VER ELEMENTOS, Arvore ainda nao Criada!!\n");
                    break;
                    system("cls");
                }
                break;
            case 5:
                if(l!=NULL){
                    if(liv!=NULL){
                        printf("\nEscolha como Buscar o Livro:\n1 - Por Nome\n2 - Por Codigo\n3 - Por Q.Paginas\n");
                        scanf("%d", &op2);
                        if(op2 == 1){
                            printf("\nDigite a Nome do Livro p/ pesquisar:\n");
                            fflush(stdin);
                            fgets(nome, 30, stdin);
                            busca = (Livro*)abpQuery(l,(void*)nome,comNome);
                            if(busca!=NULL){
                                printf("\nO Livro pesquisado foi:\n");
                                printf("\nNOME:\t %s\n",busca ->nome);
                                printf("\nQUANTIDADE DE PAGINAS:\t %d\n",busca ->qpaginas);
                                printf("\nNUMERO DE EXEMPLARES:\t %d\n",busca ->nexemplares);
                                printf("\nPRECO:\t %.2f\n",busca ->preco);
                                printf("\nCODIGO:\t %ld\n",busca ->codigo);
                                printf("\n");
                                busca = NULL;
                                break;
                                system("cls");
                            }
                            else{
                                printf("\nEste Livro nao foi encontrado na Arvore!!\n");
                                busca = NULL;
                                break;
                                system("cls");
                            }
                        }
                        if(op2 == 2){
                            printf("\nDigite a Codigo do Livro p/ pesquisar:\n");
                            scanf("%ld",&codigo);
                            busca = (Livro*)abpQuery(l,(void*)codigo,comCodigo);
                            if(busca!=NULL){
                                printf("\nO Livro pesquisado foi:\n");
                                printf("\nNOME:\t %s\n",busca ->nome);
                                printf("\nQUANTIDADE DE PAGINAS:\t %d\n",busca ->qpaginas);
                                printf("\nNUMERO DE EXEMPLARES:\t %d\n",busca ->nexemplares);
                                printf("\nPRECO:\t %.2f\n",busca ->preco);
                                printf("\nCODIGO:\t %ld\n",busca ->codigo);
                                printf("\n");
                                busca = NULL;
                                break;
                                system("cls");
                            }
                            else{
                                printf("\nEste Livro nao foi encontrado na Arvore!!\n");
                                break;
                                system("cls");
                            }
                        }
                        if(op2 == 3){
                            printf("\nDigite a Quantidade de Paginas do Livro p/ pesquisar:\n");
                            scanf("%d",&qpaginas);
                            busca = (Livro*)abpQuery(l,(void*)qpaginas,comPaginas);
                              if(busca!=NULL){
                                printf("\nO Livro pesquisado foi:\n");
                                printf("\nNOME:\t %s\n",busca ->nome);
                                printf("\nQUANTIDADE DE PAGINAS:\t %d\n",busca ->qpaginas);
                                printf("\nNUMERO DE EXEMPLARES:\t %d\n",busca ->nexemplares);
                                printf("\nPRECO:\t %.2f\n",busca ->preco);
                                printf("\nCODIGO:\t %ld\n",busca ->codigo);
                                printf("\n");
                                busca = NULL;
                                break;
                                system("cls");
                              }
                              else{
                                printf("\nEste Livro nao foi encontrado na Arvore!!\n");
                                break;
                                system("cls");
                              }
                        }
                    }
                    else{
                        printf("\nSem elementos ainda na Arvore!!\n");
                        break;
                        system("cls");
                    }
                }
                else{
                    printf("\nIMPOSSIVEL CONSULTAR, Arvore ainda nao Criada!!\n");
                    break;
                    system("cls");
                }
                break;
            case 6:
                if(l!=NULL){
                    if(liv!=NULL){
                        op2 = 0;
                        printf("\nEscolha como Remover o Livro:\n1 - Por Nome\n2 - Por Codigo\n3 - Por Q.Paginas\n");
                        scanf("%d", &op2);
                        if(op2 == 1){
                            printf("\nDigite a Nome do Livro que quer remover:\n");
                            fflush(stdin);
                            fgets(nome, 30, stdin);
                            removeu = (Livro*)abpRemove(l,(void*)nome,comNome);
                            if(removeu!=NULL){
                                printf("\nO Livro:\n");
                                printf("\nNOME:\t %s\n",removeu ->nome);
                                printf("\nQUANTIDADE DE PAGINAS:\t %d\n",removeu ->qpaginas);
                                printf("\nNUMERO DE EXEMPLARES:\t %d\n",removeu ->nexemplares);
                                printf("\nPRECO:\t %.2f\n",removeu ->preco);
                                printf("\nCODIGO:\t %ld\n",removeu ->codigo);
                                printf("\nFOI REMOVIDO COM SUCESSO!!!\n");
                                printf("\n");
                                cont --;
                                removeu = NULL;
                                break;
                                system("cls");
                            }
                            else{
                                printf("\nEste Livro nao foi encontrado na Arvore!!\n");

                                break;
                                system("cls");
                            }
                        }
                        if(op2 == 2){
                            printf("\nDigite a Codigo do Livro que quer remover:\n");
                            scanf("%ld",&codigo);
                            removeu = (Livro*)abpRemove(l,(void*)codigo,comCodigo);
                            if(removeu!=NULL){
                                printf("\nO Livro:\n");
                                printf("\nNOME:\t %s\n",removeu ->nome);
                                printf("\nQUANTIDADE DE PAGINAS:\t %d\n",removeu ->qpaginas);
                                printf("\nNUMERO DE EXEMPLARES:\t %d\n",removeu ->nexemplares);
                                printf("\nPRECO:\t %.2f\n",removeu ->preco);
                                printf("\nCODIGO:\t %ld\n",removeu ->codigo);
                                printf("\nFOI REMOVIDO COM SUCESSO!!!\n");
                                printf("\n");
                                cont --;
                                removeu = NULL;
                                break;
                                system("cls");
                            }
                            else{
                                printf("\nEste Livro nao foi encontrado na Arvore!!\n");

                                break;
                                system("cls");
                            }
                          }
                            if(op2 == 3){
                                printf("\nDigite a Quantidade de Paginas do Livro que quer remover:\n");
                                scanf("%d",&qpaginas);
                                removeu = (Livro*)abpRemove(l,(void*)qpaginas,comPaginas);
                              if(removeu!=NULL){
                                printf("\nO Livro:\n");
                                printf("\nNOME:\t %s\n",removeu ->nome);
                                printf("\nQUANTIDADE DE PAGINAS:\t %d\n",removeu ->qpaginas);
                                printf("\nNUMERO DE EXEMPLARES:\t %d\n",removeu ->nexemplares);
                                printf("\nPRECO:\t %.2f\n",removeu ->preco);
                                printf("\nCODIGO:\t %ld\n",removeu ->codigo);
                                printf("\nFOI REMOVIDO COM SUCESSO!!!\n");
                                printf("\n");
                                cont --;
                                removeu = NULL;
                                break;
                                system("cls");
                              }
                              else{
                                printf("\nEste Livro nao foi encontrado na Arvore!!\n");
                                break;
                                system("cls");
                              }
                          }

                    }else{
                        printf("\nSem elementos ainda na Arvore!!\n");
                        break;
                        system("cls");
                    }
                }
                else{
                    printf("\nIMPOSSIVEL REMOVER, Arvore ainda nao Criada!!\n");
                    break;
                    system("cls");
                }
                break;
            case 7:
                printf("\nObrigada por usar o programa!\n");
                sllDestroy(l);
                break;
        }


    }while(op!=7);

    return 0;
}
#endif /// _main_c_
