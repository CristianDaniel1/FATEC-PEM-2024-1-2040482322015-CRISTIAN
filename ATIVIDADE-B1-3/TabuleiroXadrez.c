#include <stdio.h>
#include <string.h>

#define LIN 8
#define COL 8

int main(void)
{
  char tabuleiro[LIN][COL][5];
  char peca[5];
  char numChar[2];
  char *pecas[] = {"T1", "C1", "B1", "D ", "R ", "B2", "C2", "T2"};
  char *cols[] = {"a", "b", "c", "d", "e", "f", "g", "h"};
  
  int i;
  int j;

  printf(" =-=-=-=-= TABULEIRO DE XADREZ =-=-=-=-=\n\n");
  
  for(i = 0; i < LIN; i++) {
    
    printf(" %i", i+1);
    for(j = 0; j < COL; j++) {
    
      if(i < 2 || i >= 6) {
        i < 2 ? strcpy(peca, "P") : strcpy(peca, "B");
        
        if (i == 1 || i == LIN - 2) {
          strcat(peca, "P");

          sprintf(numChar, "%i", j+1);
          strcat(peca, numChar);
        } else {
          strcat(peca, pecas[j]);
        }
        
        strcpy(tabuleiro[i][j], peca);
      } 
      
      if(i >= 2 && i < 6) 
        strcpy(tabuleiro[i][j], " X ");
      
      printf(" %s ", tabuleiro[i][j]);
    }
    printf("\n");
  }
  
  printf("  ");
  for(i = 0; i < COL; i++)
    printf("  %s  ", cols[i]);

  return 0;
}
