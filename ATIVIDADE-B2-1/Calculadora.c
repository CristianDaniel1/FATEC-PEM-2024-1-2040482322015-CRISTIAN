#include <stdio.h>

#define OPERANDO 2
#define OPERADOR 4

void calculadora(void);
float soma(float *operando);
float subtracao(float *operando);
float multi(float *operando);
float divisao(float *operando);
float realizarCalc(int operador, float *operando);

int main(void)
{
    calculadora();
    
    return 0;
}

void calculadora(void) {
  float operando[OPERANDO] = {0, 0};
  float resultado;
  int operador;
  char sair;
  
  printf("=====================================\n");
  printf("            Calculadora\n");
  printf("=====================================\n");
  
  while (sair != 'S' && sair != 's') {
    operador = 0;

    while (operador < 1 || operador > OPERADOR) {
      printf("1: Soma (+)           2: Subtracao (-)\n");
      printf("3: Multiplicacao (x)  4: Divisao (/)\n\n");
      
      printf("Selecione um operador acima:\n");
      scanf("%i", &operador);
      
      if (operador < 1 || operador > OPERADOR) 
        printf(">>> Operador inválido! <<<\n\n");
    }
    
    printf("Informe o 1º operando:\n");
    scanf("%f", &operando[0]);
    printf("Informe o 2º operando:\n");
    scanf("%f", &operando[1]);
    
    resultado = realizarCalc(operador, operando);
    
    printf("------- Resultado = %.2f -------\n", resultado);
    printf("Deseja Sair [S/N]? \n");
    scanf(" %c", &sair);
    printf("=====================================\n\n");
  }
  printf("     >>> Programa Encerrado <<<\n");
}

float soma(float *operando) {
  return  operando[0] + operando[1];
}

float subtracao(float *operando) {
  return operando[0] - operando[1];
}

float multi(float *operando) {
  return  operando[0] * operando[1];
}

float divisao(float *operando) {
  if (operando[1] == 0) {
    printf("Não é possível dividir por 0.\n");
    return 0;
  }
  
  return operando[0] / operando[1];
}

float realizarCalc(int operador, float *operando) {
  float resultado;
  
  if (operador == 1) 
    resultado = soma(operando);
  if (operador == 2) 
    resultado = subtracao(operando);
  if (operador == 3) 
    resultado = multi(operando);
  if (operador == 4) 
    resultado = divisao(operando);
    
  return resultado;
}