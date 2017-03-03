/* A simple server in the internet domain using TCP
   The port number is passed as an argument */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/select.h>
#include <sys/time.h>
#include "my.h"
#include "list.h"
#include <signal.h>

int sockfd;
int numClients;
struct s_node* head;/*head of linked list of heads */
void error(const char *msg){
	if(sockfd>0){
		close(sockfd);
	}
    perror(msg);
    exit(1);
}
struct clientInfo{
  char usrName[18];
  int fd; 
 };
void prematureKill(int sig){

	int i;
	int sd;
	my_str("Disconnecting clients....");
	for(i = 0; i<numClients; i++){
		/*sd represents the file desciptor for the current socket */
		sd = ((struct clientInfo*)elem_at(head, i))->fd;
		if(sd>0){
			write(sd, "Server Dying.",30);
			write(sd,"/END",5);
			close(sd);
			free(remove_node_at(&head,i));
		}
	}
		
	if(sockfd>0){
		close(sockfd);
	}
	my_str("Done.\n Closing...\n");
    exit(0);	
}

int main(int argc, char *argv[])
{
    int newsockfd, portno;
    socklen_t clilen;
    char buffer[1024];
    struct sockaddr_in serv_addr, cli_addr;
    int n;
	fd_set readfds;
	int maxFD;
	int sd;
	int opt = 1;
	 numClients = 0;
	 head= NULL; /*head of linked list of heads */
    if (argc < 2) {
		error("ERROR, no port provided");
    }
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if(setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, (char *)&opt, sizeof(opt)) <0){
		error("ERROR setting socket options");
	}
    if (sockfd < 0){
       error("ERROR opening socket");
	}
    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = my_atoi(argv[1]);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0){
       error("ERROR on binding");
    }
    
    listen(sockfd,5);
    clilen = sizeof(cli_addr); 
	signal(SIGTSTP, prematureKill);
	signal(SIGINT, prematureKill);	
	
	while(1){
		int i;
		int j;
		int maxIt;
		FD_ZERO(&readfds);
		/* add the main server socket to read file descriptors */
		FD_SET(sockfd, &readfds);
		maxFD = sockfd;
		for(i=0; i<numClients; i++){
			sd = ((struct clientInfo*)elem_at(head, i))->fd;
			if(sd >0){
				FD_SET(sd, &readfds);
			}
			if(sd > maxFD){
				maxFD = sd;
			}
		}
		
		my_str("Waiting...\n");
		select( maxFD + 1 , &readfds , NULL , NULL , NULL);
		if(FD_ISSET(sockfd, &readfds)){
			my_str("Incoming Call!...");
			/*if here, then means a new client is connecting*/
			if ((newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen))<0)
            {
                perror("could not accept new client\n");
            }else {
				bzero(buffer,1024);
				n = read(newsockfd,buffer,1023);
				if( n>=0){
					int j;
					char* msg;
					char* tmpUsrNme = &buffer[0]; 
					int index;
					int usrExists = 0;
					for(index = 0; index< numClients; index++){
						if(strncmp(tmpUsrNme,((struct clientInfo*)elem_at(head, index))->usrName, n ) ==0){
							my_str("New user trying to connect, but username already exists\n");
							usrExists = 1;
							 write(newsockfd,"Error, user name already exists",200);
							 write(newsockfd, "/END", 5);
						}
					}
					
					if(strncmp(tmpUsrNme, "/END", 4)==0){
						my_str("New user trying to connect, but username invalid\n");
						write(newsockfd,"Error, user name invalid",200);
						write(newsockfd, "/END", 5);
						usrExists = 1;
					}
					if(!usrExists){
					/*create new element in list*/
					struct clientInfo* ci;
					ci = (struct clientInfo*) malloc(sizeof(struct clientInfo));
					buffer[n] = '\0';
					my_strncpy(ci->usrName, buffer, n );					
					ci->fd = newsockfd;
					add_elem(ci, &head);
					numClients++;
					my_str(" Answered call from ");
					my_str(buffer);
					my_char('\n');
					msg = my_strconcat(buffer, " has entered the chat");
					/*write message to all clients that new user entered*/
					for(j = 0; j <numClients; j++){
						sd = ((struct clientInfo*)elem_at(head, j))->fd;
			    	    write(sd,msg,1040);
					}
					free(msg);
					}
				}
			}
		}
		
		/*check for inputs on the clients */
		/*create this variable so that if client disconects and numclients--, go through proper num of times */
		maxIt = numClients;
		for(i = 0; i<maxIt; i++){
			/*sd represents the file desciptor for the current socket */
			sd = ((struct clientInfo*)elem_at(head, i))->fd;
			
			/* check if this was the client sending a message */
			if(sd<=maxFD && FD_ISSET(sd, &readfds)){
				bzero(buffer,1024);

				/*abruptly closed */
				if((n=read( sd , buffer, 1024)) <= 0){
					my_str("Client died... Removing from list\n");
					close(sd);
					free(remove_node_at(&head,i));
					numClients--;
				}else {
				    /*can read from client, it is still open*/
				    int writeToAll =1;
			    	char* cbd1;
					char* cbd2;
					/*null terminate the string */
					buffer[n] = '\0';
					
					
					/*check for special chars. Only the /me causes info to get printed to all clients, 
					 * so set writeToAll to 0 in all others */
					if(buffer[0]=='/'){
					    if(strncmp(buffer, "/me ", 4)==0){
							
								cbd1 = my_strconcat(((struct clientInfo*)elem_at(head, i))->usrName, " ");
								cbd2 = my_strconcat(cbd1, &(buffer[4]));
								my_str("Recieved the following message: ");
								my_str(buffer);
								my_char('\n');
							
							
					    }else if(strncmp(buffer, "/exit", 5)==0 &&strlen(buffer)==5){
							struct clientInfo* c = elem_at(head, i);
					        n = write(sd,"/END",5);
												
							cbd1 = my_strconcat(c->usrName, " has left");
							cbd2 = my_strconcat(cbd1, " the chat");
					        close(sd);
			            	free(remove_node_at(&head,i));
				            numClients--;
							my_str(cbd2);
							my_char('\n');
				           
					    }else if(strncmp(buffer, "/nick ", 6)==0){
							char* tmpUsrNme = &buffer[6]; 
							int index;
							for(index = 0; index< numClients; index++){
								if(strncmp(tmpUsrNme,((struct clientInfo*)elem_at(head, index))->usrName, n ) ==0){
									my_str("User trying to change name, but username already exists\n");
									write(sd,"User name already exists",200);
									writeToAll = 0;
								}
							}
							if(strncmp(tmpUsrNme, "/END", 4)==0){
								my_str("New user trying to connect, but username invalid\n");
								write(sd,"Error, invalid username",200);
								writeToAll = 0;
							}		
							
							if(writeToAll){
								struct clientInfo* c = elem_at(head, i);
								char usrNmeTemp[18];
								my_strcpy(usrNmeTemp, c->usrName);
								my_strncpy(c->usrName, &(buffer[6]), n-6);
								cbd1 = my_strconcat(usrNmeTemp, " changed name to ");
								cbd2 = my_strconcat(cbd1,c->usrName );
								my_str(cbd2);
								my_char('\n');
							}
					    }else {
					       n = write(sd,"improper use of /. Try using /nick newname, /me message, or /exit",75);
					       writeToAll = 0;
					    }
					}else {
						my_str("Recieved the following message: ");
						my_str(buffer);
						my_char('\n');
						cbd1 = my_strconcat(((struct clientInfo*)elem_at(head, i))->usrName, ": ");
			           	cbd2 = my_strconcat(cbd1, &(buffer[0]));
					}
					
				    /*loop through all clients for all other input, including /me */
					for(j = 0; j <numClients &&writeToAll; j++){

						sd = ((struct clientInfo*)elem_at(head, j))->fd;
			    	    n = write(sd,cbd2,1040);
					}
					if(writeToAll){
						free(cbd1);
						free(cbd2);    
					}
				}
			}
		}
	}
    close(sockfd);
    return 0; 
}
