#include "list.h"
/*
 Returns the value the length of the list
 Parse Once.
*/
int count_s_nodes(struct s_node* head){
	int len = 0;
	while(head != NULL){
		head = head->next;
		len++;
	}
	 return len;
}