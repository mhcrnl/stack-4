/* Author : Gopi Marella,
   Date : 11/01/2014..

	Stacks implementation using linkedlist 
*/

#include <limits.h>

typedef struct StackNode {
	int data;
	struct StackNode *next;
} StackNode;

#define STACK_SUCCESS 0
#define STACK_FAILURE INT_MIN

#define STACK_EMPTY 1
#define STACK_NOT_EMPTY 0

/* Basic operations on stack */

StackNode *CreateStack( );

int push(StackNode **, int );
int pop(StackNode **);
int top(StackNode *);
int isEmpty(StackNode *);
void print_stack(StackNode *);


/* Complex functions */

void reverse_stack(StackNode *);
