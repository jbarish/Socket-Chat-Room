#include "list.h"
/*
 Returns a pointer to the elem at index n or the last node.
 Parse once.
*/
void* elem_at(struct s_node* head, int n){
    if(head!=NULL){
		int counter = 0;
		struct s_node* s = head;
		while(s->next != NULL && counter < n){
			s = s->next;
			counter++;
		}
	    return s->elem;
     }
     return NULL;
}