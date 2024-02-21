Matheus Augusto de Souza
mataugusto1999@gmail.com


#include <stdio.h>
#include <string.h>
#include "getline.h"


#define MAXLINE 1000


char *month(int m) {
  char *names[] = {
    "janeiro", "fevereiro", "março", "abril",
    "maio", "junho", "julho", "agosto",
    "setembro", "outubro", "novembro", "dezembro"
  };
  return names[m - 1];
}


int main(int argc, char *argv[]) {
  int d, m, y; int r;
  char ln[MAXLINE];


  if (argc > 1)  // caso o usuario digite algo alem da função.
  {
    FILE *fp;  // caso o usuario utilize de fato um arquivo.
    fp = fopen(argv[1], "r");
    for (;;) {
      r = my_getline(NULL, ln, sizeof ln, fp);
      if (r == TOO_LONG) {
        printf("too long: [%s]\n", ln);
        continue;
      }
    
  
      if (r == NO_INPUT) {/* quando encontramos o fim do arquivo */
        break;
      }
      
      char event[MAXLINE]; memset(event, '\0', sizeof event);
      r = sscanf(ln, "%d/%d/%d %[^\n]", &d, &m, &y, event);
      if (r < 3) { //Invalid line for some reason. 
        continue;
      }
    
      char date[MAXLINE]; memset(date, '\0', sizeof date);
      snprintf(date, sizeof date, "Dia %d de %s de %d", d, month(m), y);
      printf("%-30s --> %-.30s%s\n", date, event, 
            strlen(event) > 30 ? "..." : "");
    }
    fclose(fp);
  }
}