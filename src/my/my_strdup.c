#include "my.h"
/* duplicates the given string into a newly allocated piece of memory */
char *my_strdup(char *str){
	if(str != NULL){
		int len = my_strlen(str);
		char* nstr = (char*) malloc(sizeof(char)*len+1);
		while (*str != '\0'){
			*nstr = *str;
			nstr++;
			str++;
		}
		*nstr = '\0';
		nstr -= len;
		return nstr;
	}
	return NULL;
	
}