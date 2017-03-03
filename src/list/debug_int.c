#include "list.h"
/*
 Prints all the elems as ints separated by a space in the format
 (NULL <- Elem -> Next elem), ..., (Previous elem <- Elem -> NULL) 
*/
void debug_int(struct s_node* head){
    if(head!=NULL){
		struct s_node* s = head;
		while(s != NULL){
		    my_str("(");
		    print_int(s->prev);
		    my_str(" <- ");
		    print_int(s);
		    my_str(" -> ");
		    print_int(s->next);
		    my_str(")");
		    if(s->next !=NULL){
		        my_str(", ");
		    }
			s = s->next;
		}
    }
}