#include <stdio.h>

int main(){

    //imprime o cabeçalho do jogo
    printf("************************************\n");
    printf("* Bem vindo ao jogo de adivinhacao *\n");
    printf("************************************\n");

    int numerosecreto = 42;

    int chute;


    printf("Qual eh o seu chute?  ");
    scanf("%d", &chute);
    printf("Seu chute foi %d \n", chute);


    if(chute == numerosecreto){
       printf("Voce acertou!");
    }
    else{
        printf("Voce errou!");
    }

}   