#include "list.h"
/*
 Prints all the elems as strings separated by a space in the format
 (NULL <- Elem -> Next elem), ..., (Previous elem <- Elem -> NULL) 
*/
void debug_string(struct s_node* head){
    if(head!=NULL){
		struct s_node* s = head;
		while(s != NULL){
		    my_str("(");
		    print_string(s->prev);
		    my_str(" <- ");
		    print_string(s);
		    my_str(" -> ");
		    print_string(s->next);
		    my_str(")");
		    if(s->next !=NULL){
		        my_str(", ");
		    }
			s = s->next;
		}
    }
}