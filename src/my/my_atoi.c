#include "my.h"
/*Given a string, ignore preceding chars, and extract int
 * once hit another char, stop extracting int and return
 * handles negatives; odd num of negs = neg number, even num = positive num */
int my_atoi(char* c){
	int ans = 0;
	int s =0; /*{PREFIX = 0, NUM = 1, DONE =2}; */
	if(c !=NULL){
		int numNegs = 0;
		
		while(*c != '\0' && s!=2){
			/* if char is a number, then set state flag (s) to begin parsing number*/
			if(*c >= '0' && *c <= '9'){
				s=1;
				ans = ans*10 + (*c -48);
			
			}else if(*c == '-' && s==0){ /*if we hit a negative before we hit num */
				numNegs++;
			
			}else {
				/*if we hit a char while we were parsing numbers, then we are done*/
				if (s==1){
					s=2;
				}
			}
			c++;
		}
		if (numNegs%2==1){
			ans*=-1;
		}
		
	}
	return ans;

}