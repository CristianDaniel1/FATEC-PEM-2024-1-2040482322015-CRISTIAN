#include <stdio.h>
#include <string.h>

#define MAXNAME 50
#define MAXALUNO 50

typedef struct {
  char nome[MAXNAME];
  char status[20];
  float notaFinal;
} Aluno;

void bubbleSort(Aluno alunos[], int tam);
void menuAluno(Aluno alunos[]);
void addAluno(Aluno alunos[], int pos);
void listarAlunos(Aluno alunos[], int tam);

int main(void)
{
  Aluno alunos[MAXALUNO];

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

void menuAluno(Aluno alunos[]) {
  int opcao;
  int numAluno;

  opcao = 0;
  numAluno = 0;

  while (opcao != 3) {
    printf("======================\n");
    printf("  1: Incluir aluno\n");
    printf("  2: Listar Alunos\n");
    printf("  3: Sair\n");
    printf("======================\n");
    
    scanf("%i", &opcao);

    if (opcao == 1) {
      addAluno(alunos, numAluno);
      
      numAluno++;
    } else if (opcao == 2) {
      listarAlunos(alunos, numAluno);
    } else if (opcao != 3) {
      printf("Opçao invalida.\nTente novamente\n\n");
      
      continue;
    }
  }
}

void addAluno(Aluno alunos[], int pos) {
  Aluno novoAluno;
  float notaFinal;
  
  printf("Nome: ");
  scanf("%s", novoAluno.nome);
  
  printf("Nota final: ");
  scanf("%f", &notaFinal);
  
  novoAluno.notaFinal = notaFinal;

  if (notaFinal >= 6)
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
