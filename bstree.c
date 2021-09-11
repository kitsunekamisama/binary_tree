#define _BSTREE_C_
#include <stdio.h>
#include <stdlib.h>
#include "bstree.h"
#define TRUE 1
#define FALSE 0

typedef struct _treeNode_ {
    struct _treeNode_ *l, *r;
    void *data;
} TNode;

void PreOrdem(TNode *t, void (*visit)(void *)){
    if (t != NULL){
        visit(t->data);
        PreOrdem(t->l, visit);
        PreOrdem(t->r, visit);
    }
}


void Simetrica(TNode *t, void (*visit)(void *)){
    if (t != NULL){
        Simetrica(t->l, visit);
        visit(t->data);
        Simetrica(t->r, visit);
    }
}


void PosOrdem(TNode *t, void (*visit)(void *)){
    if (t != NULL){
        PosOrdem(t->l, visit);
        visit(t->data);
        PosOrdem(t->r, visit);
    }
}

TNode* abpCreate(TNode *t){
    TNode* raiz = (TNode*) malloc(sizeof(TNode));
    if(t != NULL){
        t = NULL;
    }
    return raiz;
}

TNode* abpInsert(TNode* t, void*data, int (*cmp)(void*,void*)){
    int stat;
    TNode *newt;
    if(t!= NULL){
        stat = cmp(data, t->data);
        if(stat < 0){
            t->l = abpInsert(t->l,data, cmp);
        }else{
            t->r = abpInsert(t->r,data, cmp);
        }
        return t;
    }else{
        newt=(TNode*)malloc(sizeof(TNode));
        if (newt != NULL){
            newt->data = data;
            newt->l = NULL;
            newt->r = NULL;
            return newt;
        }
    }
    return NULL;
}


TNode* removeMaiorArvore(TNode* t, void** data){
    if(t!= NULL){
        if(t->r != NULL){
            t->r = removeMaiorArvore(t->r, data);
            return t;
        }else{
            *data = t->data;
            return t->l;
        }
    }
    return NULL;
}


TNode* abpRemove(TNode *t, void* key, void** data, int(*cmp)(void*, void*)){
    TNode* curt;
    void* dataMaiorSubArvoreEsq;
    int stat;
    if(t != NULL){

        stat = cmp(key, t->data);
        if(stat < 0){
            t->l = abpRemove(t->l, key, data, cmp);
            return t;
        }else if(stat > 0){
            t->r = abpRemove(t->r, key, data, cmp);
            return t;
        }else if(stat == 0){
            *data = t->data;
            if(t->l == NULL && t->r == NULL){
                free(t);
                return NULL;
            }else if(t->l == NULL && t->r != NULL){
                curt = t->r;
                free(t);
                return curt;
            }else if(t->l != NULL && t->r == NULL){
                curt = t->l;
                free(t);
                return curt;
            }else{
                t->l = removeMaiorArvore(t->l, &dataMaiorSubArvoreEsq);
                t->data = dataMaiorSubArvoreEsq;
                return t;
            }
        }
    }
    return NULL;
}

void* abpQuery(TNode *t, void *key, int(*cmp)(void*, void*)){
    int stat;
    if(t != NULL){
        stat = cmp(key, t->data);
        if(stat == 0){
            return t->data;
        }else if(stat < 0){
            return abpQuery(t->l, key, cmp);
        }else{
            return abpQuery(t->r, key, cmp);
        }
    }
    return NULL;
}


int abpAltura(TNode* t){
    int h, hl, hr;
    if(t != NULL){
        hl = abpAltura(t->l);
        hr = abpAltura(t->r);
        if(hl > hr){
            h = 1 + hl;
        }else{
            h = 1 + hr;
        }
        return h;
    }
    return 0;
}

int abpCountNodes(TNode *t){
    int nl, nr;
    if(t != NULL){
        nl = abpCountNodes(t->l);
        nr = abpCountNodes(t->r);
        return 1 + nl + nr;
    }
    return 0;
}

int abpCountLeafNodes(TNode *t){
    int nl, nr, leaf = 0;
    if(t != NULL){
        nl = abpCountLeafNodes(t->l);
        nr = abpCountLeafNodes(t->r);
        if(t->l == NULL && t->r == NULL){
            leaf = 1;
        }
        return nl + nr + leaf;
    }
    return 0;
}

int abpIsEmpty(TNode *t){
    if(t == NULL){
        return TRUE;
    }
    return FALSE;
}
