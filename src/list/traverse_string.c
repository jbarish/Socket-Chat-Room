#include "list.h"
/*
 Prints all the elems as strings separated by a space
*/
void traverse_string(struct s_node* head){
    if(head!=NULL){
		struct s_node* s = head;
		while(s != NULL){
		    print_string(s);
			my_char(' ');
			s = s->next;
		}
    }
}