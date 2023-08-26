#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "filmes.c"

int main() {

   FILE *filmes = arquivoFilme();
   FILE *indiceP = arquivoIndicePrimario();
   FILE *indiceS = arquivoIndiceSecundario();

   //TODO: jogar esses arquivos indiceP e S em uma árvore balanceada

   fseek(filmes, 0, SEEK_END);


   int op;
   do {
op = menu();
      switch (op) {
         case 1:
            inserirFilme(filmes, indiceP, indiceS);
            break;
         case 2:
            printf("b");
            break;
         case 3:
            printf("c");
            break;
         case 4:
            printf("d");
            break;
         case 5:
            printf("e");
            break;
         case 6:
            printf("f");
            break;
      }
   } while (op != 0);


   fclose(filmes);
   fclose(indiceP);
   fclose(indiceS);

   return 0;
}