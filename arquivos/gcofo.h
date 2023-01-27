//ELIVELTON BOTELHO PINHEIRO - VISUAL STUDIO CODE 

#define TRUE 1
#define FALSE 0

typedef struct _cofo_ gCOFO;

gCOFO *gCofoCriar(int maxItens);
int gCofoInserir(gCOFO *gc, void* item);
void* gCofoRemover(gCOFO *gc, void* item, int (*cmp)(void*, void*));
void* gCofoBuscar(gCOFO *gc, void* item, int (*cmp)(void*, void*));
void* gCofoPrimeiro(gCOFO *gc);
void* gCofoProximo(gCOFO *gc);
int gCofoDestruir(gCOFO *gc);
int gCofoEsvaziar(gCOFO *gc);
int getNumItens(gCOFO *gc);