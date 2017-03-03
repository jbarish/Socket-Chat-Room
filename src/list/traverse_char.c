#include "list.h"
/*
 Prints all the elems as chars separated by a space
*/
void traverse_char(struct s_node* head){
    if(head!=NULL){
		struct s_node* s = head;
		while(s != NULL){
		    print_char(s);
			my_char(' ');
			s = s->next;
		}
    }
}