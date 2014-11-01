/* Author: Gopi Krishna Marella
   Date : 11/01/2014....

	Stack is a last-in-first-out (LIFO) data structure.
	This c file contains the implementation of the stacks using linkedlists.
	Data is always pushed/popped at the head of the list.
	Basic operations such as CreateStack, Push, Pop, top and isEmpty are defined.

*/

#include<stdio.h>
#include<stdlib.h>

#include"stack_ll.h"

StackNode *CreateStack() {
	/* As of now set the stack pointer to NULL, stack doesnt have any nodes. */
	return NULL;
}

inline int isEmpty(StackNode *top) {
	if(top == NULL) {
		return STACK_EMPTY;
	} else {
		return STACK_NOT_EMPTY;
	}
}

int push(StackNode **top, int data) {

	StackNode *temp=(StackNode *)malloc(sizeof(StackNode));
	if(NULL == temp) {
		printf("Memory allocation failed in Push operation.\n");
		return STACK_FAILURE;
	}
	temp->data = data;
	temp->next = *top;
	*top=temp;
	return STACK_SUCCESS;
}

int pop(StackNode **top) {
	if (STACK_EMPTY== isEmpty(*top)) {
		//Empty stack, return INT_MIN
		printf("Stack is empty, no element can be popped.\n");
		return STACK_FAILURE;
	}
	StackNode *temp = *top;
	int data = temp->data;
	*top=temp->next;
	free(temp);
	return data;
}

int top(StackNode *top) {
	if(isEmpty(top) == STACK_EMPTY) {
		return INT_MIN;
	} else {
		return top->data;
	}
}

void print_stack(StackNode *top) {
	while(top!=NULL) {
		printf("%d \n",top->data);
		printf("---\n");
		top=top->next;
	}
}


/* Reversing a stack using only the stack operations. Idea is to recusively reversing the list and inserting the element
at the bottom once the below stack part is reversed*/

/*Helper function to insert the current element at the bottom of the stack*/
static void Insert_at_bottom(StackNode **top, int data){
	if(isEmpty(*top) == STACK_EMPTY) {
		/* Now, all the elements of the stack are popped in each of the previous recursion steps,
		and element that has to be insrted at the bottom is passed along. Just push that element on to the stack*/
		push(top,data);
		return;
	}
	int curr_data = pop(top);
	Insert_at_bottom(top, data);
	push(top,curr_data);
}

void reverse_stack(StackNode *top) {
	if(isEmpty(top) == STACK_EMPTY) {
		return ;
	}
	int data = pop(&top);
	reverse_stack(top); // top is already changed in the previous pop operation, top=top->next 
	/*now the stack before me is properly reversed, just insert the element at the bottom.*/
	Insert_at_bottom(&top,data);

}
