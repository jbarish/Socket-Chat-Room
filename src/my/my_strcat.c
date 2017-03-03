#include "my.h"
/* concatinates the given src string to the end of dst string 
 * assume dst has enough memory
 */
char *my_strcat(char *dst, char *src){
	if(dst !=NULL && src !=NULL){
		int totalLen = my_strlen(src) +my_strlen(dst);
		/*move dst pointer to end of dst string (signalled by null) */
			dst = dst + my_strlen(dst);
			while(*src!='\0'){
				*dst = *src;
				dst++;
				src++;
			}
			*dst = '\0';
			dst -= totalLen;
	}
	return dst;
}