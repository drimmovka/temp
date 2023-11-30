#include <stdlib.h>
#include <wchar.h>

#include "bst.h"


Node* createNode() {
    Node* n = (Node*) malloc(sizeof(Node));
    n->key = NULL;
    n->data = 0;
    n->left = NULL;
    n->right = NULL;
    return n;
}

Bst* createBst() {
    Bst* b = (Bst*) malloc(sizeof(Bst));
    b->root = NULL;
    return b;
}

void insertByNode(Node* n, wchar_t* k) {
    if (wcscmp(n->key, k) < 0) {
        if (n->right == NULL) {
            Node* new_node = createNode();
            new_node->key = k;
            new_node->data = 1;
            n->right = new_node;
        } else {
            insertByNode(n->right, k);
        }
    } else if (wcscmp(n->key, k) > 0) {
        if (n->left == NULL) {
            Node* new_node = createNode();
            new_node->key = k;
            new_node->data = 1;
            n->left = new_node;
        } else {
            insertByNode(n->left, k);
        }
    } else {
        n->data++;
    }
}

void insert(Bst* b, wchar_t* k) {
    if (b->root == NULL) {
        b->root = createNode();
        b->root->key = k;
        b->root->data = 1;
        return;
    }
    insertByNode(b->root, k);
}

int findByNode(Node* n, wchar_t* k) {
	if (n == NULL) {
		return 0;
	}
	if (wcscmp(n->key, k) < 0) {
		return findByNode(n->right, k);
	} else if (wcscmp(n->key, k) > 0) {
		return findByNode(n->left, k);
	}
	return n->data;
}

int find(Bst* b, wchar_t* k) {
	return findByNode(b->root, k);
}

void inorderTraversalByNode(Node* n) {
	if (n == NULL) {
		return;
	}
	inorderTraversalByNode(n->left);
	wprintf(L"%ls %d\n", n->key, n->data);
	inorderTraversalByNode(n->right);
}

void InorderTraversal(Bst* b) {
	inorderTraversalByNode(b->root);
}
