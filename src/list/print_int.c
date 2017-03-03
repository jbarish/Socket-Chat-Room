#include "list.h"
/*
 Prints the elem of node as a int
*/
void print_int(struct s_node* node){
    if(node !=NULL){
        my_int(*((int*)(node->elem)));
    }else{
		my_str("NULL");
	}
}