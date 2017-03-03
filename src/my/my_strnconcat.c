#include "my.h"
/* concatinates the given src and dst string to new string, up to n chars
 * allocates memory, and returns pointer to it
 */
char *my_strnconcat(char *a, char *b, int n){
	if(a!=NULL || b !=NULL){
		int count =0;
		char* newString;
		int lena = my_strlen(a);
		int lenb = my_strlen(b);
		int totalLen;
		
		if(n<lenb){
			if(n<0){
				n = 0;
			}
			totalLen = lena + n;
		}else {
			totalLen = lena +lenb;
		}
		
		/*because a NULL pointer has a strlen of -1, add one back */
		if(a==NULL || b==NULL){
			totalLen +=1;
		}
		 newString = (char*)malloc(sizeof(char*)*totalLen +1);
		while (a!=NULL && *a != '\0'){
			*newString= *a;
			newString ++;
			a++;
		}while (b!=NULL && *b!= '\0' && count <n){
			*newString = *b;
			newString++;
			b++;
			count++;
		}
		*newString = '\0';
		return newString-totalLen;
		 
	} 
	return NULL;
}