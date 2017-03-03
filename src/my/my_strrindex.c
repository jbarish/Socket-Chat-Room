#include "my.h"

/* get the index of the last occurance of char c in s
 * if pointer is null, return -1
 * else return the last position of char c in s
 */
int my_strrindex(char* s, char c){
	
	int end;
	if (s!= NULL){
		 end = my_strlen(s);
		while (end>= 0){
			if (s[end] ==c){
				return end;
			}
			end--;
		}
	}
	return -1;

}
/*	
	
	
	
	
	
	
	
	
	
	
	int pos;
	int found;
	int len;
	if(s == NULL){
		return -1;
	}else {
		len = my_strlen(s);
		*/
		/*start at end, so add length of string to both position counter and string pointer*/
		/* s+=len-1;
		found = 0;
		for(pos = (len-1);found==0 && pos>=0; s--, pos--){
			if (*s==c){
				found = 1;
			
				pos++; will decrement by nature of for, but we don't want it to.*/
				/*
			}
		}
		if(!found){
			pos = -1;
		}
		return pos;
	}
}*/