#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "filmes.h"


struct filmes {
    char chavePrimaria[6];
    char tituloPortugues[61];
    char tituloOriginal[61];
    char nomeDiretor[26];
    char anoLancamento[5];
    char pais[31];
    char nota;
};

struct indicePrimario {
    char chave[6];
    int rrn;
    INDICEP *prox;
};

struct indiceSecundario {
    char titulo[71];
    char chave[6];
    INDICES *prox;
};

int menu() {
   int op = -1;
   do {
      printf("\n\n--------- Insira a opcao desejada:\n");
      printf("\t0- Encerrar programa\n");
      printf("\t1- Inserir novo filme\n");
      printf("\t2- Remover um filme\n");
      printf("\t3- Modificar nota de um filme\n");
      printf("\t4- Inserir novo filme\n");
      printf("\t5- Buscar um filme (por ID)\n");
      printf("\t6- Buscar um filme (por nome)\n");
      printf("Opcao: ");
      scanf("%d", &op);

      if (op < 0 || op > 6)
         printf("OPCAO INVALIDA!");
   } while (op < 0 || op > 6);

   return op;
}

FILE * arquivoFilme() {
   FILE *fp;
   fp = fopen("Trabalho 1\\Files\\movies.dat", "r+a");

   if (fp == NULL)
      fp = fopen("Trabalho 1\\Files\\movies.dat", "w+");

   return fp;
}
FILE * arquivoIndicePrimario() {
   FILE *fp;
   fp = fopen("Trabalho 1\\Files\\iprimary.idx", "r+a");

   if (fp == NULL)
      fp = fopen("Trabalho 1\\Files\\iprimary.idx", "w+");
   else
      verificaIntegridade(fp);

   return fp;
}
FILE * arquivoIndiceSecundario() {
   FILE *fp;
   fp = fopen("Trabalho 1\\Files\\ititle.idx:", "r+a");

   if (fp == NULL)
      fp = fopen("Trabalho 1\\Files\\ititle.idx", "w+");
   else
      verificaIntegridade(fp);

   return fp;
}

void verificaIntegridade(FILE *fp) {
   rewind(fp);

   int flag;
   fscanf(fp, "%d", &flag);

   if (flag == 0) { //Arquivo desatualizado
      //TODO
   }
}

char * geraChavePrimaria(FILME *filme) {
   char *chave = malloc(6);
   for (int i = 0; i < 3; i++)
      chave[i] = filme->nomeDiretor[i];
   chave[3] = filme->anoLancamento[2];
   chave[4] = filme->anoLancamento[3];
   chave[5] = '\0';

   return chave;
}

void inserirFilme(FILE *filmes, FILE *indiceP, FILE *indiceS) {
   FILME * novo = malloc(sizeof(FILME));
   printf("Digite o titulo original do filme: ");
   scanf(" %s", novo->tituloOriginal);
   printf("Digite o titulo em portugues do filme: ");
   scanf(" %s", novo->tituloPortugues);
   printf("Digite o nome do diretor: ");
   scanf(" %s", novo->nomeDiretor);
   printf("Digite o ano de lancamento: ");
   scanf(" %s", novo->anoLancamento);
   printf("Digite o pais do filme: ");
   scanf(" %s", novo->pais);
   printf("Digite sua nota para o filme: ");
   scanf(" %c", &novo->nota);
   strcpy(novo->chavePrimaria, geraChavePrimaria(novo));

   if (validaDuplicidade(novo->chavePrimaria, indiceP) == 1) {
      printf("\nEste filme ja existe na sua base de dados!");
      return;
   }

}

int validaDuplicidade(char *chave, FILE *indiceP) {
   fseek(indiceP, 2, SEEK_SET);
   char busca[6];
   char temp[10];

   while (!feof(indiceP)) {
      fscanf(indiceP, "%[^@]s", busca);
      fscanf(indiceP, "%[^#]s", temp);
      if (strcmp(busca, chave) == 0)
         return 1;
   }

   return 0;
}