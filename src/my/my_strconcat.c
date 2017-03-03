#include "my.h"
/* concatinates the given src and dst string to new string
 * allocates memory, and returns pointer to it
 */
char *my_strconcat(char *a, char *b){
	if(a!=NULL || b !=NULL){
		char* newString;
		int len = my_strlen(a) + my_strlen(b);
		/*because a NULL pointer has a strlen of -1, add one back */
		if(a==NULL ||b==NULL){
			len +=1;
		}
		 newString= (char*)malloc(sizeof(char*)*len +1);
		 *newString = '\0';
		return my_strcat(my_strcat(newString, a), b);
		 
	} 
	return NULL;
}