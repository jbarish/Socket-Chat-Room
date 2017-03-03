#include "my.h"

/*
 * copies string from source to destination up to n chars
 * assume dst has enough room
 * Handles if ptrs overlap
 */
char *my_strncpy(char *dst, char *src, int n){
	if(dst!=NULL && src !=NULL){
		/*get num iterations. if n > len of src, only do src. If n<0, do 0*/
		int len = (n>my_strlen(src)? my_strlen(src) : (n<0? 0 : n));
		int counter;

		/*if dst pointer is inside (or after src) */
		if(dst>src){
			src +=(len-1);
			dst +=len;
			*dst-- = '\0';
		
			for(counter = len;counter >0; counter--){
				*dst-- = *src--;
			}
			dst++;
		}else {
			/*if dst pointer is inside (or after src) */
			counter = 0;
			while (*src != '\0' && counter <len){
				*dst++ = *src++;
				counter++;
			}
			*dst= '\0';
			dst -=len;
		}
	}
	return dst;
}
