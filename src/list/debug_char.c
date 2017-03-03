#include "list.h"
/*
 Prints all the elems as chars separated by a space in the format
 (NULL <- Elem -> Next elem), ..., (Previous elem <- Elem -> NULL) 
*/
void debug_char(struct s_node* head){
    if(head!=NULL){
		struct s_node* s = head;
		while(s != NULL){
		    my_str("(");
		    print_char(s->prev);
		    my_str(" <- ");
		    print_char(s);
		    my_str(" -> ");
		    print_char(s->next);
		    my_str(")");
		    if(s->next !=NULL){
		        my_str(", ");
		    }
			s = s->next;
		}
    }
}