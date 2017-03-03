#include "my.h"

/* prints an integer value, i, to the command line
 * if i is negagtive, prints out the negative sign 
 */
void my_int(int i){
	
	int numTemp =i;
	int temp = i;
	int counter;
	int index;
	if(i<0){
		my_char('-');
	}
	if( i ==0){
		my_char('0');
	}else{
		/* include counter==0 to allow for numTemp to be 0 to start */
		for (counter = 0; numTemp!=0 || counter==0; counter++){
				numTemp/=10;
			}
			counter--;
			for(;counter>=0; counter--){
				temp = i;
				for(index = 0; index<counter; index++){
					temp = (temp/10);
				}
				temp %=10;
				if(temp<0){
					temp = -temp;
				}
				my_char(temp +'0');
			}
	}
}