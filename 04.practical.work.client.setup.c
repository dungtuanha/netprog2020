#include <stdio.h> 
#include <netinet/in.h>
#include <string.h> 
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

int main(){
	struct sockaddr_in saddr;
	struct hostent *h;
	int sockfd;
	unsigned short port = 8784;

	if ((sockfd=socket(AF_INET, SOCK_STREAM, 0)) < 0) {
		printf("Error creating socket\n");
	}
	if ((h=gethostbyname("ict.usth.edu.vn")) == NULL) {
		printf("Unknown host\n");
	}
	
	memset(&saddr, 0, sizeof(saddr));
	saddr.sin_family = AF_INET;
	memcpy((char *) &saddr.sin_addr.s_addr, h->h_addr_list[0], h->h_length);
	saddr.sin_port = htons(port);
	
	if (connect(sockfd, (struct sockaddr *) &saddr, sizeof(saddr)) < 0) {
		printf("Cannot connect\n");
	}
}