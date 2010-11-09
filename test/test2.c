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
	WSADATA wsaDATA;
    WSAStartup(MAKEWORD(2,2),&wsaDATA); 
    char szHostName[255];
    gethostname(szHostName, 255);
	printf("hello %s\n", szHostName);
	memset (&hints, 0, sizeof(hints));
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_flags = AI_PASSIVE;
    struct hostent *host_entry;
    host_entry=gethostbyname(szHostName);
    char * szLocalIP = 0;
    int i = 0;
    struct in_addr addr;
    while( host_entry->h_addr_list[i] != 0 ) {
           addr.s_addr = *(u_long *) host_entry->h_addr_list[i];
           printf("\tIPv4 Address #%d: %lu %s\n", i, addr.s_addr, inet_ntoa(addr));
           /*szLocalIP = inet_ntoa (*(struct in_addr *)*host_entry->h_addr_list);
           if ( szLocalIP )
              printf("%s\n", szLocalIP );*/
           i++;
    }
    
	status =  
		getaddrinfo (
			"localhost", 
            NULL, 
            &hints,
			&res );
	if ( status != 0 ) {
       WSACleanup();
       printf("status != 0\n");
	   return 2;
    }
	for ( p = res ; p != NULL ; p = p->ai_next )
	{
		void *addr;
		printf( "p->ai_addr = %d\n", p->ai_addr); 
		if ( p->ai_family == AF_INET )
		{
			struct sockaddr_in *ipv4 = ( struct sockaddr_in *) p->ai_addr;
			addr = &(ipv4->sin_addr);
			//InetNtopA ( p->ai_family, addr, ipstr, sizeof(ipstr) ); 

			printf(" inet_ntoa(ipv4->sin_addr) = %s\n", inet_ntoa(ipv4->sin_addr) );
			//printf(" ipstr = %s\n", ipstr );
		}
	}
	freeaddrinfo ( res );
    WSACleanup();
	system("PAUSE");
	return 0;			
}
