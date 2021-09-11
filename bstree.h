#ifndef _bstree_h_
    #define _bstree_h_
    #ifndef _bstree_c_
        typedef struct _t_node_ {
            void *item;
            struct t_node *left;
            struct t_node *right;
        }TNode;

        TNode *treeInsert(TNode *t, void *key, int (*cmp)(void *, void *));
        TNode *treeRemove(TNode* t, void *key, int(*cmp)(void*, void*), void **data);
        void *treeQuery(TNode *t, void *key, int(*cmp)(void*, void*));
        void *abpRemoveMenor(TNode *t, void **data);
        int treeDestroy(TNode *t);
    #else
        typedef struct t_node TNode;

        TNode *treeInsert(TNode* t, void *elm);
        void *treeRemove(TNode* t, void *key, int(*cmp)(void*, void*));
        void *treeQuery(TNode *t, void *key, int(*cmp)(void*, void*));
        void *abpRemoveMenor(TNode *t);
        int treeDestroy(TNode *t);
    #endif
#endif // _bstree_h_

