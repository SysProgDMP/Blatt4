#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>
 
int main (){

	int df,err;
	struct sockaddr_in addr;

	//Socket initialisieren
	df = socket(AF_INET,SOCK_DGRAM,0);
	if (df<0) { 
		printf ("Achtung bei der Funktion Socket ist ein Fehler aufgetreten\n");
	}
	
	//ÜBergabe der Adressen-Parameter Bei Port 0 für vom System aussuchen
	addr.sin_family = AF_INET;
	addr.sin_port = htons(0);
	addr.sin_addr.s_addr = htonl(INADDR_ANY);
	

	printf ("Wenn sie aus der Schleife wollen geben sie exit als nächste zu sendende Nachricht ein");
	char* run= (malloc(100*sizeof(char)));
	char* exit;
	exit = "exit";
	
	char msg[64];
	
	struct sockaddr_in dest;
	
	dest.sin_family = AF_INET;
	dest.sin_port = htons(4711);						// hier noch die richtigen Daten für den Empfänger eintragen
	dest.sin_addr.s_addr = inet_addr("130.37.193.13");	// hier also auch noch
	
	while (strcmp(run, exit) != 0){
		strcpy(msg, run);
		printf ("Geben sie die zu sendende Nachricht ein: \n");
		scanf ("%s", run);	
		err= sendto(df, msg, strlen(msg)+1,0, (struct sockaddr*) &dest,sizeof(struct sockaddr_in) );
		if (err <0) {
			printf (" Bei der Versendung der Datei ist ein Fehler aufgetreten");
			run ="exit";
		}
	}	
	free (run);
	int err1;
	err1= close (df);
	if (err1<0)printf ("Bei dem Schließen des Sockets ist ein Fehler aufgetreten");
	
	return 0;
}
	