/*
char **my_str2vect(char*); 
 Takes a string 
 Allocates a new vector (array of string ended by a NULL), 
 Splits apart the input string x at each space character 
 Returns the newly allocated array of strings
 Any number of ' ','\t', and '\n's can separate words.
 I.e. "hello \t\t\n class,\nhow are you?" -> {"hello", "class,", "how", "are","you?", NULL}
 */
 #include "my.h"
 char** my_str2vect(char* c){
    int numOfWords =0;
    int l = my_strlen(c);
    int flag = 1;
	int i;
	char** newC = NULL;
	int newCPos = 0;
    int wordCounter=0;
	if(c !=NULL){
		/*count number of words*/
		for(i = 0; i <= l; i++){
			/*we just finished processing a word*/
			if(flag == 0 && (c[i] == '\n'|| c[i] == '\t' || c[i]==' '|| c[i] =='\0')){
				numOfWords++;
				flag = 1;
			}else if(flag==1 && !(c[i] == '\n'|| c[i] == '\t' || c[i]==' ')){
				flag = 0; 
			}
		}
		 numOfWords++; /*allow for NULL*/
		 newC= (char**) malloc(sizeof(char*) * numOfWords);
		for(i = 0; i<=l; i++){
			 if(flag == 0 &&(c[i] == '\n'|| c[i] == '\t' || c[i]==' '|| c[i] =='\0')){
				newC[newCPos] = (char*)malloc(sizeof(char)*(wordCounter+1));
				newCPos++;
				flag = 1;
				wordCounter =0;
			 }else if(flag==1 && !(c[i] == '\n'|| c[i] == '\t' || c[i]==' '|| c[i] =='\0')){ /*about to start new word */
				flag = 0;
			 }else if(flag == 0 && !(c[i] == '\n'|| c[i] == '\t' || c[i]==' '|| c[i] =='\0')){
				wordCounter++;
			 }
		}
		for(i = 0; i <= l; i++){
			/*we just finished processing a word*/
			if(flag == 0 && (c[i] == '\n'|| c[i] == '\t' || c[i]==' '|| c[i] =='\0')){
				**newC='\0';
				*newC -= wordCounter;
				 flag = 1;
				 newC++;
				 wordCounter = 0;
			 }else if(flag==1 && !(c[i] == '\n'|| c[i] == '\t' || c[i]==' '|| c[i] =='\0')){ /*about to start new word */
				flag = 0;
				**newC= c[i];
				*newC = *newC +1;
				wordCounter++;
			 }else if(flag == 0 && !(c[i] == '\n'|| c[i] == '\t' || c[i]==' '|| c[i] =='\0')){/*in the word*/
				**newC= c[i];
				*newC = *newC +1;
				wordCounter++;
			 }
		 }
		 *newC = NULL;
		newC-=(numOfWords-1);		 
	 }
     return newC;
 }