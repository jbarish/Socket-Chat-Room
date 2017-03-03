#include "my.h"

/* get the length of the string
 * if pointer is null, return -1
 * else return length of string 
 */
int my_strlen(char* c){
	int len;
	len =0;
	if(c ==NULL){
		len =-1;
	}else {
		while(*c!= '\0'){
			len++;
			c++;
		}
		
	}
	return len;
	
}