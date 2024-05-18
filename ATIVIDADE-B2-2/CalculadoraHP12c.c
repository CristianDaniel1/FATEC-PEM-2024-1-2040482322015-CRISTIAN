// CalculadoraHP12c - Estrutura Pilha

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMMAX 4

typedef struct no {
    float valor;
    struct no *proximo;
}No;

typedef struct {
  No *topo;
  int tam;
}Pilha;

void criarPilha(Pilha *pont);
void empilhar(Pilha *pont, float num);
No* desempilhar(Pilha *pont);
int pilhaCheia(Pilha *pont);
float realizarCalc(float num1, float num2, char operador);
float resolverExpressao(char expressao[]);

int main(void)
{
  char expressao[50];

  printf("Digite a expressao: ");
  fgets(expressao, sizeof(expressao), stdin);
  
  printf("Resultado: %.2f\n", resolverExpressao(expressao));
  
  return 0;
}

void criarPilha(Pilha *pont) {
  pont->topo = NULL;
  pont->tam = 0;
}

void empilhar(Pilha *pont, float num) {
  No *novo = malloc(sizeof(No));

  if (novo) {
    novo->valor = num;
    novo->proximo = pont->topo;
    pont->topo = novo;
    pont->tam++;
  } else
    printf("\tErro ao alocar memoria!\n");
}

No* desempilhar(Pilha *pont) {
  No *remover = NULL;

  if (pont->topo) {
    remover = pont->topo;
    pont->topo = remover->proximo;
    pont->tam--;
  } else
    printf("\tPilha vazia\n");
    
  return remover;
}

int pilhaCheia(Pilha *pont) {
  if (pont->tam > TAMMAX) {
    printf("\nA expressao supera o maximo de 4 operandos [x, y, z, t]\n");
    printf("Retorno nulo ou ");
    return 1;
  }
  
  return 0;
}

float realizarCalc(float num1, float num2, char operador) {
  switch (operador) {
    case '+':
      return num1 + num2;
      break;
    case '-':
      return num1 - num2;
      break;
    case '/':
      if (num2 == 0) {
        printf("\nErro! nao e possivel dividir por 0.\n");
        return 0.0;
      } else {
        return num1 / num2;
      }
      break;
    case '*':
      return num1 * num2;
      break;
    default:
      return 0.0;
  }
}

float resolverExpressao(char expressao[]) {
  char *op;
  float num;
  Pilha pont;
  No *n1, *n2;

  criarPilha(&pont);
  op = strtok(expressao, " ");

  while (op) {
    
    if (op[0] == '+' || op[0] == '-' || op[0] == '/' || op[0] == '*') {
      n1 = desempilhar(&pont);
      n2 = desempilhar(&pont);
      num = realizarCalc(n2->valor, n1->valor, op[0]);
      
      free(n1);
      free(n2);
      empilhar(&pont, num);
    } else {
      num = strtol(op, NULL, 10);
      empilhar(&pont, num);

      if(pilhaCheia(&pont) == 1)
        return 0.0;
    }
  
    op = strtok(NULL, " ");
  }

  return num;
}