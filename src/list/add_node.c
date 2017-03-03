#include "list.h"
/*
 Inserts a node at the start of the list. DO NOT add a NULL pointer or
 a node with a NULL elem.
 DOES NOT PARSE
*/
void add_node(struct s_node* node, struct s_node** head){
	if(node != NULL && node->elem !=NULL && head !=NULL  ){
		/*if list is not empty... */
		if(*head !=NULL){
			/*if not first thing in list*/
			if((*head)->prev!=NULL){
				((*head)->prev)->next = node;
				node->prev = (*head)->prev;				
			}else {
				/*if first thing in list, then set prev to NULL*/
				node->prev = NULL;
			}
			/*link old head with new node. old head is now after new node*/
			(*head)->prev = node;
			node->next = (*head);			
		}else {
			/*if was first thing in list, then set new node's prev and next to null*/
			node->next = NULL;
			node->prev = NULL;
		}
		/*change head pointer to now point to the newly added node*/
		(*head) = node;
	}
}