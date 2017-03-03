#include "my.h"

/*
 * copies string from source to destination
 * assume dst has enough room
 * Handles if ptrs overlap
 */
char *my_strcpy(char *dst, char *src){
	if(dst!=NULL && src !=NULL){
		int len = my_strlen(src);
		int counter;
		/*if dst pointer is inside (or after src) */
		if(dst>src){
			src +=(len-1);
			dst +=len;
			*dst-- = '\0';
		
			for(counter = len;counter >0; counter--){
				*dst-- = *src--;
			}
			/*need to add one back since did one too many subs*/
			dst++;
		}else {
			/*if dst pointer is inside (or after src) */
			while (*src != '\0'){
				*dst++ = *src++;
			}
			*dst= '\0';
			dst -=len;
		}
	}
	return dst;
}
