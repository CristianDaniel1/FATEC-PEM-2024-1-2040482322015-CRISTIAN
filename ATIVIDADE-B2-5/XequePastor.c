#include <stdio.h>
#include <string.h>

#define MAXLIN 8
#define MAXCOL 8

void criarTabuleiro(void);
void exibirTabuleiro(char tabuleiro[8][8][4]);
void jogada(int origem[2], int destino[2], char tabuleiro[8][8][4]);
void xequePastor(char tabuleiro[8][8][4]);

int main(void)
{
  criarTabuleiro();
  
  return 0;
}

void criarTabuleiro(void) {
  char tabuleiro[MAXLIN][MAXCOL][4];
  char numChar[2];
  char peca[4];
  char *pecas[] = {"T1", "C1", "B1", "D ", "R ", "B2", "C2", "T2"};
  int lin;
  int col;

  printf("=========================================\n");
  printf("       Posicao inicial do tabuleiro\n");
  printf("=========================================\n\n");

  for (lin = 0; lin < MAXLIN; lin++) {

    for (col = 0; col < MAXCOL; col++) {
      
      if (lin < 2 || lin >= 6) {
        lin < 2 ? strcpy(peca, "P") : strcpy(peca, "B");
        
        if (lin == 1 || lin == MAXLIN - 2) {
          strcat(peca, "P");

          sprintf(numChar, "%i", col+1);
          strcat(peca, numChar);
        } else 
          strcat(peca, pecas[col]);
        
        strcpy(tabuleiro[lin][col], peca);
      } 
  
      if (lin >= 2 && lin < 6) {
        
        if (lin % 2 == 0) 
          col % 2 == 0 ? strcpy(peca, " - ") : strcpy(peca, " X ");
        else 
          col % 2 == 0 ? strcpy(peca, " X ") : strcpy(peca, " - ");
        
        strcpy(tabuleiro[lin][col], peca);
      }
    }
  }
  
  exibirTabuleiro(tabuleiro);
  xequePastor(tabuleiro);
}

void exibirTabuleiro(char tabuleiro[8][8][4]) {
  int lin;
  int col;
  
  for (lin = 0; lin < MAXLIN; lin++) {
    
    printf(" %i", (8 - lin));
    for (col = 0; col < MAXCOL; col++) { 
       printf(" %s ", tabuleiro[lin][col]);
    }
    printf("\n");
  }

  printf("    a    b    c    d    e    f    g    h\n\n");
}

void jogada(int origem[2], int destino[2], char tabuleiro[8][8][4]) {
  char peca[4];

  strcpy(peca, tabuleiro[origem[0]][origem[1]]);
  strcpy(tabuleiro[origem[0]][origem[1]], "...");
  strcpy(tabuleiro[destino[0]][destino[1]], peca);
}

void xequePastor(char tabuleiro[8][8][4]) {
  char *mov[7] = {"e4", "e5", "Bc4", "Cc6", "Dh5", "Cf6", "f7"};
  
  int jogadasOrigem[7][2] = {{6, 4}, {1, 4}, {7, 5}, {0, 1}, {7, 3}, {0, 6}, {3, 7}};
  int jogadasDestino[7][2] = {{4, 4}, {3, 4}, {4, 2}, {2, 2}, {3, 7}, {2, 5}, {1, 5}};
  int numJogada = 0;
  int tam;
  int i;
  
  tam = sizeof(jogadasOrigem) / sizeof(jogadasOrigem[0]);
  for (i = 0; i < tam; i++) {
    
    if (i % 2 == 0) {
      numJogada++;
      printf("=========================================\n");
      if (numJogada == 4) 
        printf("          Jogada #%i (Xeque Mate)\n", numJogada);
      else
        printf("                Jogada #%i\n", numJogada);
      printf("=========================================\n\n");
      if (i == 6)
        printf("--- Brancas capturam Peao PP6 em %s e Xeque MATE (Dxf7#)---\n", mov[i]);
      else
        printf("------------ Brancas jogam %s ------------\n", mov[i]);
    }
    else {
      printf("------------ Pretas jogam %s ------------\n", mov[i]);
    }
    
    jogada(jogadasOrigem[i], jogadasDestino[i], tabuleiro);
    exibirTabuleiro(tabuleiro);
  }
}