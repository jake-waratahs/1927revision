//Binary search tree interface

#define TRUE 1
#define FALSE 0

typedef struct _BSTree *BSTree;

//Makes a new tree
BSTree newBSTree(int root);

//Returns TRUE or FALSE if an item is in the tree
int inTree(BSTree tree, int item);

//Inserts an item
void insert(BSTree tree, int item);

//Kill the tree
void dropTree(BSTree tree);

//Print prefix order
void prefixPrint(BSTree tree);

//Print infix order
void infixPrint(BSTree tree);

//Print postfix order
void postfixPrint(BSTree tree);