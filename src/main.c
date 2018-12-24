

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
	
}

int main(int argc, char *argv[])
{
	printf("LOAD BALANCER PROGRAM");
	return 0;
}


