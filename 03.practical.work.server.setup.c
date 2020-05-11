#include <stdio.h> 
#include <netinet/in.h>
#include <string.h> 
#include <sys/socket.h>
#include <arpa/inet.h>

int main(){
	int clientlen, clientfd, serverfd = sizeof(struct sockaddr_in);
	struct sockaddr_in saddr, caddr;
	unsigned short port = 8784;
	char *clientIP;

	serverfd = socket(AF_INET, SOCK_STREAM, 0);

	memset(&saddr, 0, sizeof(saddr));
	saddr.sin_family = AF_INET;
	saddr.sin_addr.s_addr = INADDR_ANY;
	saddr.sin_port = htons(port);

	if ((bind(serverfd, (struct sockaddr *) &saddr, sizeof(saddr))) < 0) {
		printf("Error binding!\n");
		return 0;
	}

		if (listen(serverfd, 10) < 0){
		printf("Error listening!\n");
		return 0;
	}

	while(1){
		if ((clientfd = accept(serverfd, (struct sockaddr *) &caddr, &clientlen)) < 0){
			printf("Error accepting connection..\n");
			return 0;
		} else {
			clientIP = inet_ntoa(caddr.sin_addr);
			printf("A client is connected\n");
			printf("IP address: %s\n", clientIP);
		}
	}
}	