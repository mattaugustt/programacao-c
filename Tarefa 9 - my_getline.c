Matheus Augusto de Souza
mataugusto1999@gmail.com


#include <stdio.h>
#include <string.h>
#include "getline.h"


#define OK 0
#define NO_INPUT 1
#define TOO_LONG 2


int my_getline(char *prmpt, char *buff, size_t sz, FILE *fp) {
    int ch, extra;
    if (prmpt != NULL) {
        printf ("%s", prmpt);
        fflush (stdout);
    }
    if (fgets (buff, sz, fp) == NULL)  // ao inves de ter o stdin, usamos o arquivo fp.
        return NO_INPUT;


        if (buff[strlen(buff)-1] != '\n') {
        extra = 0;
        while (((ch = getchar()) != '\n') && (ch != EOF))
            extra = 1;
        return (extra == 1) ? TOO_LONG : OK;
    }
    buff[strlen(buff)-1] = '\0';
    return OK;
}