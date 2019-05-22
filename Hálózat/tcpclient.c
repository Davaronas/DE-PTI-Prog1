/***************************************/
/*             TCP client              */
/***************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdbool.h>

#define BUFSIZE 1024
#define PORT_NO 2001
#define error(a,b) fprintf(stderr, a, b)

int main(int argc, char *argv[] ) {// arg count, arg vector   

   /* Declarations */
   int fd;	                       // socket endpt	
   int flags;                      // rcv flags
   struct sockaddr_in server;	     // socket name (addr) of server 
   struct sockaddr_in client;	     // socket name of client 
   int server_size;                // length of the socket addr. server 
   int client_size;                // length of the socket addr. client 
   int bytes;    	                 // length of buffer 
   int rcvsize;                    // received bytes
   int trnmsize;                   // transmitted bytes
   int err;                        // error code
   int ip;
				// ip adress
   char on;                        // 
   char buffer[BUFSIZE+1];         // datagram dat buffer area
   char server_addr[16];           // server address	
   char bufferCheck[BUFSIZE+1]; // össze tudjam hasonlítani az előző szóval, amit most beirt a felhasználó
   _Bool firstGo = 1; // az első szónál nem ellenőrzi hogy egyezik e az utolsó betűvel a beirt buffer
   _Bool feladas = 0;
 
   /* Initialization */
   int kuldhet; // éppen küldő vagy váró állapotban van e a kliens
   on    = 1;
   flags = 0;
   server_size = sizeof server;
   client_size = sizeof client;
   sprintf(server_addr, "%s", argv[1]);
   ip = inet_addr(server_addr);
   server.sin_family      = AF_INET;
   server.sin_addr.s_addr = ip;
   server.sin_port        = htons(PORT_NO);
   

   /* Creating socket */
   fd = socket(AF_INET, SOCK_STREAM, 0);
   if (fd < 0) {
      error("%s: Socket creation error.\n",argv[0]);
      exit(1);
   }

   /* Setting socket options */
   setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, (char *)&on, sizeof on);
   setsockopt(fd, SOL_SOCKET, SO_KEEPALIVE, (char *)&on, sizeof on);

   /* Connecting to the server */
   err = connect(fd, (struct sockaddr *) &server, server_size);
   if (err < 0) {
      error("%s: Cannot connect to the server.\n", argv[0]);
      exit(2);
   }
	
	/* Receive data from the server */
	rcvsize = recv( fd, buffer, sizeof(buffer), flags );
	if (rcvsize < 0) {
		error("%s: Cannot receive data from the socket.\n", argv[0]);
		exit(4);
	}
	if(buffer[0] == 'e')
		kuldhet = 1;
	else
		kuldhet = 2;
	// printf("küldhet %d\n",kuldhet);
	if(kuldhet == 2)
		{
			firstGo = 0;
		}
	

   while(feladas == 0)
   {
		
	   	if(kuldhet == 1)
	   	{
			printf("Te jössz!\n");
		   /* User interface */
		   printf("Kérek egy szót: ");


		// printf("first go %d\n",firstGo);
		if(firstGo == 0) 
		{
			int i = strlen(bufferCheck) -1; 
			while (bufferCheck[i] != '\0')
			{
				bufferCheck[i] = '\0';
				i--;
			}
			strcpy(bufferCheck, buffer); 
			// printf("bufferCheck %s\n",bufferCheck);
		}
		
		  





	read: 
		   scanf("%s",buffer);
		
		// printf("first char of buffer %c\n\n\n\n",buffer[0]); 
		// printf("last char of bufferCheck %c\n\n", bufferCheck[strlen(bufferCheck) - 1]);
		// printf("BUFFERCHECK %s",bufferCheck);
		// printf("stringlength buffercheck %d\n\n", strlen(bufferCheck));

		if(strcmp(buffer,"-feladom-") == 0)
		{	
			printf("Feladtad! A másik játékos nyert!\n");
			
		}
		else if(buffer[0] != bufferCheck[strlen(bufferCheck) - 1] && firstGo == 0) 
		{
			printf("Nem ugyanazzal a betűvel kezdődik a szavad!\nPróbáld újra!\n"); 
			goto read; //
		}
		
		system("clear");
		firstGo = 0;
		   bytes = strlen(buffer)+1;
		   buffer[bytes] = '\0';
		   /* Sending data to the server */
		   trnmsize = send(fd, buffer, sizeof(buffer), flags);
		
		   if (trnmsize < 0) {
		      error("%s: Cannot send data to server.\n", argv[0]);
		      exit(3);
		   }
			
		}
		else
		{
			printf("Várakozás a másik játékosra...\n");
		   /* Receive data from the server */
		   rcvsize = recv( fd, buffer, sizeof(buffer), flags );
		   if (rcvsize < 0) {
		      error("%s: Cannot receive data from the socket.\n", argv[0]);
		      exit(4);
		   }
		if(strcmp(buffer,"-feladom-") == 0)
		{	
			printf("Nyertél! A másik játékos feladta!\n");
			feladas = 1;
		}
		strcpy(bufferCheck, buffer); 
	   	printf("Ellenfél választása:\n\n %s\n\n", buffer);
		}
	
	if(kuldhet == 1)
		kuldhet = 2;
	else
		kuldhet = 1;
	}
   /* User interface */
   printf("%i bytes have been sent to server.\n", trnmsize-1);


   /* Receive data from the server */
   rcvsize = recv( fd, buffer, sizeof(buffer), flags );
   if (rcvsize < 0) {
      error("%s: Cannot receive data from the socket.\n", argv[0]);
      exit(4);
   }

   /* User interface */
   if (strcmp(buffer, "Transmit is OK."))
      printf("Acknowledgement has been received from server.\n");
   else
      printf("Acknowledgement error.");


   /* Closing sockets and quit */
   close(fd);
   exit(0);
} 
