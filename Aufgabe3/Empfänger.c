#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>
 
int main(){
	int fd, err;
	struct sockaddr_in addr;

	//Socket initialisieren
	fd = socket(AF_INET,SOCK_DGRAM,0);
	if (fd<0) { 
		printf ("Achtung bei der Funktion Socket ist ein Fehler aufgetreten\n");
	}
	
	//ÜBergabe der Adressen-Parameter Bei Port 0 für vom System aussuchen
	addr.sin_family = AF_INET;
	addr.sin_port = htons(0);
	addr.sin_addr.s_addr = htonl(INADDR_ANY);
	
	
	err = bind(fd, (struct sockaddr *) &addr, sizeof(struct sockaddr_in));
	if (err<0) { 
		printf ("in der Funktion bind ist ein Fehler aufgetreten");
	}
	
	int  lange= sizeof (struct sockaddr_in);
	
	//Ausgabe des Socketname
	int socketname=getsockname(fd, (struct sockaddr *) &addr, &lange);
	printf ("Das ist die Portnummer von dem aktuellen Prozess:  %i",socketname);
	
	// Variablen für recvfrom
	char* msg = malloc (100* sizeof (char));
	int len, flen;
	struct sockaddr_in from;
	flen = sizeof(struct sockaddr_in);
	
	// Aufruf recvfrom
	len= recvfrom(fd, msg, sizeof(msg), 0 , (struct sockaddr*) &from, &flen);
	
	if (len<0)printf("Bei der recvfrom-Funktion ist ein Fehler aufgetreten");
	
	printf("Received %d bytes from host %s port %d: %s", len, inet_ntoa(from.sin_addr), ntohs(from.sin_port), msg);
	
	//Ausgabe der empfangenen Daten
	int i;
	for (i=0; i<64;i++){
		printf ("%i  ", *(msg+i));
	}
	
	int err1;
	err1= close (fd);
	if (err1<0)printf ("Bei dem Schließen des Sockets ist ein Fehler aufgetreten");
	 
	free (msg);
	
	return 0;	
}