#include <stdio.h>

int main(){

    //imprime o cabeçalho do jogo
    printf("************************************\n");
    printf("* Bem vindo ao jogo de adivinhacao *\n");
    printf("************************************\n");

    int numerosecreto = 42;

    int chute;

    for(int i=0; i < 3; i++){

        printf("O numero da tentativa eh  %d", i);
        printf("Qual eh o seu chute?  ");
        scanf("%d", &chute);
        printf("Seu chute foi %d \n", chute);


        int acertou = (chute == numerosecreto);

        if(acertou){
        printf("Voce acertou!");
        }
        else{

            int maior = chute > numerosecreto;
            if(maior){
                printf("Seu chute foi maior que o numero secreto!\n");
            }
            else{
                printf("seu chute foi menor que o numero secreto! \n");
            }
            printf("Voce errou! \n");
        }
    }
    Pritnf("Fim de Jogo!");

}   