#include "list.h"
/* 
 Removes the first node from the list. Returns elem and frees the 
 node from memory.
 DOES NOT PARSE.
*/
void* remove_node(struct s_node** node){
	void* tempElem = NULL;
	if(node!=NULL && *(node)!= NULL){
		struct s_node* temp = *node;
		tempElem = temp->elem;
		/*if not only elem in list */
		if(temp->next!=NULL){
			(temp->next)->prev = temp->prev;
		}if(temp->prev!=NULL){
			(temp->prev)->next =temp->next; 
		}
		*node = temp->next;
		free (temp);	
	}
	return tempElem;
}