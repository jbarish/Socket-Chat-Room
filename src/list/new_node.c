#include "list.h"

/*
 Allocates and returns a new node with the given pointers. You may
 create nodes with NULLs.
*/
struct s_node* new_node(void* elem, struct s_node* next, struct s_node* previous){
	struct s_node* s= (struct s_node*)malloc(sizeof(struct s_node));
	s->next =next;
	s->prev = previous;
	s->elem = elem;
	return s;
}