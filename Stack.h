//Stack.h interface

typedef struct _stack *Stack;

#define TRUE 1
#define FALSE 0

//make a new Stack
Stack newStack(void);

//pop an item off the Stack
int popStack(Stack s);

//push an item onto the stack
void pushStack(Stack s, int item);

//is the stack empty?
int stackEmpty(Stack s);

//kill the stack
void dropStack(Stack s);

//print the stack
void printStack(Stack s);