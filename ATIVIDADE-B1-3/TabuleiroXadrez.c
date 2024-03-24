#include <stdio.h>
#include <string.h>

#define MAXLIN 8
#define MAXCOL 8

int main(void)
{
  char tabuleiro[MAXLIN][MAXCOL][4];
  char peca[4];
  char numChar[2];
  char *pecas[] = {"T1", "C1", "B1", "D ", "R ", "B2", "C2", "T2"};

  int lin;
  int col;

  printf(" =-=-=-=-= TABULEIRO DE XADREZ =-=-=-=-=\n\n");
  
  for(lin = 0; lin < MAXLIN; lin++) {
    
    printf(" %i", lin+1);
    for(col = 0; col < MAXCOL; col++) {
    
      if(lin < 2 || lin >= 6) {
        lin < 2 ? strcpy(peca, "P") : strcpy(peca, "B");
        
        if (lin == 1 || lin == MAXLIN - 2) {
          strcat(peca, "P");

          sprintf(numChar, "%i", col+1);
          strcat(peca, numChar);
        } else {
          strcat(peca, pecas[col]);
        }
        
        strcpy(tabuleiro[lin][col], peca);
      } 
      
      if(lin >= 2 && lin < 6) 
        strcpy(tabuleiro[lin][col], " X ");
      
      printf(" %s ", tabuleiro[lin][col]);
    }
    printf("\n");
  }
  
  printf("    a    b    c    d    e    f    g    h");
  
  return 0;
}