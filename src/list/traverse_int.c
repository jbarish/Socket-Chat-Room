#include "list.h"
/*
 Prints all the elems as ints separated by a space
*/
void traverse_int(struct s_node* head){
    if(head!=NULL){
		struct s_node* s = head;
		while(s != NULL){
		    print_int(s);
			my_char(' ');
			s = s->next;
		}
    }
}