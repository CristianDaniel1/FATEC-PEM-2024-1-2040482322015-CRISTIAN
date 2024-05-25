#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME 50
#define MAX_ALUNO 50

typedef struct {
  char nome[MAX_NAME];
  char status[20];
  float notaFinal;
} Aluno;

void bubbleSort(Aluno alunos[], int tam);
void lowerCase(char nome[]);
void menuAluno(Aluno alunos[]);
void addAluno(Aluno alunos[], int pos);
void listarAlunos(Aluno alunos[], int tam);
float notaAluno(void);
void limparBufferEntrada(void);

int main(void)
{
  Aluno alunos[MAX_ALUNO];

  menuAluno(alunos);
  
  return 0;
}

void bubbleSort(Aluno alunos[], int tam) {
  int i;
  int j;

  for (i = 0; i < tam; i++) {
    for (j = 0; j < (tam - 1 - i); j++) {
      if (strcmp(alunos[j].nome, alunos[j+1].nome) > 0) {
        Aluno copia = alunos[j];
        alunos[j] = alunos[j + 1];
        alunos[j + 1] = copia;
      }
    }
  }
}

void lowerCase(char *nome) {
  int tamanho; 
  tamanho = strlen(nome);

  for (int i = 0; i < tamanho; i++) 
    nome[i] = tolower(nome[i]);
}

void menuAluno(Aluno alunos[]) {
  int opcao = 0;
  int numAluno = 0;

  while (opcao != 3) {
    printf("======================\n");
    printf("  1: Incluir aluno\n");
    printf("  2: Listar Alunos\n");
    printf("  3: Sair\n");
    printf("======================\n");
    
    printf("Escolha uma opcao: ");
    scanf("%i", &opcao);
    getchar();

    if (opcao == 1) {
      addAluno(alunos, numAluno);
      numAluno++;
    } else if (opcao == 2) {
      listarAlunos(alunos, numAluno);
    } else if (opcao != 3) {
      printf("Opção inválida.\nTente novamente\n\n");
    }
  }

  printf("\nPrograma finalizado.\n");
}

void addAluno(Aluno alunos[], int pos) {
  Aluno novoAluno;
  char nome[MAX_NAME];

  if (pos >= MAX_ALUNO) {
    printf("Lista de alunos excedida.\n");
    return;
  }
  
  printf("Nome: ");
  fgets(nome, sizeof(nome), stdin);

  if (nome[strlen(nome) - 1] != '\n')
    limparBufferEntrada();
  else
    nome[strcspn(nome, "\n")] = '\0';

  strcpy(novoAluno.nome, nome);
  lowerCase(novoAluno.nome);

  novoAluno.notaFinal = notaAluno();

  if (novoAluno.notaFinal >= 6)
    strcpy(novoAluno.status, "Aprovado");
  else
    strcpy(novoAluno.status, "Reprovado");
  
  alunos[pos] = novoAluno;
}

void listarAlunos(Aluno alunos[], int tam) {
  bubbleSort(alunos, tam);
  
  printf("\n          Lista de Alunos\n");
  printf("=====================================\n");
  printf(" NOME    \t  NOTA\t  STATUS\t\n");
  
  for (int i = 0; i < tam; i++) {
    printf(" %s    \t  %.2f\t  %s\t\n", alunos[i].nome, 
    alunos[i].notaFinal, alunos[i].status);
  }
  
  printf("\n");
}

float notaAluno(void) {
  float notaFinal;

  printf("Nota final: ");
  scanf("%f", &notaFinal);

  while (notaFinal < 0 || notaFinal > 10) {
    printf("Nota inválida!\nNota final: ");
    scanf("%f", &notaFinal);
  }
  getchar();

  return notaFinal;
}

void limparBufferEntrada(void) {
  int c;
  while ((c = getchar()) != '\n' && c != EOF);
}
