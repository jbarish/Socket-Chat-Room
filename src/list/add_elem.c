#include "list.h"
/* 
 Creates a new node with elem and adds it to head. DO NOT add a NULL 
 elem.
 DOES NOT PARSE
*/
void add_elem(void* elem, struct s_node** head){
	if(elem!= NULL && head!=NULL){
		add_node(new_node(elem, NULL, NULL), head);
	}
}