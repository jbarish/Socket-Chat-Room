#include "my.h"
/* Get the pointer to the first occurance of char c in string s
 * if string is null, return NULL
 * else return the pointer to the first occurance of char c in s
 */
char* my_strfind(char* c, char ch){
	int counter = 0;
	int len = my_strlen(c);
	if (c!= NULL){
		while (counter <=len){
			if (c[counter] == ch){
				return c+counter;
			}
			counter++;
		}
	}
	return NULL;

}