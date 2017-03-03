#include "list.h"
/*
 Prints the elem of node as a char
*/
void print_char(struct s_node* node){
     if(node !=NULL){
        my_char(*((char*)(node->elem)));
    }else{
		my_str("NULL");
	}
}