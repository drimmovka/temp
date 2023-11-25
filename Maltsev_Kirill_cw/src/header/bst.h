#ifndef BST_H
#define BST_H

typedef struct Node {
    char* key;
    int data;
    struct Node* left;
    struct Node* right;
} Node;

typedef struct {
    Node* root;
} Bst;

Bst* createBst();
void insert(Bst*, char*);
int find(Bst*, char*);
void InorderTraversal(Bst*);

#endif