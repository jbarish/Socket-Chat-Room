#include "my.h"

/* Takes in a number and a String.
 * Uses the length of the string as the base, and converts the number to that base
 * Prints out the letters int the index of new number
 * If num is -, print out - sign followed by letters
 * if c is empty or the pointer is null, return an error
 * if c has length 1, print the char num times.
 */
void my_num_base(int num, char* c){
	
	int base;
	int counter;
	int index;
	int temp;
    int numTemp = num;
	base = my_strlen(c);
	
	if(num<0 && base >0){
		my_char('-');
	}
	
	if (base< 0){
		my_str("Error: Null Pointer");
	}else if (base == 1){
		if(num <0){
			num = -num;
		}
		for(counter = 0; counter < num; counter++){
			my_char(*c);
		}
	}else if(base ==0){
		my_str("Error: Cannot have base 0");
	}else{
		/* include counter==0 to allow for numTemp to be 0 to start */
		for (counter = 0; numTemp!=0 || counter ==0; counter++){
			numTemp/=base;
		}
		counter--;
		
		/*get divisor up to base^counter*/
		for(;counter>=0; counter--){
			temp = num;
			for(index = 0; index<counter; index++){
			temp = (temp/base);
			}
			temp %=base;
			if(temp<0){
				temp = -temp;
			}
			
			my_char(*(c+temp));
		}
	}
}