#include <stdio.h>
#include <stdlib.h>

struct aluno {
    char *nome;
    char *curso;
    char *ano;
    char *email;
    int nro_UNESP;
};

int main() {
    FILE *fp = fopen("alunos.bin", "w+b");
    int quant;
    struct aluno *Aluno = malloc(sizeof(struct aluno));

    puts("cadastrar quantos? ");
    scanf("%d", &quant);

    for (int i = 0; i < quant; i++) {

        Aluno->nome = malloc(40 * sizeof(char));
        Aluno->curso = malloc(30 * sizeof(char));
        Aluno->ano = malloc(5 * sizeof(char));
        Aluno->email = malloc(20 * sizeof(char));

        printf("Nome: ");
        scanf(" %[^\n]s", Aluno->nome);
        printf("Curso: ");
        scanf(" %[^\n]s", Aluno->curso);
        printf("Ano: ");
        scanf(" %[^\n]s ", Aluno->ano);
        printf("Email: ");
        scanf(" %[^\n]s ", Aluno->email);
        printf("Numero UNESP: ");
        scanf(" %d", &Aluno->nro_UNESP);

        fwrite(Aluno, sizeof(struct aluno), 1, fp);
    }

    rewind(fp);

    puts("Numero que se deseja buscar:");
    scanf(" %d", &quant);
    int encontrado = 0;
    while (!feof(fp)) {
        fread(Aluno, sizeof(struct aluno), 1, fp);
        printf("%s\n", Aluno->nome);
        if (Aluno->nro_UNESP == quant) {
            encontrado = 1;
            break;
        }
    }
    if (encontrado) {
        puts("encontrado: ");
        printf("%s %s %s\n", Aluno->nome, Aluno->curso, Aluno->email);
    } else
        puts("nao encontrado");

    fclose(fp);
    return 0;
}
