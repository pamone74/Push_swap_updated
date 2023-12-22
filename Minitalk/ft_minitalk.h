#ifndef FT_MINITALK_H
#define FT_MINITALK_H
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <signal.h>
#include <string.h>
char **str = NULL;

/*
The socket address for IPV4 (Internet Internet Protocol Version 4) this  is built in
This is for socket programming and you do npt really need to 
*/
// struct sockaddr_in
// {
	// short sin_family;
	// unsigned short sin_port;
	// struct in_addr sin_addr;
	// char	sin_sero[8];
// }				t_ipv4;
// 
// struct in_addr
// {
	// unsigned long s_addr; 
	// load with inet_aton() : The inet_aton() is a function for converting the IPV4 address dotted-decimal notation to its binary form: inet_aton() stands for internet address to number 
	/*
		Example:
		int inet_aton(const char *cp, struct in_addr *inp);
		
		cp: A pointer to a string containing the IPv4 address in dotted-decimal notation (e.g., "192.168.1.1").

		inp: A pointer to a struct in_addr where the binary representation of the IPv4 address will be stored.

	*/
// };


#endif