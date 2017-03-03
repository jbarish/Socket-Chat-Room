#include "list.h"
/*
 Removes the last node from the list.
 Parse Once.
*/
void* remove_last(struct s_node** head){
	void* tempElem = NULL;
	if(head!=NULL && *(head)!= NULL){
		struct s_node* s = *head;
			while(s->next != NULL){
				s = s->next;
			}
		
		if(s->prev==NULL){
			/*if only thing in list*/
			*head = NULL;
		}else{
			(s->prev)->next = NULL;
		}
		tempElem = s->elem;
		free(s);
	}
	return tempElem;
}