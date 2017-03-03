#include "my.h"
/* Get the pointer to the last occurance of char c in string s
 * if string is null, return NULL
 * else return the pointer to the last occurance of char c in s
 */
char* my_strrfind(char* c, char ch){
	int end;
	if (c!= NULL){
		 end = my_strlen(c);
		while (end>= 0){
			if (c[end] ==ch){
				return c+end;
			}
			end--;
		}
	}
	return NULL;

}