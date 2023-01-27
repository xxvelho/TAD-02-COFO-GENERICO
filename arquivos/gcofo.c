//ELIVELTON BOTELHO PINHEIRO - VISUAL STUDIO CODE 

#include <stdio.h>
#include <stdlib.h>
#include "gcofo.h"


typedef struct _cofo_{
  int maxItens;
  int numItens;
  int cur;
  void* *itens;
}gCOFO;

gCOFO *gCofoCriar(int maxItens){
    gCOFO *gc;
    if(maxItens > 0){
        gc = (gCOFO*) malloc(sizeof(gCOFO));
        if(gc != NULL){
            gc->itens = (void**) malloc((int) sizeof(void*) * maxItens);
            if(gc->itens != NULL){
                gc->cur = -1;
                gc->maxItens = maxItens;
                gc->numItens = 0;
                return gc;
            }
            free(gc);
        }
    }
    return NULL;
}

int gCofoDestruir(gCOFO *gc){
    if(gc != NULL){
        if(gc->numItens == 0){
            free(gc->itens);
            free(gc);
            return TRUE;
        }
    }
    return FALSE;
}

int gCofoEsvaziar(gCOFO *gc){
    if(gc != NULL){
        gc->numItens = 0;
        return TRUE;
    }
    return FALSE;
}

int gCofoInserir(gCOFO *gc, void* item){
    if(gc != NULL){
        if(gc->numItens < gc->maxItens){
            gc->itens[gc->numItens] = item;
            gc->numItens++;
            return TRUE;
        }
    }
    return FALSE;
}

void* gCofoPrimeiro(gCOFO *gc){
    if(gc != NULL){
        if(gc->numItens > 0){
            gc->cur = 0;
            return gc->itens[0];
        }
    }
    return NULL;
}

void* gCofoProximo(gCOFO *gc){
    if(gc != NULL){
        if(gc->numItens > 0 && gc->cur < gc->numItens-1){
            gc->cur++;
            return gc->itens[gc->cur];
        }
    }
    return NULL;
}

void* gCofoBuscar(gCOFO *gc, void* item, int ((*cmp)(void*, void*))){
    int i, stat = FALSE;
    void * data;
    if(gc != NULL){
        if(gc->numItens > 0){
            i=0;
            stat = cmp(item, gc->itens[i]);
            while (i < gc->numItens && stat != TRUE){
                i++;
                stat = cmp(item, gc->itens[i]);
            }
            if(stat == TRUE){
                data = gc->itens[i];
                return data;
            }
        }
    }
    return NULL;
}

void* gCofoRemover(gCOFO *gc, void* item, int ((*cmp)(void*, void*))){
    int i, stat = FALSE;
    void* data;
    if(gc != NULL){
        if(gc->numItens > 0){
            i=0;
            stat = cmp(item, gc->itens[i]);
            while (i < gc->numItens && stat != TRUE){
                i++;
                stat = cmp(item, gc->itens[i]);
            }
            if(stat == TRUE){
                data = gc->itens[i];
                for(int j=i; j<gc->numItens-1; j++){
                    gc->itens[j] = gc->itens[j+1];
                }
                gc->numItens--;
                return data;
            }
        }
    }
    return NULL;
}

int getNumItens(gCOFO *gc){
    if (gc != NULL){
        return gc->numItens;
    }
    return FALSE;
}