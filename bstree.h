#ifndef BSTREE_H_INCLUDED
#define BSTREE_H_INCLUDED
/*------------------------------------------------------------------------------
Especifica��o das opera��es do TAD ABB gen�rico:
------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
Estrutura _bstree_: Declara��o de tipo que cont�m as vari�veis que comp�em a ABB.
------------------------------------------------------------------------------*/
typedef struct _treeNode_ TNode;
#endif // _bstree_h_
#ifdef _BSTREE_C_

TNode* abpCreate();
void PreOrdem(TNode *tNode, void (*visit)(void *item));
void Simetrica(TNode *tNode, void (*visit)(void *item));
void PosOrdem(TNode *tNode, void (*visit)(void *item));
TNode* abpInsert(TNode* t, void*data, int (*cmp)(void*,void*));
TNode* abpRemove(TNode *t, void* key, void** data, int(*cmp)(void*, void*));
void* abpQuery(TNode *t, void *key, int(*cmp)(void*, void*));
int abpAltura(TNode* t);
int abpCountNodes(TNode *t);
int abpIsEmpty(TNode *t);

#else

extern TNode* abpCreate();
extern void PreOrdem(TNode *tNode, void (*visit)(void *item));
extern void Simetrica(TNode *tNode, void (*visit)(void *item));
extern void PosOrdem(TNode *tNode, void (*visit)(void *item));
extern TNode* abpInsert(TNode* t, void*data, int (*cmp)(void*,void*));
extern TNode* abpRemove(TNode *t, void* key, void** data, int(*cmp)(void*, void*));
extern void* abpQuery(TNode *t, void *key, int(*cmp)(void*, void*));
extern int abpCountNodes(TNode *t);
extern int abpIsEmpty(TNode *t);
extern int abpAltura(TNode* t);

#endif // BSTREE_H_INCLUDED
