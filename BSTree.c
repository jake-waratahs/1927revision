//Implementation of binary search tree
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "BSTree.h"

struct _BSTree
{
	int item;
	BSTree left;
	BSTree right;
};

static void realInsert(BSTree tree, int item);

BSTree newBSTree(int root){
	BSTree new = malloc(sizeof(struct _BSTree));
	assert(new != NULL);
	new->item = root;
	new->left = NULL;
	new->right = NULL;
	return new;
}

int inTree(BSTree tree, int item){
	if (tree == NULL){
		return FALSE;
	} else if (tree->item == item){
		return TRUE;
	}

	if (tree->item > item){
		return inTree(tree->left, item);
	} else {
		return inTree(tree->right, item);
	}
}

void insert(BSTree tree, int item){
	if (!inTree(tree, item)){
		realInsert(tree, item);
	}
}

static void realInsert(BSTree tree, int item){
	if (item < tree->item){
		if (tree->left == NULL){
			tree->left = newBSTree(item);
			return;
		}

		insert(tree->left, item);
	} else {
		if (tree->right == NULL){
			tree->right = newBSTree(item);
			return;
		}

		insert(tree->right, item);
	}
}

void dropTree(BSTree tree){
	if (tree == NULL){
		return;
	} else if (tree->left == NULL && tree->right==NULL){
		free(tree);
		return;
	}
	dropTree(tree->left);
	dropTree(tree->right);
}

void prefixPrint(BSTree tree){
	if (tree == NULL){
		return;
	}

	printf("%d ", tree->item);
	prefixPrint(tree->left);
	prefixPrint(tree->right);
}

void infixPrint(BSTree tree){
	if (tree == NULL){
		return;
	}
	infixPrint(tree->left);
	printf("%d ", tree->item);
	infixPrint(tree->right);
}

void postfixPrint(BSTree tree){
	if (tree == NULL){
		return;
	}
	postfixPrint(tree->left);
	postfixPrint(tree->right);
	printf("%d\n", tree->item);
}