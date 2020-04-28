#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>
extern int h_errno;

int main(){
	char hostname[100];
	printf("Enter hostname: ");
	scanf("%s", hostname);

	struct hostent *ip_data = gethostbyname(hostname);
	char *host_ip = inet_ntoa(*(struct in_addr*) ip_data->h_addr_list[0]);

	printf("The ip of %s is: %s\n", hostname, host_ip);
}