#include "list.h"
/*
 Removes the node at index n or the last node.
 Parse once
*/
void* remove_node_at(struct s_node** head, int n){
	void* tempElem = NULL;
	if(n<=0){
		tempElem = remove_node(head);
	} else if(head!=NULL && *(head)!= NULL){
		int counter = 0;
		struct s_node* s = *head;
		while(s->next != NULL && counter < n){
			s = s->next;
			counter++;
		}
		/*not at end of list, link input node's prev to next one */
		tempElem = s->elem;
		if(s->next !=NULL){
			(s->next)->prev = (s->prev);
		}
		if(s->prev !=NULL){
			(s->prev)->next = (s->next);
		}else {
			*head = NULL;
		}
		free(s);
	}
	return tempElem;
}