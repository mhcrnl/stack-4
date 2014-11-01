/* Author: Gopi Marella,
   Date : 11/01/2014.

*/

#include<stdio.h>
#include"stack_ll.h"


int main() {

	StackNode *mystack = CreateStack();
	push(&mystack, 2);
	push(&mystack, 1);
	push(&mystack, 3);
	print_stack(mystack);
	printf("Reversing the stack.\n");
	reverse_stack(mystack);
	print_stack(mystack);
	return 0;
}
