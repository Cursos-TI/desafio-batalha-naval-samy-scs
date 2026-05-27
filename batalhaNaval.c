
#include <stdio.h>
int main (){

    //identificação do tabuleiro
    char letras [10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'}; 
    int tabuleiro [10][10];
    int navio = 3;
    
    //########## CRIAÇÂO DO TABULEIRO ##########
    for (int i = 0; i < 10; i++) 
    {
        for (int j = 0; j < 10; j++) 
        {
            tabuleiro [i][j] = 0;
        }
    }

    //---------------------------------------------------------------------------------------------------------------------------
    //                                        ########## Navio 1 HORIZONTAL ##########
    for (int j = 0; j < 3; j++)    {
        tabuleiro [9][j] = navio;
    } // nesta estrutura, onde o navio fica na HORIZONTAL, o 'i' devera ser fixo, enquanto o 'j' deve variar.
      // Resultado: 10A = [9][0], 10B = [9][1], 10C = [9][2]

    //---------------------------------------------------------------------------------------------------------------------------
    //                                        ########## Navio 2 VERTICAL ##########
    for (int i = 1; i < 4; i++)    {
        tabuleiro[i][4] = navio;
    } // nesta estrutura, onde o navio fica na VERTICAL, o 'j' devera ser fixo, enquanto o 'i' deve variar.
      //Resultado: 2E = [1][4], 3E = [2][4], 4E = [3][4]

    //---------------------------------------------------------------------------------------------------------------------------
    //                       ########## PERCORRER A DIAGONAL DA ESQUERDA PARA A DIREITA ##########
    //Uma diagonal da esquerda para a direita acontece quando linha e coluna aumentam juntas. Ou seja: [i][i], [i+1][i+1]...
    /*
    for (int i = 0; i < 10; i++)    { // colocar 'i' de 0 a 10 percorre toda a diagonal. ex: "i = 0; i < 10"
        tabuleiro[i][i] = navio; 
    } */

    //---------------------------------------------------------------------------------------------------------------------------
    //                       ########## Navio 3 diagonal ########## ESQUERDA PARA A DIREITA ##########

    //para este navio é necessario criar outras variaveis como uma coluna e uma linha inicial,
    //para facilitar quando for colocar os navios.
    int linha1 = 1; //DEFINE A LINHA INICIAL DO NAVIO
    int coluna1 = 6;//DEFINE A COLUNA INICIAL DO NAVIO
    for (int i = 0; i < 3; i++)    {
        tabuleiro[linha1 + i][coluna1 + i] = navio;
    }//Resultado: 2G = [1][6], 3H = [2][7], 4I = [3][8]
    
    //---------------------------------------------------------------------------------------------------------------------------
    //                       ########## PERCORRER A DIAGONAL DA DIREITA PARA A ESQUERDA ##########
    /*
    Para a diagonal da direita para a esquerda, acontece quando 'i' aumenta e 'j' é fixo mas diminui, Ou seja: [i][j], [i+1][j-i]...
    for (int i = 0; i < 10; i++)    { // colocar 'i' de 0 a 10 percorre toda a diagonal. ex: "i = 0; i < 10"
        tabuleiro[i][9 - i] = navio;
    } */

    //---------------------------------------------------------------------------------------------------------------------------
    //                       ########## Navio 4 diagonal ########## DIREITA PARA ESQUERDA ##########

    //para este navio é necessario criar outras variaveis como uma coluna e uma linha inicial,
    //para facilitar quando for colocar os navios.
    int linha2 = 5; //DEFINE A LINHA INICIAL DO NAVIO
    int coluna2 = 2;//DEFINE A COLUNA INICIAL DO NAVIO
    for (int i = 0; i < 3; i++)    {
        tabuleiro[linha2 + i][coluna2 - i] = navio;
    }//Resultado: 6C = [5][2], 7B = [4][1], 8A = [3][0]

    //---------------------------------------------------------------------------------------------------------------------------
    //                                      ########## VISUALIZAÇÃO DO TABULEIRO ##########
    
    //exibe o cabeçalho (A a J).
    printf("Tabuleiro de batalha naval.\n");
    printf("   ");
    for (int i = 0; i < 10; i++)
    {
        printf("%c ", letras[i]);
    }
    printf("\n");

    //---------------------------------------------------------------------------------------------------------------------------
    //Exibir posição do tabuleiro
    for (int i = 0; i < 10; i++)    {
        printf("%2d ", i + 1); //imprime a linha de numeros do tabuleiro (1 a 10).

        for (int j = 0; j < 10; j++)    {// distribui a exibição da matriz [i][j]
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
