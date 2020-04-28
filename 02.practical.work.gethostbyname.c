#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>
extern int h_errno;

int main(int argc, char *argv[]){
	while (argv[0] == NULL){
		char hostname[100];
		printf("Enter hostname: ");
		scanf("%s", argv[0]);
	}

	struct hostent *ip_data = gethostbyname(argv[1]);
	int n = sizeof(inet_ntoa(*(struct in_addr*) ip_data->h_addr_list));
	for(int i = 0; i < n; i++){
		char *host_ip = inet_ntoa(*(struct in_addr*) ip_data->h_addr_list[i]);
		printf("The ip of %s is: %s\n", argv[1], host_ip);
	}
}