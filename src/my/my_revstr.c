#include "my.h"

/*
 * Reverse the string in place without creating a new string
 * if pointer is null, return -1
 * return the length of the reversed string
 * NOTE: this method changes the value of the string passed in
 */
int my_revstr(char* s){
	int len;
	int fwrd;
	int bckwd;
	char temp;
	if(s==NULL){
		return -1;
	}
	len = my_strlen(s);
	fwrd = 0;
	bckwd = len-1;
	/* if fwrd= bckwd , then all things were successfully switched.
		if fwd>bckwrd, then was even-lengthed string and already switched everything */
	while(fwrd!=bckwd && fwrd<bckwd){
		temp = *(s+bckwd);
		*(s+bckwd) = *(s+fwrd);
		*(s+fwrd) = temp;
		fwrd++;bckwd--;
	}
	return len;
}