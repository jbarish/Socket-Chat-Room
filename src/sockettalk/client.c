#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h> 
#include "my.h"
#include <signal.h>

int sockfd;


void error(const char *msg)
{
	if(sockfd>0){
		close(sockfd);
	}
    perror(msg);
    exit(1);
}
void prematureKill(int sig){
	fd_set readfds;
	write(sockfd, "/exit", 5);
	FD_SET(sockfd, &readfds);
	select(sockfd+1, &readfds, NULL,NULL,NULL);
	if(sockfd>0){
		close(sockfd);
	}
    exit(0);
}

int main(int argc, char *argv[])
{
    int portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
	char buffer[1024];
    char bufferi[1024];
	char buffero[1040];
	fd_set readfds;

    if (argc < 3) {
        my_str("Error: Must provide both hostname and port\n");
       exit(0);
    }
    my_str("Please enter username: ");
    bzero(buffer,1024); /*zero out buffer */
	n = read(0, buffer, 15);/*read usrname*/
	buffer[n-1] = '\0';
	/*if(my_strlen(buffer)==0){
		my_strcpy(buffer, "default");
	}*/

    portno = my_atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) 
        error("ERROR opening socket");
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        my_str("ERROR, no such host\n");
        exit(0);
    }
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr,(char *)&serv_addr.sin_addr.s_addr,server->h_length);
    serv_addr.sin_port = htons(portno);
    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) 
        error("ERROR connecting");
    
    n = write(sockfd,buffer,my_strlen(buffer)+1); /*write username to server*/
    if (n < 0) 
         error("ERROR writing username to server");
    bzero(buffer,1024);
	signal(SIGTSTP, prematureKill);
	signal(SIGINT, prematureKill);
   
   while(1){
	    FD_ZERO(&readfds);
		FD_SET(0, &readfds);
		FD_SET(sockfd, &readfds);
		select( sockfd+1 , &readfds , NULL, NULL , NULL);
		if(FD_ISSET(sockfd, &readfds)){
			bzero(buffero, 1040); /*zero out buffer*/
			if((n = read(sockfd,buffero,1040))<=0){
				error("Server closed. Exiting...");
			}
			if(strncmp(buffero, "/END", 4)==0){
			    /*recieved command to kill oneself*/
			    break;
			}
            if (n < 0) {error("ERROR reading from socket");}
            
            my_str(buffero);
            my_char('\n');
		}
		if(FD_ISSET(0,&readfds)){
			bzero(bufferi,1024);
			n = read(0,bufferi,1024);
			bufferi[n-1] = '\0';
			n = write(sockfd,bufferi,my_strlen(bufferi)+1); 
		}
   }
    close(sockfd);
    return 0;
}