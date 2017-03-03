#include "list.h"
/*
 Adds a node at index n of a list or at the end of the list if n is 
 too large.
 Parse once
*/
void add_node_at(struct s_node* node, struct s_node** head, int n){
	
	/* if we want to add to top, use the add_node method, which does exactly that */
	if(n<=0){
		add_node(node, head);
	}else if(node != NULL && node->elem !=NULL && head !=NULL  ){
		/*if list is not empty */
		if(*head !=NULL){
			int counter = 1;
			struct s_node* s = *head;
			while(s->next != NULL && counter < n){
				s = s->next;
				counter++;
			}
			/*not at end of list, link input node to next one */
			if(s->next !=NULL){
				node->next = s->next;
				(s->next)->prev = node;
				
			}else {
				node->next = NULL;
				
			}
			/*link to previous one*/
			
			s->next = node;
			node->prev = s;
			
		}else {
			/*no nodes yet in list*/
			(*head) = node;
			node->next = NULL;
			node->prev =NULL;
		}
	}
}