#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>


#ifdef _WIN32
    #define CLEAR “cls”
#else
    #define CLEAR “clear”
#endif



#define linha 9
#define coluna 16

char **tabuleiro;




char gerarLetra() {
    char letra;
    //srand(time(NULL));
    letra = 'A' + rand() % 5;
    return letra;
}

void criarTab (char **vetor) {
    int i,j;


    for(i=0;i<linha;i++){
        for(j=0;j<coluna;j++){
            if(i == 0 || i == 8 || j == 0 || j == 15){
                vetor[i][j] = '#';
            }else{
                vetor[i][j] = ' ';
            }
        }
    }
    vetor[7][7] = gerarLetra();
}

void imprimirTab (char **vetor) {
    int i=0,j=0;
    
    for(i=0;i<linha;i++){
        for(j=0;j<coluna;j++){
            printf("%c", vetor[i][j]);
        }
        printf("\n");
    }
}

void alocaTab () {
   tabuleiro = (char**)malloc(linha * sizeof(char *));
    for(int i =0;i<coluna;i++){
        tabuleiro[i] = (char*)malloc(coluna * sizeof(char));
    } 
}


int main(){

    srand(time(NULL));

    //alocaTab()
    tabuleiro = (char**)malloc(linha * sizeof(char *));
    for(int i = 0;i<coluna;i++){
        tabuleiro[i] = (char*)malloc(coluna * sizeof(char));
    }

    criarTab(tabuleiro);
    int jogar = 1;
    while(jogar){
        imprimirTab(tabuleiro);
        switch (getch()){
        case 'w':
            tabuleiro[7][7] = gerarLetra();
            break;
        default:
            printf("saiu\n");
            jogar = 0;
            break;
        }
        system("cls");
    }


    //freeTab()
    for(int i=0;i<coluna;i++){
        free(tabuleiro[i]);
    }
    free(tabuleiro);

}
