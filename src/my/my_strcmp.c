#include "my.h"
/* lexigraphically compares two strings
 * if equal, returns 0
 * if a>b, returns + num
 * if a<b, returns - num
 * NULL is less than string
 */
int my_strcmp(char *a, char *b){
	int maxLen = (my_strlen(a)>my_strlen(b) ? my_strlen(a) : my_strlen(b));
	int count = 0;
	int result = 0;
	if (a==NULL && b==NULL){
		result = 0;
	}else if(a==NULL){
		result = -1;
	} else if (b==NULL){
		result = 1;
	}else {
		while(result ==0 && count <maxLen){
			
			result = a[count] - b[count];
			if (result!= 0){
				return result;
			}else {
				count ++;
			}
		}
	}
	return result;
	
}