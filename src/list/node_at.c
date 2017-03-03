#include "list.h"
/*
 Returns a pointer to the node at index n or the last node.
 Parse once
*/
struct s_node* node_at(struct s_node* head, int n){
    if(head!=NULL){
		int counter = 0;
		struct s_node* s = head;
		while(s->next != NULL && counter < n){
			s = s->next;
			counter++;
		}
	    return s;
     }
     return NULL;
}