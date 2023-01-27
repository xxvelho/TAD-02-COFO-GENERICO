//ELIVELTON BOTELHO PINHEIRO - VISUAL STUDIO CODE 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gcofo.h"

typedef struct _aluno_{
    char nome[30];
    int matricula;
    float nota;
}ALUNO;

int cmpNome(void* a, void* b);
int cmpMatricula( void *a, void *b);
int cmpNota(void *a, void *b);

int main (){
    gCOFO *cofo;
    int tamanhoCofo;
    
    while(TRUE){
        printf("Digite tamanho da colecao: ");
        scanf("%d", &tamanhoCofo);
        getchar();
        if(tamanhoCofo < 1){
            printf("Digite um valor maior que 0\n");
        }else{
            break;
        }
    }
    cofo = gCofoCriar(tamanhoCofo);
    if(cofo != NULL){
        ALUNO *a;
        int opcao = -1, opcao2 = -1, opcao3 = -1;
        int deuCerto;
        ALUNO *aux;
        int tempMatricula;
        char *tempNome;
        float tempNota;
        while(TRUE){
            printf("\t---MENU PRINCIPAL---\t");
            printf("\n1 - INSERIR\n");
            printf("2 - REMOVER\n");
            printf("3 - VERIFICAR\n");
            printf("4 - MOSTRE MEU COFO\n");
            printf("5 - ESVAZIAR COFO\n");
            printf("6 - APAGAR COFO\n");
            scanf("%d", &opcao);
            getchar();
            switch (opcao){
                case 1:
                    printf("\nInsira um elemento no Cofo:\n");
                    a = (ALUNO*)malloc(sizeof(ALUNO));
                    printf("NOME: ");
                    scanf("%s", a->nome);
                    getchar();
                    printf("MATRICULA E NOTA: ");
                    scanf("%d %f", &a->matricula, &a->nota);
                    getchar();
                    deuCerto = gCofoInserir(cofo, (void*)a);
                    if(deuCerto){
                        printf("\nValor inserido no Cofo.\n");
                    }else{
                        printf("\nValor nao foi inserido no Cofo.\n");
                    }
                    break;

                case 2:
                    printf("Por qual campo vc deseja verificar e remover na colecao?\n");
                    printf("\n1 - Nome");
                    printf("\n2 - Matricula");
                    printf("\n3 - Nota\n");
                    scanf("%d", &opcao2);
                    getchar();
                    
                    switch (opcao2){
                    case 1:
                        printf("Digite o nome: ");
                        scanf("%s", tempNome);
                        getchar();
                        aux = (ALUNO*) gCofoRemover(cofo, (void*) &tempNome, cmpNome);
                        printf("Removido da colecao %s - %d - Nota:%.2f\n", aux->nome, aux->matricula, aux->nota);
                        break;
                    case 2:
                        printf("Digite a matricula: ");
                        scanf("%d", &tempMatricula);
                        getchar();
                        aux = (ALUNO*) gCofoRemover(cofo, (void*) &tempMatricula, cmpMatricula);
                        printf("Removido da colecao %s - %d - Nota:%.2f\n", aux->nome, aux->matricula, aux->nota);
                        break;
                    case 3:
                        printf("Digite a nota: ");
                        scanf("%f", &tempNota);
                        getchar();
                        aux = (ALUNO*) gCofoRemover(cofo, (void*) &tempNota, cmpNota);
                        printf("Removido da colecao %s - %d - Nota:%.2f\n", aux->nome, aux->matricula, aux->nota);
                        break;
                    default:
                        printf("\nNao foi possivel realizar a operacao.\n");
                        break;
                    }

                    break;

                case 3:
                    printf("Por qual campo vc deseja verificar na colecao?\n");
                    printf("\n1 - Nome");
                    printf("\n2 - Matricula");
                    printf("\n3 - Nota\n");
                    scanf("%d", &opcao3);
                    getchar();
                    
                    switch (opcao3){
                    case 1:
                        printf("Digite o nome: ");
                        scanf("%s", tempNome);
                        getchar();
                        aux = (ALUNO*) gCofoBuscar(cofo, (void*) &tempNome, cmpNome);
                        printf("Estava na colecao %s - %d - Nota:%.2f\n", aux->nome, aux->matricula, aux->nota);
                        break;
                    case 2:
                        printf("Digite a matricula: ");
                        scanf("%d", &tempMatricula);
                        getchar();
                        aux = (ALUNO*) gCofoBuscar(cofo, (void*) &tempMatricula, cmpMatricula);
                        printf("Estava na colecao %s - %d - Nota:%.2f\n", aux->nome, aux->matricula, aux->nota);
                        break;
                    case 3:
                        printf("Digite a nota: ");
                        scanf("%f", &tempNota);
                        getchar();
                        aux = (ALUNO*) gCofoBuscar(cofo, (void*) &tempNota, cmpNota);
                        printf("Estava na colecao %s - %d - Nota:%.2f\n", aux->nome, aux->matricula, aux->nota);
                        break;
                    default:
                        printf("\nNao foi possivel realizar a operacao.\n");
                        break;
                    }
                    
                    break;

                case 4:
                    if(getNumItens > 0){
                        for(int i=0; i < getNumItens(cofo); i++){
                            printf("[Nome: %s - Matricula: %d - Nota: %.2f]\n", a->nome, a->matricula, a->nota);
                        }
                    }else{
                        printf("\nColecao vazia\n");
                    }
                    break;

                case 5:
                    deuCerto = gCofoEsvaziar(cofo);
                    
                    if(deuCerto){
                        printf("\nCofo vazio.\n");
                    }else{
                        printf("\nNao foi possivel esvaziar o Cofo.\n");
                    }
                    break;

                case 6:
                    deuCerto = gCofoDestruir(cofo);
                    if(deuCerto){
                        printf("O Cofo foi excluido. Ate logo!\n");
                        return 0;
                    }else{
                        printf("Nao foi possivel apagar o Cofo!\n");
                        break;
                    }
                    break;

                default:
                    printf("Opção Invalida");
                    break;
            }

        }

    }

    printf("Não foi possivel criar o cofo\n");


    return 0;
}

int cmpNome( void *a, void *b) {
    ALUNO *pa; 
    char *pnome;
    pa = (ALUNO*)a;
    pnome = (char *)b;

    int flag = strcmp(pa->nome, pnome);
    if (flag == 0){
        return TRUE;
    }else{
        return FALSE;
    }
}

int cmpMatricula( void *a, void *b){
    int *matr = (int *) a;
    ALUNO *aluno = (ALUNO *)b;
    if (aluno->matricula == *matr) {
        return TRUE;
    }else{
        return FALSE;
    }
}

int cmpNota(void *a, void *b){
    ALUNO *pa; int *pnota;
    pa = (ALUNO *)a;
    pnota = (int *)b;
    if(pa->nota == *pnota) {
        return TRUE;
    }else{
        return FALSE;
    }
}