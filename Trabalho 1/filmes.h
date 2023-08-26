typedef struct filmes FILME;
typedef struct indicePrimario INDICEP;
typedef struct indiceSecundario INDICES;

int menu();
FILE * arquivoFilme();
FILE * arquivoIndicePrimario();
FILE * arquivoIndiceSecundario();
void verificaIntegridade(FILE *);

char * geraChavePrimaria(FILME *);
void inserirFilme(FILE *, FILE *, FILE *);
int validaDuplicidade(char *, FILE *);
//void remover_filme();
//void modificar_nota(int nova_nota);
//void buscar_chave_primaria(char *chave);
//void buscar_chave_secundaria(char *chave);
//void listar_filmes();