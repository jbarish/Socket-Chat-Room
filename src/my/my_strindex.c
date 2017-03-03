#include "my.h"

/* Get the index of the first occurance of char c in string s
 * if string is null, return -1
 * else return the first occurance of char c in s
 */
int my_strindex(char* s, char c){
	
	int counter = 0;
	int len = my_strlen(s);
	if (s!= NULL){
		while (counter <=len){
			if (s[counter] == c){
				return counter;
			}
			counter++;
		}
	}
	return -1;
}
	
	
	
	
	/*
	
	
	
	
	int pos;
	int found;
	if(s == NULL){
		return -1;
	}else {
		 found = 0;
		for(pos=0;found==0 && *s!='\0'; s++, pos++){
			if (*s==c){
				found = 1;
				*/
				/*will increment by nature of for loop, but we don't want it to.*/
				/*
				pos--;
			}
		}
		if(!found){
			pos = -1;
		}
		return pos;
	}
}*/