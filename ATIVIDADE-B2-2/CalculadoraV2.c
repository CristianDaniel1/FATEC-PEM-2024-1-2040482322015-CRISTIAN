// Calculadora Versão 2 - Simulação de pilha com Array
// Código adicional, o original foi feito com a Estrutura Pilha

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMMAX 4

int pilhaCheia(int topo);
int empilhar(int topo, float *pilha, float num);
int desempilhar(int topo, float *pilha, float resultado);
float resolverExpressao(char expressao[], float *pilha);
float realizarCalc(float num1, float num2, char operador);

int main(void)
{
  float pilha[TAMMAX];
  float resultado;
  char expressao[50];
  
  printf("Digite a expressao: ");
  fgets(expressao, sizeof(expressao), stdin);
  
  resultado = resolverExpressao(expressao, pilha);
  printf("Resultado: %.2f\n", resultado);
  
  return 0;
}

int pilhaCheia(int topo) {
  if (topo > TAMMAX) {
    printf("\nA expressao supera o maximo de 4 operandos [x, y, z, t]\n");
    printf("Retorno nulo ou ");
    return 1;
  }
  
  return 0;
}

int empilhar(int topo, float *pilha, float num) {
  pilha[topo] = num;
  return topo + 1;
}

int desempilhar(int topo, float *pilha, float resultado) {
  pilha[topo-1] = 0;
  pilha[topo-2] = resultado;
  return topo - 1;
}

float resolverExpressao(char expressao[], float *pilha) {
  int topo;
  float num;
  char *op;
  
  op = strtok(expressao, " ");
  topo = 0;

  while (op) {
    
    if (op[0] == '+' || op[0] == '-' || op[0] == '/' || op[0] == '*') {
      num = realizarCalc(pilha[topo-2], pilha[topo-1], op[0]);
      topo = desempilhar(topo, pilha, num);
    }
    else {
      num = strtol(op, NULL, 10);
      topo = empilhar(topo, pilha, num);
    }
    
    if(pilhaCheia(topo) == 1) 
      return 0.0;
      
    op = strtok(NULL, " ");
  }
  
  return num;
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