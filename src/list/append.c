#include "list.h"
/*
 Adds a node to the end of a list. DO NOT add a NULL pointer or
 a node with a NULL elem.
 Parse once
*/
void append(struct s_node* node, struct s_node** head){
	if(node != NULL && node->elem !=NULL && head !=NULL  ){
		/*list is not empty */
		if(*head !=NULL){
			struct s_node* s = *head;
			while(s->next != NULL){
				s = s->next;
			}
			s->next = node;
			node->prev = s;
			node->next = NULL;
		}else {
			/*list is empty; just use add_node method for this*/
			add_node(node, head);
		}
	}
}