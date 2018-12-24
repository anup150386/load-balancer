

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define MAX_LISTEN_BACKLOG 1
#define BUFFER_SIZE 4096

void handle_client_connection(int client_socket_fd,
			      char *backend_host,
			      char *backend_port_str)
{
	struct addrinfo hints;
	struct addrinfo *addrs;
	struct addrinfo *addrs_iter;
	int getaddrinfo_error;
	int backend_socket_fd;
	char buffer[BUFFER_SIZE];
	int bytes_read;

	memset(&hints, 0, sizeof(struct addrinfo));
	
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	
	getaddinfo_error = getaddrinfo(backend_host, backend_port_str,
				       &hints, &addrs);
	if( getaddinfo_error != 0 )
	{
		fprintf(stderr, "Couldn't find backend: %s\n", gai_stderror(getaddrinfo_error));
		exit(1);
	}

	for( rp = result; rp != NULL; rp = rp->ai_next)
	{
		sfd = socket( rp->ai_family,
			      rp->ai_socktype,
			      rp->ai_protocol);
		if ( sfd == -1 )
		{
			continue;
		}

		if ( connect(sfd,
		     rp->ai_addr,
		     rp->ai_addrlen) != -1)
		{
			break;
		}

		close(sfd);
	}

	if ( rp == NULL )
	{
		fprintf(stderr,"Couldn't connect to backend");
		exit(1);
	}
	
	freeaddrinfo(addrs);

	bytes_read = read(client_socket_fd, buffer, BUFFER_SIZE);
	write(backend_socket_fd, buffer, bytes_read);

	while(bytes_read = read(backend_socket_fd, buffer, BUFFER_SIZE)
	{
		write(client_socket_fd, buffer, BUFFER_SIZE);
	}

	close(client_socket_fd);	
}

int main(int argc, char *argv[])
{
	char *server_port_str;	
	char *backend_addr;
	char *backend_port_str;
	
	struct addrinfo hints;
	struct addrinfo *addrs;
	struct addrinfo *addr_iter;
	int getaddrinfo_error;

	int server_socket_fd;
	int client_socket_fd;

	int so_reuseaddr;

	if(argc != 4)
	{
		fprintf(stderr,"Usage: %s \n",argv[0]);
		exit(1);
	}

	server_port_str = argv[1];
	backend_addr = argv[2];
	backend_port_str = argv[3];

	memset(&hints, 0, sizeof(struct addrinfo));
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_flags = AI_PASSIVE;

	for( addr_iter = addrs; addr_iter != NULL; addr_iter = addr_iter->ai_next)
	{
		server_socket_fd = socket(addr_iter->ai_family,
					  addr_iter->ai_socktype,
					  addr_iter->ai_protocol);
		if(server_socket_fd == -1)
		{		
			continue;
		}
		so_reuseaddr = 1;
		setsockopt(server_socket_fd, SOL_SOCKET, SO_REUSEADDR,
			   &so_reuseaddr, sizeof(so_reuseaddr));
		if(bind(server_socket_fd,
			addr_iter->ai_addr,
			
}


