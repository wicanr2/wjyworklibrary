#include <ws2tcpip.h>
#include <winsock2.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]) 
{
	struct addrinfo 
			hints, *res, *p;
	int status;
	char ipstr[100];

	printf("test2\n");
	memset (&hints, 0, sizeof(hints));
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	printf("test2\n");
	status =  
		getaddrinfo (
			argv[1], NULL, &hints,
			&res );
	if ( status != 0 )
		return 2;
	for ( p = res ; p != NULL ; p = p->ai_next )
	{
		void *addr;
		if ( p->ai_family == AF_INET )
		{
			struct sockaddr_in *ipv4 = ( struct sockaddr_in *) p->ai_addr;
			addr = &(ipv4->sin_addr);
			//InetNtopW( p->ai_family, addr, ipstr, sizeof(ipstr) ); 
			
			printf(" ipstr = %s\n", inet_ntoa(ipv4->sin_addr) );
		}
	}
	freeaddrinfo ( res );
	return 0;			
}
