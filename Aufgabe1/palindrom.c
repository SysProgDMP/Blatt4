#include <stdio.h>
#include <stdlib.h>
#include <string.h>		// die beiden Bibliotheken mussten included werden 
#include <ctype.h>		// string für strlen und ctype für toupper

int palindrom_check1(const char *st1)
{
  int st1_len = strlen(st1), i;

  for(i = 0; i < st1_len / 2; i++){
	if (toupper((int)st1[i]) != toupper((int)st1[st1_len -1 -i])) return 0; //hier musste eine -1 rein
	}
  return 1;
}

int main(void) {
  char *st1, *st2;
  int st1_len, i;
  char *exit ;
  exit = "exit";		// so musste die Übergabe gemacht werden

   
  st1 = malloc(100);
  st2 = malloc(100);

  printf("Zum Beenden exit als Eingabe angeben. \n");
  while (1) {
    printf("Eingabe: ");
    scanf("%s", st1);
    if (strcmp(st1, exit) == 0) return 0;
     
    st1_len = strlen(st1);

    for (i=0; i<st1_len; i++) {
	  st1[st1_len-1-i]= toupper ((int)st1[st1_len-1-i]); 	//hier st1 auch toupper anwenden
      st2[i] = toupper((int)st1[st1_len -1 -i]);
    }
    
    if (palindrom_check1(st1)) printf("1. Test: Palindrom \n");
    else printf("1. Test: Kein Palindrom \n");  
	for (i=0; i<st1_len;i++){
		if (st1[i] != st2[i]){
			printf("2. Test:Kein Palindrom\n");						//hier musste man alle Werte einzeln testen
			break;
			}
		if ((i+1) ==st1_len) printf ("2.Test: Palindrom\n");
	}
 }
 return 0;
}
 