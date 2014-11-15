//run the trees

#include "BSTree.h"
#include <assert.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	BSTree tree = newBSTree(5);
	assert(inTree(tree,5));
	insert(tree, 3);
	assert(inTree(tree,3));
	insert(tree, 7);
	assert(inTree(tree,7));
	insert(tree, 2);
	assert(inTree(tree,2));
	insert(tree, 4);
	assert(inTree(tree,4));
	insert(tree, 6);
	assert(inTree(tree,6));
	insert(tree, 8);
	assert(inTree(tree,8));

	prefixPrint(tree);

	dropTree(tree);
	return EXIT_SUCCESS;
}