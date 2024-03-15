// Atividade B1_2: Identificação de Palíndromos
// Programação Estruturada e Modular - ADS 2º Semestre
// Cristian Daniel Estevez Cachi
// Natalia Gomes Taira

#include <stdio.h>
#include <string.h>

int main()
{
    char  frase[100];
    char  *palavra;
    int   tamPalavra;
    int   palindromo;
    int   i;

    palindromo = 0;

    printf("-------------------\n");
    printf("Digite uma frase: \n");
    fgets(frase, sizeof(frase), stdin);

    palavra = strtok(frase, " \n");

    printf("Palavras palindromo na frase: \n");

    while (palavra != NULL)
    {
        tamPalavra = strlen(palavra);

        for(i = 0; i < tamPalavra / 2; i++)
        {
            if (palavra[i] == palavra[tamPalavra - i - 1])
            {
                palindromo = 1;
            }
            else
            {
                palindromo = 0;
                break;
            }
        }

        if(palindromo == 1)
            printf("%s \n", palavra);

        palavra = strtok(NULL, " \n");
    }

    printf("-------------------");
    return 0;
}
